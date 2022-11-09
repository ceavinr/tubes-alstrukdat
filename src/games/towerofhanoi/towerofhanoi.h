#ifndef __HANOI_H_
#define __HANOI_H__
#include "../../boolean.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/word/word.h"
#include "../../adt/stack/stack.h"

void PrintDisk(Stack S, int i, int maxWidth);

void PrintTower(Stack S1, Stack S2, Stack S3, int height);

void towerofhanoi();

#endif