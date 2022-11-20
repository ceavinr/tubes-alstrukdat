#include "console.h"

void start(ArrayDin *arrGame, ArrayDin *arrHistory)
{
    load("default.txt", arrGame, arrHistory);
}

void load(string namaFile, ArrayDin *arrGame, ArrayDin *arrHistory)
{
    *arrGame = MakeArrayDin();
    *arrHistory = MakeArrayDin();
    STARTWORD(concat("../data/", namaFile));

    if (!EOP)
    {
        int count = wordToInt(currentWord);
        int i;
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAt(arrGame, currentWord, i);
        }
        ADVWORD();
    }

    if (!EOP)
    {
        int count = wordToInt(currentWord);
        int j;
        for (j = 0; j < count; j++)
        {
            ADVWORD();
            InsertAt(arrHistory, currentWord, j);
        }
    }
}

void save(string namaFile, ArrayDin arrGame, ArrayDin arrHistory)
{
    if (stringLength(namaFile) == 0)
    {
        printf("Nama file tidak boleh kosong!\n");
    }
    else
    {
        FILE *pita;
        pita = fopen(concat("../data/", namaFile), "w");

        fprintf(pita, "%c\n", (char)(arrGame.Neff + 48));

        for (int i = 0; i < arrGame.Neff; i++)
        {
            for (int j = 0; j < arrGame.A[i].Length - 1; j++)
            {
                fprintf(pita, "%c", arrGame.A[i].TabWord[j]);
            }
            if (i < arrGame.Neff - 1)
            {
                fprintf(pita, "%c\n", arrGame.A[i].TabWord[arrGame.A[i].Length - 1]);
            }
            else
            {
                fprintf(pita, "%c", arrGame.A[i].TabWord[arrGame.A[i].Length - 1]);
            }
        }

        // Tadinya buat nampilin history
        /*fprintf(pita, "%c\n", (char)(arrHistory.Neff + 48));

        for (int j = 0; j < arrHistory.Neff - 1; j++)
        {
            fprintf(pita, "%s\n", arrHistory.A[j].TabWord);
        }

        fprintf(pita, "%s", arrHistory.A[arrHistory.Neff - 1].TabWord);
        */
        fclose(pita);
        printf("Save file berhasil disimpan..\n\n");
    }
}

void createGame(ArrayDin *arrGame)
{
    Word newGame;

    printf("Masukkan nama game yang akan ditambahkan: ");
    startInputWord();
    newGame = currentWord;
    if (!IsMember(*arrGame, newGame))
    {    
        InsertLast(arrGame, newGame);
        printf("Game berhasil ditambahkan\n");
    }
    else
    {
        printf("Game sudah tersedia.\n");
    }
    
}

void deleteGame(ArrayDin *arrGame)
{
    printf("Berikut adalah daftar game yang tersedia\n\n");
    PrintArrayDin(*arrGame, (*arrGame).Neff);
    printf("\nMasukan game yang akan dihapus: ");
    startInputWord();

    int numGame = wordToInt(currentWord);

    if (numGame > 5 && numGame <= (*arrGame).Neff)
    {
        DeleteAt(arrGame, numGame - 1);
        printf("\nGame berhasil dihapus\n");
    }
    else
    {
        printf("\nGame gagal dihapus\n");
    }
}

void launchGame(Word game)
{
    printf("\n\nLoading ");
    printWord(game);
    printf(" ...\n\n");
    printf("==============================================\n\n");

    if (stringEQWord(game, "Diner DASH"))
    {
        dinerdash();
    }
    else if (stringEQWord(game, "RNG"))
    {
        rng();
    }
    else if (stringEQWord(game, "Tictactoe"))
    {
        tictactoe();
    }
    else if (stringEQWord(game, "TOWER OF HANOI"))
    {
        towerofhanoi();
    }
    else
    {
        printf("Game ");
        printWord(game);
        printf(" masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n\n");
    }
}

void playGame(Queue *arrQueue, ArrayDin *arrHistory)
{
    if (!isQueueEmpty(*arrQueue))
    {
        /*INISIALISASI GAME PERTAMA YANG SIAP DIMAINKAN*/
        Word firstGame;

        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*arrQueue);

        dequeue(arrQueue, &firstGame);

        launchGame(firstGame);

        InsertAt(arrHistory, firstGame, Length(*arrHistory));
    }
    else
    {
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n\n");
    }
}

void skipGame(Word command, Queue *arrQueue, ArrayDin *arrHistory)
{
    /*AKUISISI JUMLAH SKIP*/
    Word numQueueString;
    akuisisiCommandWord(&numQueueString, command, 3);

    if (numQueueString.Length == 0) { /*jika masukan kosong*/
        printf("Masukan banyak skip tidak valid\n");
    }
    else
    {
        int numQueue = wordToInt(numQueueString);

        if (numQueue >= 0 && numQueue < queueLength(*arrQueue) && !isQueueEmpty(*arrQueue))
        {
            Word firstGame;
            printf("Berikut adalah daftar Game-mu\n");
            displayQueue(*arrQueue);

            /*DELETE BERDASARKAN SKIP SEKALIGUS INISIALISASI GAME PERTAMA YANG SIAP DIMAINKAN*/
            int i;
            for (i = 0; i <= numQueue; i++)
            {
                dequeue(arrQueue, &firstGame);
            }

            launchGame(firstGame);

            InsertAt(arrHistory, firstGame, Length(*arrHistory));
        }
        else if (numQueue >= queueLength(*arrQueue) || isQueueEmpty(*arrQueue))
        {
            *arrQueue = MakeQueue();
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        }
        else /*jika masukan negatif*/
        {
            printf("Masukan banyak skip tidak valid\n");
        }
    }
}

void queueGame(Queue *arrQueue, ArrayDin arrGame)
{
    printf("Berikut adalah daftar antrian game-mu\n");

    displayQueue(*arrQueue);

    printf("\nBerikut adalah daftar game yang tersedia\n");
    PrintArrayDin(arrGame, arrGame.Neff);
    printf("\nNomor Game yang mau ditambahkan ke antrian:  ");
    startInputWord();

    int numGame = wordToInt(currentWord);

    if (numGame <= arrGame.Neff && numGame >= 1)
    {
        Word newQueue = arrGame.A[numGame - 1];
        enqueue(arrQueue, newQueue);
        printf("\nGame berhasil ditambahkan kedalam daftar antrian.\n");
    }
    else
    {
        printf("\nNomor permainan tidak valid, silahkan masukan nomor game pada list.\n");
    }
}

void listGame(ArrayDin arrGame)
{
    printf("Berikut adalah daftar game yang tersedia\n");
    PrintArrayDin(arrGame, arrGame.Neff);
}

void quitProgram(boolean *flag)
{
    printf("\nAnda keluar dari game BNMO.\nBye bye ...\n\n");
    *flag = true;
}

void help()
{
    printf("\n====================================== HALAMAN HELP ====================================\n");
    printf("========================================================================================\n");
    printf("\nGUNAKAN COMMAND BERIKUT UNTUK BERINTERAKSI DENGAN PROGRAM INI\n");
    printf("1. START            : Memulai program\n");
    printf("2. LOAD <nama_file> : Membuka savefile\n");
    printf("3. SAVE <nama_file> : Menyimpan\n");
    printf("4. CREATE GAME      : Menambahkan game\n");
    printf("5. LIST GAME        : Menampilkan daftar game\n");
    printf("6. DELETE GAME      : Menghapus daftar game\n");
    printf("7. QUEUE GAME       : Menambahkan game ke daftar antrian yang akan dimainkan\n");
    printf("8. PLAY GAME        : Memainkan game pada daftar antrian paling atas\n");
    printf("9. SKIP GAME <n>     : Memainkan game dengan mendahului beberapa game di atasnya\n");
    printf("10. QUIT            : Keluar dari program\n");
    printf("11. HELP            : Panduan penggunaan\n");
}

void scoreBoard(scoreboard towerofhanoi, scoreboard dinerdash, scoreboard rng)
{
    printf("**** SCOREBOARD GAME TOWER OF HANOI ****\n");
    PrintScoreboard(towerofhanoi);
    printf("**** SCOREBOARD GAME TOWER OF HANOI ****\n");
    PrintScoreboard(dinerdash);
    printf("**** SCOREBOARD GAME TOWER OF HANOI ****\n");
    PrintScoreboard(rng);
}

void resetScoreBoard(scoreboard towerofhanoi, scoreboard dinerdash, scoreboard rng)
{
    int num_reset;

    printf("\nDAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    printf("1. RNG\n");
    printf("2. Diner Dash\n");
    printf("3. HANGMAN\n");
    printf("4. TOWER OF HANOI\n");
    printf("5. SNAKE ON METEOR\n");

    printf("\nSCOREBOARD YANG INGIN DIHAPUS: ");
    startInputWord();
    num_reset = wordToInt(currentWord);

    if (num_reset >= 0 && num_reset<=5)
    {       
        boolean valid = false;
        while (!valid)
        {
            printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ", num_reset==1?"RNG": num_reset==2?"DINER DASH": num_reset==3?"HANGMAN": num_reset==4?"TOWER OF HANOI": num_reset==5?"SNAKE": "ALL");
            startInputWord();
            if (stringEQWord(currentWord, "YA") || stringEQWord(currentWord, "TIDAK"))
            {
                valid = true;
            } else {
                printf("\nMasukan tidak valid coba lagi.\n");
            }
        }
        

        if (stringEQWord(currentWord, "YA")) 
        {
            switch (num_reset)
            {
            case 0:
                CreateEmptyMap(&(towerofhanoi).mapGame);
                CreateEmptySet(&(towerofhanoi).setGame);

                CreateEmptyMap(&(dinerdash).mapGame);
                CreateEmptySet(&(dinerdash).setGame);

                CreateEmptyMap(&(rng).mapGame);
                CreateEmptySet(&(rng).setGame);
                break;
            case 1:

                CreateEmptyMap(&(rng).mapGame);
                CreateEmptySet(&(rng).setGame);
                break;
            case 2:
                CreateEmptyMap(&(dinerdash).mapGame);
                CreateEmptySet(&(dinerdash).setGame);
                break;
            case 3:
                //hangman
                break;
            case 4:
                CreateEmptyMap(&(towerofhanoi).mapGame);
                CreateEmptySet(&(towerofhanoi).setGame);
                break;
            case 5:
                //snake
                break;
            default:
                break;
            }
            printf("\nScoreboard berhasil di-reset.\n");
        } else
        {
            printf("\nScoreboard tidak jadi di-reset.\n");
        }
    }
    else
    {
        printf("\nScoreboard tidak tersedia.\n");
    }
}

void showHistory(Word command, ArrayDin arrHistory)
{
    Word banyakHistory;
    akuisisiCommandWord(&banyakHistory, command, 2);
    if (banyakHistory.Length > 0)
    {
        int banyakHistory_int = wordToInt(banyakHistory);
        if (banyakHistory_int >= 0)
        {
            printf("Berikut adalah daftar Game yang telah dimainkan\n");
            PrintArrayDin(arrHistory, banyakHistory_int);
        }
        else
        {
            printf("History gagal ditampilkan.\n");
        }
    }
    else
    {
        printf("History gagal ditampilkan.\n");
    }
}

void resetHistory(ArrayDin *arrHistory)
{
    boolean valid = false;
    while (!valid)
    {
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
        startInputWord();
        if (stringEQWord(currentWord, "YA") || stringEQWord(currentWord, "TIDAK"))
        {
            valid = true;
        } else {
            printf("\nMasukan tidak valid coba lagi.\n");
        }
    }

    if (stringEQWord(currentWord, "YA"))
    {
        *arrHistory = MakeArrayDin();
        printf("\nHistory berhasil di-reset.\n");
    } else
    {
        printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        PrintArrayDin(*arrHistory, (*arrHistory).Neff);
    }
    
    
}