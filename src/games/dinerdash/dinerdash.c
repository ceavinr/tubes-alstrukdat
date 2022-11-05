#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinerdash.h"
#include "../../gambar.h"
#include "../../adt/arraydin/arraydin.h"

int kodeToInt(Word kode)
{
    int num = 0;
    int countNonNumber = 0;
    for (int i = 0; i < kode.Length; i++)
    {
        if (kode.TabWord[i] >= 48 && kode.TabWord[i] <= 57)
        {
            num = num * 10 + kode.TabWord[i] - 48;
        }
        else
        {
            countNonNumber += 1;
        }
    }
    if (countNonNumber > 1)
    {
        return -1;
    }
    else
    {
        return num;
    }
}

void dinerdash()
{
    Order orderList, cooking;
    Masakan m, m_add, m_del;
    Word command, masakan;
    ArrayDin arrMasakan;
    int saldo = 0, served = 0;
    boolean gameOn = true;

    CreateOrder(&orderList);
    CreateOrder(&cooking);

    for (int i = 0; i < 3; i++)
    {
        NOMOR(m) = i;
        DURASI(m) = rand() % 5 + 1;
        KETAHANAN(m) = rand() % 5 + 1;
        HARGA(m) = rand() % 5001 + 10000;

        addOrder(&orderList, m);
    }

    gambarDinerDash();

    printf("Press (y) to start...\n");
    startInputWord();

    if (stringEQWord(currentWord, "y"))
    {
        gameOn = true;
    }
    else
    {
        gameOn = false;
    }

    while (gameOn)
    {
        boolean inputValid = false;

        printf("=========================================================================================\n");
        printf("\nSALDO: %d\n\n", saldo);

        // Display Table
        displayOrder(orderList);
        displayCooking(cooking);
        displayReady(cooking);

        // Validasi Input
        while (!inputValid)
        {
            arrMasakan = MakeArrayDin();

            printf("\nMASUKKAN COMMAND: ");
            startInputWord();
            akuisisiCommandWord(&command, currentWord, 1);

            if (stringEQWord(command, "SERVE"))
            {
                akuisisiCommandWord(&masakan, currentWord, 3);

                if (masakan.Length > 0)
                {
                    printf("Hanya bisa menyajikan 1 masakan dalam satu waktu\n");
                }
                else
                {
                    akuisisiCommandWord(&masakan, currentWord, 2);

                    if (masakan.TabWord[0] == 'M' && kodeToInt(masakan) != -1)
                    {
                        if (!isIn(orderList, kodeToInt(masakan)))
                        {
                            printf("M%d tidak ada di pesanan\n", kodeToInt(masakan));
                        }
                        else if (!isIn(cooking, kodeToInt(masakan)))
                        {
                            printf("M%d belum dimasak\n", kodeToInt(masakan));
                        }
                        else if (DURASI(find(cooking, kodeToInt(masakan))) > 0)
                        {
                            printf("M%d belum dapat disajikan karena sedang dimasak\n", kodeToInt(masakan));
                        }
                        else if (NOMOR(HEAD(orderList)) != kodeToInt(masakan))
                        {
                            printf("M%d belum dapat disajikan karena M%d belum selesai\n", kodeToInt(masakan), NOMOR(HEAD(orderList)));
                        }
                        else
                        {
                            inputValid = true;
                        }
                    }
                }
            }
            else if (stringEQWord(command, "COOK"))
            {
                int noMasak = 2;

                boolean stop = false;
                inputValid = true;

                akuisisiCommandWord(&masakan, currentWord, 7);

                if (masakan.Length > 0)
                {
                    printf("Hanya bisa memasak 5 masakan dalam satu waktu\n");
                    inputValid = false;
                }
                else
                {
                    while (!stop)
                    {
                        akuisisiCommandWord(&masakan, currentWord, noMasak);

                        if (masakan.Length == 0)
                        {
                            stop = true;
                        }
                        else
                        {
                            if (masakan.TabWord[0] == 'M' && kodeToInt(masakan) != -1)
                            {
                                if (isIn(orderList, kodeToInt(masakan)))
                                {
                                    InsertLast(&arrMasakan, masakan);
                                }
                                else
                                {
                                    printf("M%d tidak ada di pesanan\n", kodeToInt(masakan));
                                    inputValid = false;
                                }
                            }
                            else
                            {
                                inputValid = false;
                                stop = true;
                            }
                        }
                        noMasak++;
                    }
                }
            }
        }

        if (stringEQWord(command, "COOK")) // Jika command == "COOK"
        {
            for (int i = 0; i < NEFF(arrMasakan); i++)
            {
                m_add = find(orderList, kodeToInt(BUFFER(arrMasakan)[i]));
                DURASI(m_add) += 1;
                addOrder(&cooking, m_add);
                printf("Berhasil memasak M%d\n", kodeToInt(BUFFER(arrMasakan)[i]));
            }
        }
        else // Jika command == "SERVE"
        {
            deleteOrderAt(&cooking, &m_del, kodeToInt(masakan));
            deleteOrderAt(&orderList, &m_del, kodeToInt(masakan));
            printf("\nBerhasil mengantar M%d\n", kodeToInt(masakan));
            saldo += HARGA(m_del);
            served++;
        }

        if (inputValid)
        {
            for (int i = 0; i <= IDX_TAIL(cooking); i++)
            {
                if (DURASI(ORDERELMT(cooking, i)) > 0)
                {
                    DURASI(ORDERELMT(cooking, i)) -= 1;
                    if (DURASI(ORDERELMT(cooking, i)) == 0)
                    {
                        printf("Makanan M%d telah selesai dimasak\n", NOMOR(ORDERELMT(cooking, i)));
                    }
                }
                else
                {
                    KETAHANAN(ORDERELMT(cooking, i)) -= 1;
                    if (KETAHANAN(ORDERELMT(cooking, i)) == 0)
                    {
                        deleteOrderAt(&cooking, &m_del, NOMOR(ORDERELMT(cooking, i)));
                    }
                }
            }

            CreateMasakan(&m, NOMOR(TAIL(orderList)) + 1);
            addOrder(&orderList, m);
        }

        if (IDX_TAIL(orderList) == 7)
        {
            printf("Kamu kalah karena antrian telah melebihi 7 pelanggan\n");
            printf("Skor: %d\n", saldo);
            gameOn = false;
        }
        else if (served == 15)
        {
            printf("Kamu berhasil menang karena sudah melayani 15 pelanggan\n");
            printf("Skor: %d\n", saldo);
            gameOn = false;
        }
    }
}
