/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "../../boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define ROW_CAP 3
#define COL_CAP 3

typedef int Index; /* Index baris, kolom */
typedef char ElType;
typedef struct
{
    ElType contents[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(Matrix *m, int nRow, int nCol);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROWS(M) (M).rowEff
#define COLS(M) (M).colEff
#define MATRIXELMT(M, i, j) (M).contents[(i)][(j)]

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m);
/* Mengirimkan Index baris terbesar m */
Index getLastIdxCol(Matrix m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, Index i, Index j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, Index i);
/* Mengirimkan elemen m(i,i) */

/* ********** Operasi lain ********** */
int count(Matrix m);
/* Mengirimkan banyaknya elemen m */

#endif