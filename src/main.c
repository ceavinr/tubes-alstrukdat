#include <stdio.h>
#include "boolean.h"
#include "./procedure/load/load.h"
#include "./procedure/primitif/primitif.h"
#include "./adt/arraydin/arraydin.h"

void commandInput(Word command) {
    
}

int main() {
    boolean quit = false;
    ArrayDin arrGame = MakeArrayDin();
    ArrayDin arrHistory = MakeArrayDin();

    printf("\n======== SELAMAT DATANG DI BNMO ========\n");
    printf("\n=========== TUBES ALSTRUKDAT ===========\n");

    while (!quit) {  
        printf("\nENTER COMMAND: ");
        Word command;
        startInputWord();
        command = currentWord;

        Word cek;
        akuisisiCommandWord(&cek, command);
        if (stringEQWord(cek, "LOAD") || stringEQWord(cek, "SAVE")) {
            char* file;
            file = akuisisiFile(command);
            if (stringEQWord(cek, "LOAD")) {
                load(concat("../data/", file), &arrGame, &arrHistory);
                printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
            } else if (stringEQWord(cek, "LOAD")) {
                /* BELUM ADA */
                printf("Save file berhasil disimpan..\n\n");
            }
        } else {
            if (stringEQWord(command, "START")) {
                load("../data/default.txt", &arrGame, &arrHistory);
                printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
            } else if (stringEQWord(command, "QUIT")) {
                printf("\nAnda keluar dari game BNMO.\nBye bye ...\n\n");
                quit = true;
            } else if (stringEQWord(command, "CREATE GAME")) {
                /* BELUM ADA */
            } else if (stringEQWord(command, "QUEUE GAME")) {
                /* BELUM ADA */
            } else if (stringEQWord(command, "PLAY GAME")) {
                /* BELUM ADA */
            } else if (stringEQWord(command, "LIST GAME")) {
                printf("Berikut adalah daftar game yang tersedia\n\n");
                PrintArrayDin(arrGame);
                printf("\n");
            } else if (stringEQWord(command, "DELETE GAME")) {
                printf("Berikut adalah daftar game yang tersedia\n\n");
                PrintArrayDin(arrGame);
                printf("\nMasukan game yang akan dihapus: ");
                int numGame;
                scanf("%d", &numGame);
                if (numGame > 5 && arrGame.Neff>5) {
                    DeleteAt(&arrGame, numGame-1);
                    printf("\nGame berhasil dihapus\n");
                } else {
                    printf("\nGame gagal dihapus\n");
                }
            } else if (stringEQWord(command, "PLAY GAME")) {
                /* BELUM ADA */
            } else {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n\n");
            }    
        }
        
    }


    return 0;
}

