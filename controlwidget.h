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
#include "targetcontrol.h"
#include "displaywidget.h"
#include "timestuff.h"


class ControlWidget : public QWidget
{
	Q_OBJECT

public:
	ControlWidget(QDesktopWidget * qdw);
	
private:
	QSpinBox *trialNumBox, *subjectBox;
	QPushButton *startButton; 	
	QComboBox *stimulusBox, *treatmentBox;
	QFormLayout * layout;
		
	DisplayWidget * userWidget;

	void closeEvent(QCloseEvent *event);
	void goGray() {for(std::vector<QWidget*>::iterator it=grayList.begin();it!=grayList.end();++it) (*it)->setEnabled(false); }
	void unGray() {for(std::vector<QWidget*>::iterator it=grayList.begin();it!=grayList.end();++it) (*it)->setEnabled(true); }
	point loadTrial(int T);
	void noConsecutive(bool * array, int n);
	
	QByteArray in,out;
	int inSize, outSize;
	QUdpSocket * us;
	TargetControl * targets;
	QFile contFile, trialFile;
	QTextStream outStream, trialStream;
	
	double * minJerkParams[6];
	double viscousity,curl,saddle, inertia,KSpring, kickP, kickD, offsetMag, offsetTau;
	enum treatments {UNTREATED=0, EA=1, X2=2} treatment;
	enum stimuli {UNSTIMULATED=0, CURL=1, SADDLE=2} stimulus;
	enum GameState {acquireTarget=0, inTarget=1} state;
	std::vector<QWidget*> grayList;
	std::vector<DisplayWidget::Sphere> sphereVec;
	std::deque<double> times;
	DisplayWidget::Sphere sphere;

	timespec zero, now, trialStart, targetAcquired;
	bool ExperimentRunning, inputReady, outputReady, ignoreInput, leftOrigin;
	int trial, subject;
	point origin, cursor, velocity, accel, target, force, center, normal, lastNormal;
	double min;
	
signals:
	void endApp();
	
public slots:
	void readPending();
	void startClicked();
	void setTrialNum(int i) {trial=i;}
	void setSubject(int i) {subject=i;}
	
	void setTreatment(int i) {treatment=treatments(i);}
	void setStimulus(int i) {stimulus=stimuli(i);}
	
};

#endif
