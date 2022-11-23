#ifndef __Snake__
#define __Snake__

#include "../../adt/listdp/listdp.h"
#include "../../boolean.h"


void Move(List *L,char input);

void createSnake(List*L);

void printPoint(POINT P);

address isPoinMember(List L,int i,int j);

void printMap(List L,POINT food,POINT meteor, POINT obstacle);

boolean isNotWall(List L,char input);

boolean isBody(List L,char input);

void moveHead(List *L,char input);

boolean isEat(List *L,POINT P);

void addFood(POINT *food,List L, POINT obstacle);

void addMeteor(POINT *meteor,POINT food);

void addObstacle(List L,POINT* obstacle);

boolean isAvail(List L,int X,int Y);

void addTail(List *L,ElmtList newtail);

void MeteorHitBody(List *L,POINT food, POINT meteor);

void snakeOnMeteor(int * skor);

boolean isLose(List L,POINT meteor, POINT obstacle);

boolean isHeadHitObstacle(List L,POINT obstacle);

boolean isMeteorHitHead(List L);

int lengthSnake(List L);

#endif