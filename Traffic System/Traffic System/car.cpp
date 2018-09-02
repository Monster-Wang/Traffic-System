#include "car.h"
#include "trafficsystem.h"
#include "global.h"


CarPosition carposition[8];


int CarNum = 0;

Car::Car(int dir, int cartype)
{
	CARTYPE = cartype;
	CarModel = dir;
	Loadcar();
	
	switch (CarModel)
	{
		case toEast:
			CarSpeed_dy = 0;
			carposition[CarNum].direction = toEast;

			if (CARTYPE == SPECIAL)
			{
				carposition[CarNum].x = 0;
				carposition[CarNum].y = 535;
				CarPP = CarNum;

				setPos(0, 535);
				CarSpeed_dx = 2;
			}
			else if (CARTYPE == COMMON)
			{
				carposition[CarNum].x = 0;
				carposition[CarNum].y = 465;
				CarPP = CarNum;
				setPos(0, 465);
				CarSpeed_dx = 1;
			}
			break;
		case toNorth://逆时针旋转90度
			CarSpeed_dx = 0;
			carposition[CarNum].direction = toNorth;
			if (CARTYPE == SPECIAL)
			{
				carposition[CarNum].x = 685;
				carposition[CarNum].y = 900;
				CarPP = CarNum;
				setPos(685, 900);
				CarSpeed_dy = -2;
			}
			else if (CARTYPE == COMMON)
			{
				carposition[CarNum].x = 615;
				carposition[CarNum].y = 900;
				CarPP = CarNum;
				setPos(615, 900);
				CarSpeed_dy = -1;
			}
			break;
		case toWest://旋转180度
			carposition[CarNum].direction = toWest;
			CarSpeed_dy = 0;
			if (CARTYPE == SPECIAL)
			{
				carposition[CarNum].x = 1200;
				carposition[CarNum].y = 325;
				CarPP = CarNum;
				setPos(1200, 325);
				CarSpeed_dx = -2;
			}
			else if (CARTYPE == COMMON)
			{
				carposition[CarNum].x = 1200;
				carposition[CarNum].y = 395;
				CarPP = CarNum;
				setPos(1200, 395);
				CarSpeed_dx = -1;
			}
			break;
		case toSouth://顺时针旋转90度
			CarSpeed_dx = 0;
			carposition[CarNum].direction = toSouth;
			if (CARTYPE == SPECIAL)
			{
				carposition[CarNum].x = 475;
				carposition[CarNum].y = 0;
				CarPP = CarNum;
				setPos(475, 0);
				CarSpeed_dy = 2;
			}
			else if (CARTYPE == COMMON)
			{
				carposition[CarNum].x = 545;
				carposition[CarNum].y = 0;
				CarPP = CarNum;
				setPos(545, 0);
				CarSpeed_dy = 1;
			}
			break;
		default:
			break;
	}
	CarNum++;
	startTimer(10);
}


void Car::timerEvent(QTimerEvent *)
{
	//边界控制  
	qreal edgeright = scene()->sceneRect().right() + boundingRect().width();
	qreal edgeleft = scene()->sceneRect().left() - boundingRect().width();
	qreal edgetop = scene()->sceneRect().top() - boundingRect().height();
	qreal edgebottom = scene()->sceneRect().bottom() + boundingRect().height();

	if (pos().x() >= edgeright)
		setPos(scene()->sceneRect().left(), pos().y());
	if (pos().x() <= edgeleft)
		setPos(scene()->sceneRect().right(), pos().y());
	if (pos().y() <= edgetop)
		setPos(pos().x(), scene()->sceneRect().bottom());
	if (pos().y() >= edgebottom)
		setPos(pos().x(), scene()->sceneRect().top());

	//speed of car and route control
	qreal dx = CarSpeed_dx;
	qreal dy = CarSpeed_dy;


	int i = 0;

	switch (CarModel)
	{
	case toEast:
		for (i = 0; i < CarNum; i++)
		{
			if (i != CarPP)
			{
				if (carposition[i].y == carposition[CarPP].y)
				{
					//同向碰撞检测
					//if ((carposition[CarPP].x + 100 > carposition[i].x))
					//{
					//	//stop car
					//	dx = 0; dy = 0;
					//}
				}

				if (CARTYPE == COMMON)
				{

					if (carposition[i].direction == toSouth)
					{
						//交叉碰撞检测
						if ((carposition[CarPP].x + 80 < carposition[i].x && carposition[i].x < carposition[CarPP].x + 100)
							&& (carposition[i].y - 40 < carposition[CarPP].y && carposition[CarPP].y < carposition[i].y + 90))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
					else if (carposition[i].direction == toNorth)
					{
						if ((carposition[CarPP].x + 80 < carposition[i].x && carposition[i].x < carposition[CarPP].x + 100)
							&& (carposition[i].y - 50 < carposition[CarPP].y && carposition[CarPP].y < carposition[i].y + 80))
						{
							//stop car
							dx = 0; dy = 0;
						}

					}

				}
				else{
					//同向检测
					if (carposition[i].direction == toNorth || carposition[i].direction == toSouth)
					{
						//交叉碰撞检测
						if ((carposition[CarPP].x + 80 < carposition[i].x && carposition[i].x < carposition[CarPP].x + 100)
							&& (carposition[i].y - 40 < carposition[CarPP].y &&carposition[CarPP].y < carposition[i].y + 80))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
				}
			}
		}
		break;
	case toWest:
		for (i = 0; i < CarNum; i++)
		{
			if (i != CarPP)
			{
				if (carposition[i].y == carposition[CarPP].y)
				{
					//同向碰撞检测
					//if ((carposition[CarPP].x + 100 > carposition[i].x))
					//{
					//	//stop car
					//	dx = 0; dy = 0;
					//}
				}

				if (CARTYPE == COMMON)
				{

					if (carposition[i].direction == toSouth)
					{
						//交叉碰撞检测
						if ((carposition[i].x + 40 < carposition[CarPP].x  && carposition[CarPP].x < carposition[i].x + 60)
							&& (carposition[i].y - 40 < carposition[CarPP].y && carposition[CarPP].y < carposition[i].y + 90))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
					else if (carposition[i].direction == toNorth)
					{
						if ((carposition[i].x + 40 < carposition[CarPP].x  && carposition[CarPP].x < carposition[i].x + 60)
							&& (carposition[i].y - 50 < carposition[CarPP].y && carposition[CarPP].y < carposition[i].y + 80))
						{
							//stop car
							dx = 0; dy = 0;
						}

					}
				}
				else{
					//同向检测
					if (carposition[i].direction == toSouth || carposition[i].direction == toNorth)
					{
						//交叉碰撞检测
						if ((carposition[i].x + 40 < carposition[CarPP].x  && carposition[CarPP].x < carposition[i].x + 60)
							&& (carposition[i].y - 40 < carposition[CarPP].y &&carposition[CarPP].y < carposition[i].y + 80))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
				}
			}
		}
		break;
	case toNorth:
		for (i = 0; i < CarNum; i++)
		{
			if (i != CarPP)
			{
				if (carposition[i].x == carposition[CarPP].x)
				{
					//同向碰撞检测
					//if ((carposition[CarPP].x + 100 > carposition[i].x))
					//{
					//	//stop car
					//	dx = 0; dy = 0;
					//}
				}
				if (CARTYPE == COMMON)
				{
					if (carposition[i].direction == toEast)
					{
						//交叉碰撞检测
						if ((carposition[i].y + 40 < carposition[CarPP].y && carposition[CarPP].y < carposition[i].y + 60)
							&& (carposition[i].x - 40 < carposition[CarPP].x && carposition[CarPP].x < carposition[i].x + 90))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
					else if (carposition[i].direction == toWest)
					{
						if ((carposition[i].y + 40 < carposition[CarPP].y && carposition[CarPP].y < carposition[i].y + 60)
							&& (carposition[i].x - 50 < carposition[CarPP].x && carposition[CarPP].x < carposition[i].x + 80))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
				}else{
					if (carposition[i].direction == toWest || carposition[i].direction == toEast)
					{
						if ((carposition[i].y + 40 < carposition[CarPP].y && carposition[CarPP].y < carposition[i].y + 60)
						&& (carposition[i].x - 40 < carposition[CarPP].x && carposition[CarPP].x < carposition[i].x + 80))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
				}
			}
		}
		break;
	case toSouth:
		for (i = 0; i < CarNum; i++)
		{
			if (i != CarPP)
			{
				if (carposition[i].x == carposition[CarPP].x)
				{
					//同向碰撞检测
					//if ((carposition[CarPP].x + 100 > carposition[i].x))
					//{
					//	//stop car
					//	dx = 0; dy = 0;
					//}
				}
				if (CARTYPE == COMMON)
				{
					if (carposition[i].direction == toEast)
					{
						//交叉碰撞检测
						if ((carposition[CarPP].y + 80 < carposition[i].y && carposition[i].y < carposition[CarPP].y + 100)
							&& (carposition[i].x - 40 < carposition[CarPP].x && carposition[CarPP].x < carposition[i].x + 90))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
					else if (carposition[i].direction == toWest)
					{
						if ((carposition[CarPP].y + 80 < carposition[i].y && carposition[i].y < carposition[CarPP].y + 100)
							&& (carposition[i].x - 50 < carposition[CarPP].x && carposition[CarPP].x < carposition[i].x + 80))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
				}
				else{
					if (carposition[i].direction == toWest || carposition[i].direction == toEast)
					{
						if ((carposition[CarPP].y + 80 < carposition[i].y && carposition[i].y < carposition[CarPP].y + 100)
							&& (carposition[i].x - 40 < carposition[CarPP].x && carposition[CarPP].x < carposition[i].x + 80))
						{
							//stop car
							dx = 0; dy = 0;
						}
					}
				}
			}
		}
		break;
	default:
		break;
	}
	//碰撞检测停车

	if (CARTYPE == COMMON)
	{
		if (!Signal_flag)
		{
			switch (CarModel)
			{
			case toEast:
				//停车线停车
				if (pos().x() < 305 && pos().x() > 300)
				{
					dx = 0; dy = 0;
				}
				break;
			case toWest:
				if (pos().x() > 815 && pos().x() < 820)
				{
					dx = 0; dy = 0;
				}
				break;
			default:
				break;
			}
		}else {
			switch (CarModel)
			{
			case toNorth:
				if (pos().y() < 670 && pos().y() > 665)
				{
					dx = 0; dy = 0;
				}
				break;
			case toSouth:
				if (pos().y() > 150 && pos().y() < 155)
				{
					dx = 0; dy = 0;
				}
				break;
			default:
				break;
			}
		}
	}
	
	//小车行进控制
	setPos(mapToParent(dx, dy));

	//更新小车位置
	carposition[CarPP].x = pos().x();
	carposition[CarPP].y = pos().y();
	
}

QRectF Car::boundingRect() const
{
	if (CARTYPE == SPECIAL)
		return QRectF(0, 0, Special_Car[CarModel].width(), Special_Car[CarModel].height());
	else if (CARTYPE == COMMON)
		return QRectF(0, 0, Common_Car[CarModel].width(), Common_Car[CarModel].height());
}

void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) 
{
	if (CARTYPE == SPECIAL)
		painter->drawPixmap(boundingRect().topLeft(), Special_Car[CarModel]);
	else if (CARTYPE == COMMON)
		painter->drawPixmap(boundingRect().topLeft(), Common_Car[CarModel]);
}

void Car::Loadcar()
{
	qreal height;
	qreal width;

	Special_Car[0].load("images/car2_1.png");
	width = Special_Car[0].width();
	height = Special_Car[0].height();
	//将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
	Special_Car[0] = Special_Car[0].scaled(width*0.2, height*0.2,
		Qt::KeepAspectRatio);

	Common_Car[0].load("images/car1_1.png");
	width = Common_Car[0].width();
	height = Common_Car[0].height();
	//将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
	Common_Car[0] = Common_Car[0].scaled(width*0.2, height*0.2,
		Qt::KeepAspectRatio);

	/****************************************************************/
	Special_Car[1].load("images/car2_2.png");
	width = Special_Car[1].width();
	height = Special_Car[1].height();
	//将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
	Special_Car[1] = Special_Car[1].scaled(width*0.2, height*0.2,
		Qt::KeepAspectRatio);
	Common_Car[1].load("images/car1_2.png");
	width = Common_Car[1].width();
	height = Common_Car[1].height();
	//将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
	Common_Car[1] = Common_Car[1].scaled(width*0.2, height*0.2,
		Qt::KeepAspectRatio);

	/*****************************************************************/
	Special_Car[2].load("images/car2_3.png");
	width = Special_Car[2].width();
	height = Special_Car[2].height();
	//将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
	Special_Car[2] = Special_Car[2].scaled(width*0.2, height*0.2,
		Qt::KeepAspectRatio);
	Common_Car[2].load("images/car1_3.png");
	width = Common_Car[2].width();
	height = Common_Car[2].height();
	//将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
	Common_Car[2] = Common_Car[2].scaled(width*0.2, height*0.2,
		Qt::KeepAspectRatio);

	/****************************************************************/
	Special_Car[3].load("images/car2_4.png");
	width = Special_Car[3].width();
	height = Special_Car[3].height();
	//将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
	Special_Car[3] = Special_Car[3].scaled(width*0.2, height*0.2,
		Qt::KeepAspectRatio);
	Common_Car[3].load("images/car1_4.png");
	width = Common_Car[3].width();
	height = Common_Car[3].height();
	//将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
	Common_Car[3] = Common_Car[3].scaled(width*0.2, height*0.2,
		Qt::KeepAspectRatio);
	
}


