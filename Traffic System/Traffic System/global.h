#ifndef GLOBAL_H
#define GLOBAL_H


#define CarWidth	410*0.2
#define CarHeigth   210*0.2


extern bool Signal_flag;
extern int CarNum;

struct CarPosition
{
	qreal x;
	qreal y;
	int direction;

};

extern CarPosition carposition[8];

enum CarType{
	SPECIAL,
	COMMON
};

enum CarMoveDirection{
	toEast,
	toNorth,
	toWest,
	toSouth
};




#endif