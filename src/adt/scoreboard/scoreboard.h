#ifndef __SCORE_H__
#define __SCOREBOARD_H__
#include "../word/word.h"
#include "../set/set.h"
#include "../map/map.h"

typedef struct {
    Set setGame;
    Map mapGame;
} scoreboard;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. scoreboard suatu game terdefinisi
 */
void CreateScoreboard(scoreboard *game);

/**
 * Konstruktor
 * I.S. setGame, mapGame, playernam, score, terdefinisi sehabis memainkan suatu game
 * F.S. Memasukan ke dalam leaderboard dan melakukan sorting
 */
void InsertScoreboard(scoreboard *game, Word playerName, valuetype score);

/**
 * Konstruktor
 * I.S. setGame dan mapGame terdefinisi
 * F.S. Menampilkan leaderboard sesuai format dalam spesifikasi
 */
void PrintScoreboard(scoreboard game);

/**
 * Konstruktor
 * I.S. setGame dan mapGame terdefinisi
 * F.S. Melakukan sorting pada setGame(berisi playername) sesuai skor yang terdapat dalam map
 */
void SortScoreboard(Set *setGame, Map mapGame);

#endif