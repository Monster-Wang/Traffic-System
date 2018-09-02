#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>

class QGraphicsScene;

class Controller : public QObject
{
	Q_OBJECT
public:
	Controller(QGraphicsScene &scene, QObject *parent = 0);
	~Controller();

private:
	QGraphicsScene &scene;
};

#endif