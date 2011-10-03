#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QGLWidget>
#include <QRect>
#include <QBasicTimer>
#include <QMutex>
#include <QGLPixelBuffer>
#include <vector>
#include <deque>
#include "point.h"


#define LEFT .3193l
#define RIGHT -.3334l
#define TOP .2203l
#define BOTTOM .7033l
#define PROJECTORX -.02524l
#define PROJECTORY .670401l
#define PROJECTORZ 1.25l

#define LOWERBAR .50l
#define UPPERBAR .65l

class DisplayWidget : public QGLWidget
{
	Q_OBJECT 
	
public:
	struct Sphere
	{
		point position;
		double radius;
		point color;
	};
	
	DisplayWidget(QWidget *parent=0, bool FullScreen=false);
	~DisplayWidget();
	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);
	void timerEvent(QTimerEvent * event) {updateGL();}
	
	void setBGColor(point color) {dataMutex.lock(); backgroundColor=color; dataMutex.unlock();}
	void setSpheres(std::vector<Sphere> s) {dataMutex.lock(); spheres=s; dataMutex.unlock();}
	void setBars(std::deque<double> t) {dataMutex.lock(); times=t; dataMutex.unlock();}
	void setText(QString t) {dataMutex.lock(); text=t; dataMutex.unlock();}
	
private:
	GLuint sphereList, dyntexture;
	int W, H;
	QBasicTimer timer;
	std::vector<Sphere> spheres;
	std::deque<double> times;
	point backgroundColor;
	QMutex dataMutex;
	double min;
	QString text;
	QGLPixelBuffer * pbuffer;
};

#endif
