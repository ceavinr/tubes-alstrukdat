#include <stdio.h>
#include "boolean.h"
#include "./procedure/load/load.h"
#include "./procedure/primitif/primitif.h"
#include "./adt/arraydin/arraydin.h"

int main() {
    boolean quit = false;
    ArrayDin arrGame = MakeArrayDin();
    ArrayDin arrHistory = MakeArrayDin();

    while (!quit) {
        char* command;
        printf("ENTER COMMAND: ");

        gets(command);

        if (stringEQ(command, "START")) {
            load("../data/default.txt", &arrGame, &arrHistory);
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
        } else if (stringEQ(command, "QUIT")) {
            printf("\nAnda keluar dari game BNMO.\nBye bye ...");
            quit = true;
        } else if (stringEQ(command, "LOAD")) { 
            load("../data/savefile.txt", &arrGame, &arrHistory);
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
        } else if (stringEQ(command, "LIST GAME")) {
            printf("Berikut adalah daftar game yang tersedia\n\n");
            PrintArrayDin(arrGame);
        } else if (stringEQ(command, "DELETE GAME")) {
            printf("Berikut adalah daftar game yang tersedia\n\n");
            PrintArrayDin(arrGame);
            printf("Masukan game yang akan dihapus: ");
            int numGame;
            scanf("%d", &numGame);
            if (numGame > 5) {
                DeleteAt(&arrGame, numGame-1);
                printf("\nGame berhasil dihapus\n\n");
            } else {
                printf("\nGame gagal dihapus\n\n");
            }
        } else {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n\n");
        }    
    }

    return 0;
}

