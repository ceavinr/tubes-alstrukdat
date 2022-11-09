/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef DINERDASH_H
#define DINERDASH_H
#include "../../boolean.h"
#include "../../adt/array/array.h"
#include "../../adt/order/order.h"
#include "../../adt/mesinkata/mesinkata.h"
#include "../../adt/word/word.h"

/* *** Display *** */

/* Menampilkan daftar masakan yang terdapat pada antrian pesanan */
void displayOrder(Order o);
/* Menampilkan daftar masakan yang sedang dimasak */
void displayCooking(Order o);
/* Menampilkan daftar masakan yang sudah siap untuk disajikan */
void displayReady(Order o);

/* Konversi kode masakan (M<nomor>) menjadi nomor*/
int kodeToInt(Word kode);

/* Menjalankan game */
/* I.S. Sembarang */
/* F.S. Antrian melebihi 7 (kalah) atau sudah melayani 15 pelanggan (menang) */
void dinerdash();

#endif