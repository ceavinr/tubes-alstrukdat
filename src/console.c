#include "console.h"
#include "./games/dinerdash/dinerdash.h"
#include "./games/rng/rng.h"
#include "./games/tictactoe/tictactoe.h"
#include "./games/towerofhanoi/towerofhanoi.h"

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
    PrintArrayDin(*arrGame);
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
    PrintArrayDin(arrGame);
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
    PrintArrayDin(arrGame);
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

void printLeaderboard(Set setGame, Map mapGame, Word game)
{
    int i, j, skor;
    address key;
    int spacing;

    printf("**** SCOREBOARD GAME ");
    printWord(game);
    printf(" ****\n");

    printf("| NAMA          | SKOR          |\n");
    printf("|-------------------------------|\n");

    for (i=0; i<setGame.Count; i++)
    {
        printf("| ");
        printWord(setGame.Elements[i]);

        spacing = 14 - setGame.Elements[i].Length;
        for (j=0; j<spacing; j++)
        {
            printf(" ");
        }

        key = ToKey(setGame.Elements[i]);
        skor = ValueInMap(mapGame, key);
        printf("| %d", skor);

        spacing = 14;
        while (skor == 0)
        {
            skor = skor/10;
            spacing--;
        }
        for (j=0; j<spacing; j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    printf("\n");
}

