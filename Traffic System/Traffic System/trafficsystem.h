#ifndef TRAFFICSYSTEM_H
#define TRAFFICSYSTEM_H

#include <QtWidgets/QMainWindow>
#include "ui_trafficsystem.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QRectF>
#include <QObject>
#include <QTimer>
#include <QDebug>



class QGraphicsScene;
class QGraphicsView;

class TrafficSystem : public QMainWindow
{
	Q_OBJECT

public:
	TrafficSystem(QWidget *parent = 0);
	~TrafficSystem();

private:
	Ui::TrafficSystemClass ui;
	void RoadLine(QPaintDevice *pd);
	QGraphicsScene *scene;
	QGraphicsView *view;

protected:
	void paintEvent(QPaintEvent *e);

};

#endif // TRAFFICSYSTEM_H
