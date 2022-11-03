#include "console.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Membaca file default dan menyimpan ke dalam array, history bisa kosong namun terdefinisi
 */
void start(ArrayDin* arrGame, ArrayDin* arrHistory) {
    load("../data/default.txt", arrGame, arrHistory);
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
}

/**
 * Konstruktor
 * I.S. program berjalan
 * F.S. Melakukan Load dari savefile dan menyimpan ke dalam array game dan history
 */
void load(char* savefile, ArrayDin *arrGame, ArrayDin *arrHistory) {
    
    *arrGame = MakeArrayDin();
    *arrHistory = MakeArrayDin();
    STARTWORD(savefile);
    if (!EOP) {
        int count;
        wordToInt(currentWord, &count);
        int i;
        for (i=0; i<count; i++) {
            ADVWORD();
            InsertAt(arrGame, currentWord, i);
        }
        ADVWORD();
    }
    if (!EOP) {
        int count;
        wordToInt(currentWord, &count);
        int j;
        for (j=0; j<count; j++) {
            ADVWORD();
            InsertAt(arrHistory, currentWord, j);
        }
    }
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
}

/**
 * Konstruktor
 * I.S. Array game terdefinisi
 * F.S. Game berdasarkan input pengguna tersimpan ke dalam array game
 */
void newGame(ArrayDin* arrGame) {
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
void deleteGame(ArrayDin* arrGame) {
    printf("Berikut adalah daftar game yang tersedia\n\n");
    PrintArrayDin(*arrGame);
    printf("\nMasukan game yang akan dihapus: ");
    int numGame;
    startInputWord();
    wordToInt(currentWord, &numGame);
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
void playGame(ArrayDin* arrQueue, ArrayDin* arrHistory) {
    if (!IsEmpty(*arrQueue))
    {
        /*INISIALISASI GAME PERTAMA YANG SIAP DIMAINKAN*/
        Word firstGame = (*arrQueue).A[0];

        printf("Berikut adalah daftar Game-mu\n");
        PrintArrayDin(*arrQueue);

        printf("\n\nLoading ");
        PrintWord(firstGame);
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
            PrintWord(firstGame);
            printf(" masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n\n");
        }
        InsertAt(arrHistory, firstGame, Length(*arrHistory));
        DeleteFirst(arrQueue);
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
void skipGame(Word command, ArrayDin* arrQueue, ArrayDin* arrHistory) {
    /*AKUISISI JUMLAH SKIP*/
    Word numQueueString;
    int numQueue;
    akuisisiCommandWord(&numQueueString, command, 2);
    wordToInt(numQueueString, &numQueue);

    if (numQueue < (*arrQueue).Neff && !IsEmpty(*arrQueue)){
        int i;
        for(i=0; i<numQueue; i++){
            DeleteFirst(arrQueue);
        }
        playGame(arrQueue, arrHistory);
    } 
    else
    {
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
}

/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menampilkan seluruh game yang tersedia
 */
void listGame(ArrayDin arrGame) {
    printf("Berikut adalah daftar game yang tersedia\n\n");
    PrintArrayDin(arrGame);
    printf("\n");
}

/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Keluar dari program
 */
void quitProgram(boolean* flag) {
    printf("\nAnda keluar dari game BNMO.\nBye bye ...\n\n");
    *flag = true;
}