#include "controlwidget.h"
#include <QDesktopWidget>
#include <cstdio>

#define targetDuration .5
#define oRadius min/80
#define cRadius min/40
#define tRadius min/40
#define calRadius min/40
#define TAB << "\t" <<
#define CURLVAL -20
#define SADDLEVAL 10
#define TIME_OFFSET .25l
#define VISCOUS_MAG 150
#define VISCOUS_DURATION .8
#define PULSE_DURATION .3
#define PULSE_MAG 10

ControlWidget::ControlWidget(QDesktopWidget * qdw) : QWidget(qdw->screen(qdw->primaryScreen()))
{
	//Take care of window and input initialization.
	setFocus(); //Foreground window that gets all X input
	
	center=point((LEFT+RIGHT)/2l,(TOP+BOTTOM)/2l); //Known from direct observation, do not change
	cursor=center;
	origin=center;
	//state=acquireTarget;
	
	min=(fabs(LEFT-RIGHT)>fabs(TOP-BOTTOM)?fabs(TOP-BOTTOM):fabs(LEFT-RIGHT)); //Screen diameter (shortest dimension) known from direct observation, do not change
	target=point(5,5);
	
	//Snag a UDP Socket and call a function (readPending) every time there's a new packet.
	ignoreInput=true;
	lastTargetTime=-1.0;
	us=new QUdpSocket(this);
	us->bind(QHostAddress("192.168.1.1"),25000,QUdpSocket::DontShareAddress); //Bind the IP and socket you expect packets to be received from XPC on.
	connect(us, SIGNAL(readyRead()),this, SLOT(readPending()));
	
	//Develop GUI window
	layout = new QFormLayout(this);

	layout->addRow(startButton=new QPushButton("Start"));
	connect(startButton, SIGNAL(clicked()), this, SLOT(startClicked()));
	
	layout->addRow(tr("Subject Number:"), subjectBox=new QSpinBox(this));
	subjectBox->setValue(0);
	subjectBox->setMaximum(1000);
	subjectBox->setMinimum(0);
	grayList.push_back(subjectBox);
	connect(subjectBox, SIGNAL(valueChanged(int)), this, SLOT(setSubject(int)));
	
	layout->addRow(tr("Trial Number:"), trialNumBox=new QSpinBox(this));
	trialNumBox->setValue(0);
	trialNumBox->setMaximum(10000);
	trialNumBox->setMinimum(0);
	grayList.push_back(trialNumBox);
	connect(trialNumBox, SIGNAL(valueChanged(int)), this, SLOT(setTrialNum(int)));
	
	layout->addRow("Stimulus:",stimulusBox=new QComboBox(this));
	stimulusBox->insertItem(0,"Unstimulated");
	stimulusBox->insertItem(1,"Curl");
	stimulusBox->insertItem(2,"Saddle");
	stimulus=UNSTIMULATED;
	connect(stimulusBox, SIGNAL(activated(int)), this, SLOT(setStimulus(int)));
	
	layout->addRow(tr("Added Delay:"), delayBox=new QDoubleSpinBox(this));
	delayBox->setValue(0);
	delayBox->setMaximum(2);
	delayBox->setMinimum(0);
	delayBox->setDecimals(3);
	visualdelay=-1;
	connect(delayBox, SIGNAL(valueChanged(double)), this, SLOT(setDelay(double)));
	
	setLayout(layout);
	
	//Plop window in a sane place on the primary screen	
	QRect geo=qdw->screenGeometry();
	geo.setWidth(2*geo.width()/3);
	geo.setHeight(4*geo.height()/5);
	geo.translate(80,80);
	setGeometry(geo);
	
	//Take care of plopping subject's interface onto the secondary screen.
	int notprimary=qdw->primaryScreen()==0?1:0;
	
	userWidget=new DisplayWidget(qdw->screen(notprimary), true);
	userWidget->setGeometry(qdw->screenGeometry(notprimary));
	userWidget->show();
	
	//Set up a "calibration" field. Should be a 1/4 circle in each corner
	sphereVec.clear();
	sphere.color=point(0,.5,0);
	sphere.position=center;
	sphere.radius=min;
	sphereVec.push_back(sphere);
	sphere.color=point(.5,.5,.5);
	sphere.position=center;
	sphere.radius=min/2l;
	sphereVec.push_back(sphere);
	sphere.color=point(1,0,0);
	sphere.position=center;
	sphere.radius=calRadius;
	sphereVec.push_back(sphere);
	point unit(1,0);
	for(double k=0;k<4;k++)
	{
		sphere.color=point(1,0,0);
		sphere.position=center+unit.rotateZero(k*3.14159l/2l)*(min/2l);
		sphere.radius=calRadius;
		sphereVec.push_back(sphere);
	}
	sphere.color=point(.5,.5,.5); //Grey
	sphere.position=point(LEFT,TOP);
	sphere.radius=calRadius;
	sphereVec.push_back(sphere);
	sphere.color=point(.5,.5,.5); //Grey
	sphere.position=point(LEFT,BOTTOM);
	sphere.radius=calRadius;
	sphereVec.push_back(sphere);
	sphere.color=point(.5,.5,.5); //Grey
	sphere.position=point(RIGHT,TOP);
	sphere.radius=calRadius;
	sphereVec.push_back(sphere);
	sphere.color=point(.5,.5,.5); //Grey
	sphere.position=point(RIGHT,BOTTOM);
	sphere.radius=calRadius;
	sphereVec.push_back(sphere);
	userWidget->setSpheres(sphereVec);
	userWidget->setDeepBGColor(point(1,0,0));
	
	inSize=0;
	
	//Initialize everything UPD-related to values that prevent problems
	curl=0;
	saddle=0;
	trial=0;
	subject=0;
	probeDelay=9999999; //Several months ~ infinity
	pillowMag=0;
	ExperimentRunning=false;
	commandforce=point(0,0);
	probeOn=-1;
}

void ControlWidget::readPending()
{
	while(us->hasPendingDatagrams())
	{	
		int s=us->pendingDatagramSize();
		if(inSize != s) read.resize(s);
		us->readDatagram(read.data(), read.size());
		double targetTime=*reinterpret_cast<double*>(read.data());
		if(targetTime>lastTargetTime)
		{
			lastTargetTime=targetTime;
			processUDP(read);
		}
	}
}
	
void ControlWidget::processUDP(QByteArray in)
{
	now=getTime();
	if(ignoreInput) //Send something back out so that XPC doesn't choke/stall/worse
	{
		out=QByteArray(in.data(),sizeof(double));//Copy the timestamp from the input
		switch(stimulus)
		{
		case UNSTIMULATED:
			curl=0;
			saddle=0;
			break;
		case CURL:
			curl=CURLVAL;
			saddle=0;
			break;
		case SADDLE:
			curl=0;
			saddle=SADDLEVAL;
			break;
			
		}
		out.append(reinterpret_cast<char*>(&curl),sizeof(double));
		out.append(reinterpret_cast<char*>(&saddle),sizeof(double));
		out.append(reinterpret_cast<char*>(&target.X()),sizeof(double));
		out.append(reinterpret_cast<char*>(&target.Y()),sizeof(double));
		out.append(reinterpret_cast<char*>(&pillowMag),sizeof(double));
		out.append(reinterpret_cast<char*>(&commandforce.X()),sizeof(double));
		out.append(reinterpret_cast<char*>(&commandforce.Y()),sizeof(double));
		us->writeDatagram(out.data(),out.size(),QHostAddress("192.168.1.2"),25000);
		return;
	}
	
	//Data from force input is not delayed since the subject observes it with no delay.
	force.X()=*reinterpret_cast<double*>(in.data()+7*sizeof(double));
	force.Y()=*reinterpret_cast<double*>(in.data()+8*sizeof(double));
	times.push_back(now);
	data.push_back(in);
	bool old_enough=false;
	if (visualdelay>0)
	{
		while((now-times.front())>=visualdelay)
		{
			times.pop_front();
			in=data.front();
			data.pop_front();
			old_enough=true;
		}
		if(!old_enough) return;
	}
	
	
	cursor.X()=*reinterpret_cast<double*>(in.data()+sizeof(double));
	cursor.Y()=*reinterpret_cast<double*>(in.data()+2*sizeof(double));
	velocity.X()=*reinterpret_cast<double*>(in.data()+3*sizeof(double));
	velocity.Y()=*reinterpret_cast<double*>(in.data()+4*sizeof(double));
	accel.X()=*reinterpret_cast<double*>(in.data()+5*sizeof(double));
	accel.Y()=*reinterpret_cast<double*>(in.data()+6*sizeof(double));
	//Data from force input is not delayed since the subject observes it with no delay.
	
	if (!leftOrigin) trialStart=now;
	if(!leftOrigin) if (cursor.dist(origin)>(oRadius+cRadius)) leftOrigin=true;
	
	sphereVec.clear();
	//Target
	if(state!=inTarget) sphere.color=point(1,0,0); //Red
	else //Yellow -> too slow, White -> too fast
	{
		double acquire_time=targetAcquired-trialStart+TIME_OFFSET;
		//double color=exp(-pow(((targetAcquired-trialStart+TIME_OFFSET)-(UPPERBAR+LOWERBAR)/2l)*5l,2));
		//sphere.color=point(1l-color,color,0);
		if (acquire_time<LOWERBAR) sphere.color=point(1,1,0);
		else if (acquire_time>UPPERBAR) sphere.color=point(1,1,1);
		else sphere.color=point(0,1,0);
	}
	sphere.position=target;
	sphere.radius=tRadius;
	sphereVec.push_back(sphere);
	//Cursor
	sphere.color=point(0,0,1); //Blue
	sphere.position=cursor;
	sphere.radius=cRadius;
	sphereVec.push_back(sphere);
	userWidget->setSpheres(sphereVec);
		
	switch(state)
	{
	case acquireTarget:
		if (cursor.dist(target)<(tRadius+cRadius)) {state=inTarget; targetAcquired=now;}
		break;
	case inTarget:
		if (cursor.dist(target)<(tRadius+cRadius))
		{
			if((now-targetAcquired)>=targetDuration)
			{
				origin=target;
				if(trial>=1) {target=loadTrial(trial+1);}
				else {target=(target==(point(0,0)+center)?point(0,min/3)+center:point(0,0)+center);}
				state=acquireTarget;
				leftOrigin=false;
			}
		}
		else state=acquireTarget;
		break;
	}
	
	double delay=now-trialStart;
	pillowMag=0;
	commandforce=point(0,0);
	switch(probe)
	{
		case NONE:
			break;
		case VISCOUSITY:
			if ((delay>=probeDelay)&&(delay<=(probeDelay+VISCOUS_DURATION)))
			{
				curl=0;
				if(probeOn<0) probeOn=delay;
				pillowMag=VISCOUS_MAG*evalSigmoid(delay-probeOn,.05l); //choose risetime=rise time of motors?
			}
			break;
		case PULSE:
			if ((delay>=probeDelay)&&(delay<=(probeDelay+PULSE_DURATION)))
			{
				curl=0;
				if(probeOn<0)
				{
					probeOn=delay;
					point tmou=(target-origin).unit();
					point cmo=(cursor-origin);
					unitcommandforce=((tmou*tmou.dot(cmo))+origin-cursor).unit();
					std::cout<< unitcommandforce.X() TAB unitcommandforce.Y() << std::endl;
				}
				commandforce=unitcommandforce*PULSE_MAG; //*evalSigmoid(delay-probeOn,.01l); //choose risetime < rise time of motors?
			}
			break;
	}
		
	//out = {most recent timestamp, curl mag, saddle mag, target x, target y (both in robot coordinates), and pillowvec}
	
	out=QByteArray(in.data(),sizeof(double));//Copy the timestamp from the input
	out.append(reinterpret_cast<char*>(&curl),sizeof(double));
	out.append(reinterpret_cast<char*>(&saddle),sizeof(double));
	out.append(reinterpret_cast<char*>(&target.X()),sizeof(double));
	out.append(reinterpret_cast<char*>(&target.Y()),sizeof(double));
	out.append(reinterpret_cast<char*>(&pillowMag),sizeof(double));
	out.append(reinterpret_cast<char*>(&commandforce.X()),sizeof(double));
	out.append(reinterpret_cast<char*>(&commandforce.Y()),sizeof(double));
	//This will require additional appends for other stimuli
	us->writeDatagram(out.data(),out.size(),QHostAddress("192.168.1.2"),25000);
	
	outStream << trial TAB now-zero TAB cursor.X() TAB cursor.Y() TAB velocity.X() TAB velocity.Y() TAB accel.X() TAB accel.Y() TAB force.X() TAB force.Y() TAB pillowMag TAB commandforce.X() TAB commandforce.Y() << endl;
}

void ControlWidget::startClicked()
{
	userWidget->setDeepBGColor(point(0,0,0));
	if(subject>0)
	{
		goGray();
		startButton->setText("Experiment running...");
		char fname[200];
		std::sprintf(fname, "./Data/input%i.dat",subject);
		trialFile.setFileName(fname);
		trialStream.setDevice(&trialFile);
		std::sprintf(fname, "./Data/output%i.dat",subject);
		contFile.setFileName(fname);
		contFile.open(QIODevice::Append);
		outStream.setDevice(&contFile);
		trialStream.setDevice(&trialFile);
		
		
		if(trialFile.exists()) {trialFile.open(QIODevice::ReadOnly); target=loadTrial(trial);}
		else
		{
			QMessageBox::critical(this, "File Not Found!", "File not found, please select a different file.");
		}
	}
	else
	{
		trialFile.setFileName("/dev/null");
		trialStream.setDevice(&trialFile);
		contFile.setFileName("/dev/null");
		contFile.open(QIODevice::Append);
		outStream.setDevice(&contFile);
		trialStream.setDevice(&trialFile);	
		target=center;
	}
	ExperimentRunning=true;
	ignoreInput=false;
	zero=getTime(); //Get first time point.
}



void ControlWidget::closeEvent(QCloseEvent *event)
{
	if(ExperimentRunning)
		if(QMessageBox::question(this, tr("For realz?"), tr("Do you really want to shutdown the experiment?"), QMessageBox::Yes| QMessageBox::Cancel)!=QMessageBox::Yes)
		{
			event->ignore();
			return;
		}
	emit(endApp());
	event->accept();
}



point ControlWidget::loadTrial(int T)
{
	probeOn=-1;
	trial=T;
	if(trialFile.atEnd()) emit(endApp());
	
	char line[200];
	std::string qline;
	int temptrial;
	unsigned int tempprobe;
	double tempx, tempy,tempstim,tempdelay;
	std::cout << "Loading Trial " << T << std::endl;
	do
	{
		trialFile.readLine(line,200);
		std::cout << line << std::endl;
		if(sscanf(line, "%d\t%lf\t%lf\t%lf\t%lf\t%d\t%lf",&temptrial,&tempstim,&tempx,&tempy,&probeDelay,&tempprobe,&tempdelay));
		else
		{
			std::cout << "Complete failure to read line: " << line << std::endl; return center;
		}
	} while ((temptrial < T)&&(!trialFile.atEnd()));
	
	if (fabs(tempstim)>.5) {stimulus=stimuli(1); stimulusBox->setCurrentIndex(1);}
	else {stimulus=stimuli(0); stimulusBox->setCurrentIndex(0);}
	curl=tempstim;
	probe=ProbeType(tempprobe);
	trialNumBox->setValue(T);
	visualdelay=tempdelay;
	delayBox->setValue(visualdelay);
	
	std::cout << "Finished Loading Trial " << temptrial << std::endl;
	double min23=.45*min;	
	return point(tempx,-tempy)*min23+center-point(0,min*.01);
}



