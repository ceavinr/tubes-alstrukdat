#ifndef __HANOI_H_
#define __HANOI_H__
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/word/word.h"
#include "../../adt/stack/stack.h"

/* *** Display *** */

/* I.S. S, i, dan maxWidth terdefinisi */
/* F.S. Menampilkan gambar disk ke i dari tower S */
void PrintDisk(Stack S, int i, int maxWidth);
/* I.S. S1, S2, S3, dan height terdefinisi */
/* F.S. Menampilkan state dari ketiga tower */
void DisplayState(Stack S1, Stack S2, Stack S3, int height);

/* Proses: Menjalankan game */
/* I.S. Sembarang */
/* F.S. Tower ke tiga terisi terurut membesar dari TOP */
void towerofhanoi();

#endif