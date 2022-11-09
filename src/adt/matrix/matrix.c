#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(Matrix *m, int nRow, int nCol)
{
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* ********** Operasi lain ********** */
int count(Matrix m)
{
    /* Mengirimkan banyaknya elemen m */
    return (ROWS(m) * COLS(m));
}
