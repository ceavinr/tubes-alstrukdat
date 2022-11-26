#include "console.h"

void start(ArrayDin *arrGame, StackHistory *stackHistory, ListScore *scoreboard)
{
    load("../data/default.txt", arrGame, stackHistory, scoreboard);
}

void loadToArray(ArrayDin *arr, ListScore *scoreboard)
{
    int count, i;
    if (!EOP)
    {
        count = wordToInt(currentWord);
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            InsertAtArrayDin(arr, currentWord, i);
        }
        ADVWORD();
    }
}

void loadToStack(StackHistory *S, ListScore *scoreboard)
{
    int count, i;
    if (!EOP)
    {
        count = wordToInt(currentWord);
        for (i = 0; i < count; i++)
        {
            ADVWORD();
            PushHistory(S, currentWord);
        }
        ADVWORD();
    }

    // INVERSE
    InverseStackHistory(S);
}

void loadToScoreboard(Map *game)
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
            InsertInMap(game, name, wordToInt(score));
        }
        ADVWORD();
    }
}

void load(string namaFile, ArrayDin *arrGame, StackHistory *stackHistory, ListScore *scoreboard)
{
    int i;

    STARTWORD(concat("../data/", namaFile));

    loadToArray(arrGame, scoreboard);
    for (i = 0; i < (*arrGame).Neff; i++)
    {
        InsertLastScoreboard(scoreboard, (*arrGame).A[i]);
    }

    loadToStack(stackHistory, scoreboard);

    for (i = 0; i < (*scoreboard).Neff; i++)
    {
        loadToScoreboard(&(*scoreboard).A[i].MapScoreboard);
    }
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

void saveStack(StackHistory S, FILE *pita)
{
    int i, j, neff;
    Word count, val;
    neff = Top(S) + 1;
    count = intToWord(neff);
    for (i = 0; i < count.Length; i++)
    {
        fprintf(pita, "%c", count.TabWord[i]);
    }
    if (neff != 0)
    {
        fprintf(pita, "\n");
    }

    for (i = 0; i < neff; i++)
    {
        PopHistory(&S, &val);
        for (j = 0; j < val.Length; j++)
        {
            fprintf(pita, "%c", val.TabWord[j]);
        }
        if (i < neff - 1)
        {
            fprintf(pita, "\n");
        }
    }
}

void saveScoreboard(Map game, FILE *pita)
{
    int i, j;
    Word count, val;
    count = intToWord(game.Count);
    for (i = 0; i < count.Length; i++)
    {
        fprintf(pita, "%c", count.TabWord[i]);
    }
    if (game.Count != 0)
    {
        fprintf(pita, "\n");
    }

    for (i = 0; i < game.Count; i++)
    {
        for (j = 0; j < game.Elements[i].Key.Length; j++)
        {
            fprintf(pita, "%c", game.Elements[i].Key.TabWord[j]);
        }
        fprintf(pita, " ");

        val = intToWord(game.Elements[i].Value);
        for (j = 0; j < val.Length; j++)
        {
            fprintf(pita, "%c", val.TabWord[j]);
        }
        if (i < game.Count - 1)
        {
            fprintf(pita, "\n");
        }
    }
}

void save(string namaFile, ArrayDin arrGame, StackHistory stackHistory, ListScore *scoreboard)
{
    int i;
    if (stringLength(namaFile) == 0)
    {
        printf("Nama file tidak boleh kosong!\n");
    }
    else
    {
        FILE *pita;
        pita = fopen(concat("data/", namaFile), "w");

        /* Daftar Game dan History*/
        saveArray(arrGame, pita);
        fprintf(pita, "\n");
        saveStack(stackHistory, pita);
        fprintf(pita, "\n");

        /* Scoreboard */
        for (i = 0; i < (*scoreboard).Neff; i++)
        {
            saveScoreboard((*scoreboard).A[i].MapScoreboard, pita);
            if (i < (*scoreboard).Neff - 1)
            {
                fprintf(pita, "\n");
            }
        }

        fclose(pita);
        printf("Save file berhasil disimpan..\n");
    }
}

void createGame(ArrayDin *arrGame, ListScore *scoreboard)
{
    Word newGame;

    printf("Masukkan nama game yang akan ditambahkan: ");
    startInputWord();
    newGame = currentWord;
    if (!IsMemberArrayDin(*arrGame, newGame))
    {
        InsertLastArrayDin(arrGame, newGame);
        InsertLastScoreboard(scoreboard, newGame);
        printf("Game berhasil ditambahkan\n");
    }
    else
    {
        printf("Game sudah tersedia.\n");
    }
}

void deleteGame(ArrayDin *arrGame, ListScore *scoreboard)
{
    printf("Berikut adalah daftar game yang tersedia\n\n");
    PrintArrayDin(*arrGame, (*arrGame).Neff);
    printf("\nMasukan game yang akan dihapus: ");
    startInputWord();

    int numGame = wordToInt(currentWord);

    if (numGame > 5 && numGame <= (*arrGame).Neff)
    {
        DeleteAtArrayDin(arrGame, numGame - 1);
        DeleteAtScoreboard(scoreboard, numGame - 1);
        printf("\nGame berhasil dihapus\n");
    }
    else
    {
        printf("\nGame gagal dihapus\n");
    }
}

void launchGame(Word game, ListScore *scoreboard, StackHistory *stackHistory)
{
    int score, index;
    boolean cek;

    loadingGame(game);

    if (stringEQWord(game, "RNG"))
    {
        rng(&score);
    }
    else if (stringEQWord(game, "Diner DASH"))
    {
        dinerdash(&score);
    }
    else if (stringEQWord(game, "HANGMAN"))
    {
        // HANGMAN
    }
    else if (stringEQWord(game, "TOWER OF HANOI"))
    {
        towerofhanoi(&score);
    }
    else if (stringEQWord(game, "SNAKE ON METEOR"))
    {
        snakeOnMeteor(&score);
    }
    else if (stringEQWord(game, "TICTACTOE"))
    {
        tictactoe(&score);
    }
    else if (stringEQWord(game, "AMOGUS FIGHT"))
    {
        amogusfight(&score);
    }
    else
    {
        printf("============= Game Over =============\n");
        score = rand() % 101;
        printf("Skor akhir: %d\n", score);
    }
    PushHistory(stackHistory, game);

    index = SearchScoreboard(scoreboard, game);
    while (!cek)
    {
        printf("Masukan Nama: ");
        startInputWord();
        if (!IsMemberInMap((*scoreboard).A[index].MapScoreboard, currentWord))
        {
            InsertInMap(&(*scoreboard).A[index].MapScoreboard, currentWord, score);
            cek = true;
        }
        else
        {
            printf("\nNama pemain pada game ");
            printWord(game);
            printf(" sudah tersedia.\n");
        }
    }
}

void playGame(Queue *arrQueue, StackHistory *stackHistory, ListScore *scoreboard)
{
    if (!isQueueEmpty(*arrQueue))
    {
        /*INISIALISASI GAME PERTAMA YANG SIAP DIMAINKAN*/
        Word firstGame;

        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*arrQueue);

        dequeue(arrQueue, &firstGame);

        launchGame(firstGame, scoreboard, stackHistory);
    }
    else
    {
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
}

void skipGame(Word command, Queue *arrQueue, StackHistory *stackHistory, ListScore *scoreboard)
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

            launchGame(firstGame, scoreboard, stackHistory);
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
    printf("\nNomor Game yang mau ditambahkan ke antrian: ");
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

void showScoreboard(ListScore *scoreboard)
{
    int i;
    for (i = 0; i < (*scoreboard).Neff; i++)
    {
        printf("**** SCOREBOARD GAME ");
        printWord((*scoreboard).A[i].GameTitle);
        printf(" ****\n");
        PrintMap((*scoreboard).A[i].MapScoreboard);
    }
}

void resetScoreboard(ListScore *scoreboard)
{
    int num_reset, i;

    printf("\nDAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    for (i = 0; i < (*scoreboard).Neff; i++)
    {
        printf("%d. ", i + 1);
        printWord((*scoreboard).A[i].GameTitle);
        printf("\n");
    }

    printf("\nSCOREBOARD YANG INGIN DIHAPUS: ");
    startInputWord();
    num_reset = wordToInt(currentWord);

    if (num_reset >= 0 && num_reset <= 5)
    {
        boolean valid = false;
        while (!valid)
        {
            printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
            if (num_reset == 0)
            {
                printf("ALL");
            }
            else
            {
                printWord((*scoreboard).A[num_reset - 1].GameTitle);
            }

            printf(" (YA/TIDAK)? ");
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
            if (num_reset == 0)
            {
                for (i = 0; i < (*scoreboard).Neff; i++)
                {
                    CreateEmptyMap(&(*scoreboard).A[i].MapScoreboard);
                }
            }
            else
            {
                CreateEmptyMap(&(*scoreboard).A[num_reset - 1].MapScoreboard);
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

void showHistory(Word command, StackHistory stackHistory)
{
    Word banyakHistory;
    akuisisiCommandWord(&banyakHistory, command, 2);
    if (banyakHistory.Length > 0)
    {
        int banyakHistory_int = wordToInt(banyakHistory);
        if (banyakHistory_int > 0)
        {
            printf("Berikut adalah daftar Game yang telah dimainkan\n");
            PrintStackHistory(stackHistory, banyakHistory_int);
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

void resetHistory(StackHistory *stackHistory)
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
        CreateStackHistory(stackHistory);
        printf("\nHistory berhasil di-reset.\n");
    }
    else
    {
        printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        PrintStackHistory(*stackHistory, Top(*stackHistory) + 1);
    }
}