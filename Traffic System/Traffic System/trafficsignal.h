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
	Signal();//���캯��
	~Signal();//��������
	QRectF boundingRect() const;   //�����Զ����ͼƬԪ�ķ�Χ  
	void timerEvent(QTimerEvent *);//8s ���̵��л��¼�

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};


#endif 