#include "console.h"

int main()
{
    /*INISIALISASI*/
    boolean quit = false;
    ArrayDin arrGame = MakeArrayDin();
    ArrayDin arrHistory = MakeArrayDin();
    ArrayDin arrQueue = MakeArrayDin();

    printf("\n======== SELAMAT DATANG DI BNMO ========\n");
    printf("\n=========== TUBES ALSTRUKDAT ===========\n");

    /*LOOPING PROGRAM*/
    while (!quit)
    {
        Word command;
        Word cek;

        printf("\nENTER COMMAND: ");
        startInputWord();
        command = currentWord;
        akuisisiCommandWord(&cek, command, 1);

        if (stringEQWord(cek, "LOAD") || stringEQWord(cek, "SAVE"))
        {
            /*Akuisisi File Berdasarkan Input*/
            char *file;
            file = akuisisiFile(command);

            if (stringEQWord(cek, "LOAD"))
            {
                load(concat("../data/", file), &arrGame, &arrHistory);
            }
            else if (stringEQWord(cek, "SAVE"))
            {
                /* BELUM ADA */
                printf("Save file berhasil disimpan..\n\n");
            }
        }
        else if (stringEQWord(cek, "SKIPGAME"))
        {
            skipGame(command, &arrQueue, &arrHistory);
        }
        else
        {
            if (stringEQWord(command, "START"))
            {
                start(&arrGame, &arrHistory);
            }
            else if (stringEQWord(command, "QUIT"))
            {
                quitProgram(&quit);
            }
            else if (stringEQWord(command, "CREATE GAME"))
            {
                newGame(&arrGame);
            }
            else if (stringEQWord(command, "QUEUE GAME"))
            {
                /* BELUM ADA */
            }
            else if (stringEQWord(command, "PLAY GAME"))
            {
<<<<<<< HEAD
                playGame(&arrQueue, &arrHistory);
=======
                if (!IsEmpty(arrQueue))
                {
                    printf("Berikut adalah daftar Game-mu\n");
                    PrintArrayDin(arrQueue);
                    printf("\n\n");
                    Word firstGame = arrQueue.A[0];
                    printf("Loading ");
                    printWord(firstGame);
                    printf(" ...\n\n");
                    if (stringEQWord(firstGame, "DINER DASH"))
                    {
                        /*Game dinner dash*/
                    }
                    if (stringEQWord(firstGame, "RNG"))
                    {
                        /*Game RNG*/
                    }
                    else
                    {
                        printf("Game ");
                        printWord(firstGame);
                        printf(" masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n\n");
                    }
                    InsertAt(&arrHistory, firstGame, Length(arrHistory));
                    DeleteFirst(&arrQueue);
                }
                else
                {
                    printf("Antrian game kosong.\nSilakan masukan queue game terlebih dahulu!\n\n");
                }
>>>>>>> 68b30335ac8c814586ae34465e8374450a5e70ee
            }
            else if (stringEQWord(command, "LIST GAME"))
            {
                listGame(arrGame);
            }
            else if (stringEQWord(command, "DELETE GAME"))
            {
                deleteGame(&arrGame);
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
