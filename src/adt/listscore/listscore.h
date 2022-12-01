/* MODUL LIST MAP untuk Scoreboard */
/* Penempatan elemen selalu rapat kiri */

#ifndef __ADTListScoreboard__
#define __ADTListScoreboard__

#include "../../boolean.h"
#include "../map/map.h"

/* Kamus Umum */
#define MaxElListScore 100
#define InvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int

typedef struct {
    Word GameTitle;
	Map MapScoreboard;  
} ElTypeScore;

typedef struct {
	ElTypeScore A[MaxElListScore];  
	int Neff;
} ListScore;

#define List(i) L.A(i)

/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxElListScore */
void MakeListScore(ListScore *L);

/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
boolean IsEmptyScoreboard(ListScore *L);

/* Prekondisi : X sembarang */
/* Mengirimkan index jika terdapat elemen X di dalam list */
int SearchScoreboard(ListScore *L, Word title);

/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
void InsertLastScoreboard(ListScore *L, Word title);

/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
void DeleteAtScoreboard(ListScore *L, IdxType i);

#endif