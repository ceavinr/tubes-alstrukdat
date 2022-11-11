/* ********** Definisi TYPE Matrix dengan elemen character ********** */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "../../boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define ROW_CAP 3
#define COL_CAP 3

typedef int Index; /* Index baris, kolom */

typedef struct
{
    char contents[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define ROWS(M) (M).rowEff
#define COLS(M) (M).colEff
#define MATRIXELMT(M, i, j) (M).contents[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Konstruktor membentuk Matrix *** */
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
void CreateMatrix(Matrix *m, int nRow, int nCol);

/* Mengirimkan banyaknya elemen m */
int count(Matrix m);

#endif