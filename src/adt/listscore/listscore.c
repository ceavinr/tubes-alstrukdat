#include <stdio.h>
#include "listscore.h"

void MakeListScore(ListScore *L) {
	(*L).Neff = 0;
}

boolean IsEmptyScoreboard(ListScore L) {
	return L.Neff == 0;
}

int SearchScoreboard(ListScore *L, Word title) {
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
	boolean cek = false;
	IdxType i = 0;
	while (!cek && i <= (*L).Neff-1) {
		if (IsEQWord(title, (*L).A[i].GameTitle)) {
			cek = true;
		} else {
			i += 1;
		}
	}
	if (cek) {
		return i;
	} else {
		return InvalidIdx;
	}
}

void InsertLastScoreboard(ListScore *L, Word title) {
	int idx = (*L).Neff;
	CopyWord(&(*L).A[idx].GameTitle, title);
	(*L).Neff++;
}

void DeleteAtScoreboard(ListScore *L, IdxType i) {
	int j;
	for (j=i; j<(*L).Neff-1; j++) {
       	(*L).A[j] = (*L).A[j+1];
		CopyWord(&(*L).A[j].GameTitle, (*L).A[j+1].GameTitle);
		CopyMap(&(*L).A[j].MapScoreboard, (*L).A[j+1].MapScoreboard);
    }
	(*L).Neff--;
}