#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include <QGraphicsScene> 
#include <QRectF>


class Car : public QObject, public QGraphicsItem
{
	Q_OBJECT

public:
	explicit Car(int dir, int cartype);//���캯��
	void Loadcar();//��������ͼƬ
	QRectF boundingRect() const;  //�����Զ����ͼƬԪ�ķ�Χ  
	void timerEvent(QTimerEvent *);//10ms���Ƶ��ȴ����¼�
	
protected:
	//�ػ��¼�����
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

public:
	QPixmap Special_Car[4];
	QPixmap Common_Car[4];

	//���ٿ��Ʊ���
	int CarSpeed_dx = 0,CarSpeed_dy = 0;

	int CARTYPE = 0;
	int CarModel = 0;
	int CarPP = 0;
};




#endif