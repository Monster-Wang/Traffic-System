#include "trafficsystem.h"
#include <QtWidgets/QApplication>

#include <QApplication>
#include <QPushButton>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TrafficSystem w;
	w.show();
	return a.exec();

}
