#include "controlwidget.h"
#include "randb.h"
#include <QDesktopWidget>
#include <cstdio>

#define targetDuration .5
#define HOLDTIME .5
#define oRadius min/80
#define cRadius min/40
#define tRadius min/40
#define calRadius min/40
#define TAB << "\t" <<

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
	subject=0;
	
	layout->addRow(tr("Trial Number:"), trialNumBox=new QSpinBox(this));
	trialNumBox->setValue(1);
	trialNumBox->setMaximum(10000);
	trialNumBox->setMinimum(0);
	grayList.push_back(trialNumBox);
	connect(trialNumBox, SIGNAL(valueChanged(int)), this, SLOT(setTrialNum(int)));
	trial=1;
	
	layout->addRow("Stimulus:",stimulusBox=new QComboBox(this));
	stimulusBox->insertItem(0,"Unstimulated");
	stimulusBox->insertItem(1,"Stimulated");
	stimulus=UNSTIMULATED;
	connect(stimulusBox, SIGNAL(activated(int)), this, SLOT(setStimulus(int)));
	
	layout->addRow(tr("Stimulus Gain:"), gainBox=new QDoubleSpinBox(this));
	gainBox->setValue(0);
	gainBox->setMaximum(5);
	gainBox->setMinimum(-5);
	gainBox->setDecimals(3);
	sigGain=0;
	gain=0;
	connect(gainBox, SIGNAL(valueChanged(double)), this, SLOT(setGain(double)));
	
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
	ExperimentRunning=false;
}

void ControlWidget::readPending()
{
	now=getTime();
	
	int s=us->pendingDatagramSize();
	if(inSize != s) in.resize(s);
	us->readDatagram(in.data(), in.size());
	
	if(ignoreInput) //Send something back out so that XPC doesn't choke/stall/worse
	{
		gain=sigGain;
		out=QByteArray(in.data(),sizeof(double));//Copy the timestamp from the input
		out.append(reinterpret_cast<char*>(&gain),sizeof(double));
		us->writeDatagram(out.data(),out.size(),QHostAddress("192.168.1.2"),25000);
		return;
	}
	
	cursor.X()=*reinterpret_cast<double*>(in.data()+sizeof(double));
	cursor.Y()=*reinterpret_cast<double*>(in.data()+2*sizeof(double));
	velocity.X()=*reinterpret_cast<double*>(in.data()+3*sizeof(double));
	velocity.Y()=*reinterpret_cast<double*>(in.data()+4*sizeof(double));
	accel.X()=*reinterpret_cast<double*>(in.data()+5*sizeof(double));
	accel.Y()=*reinterpret_cast<double*>(in.data()+6*sizeof(double));
	force.X()=*reinterpret_cast<double*>(in.data()+7*sizeof(double));
	force.Y()=*reinterpret_cast<double*>(in.data()+8*sizeof(double));
	
	if (!leftOrigin) trialStart=now;
	if (!leftOrigin) if (cursor.dist(origin)>(oRadius+cRadius)) leftOrigin=true;
	
	sphereVec.clear();
	//Target
	if(state!=hold)
	{
		if(state!=inTarget) sphere.color=point(1,0,0); //Red
		else //Yellow -> too slow, White -> too fast
		{
			double acquire_time=targetAcquired-trialStart;
			if (acquire_time<.4) sphere.color=point(1,1,0);
			else if (acquire_time>.6) sphere.color=point(1,1,1);
			else sphere.color=point(0,1,0);
		}
		sphere.position=target;
		sphere.radius=tRadius;
		sphereVec.push_back(sphere);
	}
	//Cursor
	sphere.color=point(0,0,1); //Blue
	sphere.position=cursor;
	sphere.radius=cRadius;
	sphereVec.push_back(sphere);
	userWidget->setSpheres(sphereVec);
		
	switch(state)
	{
	case acquireTarget:
		gain=sigGain;
		if (cursor.dist(target)<(tRadius+cRadius)) {state=inTarget; targetAcquired=now;}
		break;
	case inTarget:
		gain=sigGain;
		if (cursor.dist(target)<(tRadius+cRadius))
		{
			if((now-targetAcquired)>=targetDuration)
			{
				origin=target;
				loadTrial(trial+1);
				leftOrigin=false;
			}
		}
		else state=acquireTarget;
		break;
	case hold:
		if((now-holdStart)>HOLDTIME) state=acquireTarget;
		gain=sigGain*evalSigmoid((now-holdStart),.4);
		break;
	}
	
	out=QByteArray(in.data(),sizeof(double));//Copy the timestamp from the input
	out.append(reinterpret_cast<char*>(&gain),sizeof(double));
	//This will require additional appends for other stimuli
	us->writeDatagram(out.data(),out.size(),QHostAddress("192.168.1.2"),25000);
	
	outStream << trial TAB now-zero TAB cursor.X() TAB cursor.Y() TAB velocity.X() TAB velocity.Y() TAB accel.X() TAB accel.Y() TAB force.X() TAB force.Y() TAB sigGain << endl;
}

void ControlWidget::startClicked()
{
	userWidget->setDeepBGColor(point(0,0,0));
	goGray();
	startButton->setText("Experiment running...");
	if(subject>0)
	{
		char fname[200];
		std::sprintf(fname, "./Data/output%i.dat",subject);
		contFile.setFileName(fname);
		contFile.open(QIODevice::Append);
		outStream.setDevice(&contFile);
	}
	else
	{
		contFile.setFileName("/dev/null");
		contFile.open(QIODevice::Append);
		outStream.setDevice(&contFile);
	}
	target=loadTrial(trial);
	ExperimentRunning=true;
	ignoreInput=false;
	zero=getTime(); //Get first time point.
	lastStim=0;
	smalls=0;
	bigs=0;
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
	trial=T;
	if((smalls+bigs)>=8) emit(endApp());

	if(trial==1)
	{
		leftSide=true;
	}
	
	double mean=.1;
	if(leftSide) {mean*=-1; leftSide=false;}
	else leftSide=true;
	target=point(mean+randb(-.05,.05),center.Y());
	
	sigGain=0;
	if(((T>20)&&((T-lastStim)>=3)&&(randd()<.333))||((T>20)&&((T-lastStim)>=9))) 
	{
		lastStim=T;
		if(randd()<=((4l-smalls)/(8l-smalls-bigs))) {sigGain=1; smalls+=1;}
		else {sigGain=2.5; bigs+=1;}
	}
	
	
	if (sigGain>0) {stimulus=stimuli(1); stimulusBox->setCurrentIndex(1);}
	else {stimulus=stimuli(0); stimulusBox->setCurrentIndex(0);}
	trialNumBox->setValue(T);
	gainBox->setValue(sigGain);
	
	state=hold;
	holdStart=now;
	return target;
}



