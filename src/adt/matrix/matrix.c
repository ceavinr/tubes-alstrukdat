#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void CreateMatrix(Matrix *m, int nRow, int nCol)
{
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

int count(Matrix m)
{
    return (ROWS(m) * COLS(m));
}
