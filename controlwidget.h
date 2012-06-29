#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QtGui>
#include <QByteArray>
#include <QUdpSocket>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <vector>
#include <deque>
#include <iostream>
#include "displaywidget.h"
#include "timestuff.h"
#include <cmath>


class ControlWidget : public QWidget
{
	Q_OBJECT

public:
	ControlWidget(QDesktopWidget * qdw);
	
private:
	QSpinBox *trialNumBox, *subjectBox;
	QDoubleSpinBox *delayBox;
	QPushButton *startButton; 	
	QComboBox *stimulusBox;
	QFormLayout * layout;
		
	DisplayWidget * userWidget;

	void closeEvent(QCloseEvent *event);
	void goGray() {for(std::vector<QWidget*>::iterator it=grayList.begin();it!=grayList.end();++it) (*it)->setEnabled(false); }
	void unGray() {for(std::vector<QWidget*>::iterator it=grayList.begin();it!=grayList.end();++it) (*it)->setEnabled(true); }
	point loadTrial(int T);
	void noConsecutive(bool * array, int n);
	void processUDP(QByteArray in);
	
	QByteArray read,out;
	int inSize, outSize;
	QUdpSocket * us;
	QFile contFile, trialFile;
	QTextStream outStream, trialStream;
	
	double * minJerkParams[6];
	double lastTargetTime, viscousity, curl, saddle, inertia, probeDelay, pillowMag, min, probeOn, visualdelay;
	enum stimuli {UNSTIMULATED=0, CURL=1, SADDLE=2} stimulus;
	enum GameState {acquireTarget=0, inTarget=1} state;
	enum ProbeType {NONE=0, VISCOUSITY=1, PULSE=2} probe;
	std::vector<QWidget*> grayList;
	std::vector<DisplayWidget::Sphere> sphereVec;
	std::deque<timespec> times;
	std::deque<QByteArray> data;
	DisplayWidget::Sphere sphere;

	timespec zero, now, trialStart, targetAcquired;
	bool ExperimentRunning, inputReady, outputReady, ignoreInput, leftOrigin;
	int trial, subject;
	point origin, cursor, velocity, accel, target, force, center, commandforce, unitcommandforce;
	
signals:
	void endApp();
	
public slots:
	void readPending();
	void startClicked();
	void setTrialNum(int i) {trial=i;}
	void setSubject(int i) {subject=i;}
	double evalSigmoid(double t, double risetime) {double a=10l/risetime; t-=risetime/2l; return (a*t/sqrt(1l+pow(a*t,2))+1l)/2l;}
	void setStimulus(int i) {stimulus=stimuli(i);}
	void setDelay(double d) {if (d<=0.0) visualdelay=-1; else visualdelay=d;}
};

#endif
