#include "console.h"
#include "interface.h"

int main()
{
    /*INISIALISASI*/
    Word command, namaFile;
    boolean quit = false, inputValid = false;
    ArrayDin arrGame = MakeArrayDin();
    StackHistory stackHistory;
    CreateStackHistory(&stackHistory);
    Queue arrQueue = MakeQueue();
    /* Scoreboard */
    ListScore scoreboard;
    MakeListScore(&scoreboard);

    while (!inputValid)
    {
        gambarKarakterBNMO();

        printf("\n================================ MAIN MENU ================================\n");
        printf("1. START\n");
        printf("2. LOAD <nama_file>\n");

        printf("\nENTER COMMAND: ");
        startInputWord();
        akuisisiCommandWord(&command, currentWord, 1);
        clear();
        if (stringEQWord(command, "START"))
        {
            start(&arrGame, &stackHistory, &scoreboard);
            if (!IsEmptyArrayDin(arrGame))
            {
                loading();
                printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
                inputValid = true;
            }
            else
            {
                printf("Gagal membaca file.\n");
            }
        }
        else if (stringEQWord(command, "LOAD"))
        {
            akuisisiCommandWord(&namaFile, currentWord, 2);
            if (namaFile.Length > 0)
            {
                load(wordToString(namaFile), &arrGame, &stackHistory, &scoreboard);
                if (!IsEmptyArrayDin(arrGame))
                {
                    loading();
                    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
                    inputValid = true;
                }
                else
                {
                    printf("Gagal membaca file.\n");
                }
            }
            else
            {
                printf("Gagal membaca file.\n");
            }
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }

        printf("\nEnter to continue...");
        startInput();
        clear();
    }

    /*LOOPING PROGRAM*/
    while (!quit)
    {
        Word cek;
        Word cek2;

        printf("\n============================ SELAMAT DATANG DI ============================\n");
        gambarBNMO();
        printf("\n================================ MAIN MENU ================================\n");
        printf("1. SAVE <nama_file>\n");
        printf("2. CREATE GAME\n");
        printf("3. LIST GAME\n");
        printf("4. DELETE GAME\n");
        printf("5. QUEUE GAME\n");
        printf("6. PLAY GAME\n");
        printf("7. SKIP GAME <n>\n");
        printf("8. SCOREBOARD\n");
        printf("9. RESET SCOREBOARD\n");
        printf("10. HISTORY <n>\n");
        printf("11. RESET HISTORY\n");
        printf("12. QUIT\n");
        printf("13. HELP\n");

        printf("\nENTER COMMAND: ");
        startInputWord();
        CopyWord(&command, currentWord);
        akuisisiCommandWord(&cek, command, 1);

        /*Handle "SKIP GAME"*/
        akuisisiCommandWord(&cek2, command, 2);

        clear();

        if (stringEQWord(cek, "SAVE"))
        {
            akuisisiCommandWord(&namaFile, currentWord, 2);
            save(wordToString(namaFile), arrGame, stackHistory, &scoreboard);
        }
        else if (stringEQWord(command, "CREATE GAME"))
        {
            createGame(&arrGame, &scoreboard);
        }
        else if (stringEQWord(command, "LIST GAME"))
        {
            listGame(arrGame);
        }
        else if (stringEQWord(command, "DELETE GAME"))
        {
            deleteGame(&arrGame, &scoreboard);
        }
        else if (stringEQWord(command, "QUEUE GAME"))
        {
            queueGame(&arrQueue, arrGame);
        }
        else if (stringEQWord(command, "PLAY GAME"))
        {
            playGame(&arrQueue, &stackHistory, &scoreboard);
        }
        else if (stringEQWord(cek, "SKIP") && stringEQWord(cek2, "GAME"))
        {
            skipGame(command, &arrQueue, &stackHistory, &scoreboard);
        }
        else if (stringEQWord(command, "QUIT"))
        {
            quitProgram(&quit);
        }
        else if (stringEQWord(command, "HELP"))
        {
            help();
        }
        else if (stringEQWord(command, "SCOREBOARD"))
        {
            showScoreboard(&scoreboard);
        }
        else if (stringEQWord(command, "RESET SCOREBOARD"))
        {
            resetScoreboard(&scoreboard);
        }
        else if (stringEQWord(cek, "HISTORY"))
        {
            showHistory(command, stackHistory);
        }
        else if (stringEQWord(command, "RESET HISTORY"))
        {
            resetHistory(&stackHistory);
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }

        if (!quit)
        {
            printf("\nEnter to back to main menu...");
            startInput();
            clear();
        }
        else
        {
            sleep(500);
            clear();
        }
    }

    return 0;
}