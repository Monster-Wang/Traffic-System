#ifndef TRAFFICSIGNAL_H
#define TRAFFICSIGNAL_H

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene> 
#include <QRectF>
#include "trafficsystem.h"

class Signal : public QObject, public QGraphicsItem
{
	Q_OBJECT

public:
	Signal();//构造函数
	~Signal();//析构函数
	QRectF boundingRect() const;   //设置自定义的图片元的范围  
	void timerEvent(QTimerEvent *);//8s 红绿灯切换事件

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};


#endif 