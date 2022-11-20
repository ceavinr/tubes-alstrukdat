#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "./adt/string/string.h"
#include "./adt/arraydin/arraydin.h"
#include "./adt/queue/queue.h"
#include "./adt/word/word.h"
#include "./adt/mesin/mesinkata.h"
#include "./adt/mesin/mesinkarakter.h"
#include "./games/dinerdash/dinerdash.h"
#include "./games/rng/rng.h"
#include "./games/tictactoe/tictactoe.h"
#include "./games/towerofhanoi/towerofhanoi.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Membaca file default dan menyimpan ke dalam array, history bisa kosong namun terdefinisi
 */
void start(ArrayDin *arrGame, ArrayDin *arrHistory);

/**
 * Konstruktor
 * I.S. program berjalan
 * F.S. Melakukan Load dari savefile dan menyimpan ke dalam array game dan history
 */
void load(string namaFile, ArrayDin *arrGame, ArrayDin *arrHistory);

/**
 * Konstruktor
 * I.S. program berjalan
 * F.S. menyimpan arraygame dan arrayhistory ke dalam file
 */
void save(string namaFile, ArrayDin arrGame, ArrayDin arrHistory);

/**
 * Konstruktor
 * I.S. Array game terdefinisi
 * F.S. Game berdasarkan input pengguna tersimpan ke dalam array game
 */
void createGame(ArrayDin *arrGame);

/**
 * Konstruktor
 * I.S. Array game terdefinisi
 * F.S. Game yang dipilih terhapus dari program, default game tidak diizinkan dihapus
 */
void deleteGame(ArrayDin *arrGame);

/*
 * Konstruktor
 * I.S. program berjalan
 * F.S. masuk ke dalam game dan menjalankan game yang terdapat dalam queue
 */
void launchGame(Word game);

/**
 * Konstruktor
 * I.S. Program berjalan, array Queue dan array history terdefinisi
 * F.S. Game antrian pertama dimainkan, setelah diamainkan dimasukan ke history
 */
void playGame(Queue *arrQueue, ArrayDin *arrHistory);

/**
 * Konstruktor
 * I.S. Program berjalan, array Queue dan array history terdefinisi
 * F.S. Game dalam antrian diskip sebanyak input pengguna
 */
void skipGame(Word command, Queue *arrQueue, ArrayDin *arrHistory);

/**
 * Konstruktor
 * I.S. Program berjalan, array Queue dan array game terdefinisi
 * F.S. Game masuk ke dalam daftar antrian
 */
void queueGame(Queue *arrQueue, ArrayDin arrGame);

/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menampilkan seluruh game yang tersedia
 */
void listGame(ArrayDin arrGame);

/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Keluar dari program
 */
void quitProgram(boolean *flag);

/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menampilkan bantuan interaksi dengan program
 */
void help();

#endif