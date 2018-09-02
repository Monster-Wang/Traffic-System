#include "trafficsignal.h"
#include "global.h"

bool Signal_flag = false;

Signal::Signal()
{
    Signal_flag = true;
	setFlag(ItemIsMovable);  //可以移动  
	startTimer(8000);
}

void Signal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

	painter->setPen(Qt::black);

	painter->setBrush(Signal_flag ? (Qt::green) : (Qt::red));
	painter->drawEllipse(350, 600, 40, 40);
	painter->drawEllipse(810, 260, 40, 40);

	painter->setBrush(Signal_flag ? (Qt::red) : (Qt::green));
	painter->drawEllipse(410, 200, 40, 40);
	painter->drawEllipse(750, 660, 40, 40);


}

void Signal::timerEvent(QTimerEvent *)
{
	Signal_flag = !Signal_flag;
	this->update(); //估计重新执行paint这个函数  
}

QRectF Signal::boundingRect() const  //静态函数  
{
	return QRectF(330,180, 830,680);
}

Signal::~Signal()
{

}


