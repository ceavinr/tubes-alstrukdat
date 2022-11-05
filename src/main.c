#include "console.h"
#include "gambar.h"

int main()
{
    /*INISIALISASI*/
    boolean quit = false;
    ArrayDin arrGame = MakeArrayDin();
    ArrayDin arrHistory = MakeArrayDin();
    Queue arrQueue = MakeQueue();

    printf("\n================================== SELAMAT DATANG DI BNMO ===================================\n");
    gambarBNMO();
    help();

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
            }
            else if (stringEQWord(cek, "SAVE"))
            {
                save(command, arrGame, arrHistory);
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
                help();
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n\n");
            }
        }
    }

    return 0;
}
