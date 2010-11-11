#include <QApplication>
#include "controlwidget.h"

int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	ControlWidget cw(a.desktop());
	cw.show();
	QObject::connect(&cw, SIGNAL(endApp()), &a, SLOT(quit()));
	return a.exec();
}


	
