#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QGLWidget>
#include <QRect>
#include <QBasicTimer>
#include <QMutex> 
#include <vector>
#include <deque>
#include "point.h"

#define LEFT (-.019l+.506l/2l)
#define RIGHT (-.019l-.506l/2l)
#define TOP (.53l-.288l/2l)
#define BOTTOM (.53l+.288l/2l)

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
	GLuint sphereList;
	int W, H;
	QBasicTimer timer;
	std::vector<Sphere> spheres;
	std::deque<double> times;
	point backgroundColor;
	QMutex dataMutex;
	double min;
	QString text;
};

#endif
