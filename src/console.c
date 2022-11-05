#include "console.h"
#include "./games/dinerdash/dinerdash.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Membaca file default dan menyimpan ke dalam array, history bisa kosong namun terdefinisi
 */
void start(ArrayDin *arrGame, ArrayDin *arrHistory)
{
    /*INISIASI FILE DEFAULT*/
    Word default_command = stringToWord("LOAD default.txt");

    load(default_command, arrGame, arrHistory);
}

/**
 * Konstruktor
 * I.S. program berjalan
 * F.S. Melakukan Load dari savefile dan menyimpan ke dalam array game dan history
 */
void load(Word command, ArrayDin *arrGame, ArrayDin *arrHistory)
{
    Word handle;
    akuisisiCommandWord(&handle, command, 2);
    if (handle.Length == 0)
    {
        printf("File tidak tersedia! Pastikan benar!\n");
    }
    else
    {
        /*Akuisisi File Berdasarkan Input*/
        char *file;
        file = akuisisiFile(command);

        *arrGame = MakeArrayDin();
        *arrHistory = MakeArrayDin();
        STARTWORD(concat("../data/", file));

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

        Word cek;
        akuisisiCommandWord(&cek, command, 1);
        if (!IsEmpty(*arrGame))
        {
            if (stringEQWord(cek, "LOAD"))
            {
                printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
            }
            else
            {
                printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
            }
        }
    }
}

/**
 * Konstruktor
 * I.S. program berjalan
 * F.S. menyimpan arraygame dan arrayhistory ke dalam file
 */
void save(Word command, ArrayDin arrGame, ArrayDin arrHistory)
{
    Word handle;
    akuisisiCommandWord(&handle, command, 2);
    if (handle.Length == 0)
    {
        printf("Nama file tidak boleh kosong!\n");
    }
    else
    {
        char *file;
        file = akuisisiFile(command);

        FILE *pita;
        pita = fopen(concat("../data/", file), "w");

        fprintf(pita, "%c\n", (char)(arrGame.Neff + 48));

        for (int i = 0; i < arrGame.Neff; i++)
        {
            fprintf(pita, "%s\n", arrGame.A[i].TabWord);
        }

        fprintf(pita, "%c\n", (char)(arrHistory.Neff + 48));

        for (int j = 0; j < arrHistory.Neff - 1; j++)
        {
            fprintf(pita, "%s\n", arrHistory.A[j].TabWord);
        }

        fprintf(pita, "%s", arrHistory.A[arrHistory.Neff - 1].TabWord);

        fclose(pita);
        printf("Save file berhasil disimpan..\n\n");
    }
}

/**
 * Konstruktor
 * I.S. Array game terdefinisi
 * F.S. Game berdasarkan input pengguna tersimpan ke dalam array game
 */
void newGame(ArrayDin *arrGame)
{
    Word newGame;

    printf("Masukkan nama game yang akan ditambahkan: ");
    startInputWord();
    newGame = currentWord;
    InsertLast(arrGame, newGame);
    printf("Game berhasil ditambahkan\n");
}

/**
 * Konstruktor
 * I.S. Array game terdefinisi
 * F.S. Game yang dipilih terhapus dari program, default game tidak diizinkan dihapus
 */
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

/**
 * Konstruktor
 * I.S. Program berjalan, array Queue dan array history terdefinisi
 * F.S. Game antrian pertama dimainkan, setelah diamainkan dimasukan ke history
 */
void playGame(Queue *arrQueue, ArrayDin *arrHistory)
{
    if (!isQueueEmpty(*arrQueue))
    {
        /*INISIALISASI GAME PERTAMA YANG SIAP DIMAINKAN*/
        Word firstGame;
        dequeue(arrQueue, &firstGame);

        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*arrQueue);

        printf("\n\nLoading ");
        printWord(firstGame);
        printf(" ...\n\n");
        printf("==============================================\n\n");

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
        InsertAt(arrHistory, firstGame, Length(*arrHistory));
    }
    else
    {
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n\n");
    }
}

/**
 * Konstruktor
 * I.S. Program berjalan, array Queue dan array history terdefinisi
 * F.S. Game dalam antrian diskip sebanyak input pengguna
 */
void skipGame(Word command, Queue *arrQueue, ArrayDin *arrHistory)
{
    /*AKUISISI JUMLAH SKIP*/
    Word numQueueString;
    akuisisiCommandWord(&numQueueString, command, 2);

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

        printf("\n\nLoading ");
        printWord(firstGame);
        printf(" ...\n\n");
        printf("==============================================\n\n");

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
        InsertAt(arrHistory, firstGame, Length(*arrHistory));
    }
    else if (numQueue >= queueLength(*arrQueue) || isQueueEmpty(*arrQueue))
    {
        *arrQueue = MakeQueue();
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
    else
    {
        printf("\nNomor permainan tidak valid, silahkan masukan nomor game pada list.\n");
    }
}

/**
 * Konstruktor
 * I.S. Program berjalan, array Queue dan array game terdefinisi
 * F.S. Game masuk ke dalam daftar antrian
 */
void queueGame(Queue *arrQueue, ArrayDin arrGame)
{
    printf("Berikut adalah daftar antrian game-mu\n");
    if (isQueueEmpty(*arrQueue))
    {
        printf("\n=========== Daftar Kosong ===========\n");
    }
    else
    {
        displayQueue(*arrQueue);
    }
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

/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menampilkan seluruh game yang tersedia
 */
void listGame(ArrayDin arrGame)
{
    printf("Berikut adalah daftar game yang tersedia\n\n");
    PrintArrayDin(arrGame);
    printf("\n");
}

/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Keluar dari program
 */
void quitProgram(boolean *flag)
{
    printf("\nAnda keluar dari game BNMO.\nBye bye ...\n\n");
    *flag = true;
}

/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menampilkan bantuan interaksi dengan program
 */
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
    printf("9. SKIPGAME <n>     : Memainkan game dengan mendahului beberapa game di atasnya\n");
    printf("10. QUIT            : Keluar dari program\n");
    printf("11. HELP            : Panduan penggunaan\n");
}