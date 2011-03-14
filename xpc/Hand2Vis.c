/* 
 *  File     : Hand2Vis.c  'S-Function in C for XPC target'
 *  Abstract : Evaluates the conditions for deciding if a target position has been reached.
 *			   The conditions change depending on the falg feedback type.
 *			   If feedback type is 0 the posiotion of the endpoint its velocity and the time
 *			   spent in the target are evaluated. If it is 1 the position of the endpoint projection
 *			   ,on the a line going from the origin to the target, is evaluated.
 *			 
 *      
 *      Input: Robot's endpoint position (X,Y), target position Xt,Yt 
 *			   feedback type:0 normal 1 if the proyection is in target.
 *      
 *
 *    Output :  1 if experimental conditions on position velocity and time are met 
 *				according to feedback type.
 *              0 otherwise. 
 *      
 *  Santiago Acosta 02-12-03
 */


#define S_FUNCTION_NAME Hand2Vis
#define S_FUNCTION_LEVEL 2
#define PI 3.14159


#include "simstruc.h"
#include "hand2vis.h"



#define U(element) (*uPtrs[element])  /* Pointer to Input Port0 */


#define INF_TARGET_SIZE 10000  /* 'Infinite target size'  in mm */
#define INF_DISPLAY 10000 /* out of plotting area */



/* PARAMETERS */

	/* 
	 *  Target size :'TS' 
	 */
// #define TS_IDX 0
// #define TS_PARAM(S) ssGetSFcnParam(S,TS_IDX)
 	/* 
	 *  Hold Interval :'HI' 
	 */
// #define HI_IDX 1
// #define HI_PARAM(S) ssGetSFcnParam(S,HI_IDX)
 	/* 
	 *  Velocity Threshhold :'VT' 
	 */
// #define VT_IDX 2
// #define VT_PARAM(S) ssGetSFcnParam(S,VT_IDX)
 
#define NPARAMS 0


// real_T x_h[3]= { 0.0,0.0,0.0 };
// real_T y_h[3]= { 0.0,0.0,0.0 };

real_T SamplingTime = 0.0; /* sampling time */
// real_T samples_in_target=0.0; /* number of samples correspondig to parameter duration in target */ 
// real_T target_size= 0.0;
// real_T vel_thresh=0.0;

// static int_T	flg=1;
static int_T	counter=1;
// static real_T visualXY[2] = {0.0,0.0};

// static real_T	countSamples;
// static int_T	update = 0;
//static real_T	TrialTime=0;
//static real_T	LastTrialTime=0; 
//static real_T	maxVel = 0;
//static real_T	LastTrialmaxVel=0;
//static int_T	TargetStatus = 1;
//static int_T	SpeedTrigger = 0;
//static real_T   prevX = 0;
//static real_T   prevY = 0;
static real_T   predX = 0; 
static real_T   predY = 0; 


/*====================*
 * S-function methods *
 *====================*/
static void UpdatePositionBuffers(real_T x, real_T y);

// #define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
  /* Function: mdlCheckParameters =============================================
   * Abstract:
   *    Validate our parameters to verify they are okay.
   */
  static void mdlCheckParameters(SimStruct *S)
  {
      /* Check 1st parameter: target size */
      {
          if (!mxIsDouble(TS_PARAM(S)) ||
              mxGetNumberOfElements(TS_PARAM(S)) != 1) {
              ssSetErrorStatus(S,"1st parameter to S-function must be a "
                               "scalar \"lower bound\" which limits "
                               "the size of the target in m");
              return;
          }
      }
 
      /* Check 2nd parameter: hold time*/
      {
          if (!mxIsDouble(HI_PARAM(S)) ||
              mxGetNumberOfElements(HI_PARAM(S)) != 1) {
              ssSetErrorStatus(S,"2nd parameter to S-function must be a "
                               "scalar \"upper bound\" which defines "
                               "the time the subject must be in the target in sec.");
              return;
          }
      }
 
      /* Check 3nd parameter: velocity threshold */
      {
          if (!mxIsDouble(VT_PARAM(S)) ||
              mxGetNumberOfElements(VT_PARAM(S)) != 1) {
              ssSetErrorStatus(S,"3rd parameter to S-function must be a "
                               "scalar \"initial value\" which defines "
                               "maximum velocity allowed inside the target in m/sec.");
              return;
          }
      }
  }
#endif /* MDL_CHECK_PARAMETERS */
 


/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{
  
    ssSetNumSFcnParams(S, NPARAMS);  /* Number of expected parameters */
     
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 2); // discrete states visualX and visualY  

    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, 3);  /* Five Inputs: X, Y, Xt, Yt,feedback type 0 or 1)  */
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S, 1)) return;
    ssSetOutputPortWidth(S, 0, 4);  /*  target reached flag and position or false position */

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}



/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy that we inherit our sample time from the driving block.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME); 
    ssSetOffsetTime(S, 0, 0.0);
}



#define MDL_INITIALIZE_CONDITIONS
/* Function: mdlInitializeConditions ========================================
 * Abstract:
 *    Initialize discrete states .
 */
static void mdlInitializeConditions(SimStruct *S)
{
    real_T *x0 = ssGetRealDiscStates(S);
   
		x0[0]=0;    /* x */
        x0[1]=0;    /* y */

	

	SamplingTime = ssGetSampleTime(S,0); /* Get the sampling period */	
	 counter = 1;

/*
 * Convert parameters to global variables so that you only call callback functions once
 * at the begining of the simulation. This is intended for Dialog Parameter only.
 * Care should be taken if the parameters are changed during simulation (runtime parameters) 
 * in which case a different procedure needs to be implemented.
 * (see runtime parameters in the 'S-functions' documentation.
 */
	 
/*	 samples_in_target= *mxGetPr(HI_PARAM(S))/SamplingTime;
	 target_size      = *mxGetPr(TS_PARAM(S));
	 vel_thresh       = *mxGetPr(VT_PARAM(S));
										 // try this:  *mxGetPr(HI_PARAM(S))
 */
}



/* Function: mdlOutputs =======================================================
 * Abstract:
 *      
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
	real_T				*y    = ssGetOutputPortRealSignal(S,0);
    real_T              *visualXY  = ssGetRealDiscStates(S);
    InputRealPtrsType	uPtrs = ssGetInputPortRealSignalPtrs(S,0);
	real_T				tempx ;
	real_T				tempy ;
	real_T				TargetClock;
	int_T				vftype;
	real_T				gamma, theta, fi, yprime,L;
		
    UNUSED_ARG(tid); /* not used in single tasking mode */
	
	if (counter>15) { // wait for derivatives to settle 
		// TODO: remove inverse transform when the predictions are made in manipulandum coords.
		y[0] = V2H[0][0]*predX +V2H[0][1]*predY +V2H[0][2]*predX*predX +V2H[0][3]*predY*predY +V2H[0][4]*predX*predY +V2H[0][5];
		y[1] = V2H[1][0]*predX +V2H[1][1]*predY +V2H[1][2]*predX*predX +V2H[1][3]*predY*predY +V2H[1][4]*predX*predY +V2H[1][5];;
		y[2] = V2H[0][0]*visualXY[0] +V2H[0][1]*visualXY[1] +V2H[0][2]*visualXY[0]*visualXY[0] +V2H[0][3]*visualXY[1]*visualXY[1] +V2H[0][4]*visualXY[0]*visualXY[1] +V2H[0][5];
		y[3] = V2H[1][0]*visualXY[0] +V2H[1][1]*visualXY[1] +V2H[1][2]*visualXY[0]*visualXY[0] +V2H[1][3]*visualXY[1]*visualXY[1] +V2H[1][4]*visualXY[0]*visualXY[1] +V2H[1][5];
	}
	else {
        y[0] = 0;
		y[1] = 0;
        y[2] = 0;
		y[3] = 0;
	}
	counter++;
}


#define MDL_UPDATE
/* Function: mdlUpdate ======================================================
 * Abstract:
 *      xdot = 
 */
static void mdlUpdate(SimStruct *S, int_T tid)
{
   
    real_T            *visualXY  = ssGetRealDiscStates(S);
    InputRealPtrsType uPtrs    = ssGetInputPortRealSignalPtrs(S,0);
	int_T lp;
/*	static real_T Px[4] = {0,0,0,0}; // Position
	static real_T Py[4] = {0,0,0,0};
	static real_T Vx[2] = {0,0}; // Velocity
	static real_T Vy[2] = {0,0};
	static real_T Ax;    // Acceleration
	static real_T Ay;
	real_T        velx=0;
	real_T        vely=0;
	real_T        win[4]= { -0.25,-0.25,0.25,0.25};
	int_T         i;
	real_T		  velCoef, accCoef; */
	real_T		  Hx,Hy,x,y,predHorizon;

    UNUSED_ARG(tid); /* not used in single tasking mode */


	Hx = U(0);
	Hy = U(1);
	predHorizon = U(2);

	// visualXY[0] =  1.2019*Hx +0.0229*Hy -0.0370*Hx*Hx -0.0306*Hy*Hy -0.0269*Hx*Hy +0.0197;
	// visualXY[1] = -0.0105*Hx +1.1619*Hy +0.0262*Hx*Hx -0.0054*Hy*Hy +0.0169*Hx*Hy -0.0163;
	
	// TODO: stop transforming to visual coordinates here and make predictions in manip. coords.
	visualXY[0] = H2V[0][0]*Hx +H2V[0][1]*Hy +H2V[0][2]*Hx*Hx +H2V[0][3]*Hy*Hy +H2V[0][4]*Hx*Hy +H2V[0][5];
	visualXY[1] = H2V[1][0]*Hx +H2V[1][1]*Hy +H2V[1][2]*Hx*Hx +H2V[1][3]*Hy*Hy +H2V[1][4]*Hx*Hy +H2V[1][5];
	
	// visualXY[0] = Hx;
	// visualXY[1] = Hy;
	
	UpdatePositionBuffers(visualXY[0], visualXY[1], predHorizon);
}


static void UpdatePositionBuffers(real_T x, real_T y,real_T predHorizon)
{
	static real_T Px[4] = {0,0,0,0}; // Position
	static real_T Py[4] = {0,0,0,0};
	static real_T Vx[2] = {0,0}; // Velocity
	static real_T Vy[2] = {0,0};
	static real_T AccBuffx[7] = {0,0,0,0,0,0,0};
	static real_T AccBuffy[7] = {0,0,0,0,0,0,0};
	static real_T Ax;    // Acceleration
	static real_T Ay;
	real_T        velx=0;
	real_T        vely=0;
	real_T        win[4]= { -0.25,-0.25,0.25,0.25};
	real_T		  winHan[7] = { 0.0366, 0.1250, 0.2134, 0.2500, 0.2134, 0.1250, 0.0366 };
	int_T         i;
	real_T		  velCoef, accCoef;

	for (i=0; i<3; i++) {
		Px[i] = Px[i+1];
		Py[i] = Py[i+1];
		velx += win[i]*Px[i];
		vely += win[i]*Py[i];
	}
	Px[3] = x;
	Py[3] = y;
	velx += win[3]*Px[3];
	vely += win[3]*Py[3];
	Vx[0] = Vx[1];
	Vx[1] = velx;
	Vy[0] = Vy[1];
	Vy[1] = vely;
	for (i=0; i<6; i++) {
		AccBuffx[i] = AccBuffx[i+1];
		AccBuffy[i] = AccBuffy[i+1];
	}
	AccBuffx[6] = Vx[1]-Vx[0];
	AccBuffy[6] = Vy[1]-Vy[0];
	Ax = 0;
	Ay = 0;
	for (i=0; i<7; i++) {
		Ax += AccBuffx[i]*winHan[i];
		Ay += AccBuffy[i]*winHan[i];
	}
	
	if (predHorizon >0) {
		velCoef = -0.00034264*predHorizon*predHorizon +0.206032634*predHorizon + 0.92582937864;
		accCoef = -0.00006207*pow(predHorizon,3) +0.020374548*predHorizon*predHorizon + 0.272840224*predHorizon + 0.832225862;
		predX = x + velCoef*velx + accCoef*Ax; 
		predY = y + velCoef*vely + accCoef*Ay;
	}
	else {
		predX = x;
		predY = y;
	}

	// predX = x + 6.89*velx +25.35*Ax; // Horizon of 30ms
	// predY = y + 6.89*vely +25.35*Ay;
}


/* Function: mdlTerminate =====================================================
 * Abstract:
 *    No termination needed, but we are required to have this routine.
 */
static void mdlTerminate(SimStruct *S)
{
    
     /*UNUSED_ARG(S); /* unused input argument */
    
	

}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


