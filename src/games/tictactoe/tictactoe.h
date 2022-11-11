#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/matrix/matrix.h"
#include "../../adt/word/word.h"

/* **** Fungsi untuk mengecek apakah game sudah ada pemenang atau belum **** */

/* Mengembalikan true jika semua elemen pada salah satu diagonal papan berisi mark */
boolean isDiagonalWin(Matrix papan, char mark);
/* Mengembalikan true jika semua elemen pada salah satu vertikal papan berisi mark */
boolean isVerticalWin(Matrix papan, char mark);
/* Mengembalikan true jika semua elemen pada salah satu horizontal papan berisi mark */
boolean isHorizontalWin(Matrix papan, char mark);

/* Mengembalikan true jika seluruh elemen papan berisi X atau O */
boolean isBoardFull(Matrix papan);

/* I.S. papan terdefinisi */
/* F.S. Menampilkan tampilan papan */
void board(Matrix papan);

/* Prosedur untuk menjalankan game Tic Tac Toe*/
/* I.S. Sembarang */
/* F.S. Salah satu user menang atau keduanya seri */
void tictactoe();

#endif
