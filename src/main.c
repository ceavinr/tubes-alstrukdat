#include <stdio.h>
#include "boolean.h"
#include "./procedure/load/load.h"
#include "./adt/kata/kata.h"
#include "./adt/arraydin/arraydin.h"

void commandInput(Word command)
{
}

int main()
{
    boolean quit = false;
    ArrayDin arrGame = MakeArrayDin();
    ArrayDin arrHistory = MakeArrayDin();
    ArrayDin arrQueue = MakeArrayDin();

    printf("\n======== SELAMAT DATANG DI BNMO ========\n");
    printf("\n=========== TUBES ALSTRUKDAT ===========\n");

    while (!quit)
    {
        printf("\nENTER COMMAND: ");
        Word command;
        startInputWord();
        command = currentWord;

        Word cek;
        akuisisiCommandWord(&cek, command);
        if (stringEQWord(cek, "LOAD") || stringEQWord(cek, "SAVE"))
        {
            char *file;
            file = akuisisiFile(command);
            if (stringEQWord(cek, "LOAD"))
            {
                load(concat("../data/", file), &arrGame, &arrHistory);
                printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
            }
            else if (stringEQWord(cek, "SAVE"))
            {
                /* BELUM ADA */
                printf("Save file berhasil disimpan..\n\n");
            }
        }
        else
        {
            if (stringEQWord(command, "START"))
            {
                load("../data/default.txt", &arrGame, &arrHistory);
                printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
            }
            else if (stringEQWord(command, "QUIT"))
            {
                printf("\nAnda keluar dari game BNMO.\nBye bye ...\n\n");
                quit = true;
            }
            else if (stringEQWord(command, "CREATE GAME"))
            {
                printf("Masukkan nama game yang akan ditambahkan: ");
                Word newGame;
                startInputWord();
                newGame = currentWord;
                InsertLast(&arrGame, newGame);
                printf("Game berhasil ditambahkan\n");
            }
            else if (stringEQWord(command, "QUEUE GAME"))
            {
                /* BELUM ADA */
            }
            else if (stringEQWord(command, "PLAY GAME"))
            {
                if (!IsEmpty(arrQueue)) {
                    printf("Berikut adalah daftar Game-mu\n");
                    PrintArrayDin(arrQueue);
                    printf("\n\n");
                    Word firstGame = arrQueue.A[0];
                    printf("Loading ");
                    PrintWord(firstGame);
                    printf(" ...\n\n");
                    if (stringEQWord(firstGame, "DINER DASH")) {
                        /*Game dinner dash*/
                    } if (stringEQWord(firstGame, "RNG")) {
                        /*Game RNG*/
                    } else {
                        printf("Game ");
                        PrintWord(firstGame);
                        printf(" masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n\n");
                    }
                } else {
                    printf("Antrian game kosong.\nSilakan masukan queue game terlebih dahulu!\n\n");
                }
            }
            else if (stringEQWord(command, "LIST GAME"))
            {
                printf("Berikut adalah daftar game yang tersedia\n\n");
                PrintArrayDin(arrGame);
                printf("\n");
            }
            else if (stringEQWord(command, "DELETE GAME"))
            {
                printf("Berikut adalah daftar game yang tersedia\n\n");
                PrintArrayDin(arrGame);
                printf("\nMasukan game yang akan dihapus: ");
                int numGame;
                scanf("%d", &numGame);
                if (numGame > 5 && arrGame.Neff > 5)
                {
                    DeleteAt(&arrGame, numGame - 1);
                    printf("\nGame berhasil dihapus\n");
                }
                else
                {
                    printf("\nGame gagal dihapus\n");
                }
            }
            else if (stringEQWord(command, "HELP"))
            {
                /* BELUM ADA */
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n\n");
            }
        }
    }

    return 0;
}
