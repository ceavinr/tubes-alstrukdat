#include "console.h"
#include "gambar.h"

int main()
{
    /*INISIALISASI*/
    Word command, namaFile;
    string namaFileStr;
    boolean quit = false, inputValid = false;
    ArrayDin arrGame = MakeArrayDin();
    ArrayDin arrHistory = MakeArrayDin();
    Queue arrQueue = MakeQueue();

    /* SCOREBOARD */
    scoreboard scoreRNG;
    CreateScoreboard(&scoreRNG);
    
    scoreboard scoreHangman;
    CreateScoreboard(&scoreHangman);

    scoreboard scoreDinerDash;
    CreateScoreboard(&scoreDinerDash);

    scoreboard scoreTowerOfHanoi;
    CreateScoreboard(&scoreTowerOfHanoi);
    
    scoreboard scoreSnakeOnMeteor;
    CreateScoreboard(&scoreSnakeOnMeteor);

    while (!inputValid)
    {
        gambarKarakterBNMO();

        printf("\n================================ MAIN MENU ================================\n");
        printf("1. START\n");
        printf("2. LOAD <nama_file>\n");

        printf("\nENTER COMMAND: ");
        startInputWord();
        akuisisiCommandWord(&command, currentWord, 1);

        if (stringEQWord(command, "START"))
        {
            start(&arrGame, &arrHistory);
            if (!IsEmpty(arrGame))
            {
                printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
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
                load(wordToString(namaFile), &arrGame, &arrHistory, &scoreRNG, &scoreHangman, &scoreDinerDash, &scoreTowerOfHanoi, &scoreSnakeOnMeteor);
                if (!IsEmpty(arrGame))
                {
                    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
                    inputValid = true;
                }
                else
                {
                    printf("Gagal membaca file.\n");
                }
            }
            else
            {
                printf("Gagal membaca file.\n\n");
            }
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n\n");
        }
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

        if (stringEQWord(cek, "SAVE"))
        {
            akuisisiCommandWord(&namaFile, currentWord, 2);
            save(wordToString(namaFile), arrGame, arrHistory, scoreRNG, scoreHangman, scoreDinerDash, scoreTowerOfHanoi, scoreSnakeOnMeteor);
        }
        else if (stringEQWord(command, "CREATE GAME"))
        {
            createGame(&arrGame);
        }
        else if (stringEQWord(command, "LIST GAME"))
        {
            listGame(arrGame);
        }
        else if (stringEQWord(command, "DELETE GAME"))
        {
            deleteGame(&arrGame);
        }
        else if (stringEQWord(command, "QUEUE GAME"))
        {
            queueGame(&arrQueue, arrGame);
        }
        else if (stringEQWord(command, "PLAY GAME"))
        {
            playGame(&arrQueue, &arrHistory);
        }
        else if (stringEQWord(cek, "SKIP") && stringEQWord(cek2, "GAME"))
        {
            skipGame(command, &arrQueue, &arrHistory);
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
            scoreBoard(scoreRNG, scoreHangman, scoreDinerDash, scoreTowerOfHanoi, scoreSnakeOnMeteor);
        }
        else if (stringEQWord(command, "RESET SCOREBOARD"))
        {
            resetScoreBoard(&scoreRNG, &scoreHangman, &scoreDinerDash, &scoreTowerOfHanoi, &scoreSnakeOnMeteor);
        }
        else if (stringEQWord(cek, "HISTORY"))
        {
            showHistory(command, arrHistory);
        }
        else if (stringEQWord(command, "RESET HISTORY"))
        {
            resetHistory(&arrHistory);
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n\n");
        }
    }

    return 0;
}
