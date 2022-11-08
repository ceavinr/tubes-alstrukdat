#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "../../boolean.h"
#include "../../adt/array/array.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/word/word.h"

/*Fungsi untuk mengecek apakah game sudah ada pemenang atau belum*/
int isWin(Array papan);

/*Prosedur untuk melakukan print tampilan papan kepada user*/
void board(Array papan);

/*Prosedur untuk menjalankan game Tic Tac Toe*/
void tictactoe();

#endif

