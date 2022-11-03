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
            if (stringEQWord(cek, "LOAD"))
            {
                load(command, &arrGame, &arrHistory);
                printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
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
                queueGame(&arrQueue, arrGame);
            }
            else if (stringEQWord(command, "PLAY GAME"))
            {
                playGame(&arrQueue, &arrHistory);
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
