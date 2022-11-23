#include "console.h"

void start(ArrayDin *arrGame, ArrayDin *arrHistory)
{
    Scoreboard rng;
    Scoreboard hangman;
    Scoreboard dinerdash;
    Scoreboard toh;
    Scoreboard som;
    load("default.txt", arrGame, arrHistory, &rng, &hangman, &dinerdash, &toh, &som);
}

void loadToarray(ArrayDin *arr)
{
    int count, i;
    if (!EOP)
    {
        count = wordToInt(currentWord);
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAt(arr, currentWord, i);
        }
        ADVWORD();
    }
}

void loadToScoreboard(Scoreboard *Scoreboard)
{
    int count, i;
    Word name, score;
    if (!EOP)
    {
        count = wordToInt(currentWord);
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            akuisisiCommandWord(&name, currentWord, 1);
            akuisisiCommandWord(&score, currentWord, 2);
            InsertScoreboard(Scoreboard, name, wordToInt(score));
        }
        ADVWORD();
    }
}

void load(string namaFile, ArrayDin *arrGame, ArrayDin *arrHistory, Scoreboard *rng, Scoreboard *hangman, Scoreboard *dinerdash, Scoreboard *toh, Scoreboard *som)
{
    STARTWORD(concat("../data/", namaFile));

    loadToarray(arrGame);
    loadToarray(arrHistory);
    loadToScoreboard(rng);
    loadToScoreboard(hangman);
    loadToScoreboard(dinerdash);
    loadToScoreboard(toh);
    loadToScoreboard(som);
}

void saveArray(ArrayDin arr, FILE *pita)
{
    int i, j;
    Word count;
    count = intToWord(arr.Neff);
    for (i = 0; i < count.Length; i++)
    {
        fprintf(pita, "%c", count.TabWord[i]);
    }
    if (arr.Neff != 0)
    {
        fprintf(pita, "\n");
    }

    for (i = 0; i < arr.Neff; i++)
    {
        for (j = 0; j < arr.A[i].Length; j++)
        {
            fprintf(pita, "%c", arr.A[i].TabWord[j]);
        }
        if (i < arr.Neff - 1)
        {
            fprintf(pita, "\n");
        }
    }
}

void saveScoreboard(Scoreboard Scoreboard, FILE *pita)
{
    int i, j;
    Word count, val;
    count = intToWord(Scoreboard.setGame.Count);
    for (i = 0; i < count.Length; i++)
    {
        fprintf(pita, "%c", count.TabWord[i]);
    }
    if (Scoreboard.setGame.Count != 0)
    {
        fprintf(pita, "\n");
    }

    for (i = 0; i < Scoreboard.setGame.Count; i++)
    {
        for (j = 0; j < Scoreboard.setGame.Elements[i].Length; j++)
        {
            fprintf(pita, "%c", Scoreboard.setGame.Elements[i].TabWord[j]);
        }
        fprintf(pita, " ");

        val = intToWord(ValueInMap(Scoreboard.mapGame, ToKey(Scoreboard.setGame.Elements[i])));
        for (j = 0; j < val.Length; j++)
        {
            fprintf(pita, "%c", val.TabWord[j]);
        }
        if (i < Scoreboard.setGame.Count - 1)
        {
            fprintf(pita, "\n");
        }
    }
}

void save(string namaFile, ArrayDin arrGame, ArrayDin arrHistory, Scoreboard rng, Scoreboard hangman, Scoreboard dinerdash, Scoreboard toh, Scoreboard som)
{
    if (stringLength(namaFile) == 0)
    {
        printf("Nama file tidak boleh kosong!\n");
    }
    else
    {
        FILE *pita;
        pita = fopen(concat("../data/", namaFile), "w");

        /* Daftar Game dan History*/
        saveArray(arrGame, pita);
        fprintf(pita, "\n");
        saveArray(arrHistory, pita);
        fprintf(pita, "\n");

        /* Scoreboard */
        saveScoreboard(rng, pita);
        fprintf(pita, "\n");
        saveScoreboard(hangman, pita);
        fprintf(pita, "\n");
        saveScoreboard(dinerdash, pita);
        fprintf(pita, "\n");
        saveScoreboard(toh, pita);
        fprintf(pita, "\n");
        saveScoreboard(som, pita);

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

void launchGame(Word game, Scoreboard *srng, Scoreboard *shangman, Scoreboard *sdinerdash, Scoreboard *stoh, Scoreboard *ssom)
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

void playGame(Queue *arrQueue, ArrayDin *arrHistory, Scoreboard *rng, Scoreboard *hangman, Scoreboard *dinerdash, Scoreboard *toh, Scoreboard *som)
{
    if (!isQueueEmpty(*arrQueue))
    {
        /*INISIALISASI GAME PERTAMA YANG SIAP DIMAINKAN*/
        Word firstGame;

        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*arrQueue);

        dequeue(arrQueue, &firstGame);

        launchGame(firstGame, rng, hangman, dinerdash, toh, som);

        InsertAt(arrHistory, firstGame, Length(*arrHistory));
    }
    else
    {
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n\n");
    }
}

void skipGame(Word command, Queue *arrQueue, ArrayDin *arrHistory, Scoreboard *rng, Scoreboard *hangman, Scoreboard *dinerdash, Scoreboard *toh, Scoreboard *som)
{
    /*AKUISISI JUMLAH SKIP*/
    Word numQueueString;
    akuisisiCommandWord(&numQueueString, command, 3);

    if (numQueueString.Length == 0)
    { /*jika masukan kosong*/
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

            launchGame(firstGame, rng, hangman, dinerdash, toh, som);

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
    printf("9. SKIP GAME <n>    : Memainkan game dengan mendahului beberapa game di atasnya\n");
    printf("10. Scoreboard       : Menampilkan Scoreboard masing-masing game\n");
    printf("11. RESET Scoreboard : Melakukan reset Scoreboard pada suatu game yang dipilih\n");
    printf("12. HISTORY <n>      : Menampilkan n history game terbaru yang pernah dimainkan\n");
    printf("13. RESET HISTORY    : Melakukan reset history game yang pernah dimainkan\n");
    printf("14. QUIT            : Keluar dari program\n");
    printf("15. HELP            : Panduan penggunaan\n");
}

void scoreboard(Scoreboard rng, Scoreboard hangman, Scoreboard dinerdash, Scoreboard toh, Scoreboard som)
{
    printf("**** Scoreboard GAME RNG ****\n");
    PrintScoreboard(rng);
    printf("**** Scoreboard GAME HANGMAN ****\n");
    PrintScoreboard(hangman);
    printf("**** Scoreboard GAME DINER DASH ****\n");
    PrintScoreboard(dinerdash);
    printf("**** Scoreboard GAME TOWER OF HANOI ****\n");
    PrintScoreboard(toh);
    printf("**** Scoreboard GAME SNAKE ON METEOR ****\n");
    PrintScoreboard(som);
}

void resetScoreboard(Scoreboard *rng, Scoreboard *hangman, Scoreboard *dinerdash, Scoreboard *toh, Scoreboard *som)
{
    int num_reset;

    printf("\nDAFTAR Scoreboard:\n");
    printf("0. ALL\n");
    printf("1. RNG\n");
    printf("2. Diner Dash\n");
    printf("3. HANGMAN\n");
    printf("4. TOWER OF HANOI\n");
    printf("5. SNAKE ON METEOR\n");

    printf("\nScoreboard YANG INGIN DIHAPUS: ");
    startInputWord();
    num_reset = wordToInt(currentWord);

    if (num_reset >= 0 && num_reset <= 5)
    {
        boolean valid = false;
        while (!valid)
        {
            printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET Scoreboard %s (YA/TIDAK)? ", num_reset == 1 ? "RNG" : num_reset == 2 ? "DINER DASH"
                                                                                                                : num_reset == 3   ? "HANGMAN"
                                                                                                                : num_reset == 4   ? "TOWER OF HANOI"
                                                                                                                : num_reset == 5   ? "SNAKE"
                                                                                                                                   : "ALL");
            startInputWord();
            if (stringEQWord(currentWord, "YA") || stringEQWord(currentWord, "TIDAK"))
            {
                valid = true;
            }
            else
            {
                printf("\nMasukan tidak valid coba lagi.\n");
            }
        }

        if (stringEQWord(currentWord, "YA"))
        {
            switch (num_reset)
            {
            case 0:
                CreateScoreboard(rng);
                CreateScoreboard(dinerdash);
                CreateScoreboard(hangman);
                CreateScoreboard(toh);
                CreateScoreboard(som);
                break;
            case 1:
                CreateScoreboard(rng);
                break;
            case 2:
                CreateScoreboard(dinerdash);
                break;
            case 3:
                CreateScoreboard(hangman);
                break;
            case 4:
                CreateScoreboard(toh);
                break;
            case 5:
                CreateScoreboard(som);
                break;
            default:
                break;
            }
            printf("\nScoreboard berhasil di-reset.\n");
        }
        else
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
        if (banyakHistory_int > 0)
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
        }
        else
        {
            printf("\nMasukan tidak valid coba lagi.\n");
        }
    }

    if (stringEQWord(currentWord, "YA"))
    {
        *arrHistory = MakeArrayDin();
        printf("\nHistory berhasil di-reset.\n");
    }
    else
    {
        printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        PrintArrayDin(*arrHistory, (*arrHistory).Neff);
    }
}