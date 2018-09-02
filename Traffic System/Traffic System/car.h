#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include <QGraphicsScene> 
#include <QRectF>


class Car : public QObject, public QGraphicsItem
{
	Q_OBJECT

public:
	explicit Car(int dir, int cartype);//构造函数
	void Loadcar();//导入汽车图片
	QRectF boundingRect() const;  //设置自定义的图片元的范围  
	void timerEvent(QTimerEvent *);//10ms控制调度处理事件
	
protected:
	//重绘事件函数
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

public:
	QPixmap Special_Car[4];
	QPixmap Common_Car[4];

	//车速控制变量
	int CarSpeed_dx = 0,CarSpeed_dy = 0;

	int CARTYPE = 0;
	int CarModel = 0;
	int CarPP = 0;
};




#endif