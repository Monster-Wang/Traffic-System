#include "trafficsystem.h"
#include "trafficsignal.h"
#include "car.h"
#include "global.h"


TrafficSystem::TrafficSystem(QWidget *parent):
	QMainWindow(parent),
	scene(new QGraphicsScene(this)),
	view(new QGraphicsView(scene, this))
{
	setCentralWidget(view);
	ui.setupUi(this);
	setFixedSize(1200, 900);
	scene->setSceneRect(0, 0, 1200, 900);
	scene->addWidget(this);	

	Car *car0 = new Car(toEast, SPECIAL);
	scene->addItem(car0);
	Car *car1 = new Car(toEast, COMMON);
	scene->addItem(car1);

	Car *car2 = new Car(toWest,SPECIAL);
	scene->addItem(car2);
	Car *car3 = new Car(toWest, COMMON);
	scene->addItem(car3);

	Car *car4 = new Car(toNorth, SPECIAL);
	scene->addItem(car4);
	Car *car5 = new Car(toNorth, COMMON);
	scene->addItem(car5);

	Car *car6 = new Car(toSouth, SPECIAL);
	scene->addItem(car6);
	Car *car7 = new Car(toSouth, COMMON);
	scene->addItem(car7);

	Signal *sig = new Signal();
	scene->addItem(sig);

	QGraphicsView *view = new QGraphicsView;
	view->setScene(scene);    //���ó���   
	view->setFixedSize(1200, 900);//������ͼ��С  
	view->show();
	
}


void TrafficSystem::paintEvent(QPaintEvent *e)
{
	RoadLine(this);
}

TrafficSystem::~TrafficSystem()
{

}

void TrafficSystem::RoadLine(QPaintDevice *pd)
{
	QPainter painter(pd);
	painter.setRenderHint(QPainter::Antialiasing, true);

	/****************************��·��������*************************/
	// ���û�����ɫ�����
	painter.setPen(QPen(QColor(70, 70, 70)));
	// ���û�ˢ��ɫ
	painter.setBrush(QColor(70, 70, 70));

	painter.drawRect(0, 310, 1200, 280);//����
	painter.drawRect(460, 0, 280, 900);//����


	/***********************��ƺ��������***************************/
	// ���û�����ɫ�����
	painter.setPen(QPen(QColor(95, 125, 60)));
	// ���û�ˢ��ɫ
	painter.setBrush(QColor(95, 125, 60));

	painter.drawRect(0, 0, 460, 310);
	painter.drawRect(740, 0, 460, 310);
	painter.drawRect(0, 590, 460, 310);
	painter.drawRect(740, 590, 460, 310);

	/***********************���*************************/
	//·����
	painter.setPen(QPen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap));
	painter.drawLine(0, 315, 390, 315);
	painter.drawLine(0, 315 + 270, 390, 315 + 270);
	//ͬ�򳵵��ָ���
	painter.setPen(QPen(Qt::white, 6, Qt::DashLine, Qt::SquareCap));
	painter.drawLine(0, 380, 390, 380);
	painter.drawLine(0, 380 + 140, 390, 380 + 140);
	//˫����

	painter.setPen(QPen(Qt::yellow, 6, Qt::SolidLine, Qt::SquareCap));
	painter.drawLine(0, 445, 390, 445);
	painter.drawLine(0, 445 + 10, 390, 445 + 10);


	/************************�ұ�************************/
	//·����
	painter.setPen(QPen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap));
	painter.drawLine(810, 315, 1200, 315);
	painter.drawLine(810, 315 + 270, 1200, 315 + 270);
	//ͬ�򳵵��ָ���
	painter.setPen(QPen(Qt::white, 6, Qt::DashLine, Qt::SquareCap));
	painter.drawLine(810, 380, 1200, 380);
	painter.drawLine(810, 380 + 140, 1200, 380 + 140);
	//˫����
	painter.setPen(QPen(Qt::yellow, 6, Qt::SolidLine, Qt::SquareCap));
	painter.drawLine(810, 445, 1200, 445);
	painter.drawLine(810, 445 + 10, 1200, 445 + 10);


	/***********************�ϱ�*************************/
	//·����
	painter.setPen(QPen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap));
	painter.drawLine(465, 0, 465, 240);
	painter.drawLine(465 + 270, 0, 465 + 270, 240);
	//ͬ�򳵵��ָ���
	painter.setPen(QPen(Qt::white, 6, Qt::DashLine, Qt::SquareCap));
	painter.drawLine(530, 0, 530, 240);
	painter.drawLine(530 + 140, 0, 530 + 140, 240);
	//˫����
	painter.setPen(QPen(Qt::yellow, 6, Qt::SolidLine, Qt::SquareCap));
	painter.drawLine(595, 0, 595, 240);
	painter.drawLine(595 + 10, 0, 595 + 10, 240);

	/*************************�±�***********************/
	//·����
	painter.setPen(QPen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap));
	painter.drawLine(465, 660, 465, 900);
	painter.drawLine(465 + 270, 660, 465 + 270, 900);
	//ͬ�򳵵��ָ���
	painter.setPen(QPen(Qt::white, 6, Qt::DashLine, Qt::SquareCap));
	painter.drawLine(530, 660, 530, 900);
	painter.drawLine(530 + 140, 660, 530 + 140, 900);
	//˫����
	painter.setPen(QPen(Qt::yellow, 6, Qt::SolidLine, Qt::SquareCap));
	painter.drawLine(595, 660, 595, 900);
	painter.drawLine(595 + 10, 660, 595 + 10, 900);

	/*************************������*****************************/
	painter.setPen(QPen(Qt::white, 10, Qt::SolidLine, Qt::SquareCap));
	int i = 0;
	for (i = 0; i < 14; i++)
	{
		painter.drawLine(410, 320 + i * 20, 410 + 40, 320 + i * 20);
		painter.drawLine(750, 320 + i * 20, 750 + 40, 320 + i * 20);

		painter.drawLine(470 + i * 20, 260, 470 + i * 20, 260 + 40);
		painter.drawLine(470 + i * 20, 600, 470 + i * 20, 600 + 40);
	}

	/**************************ֹͣ��******************************/
	painter.setPen(QPen(Qt::white, 6, Qt::SolidLine, Qt::SquareCap));

	painter.drawLine(390, 445, 390, 445 + 140);
	painter.drawLine(810, 315, 810, 315 + 140);

	painter.drawLine(465, 240, 465 + 140, 240);
	painter.drawLine(595, 660, 595 + 140, 660);

}



