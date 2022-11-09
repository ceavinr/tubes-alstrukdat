#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "../../boolean.h"
#include "../../adt/array/array.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/matrix/matrix.h"
#include "../../adt/word/word.h"

/*Fungsi untuk mengecek apakah game sudah ada pemenang atau belum*/
boolean isDiagonalWin(Matrix papan, char mark);
boolean isVerticalWin(Matrix papan, char mark);
boolean isHorizontalWin(Matrix papan, char mark);
boolean isWin(Matrix papan, char mark);
boolean isBoardFull(Matrix papan);

/*Prosedur untuk melakukan print tampilan papan kepada user*/
void board(Matrix papan);

/*Prosedur untuk menjalankan game Tic Tac Toe*/
void tictactoe();

#endif
