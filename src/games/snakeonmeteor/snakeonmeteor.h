#ifndef __Snake__
#define __Snake__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../adt/Listdp/Listdp.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../boolean.h"
#include "../../interface.h"


void Move(ListDP *L,char input);

void createSnake(ListDP*L);

void printPoint(POINT P);

addressDP addressMemberPoint(ListDP L,int i,int j);

void printMap(ListDP L,POINT food,POINT meteor, POINT obstacle);

boolean isNotWall(ListDP L,char input);

boolean isBody(ListDP L,char input);

void moveHead(ListDP *L,char input);

boolean isEat(ListDP *L,POINT P);

void addFood(POINT *food,ListDP L, POINT obstacle);

void addMeteor(POINT *meteor,POINT food,POINT obstacle);

void addObstacle(ListDP L,POINT* obstacle);

boolean isAvail(ListDP L,int X,int Y,POINT obstacle);

boolean isBody(ListDP L,char input);

boolean isBodyExceptHead(ListDP L, char input);

void addTail(ListDP *L,boolean *hit,POINT obstacle,POINT meteor) ;//ElmtListDP newtail);

void MeteorHitBody(ListDP *L,POINT food, POINT meteor,POINT obstacle);

void snakeOnMeteor(int * skor);

boolean isMeteorPanas(ListDP L, POINT meteor, char input);

boolean isHeadHitObstacle(ListDP L,POINT obstacle);

boolean isMeteorHitHead(ListDP L);

boolean isBotHeadEmpty(ListDP L,POINT meteor);

boolean isRightHeadEmpty(ListDP L,POINT meteor);

boolean isLefttHeadEmpty(ListDP L,POINT meteor);

boolean isTopHeadEmpty(ListDP L,POINT meteor);

boolean isBotTailEmpty(ListDP L);

boolean isRightTailEmpty(ListDP L);

boolean isLeftTailEmpty(ListDP L);

boolean isTopTailEmpty(ListDP L);

boolean isNoMoreHeadSpace(ListDP L,POINT meteor);

int lengthSnake(ListDP L);

boolean isInputValid(ListDP L,char input);

#endif