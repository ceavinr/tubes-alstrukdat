#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinerdash.h"
#include "../../gambar.h"

int kodeToInt(Word kode)
{
    int num = 0;
    int countNumber = 0;
    for (int i = 0; i < 3; i++)
    {
        if (kode.TabWord[i] >= 48 && kode.TabWord[i] <= 57)
        {
            countNumber += 1;
            num = num * 10 + kode.TabWord[i] - 48;
        }
    }
    if (countNumber == 0)
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

    // char command[5];
    // char *masakan = malloc(3 * sizeof(char));
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
        int count = 0;
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
            printf("\nMASUKKAN COMMAND: ");
            startInputWord();
            akuisisiCommandWord(&command, currentWord, 1);
            akuisisiCommandWord(&masakan, currentWord, 2);

            if (stringEQWord(command, "COOK") || stringEQWord(command, "SERVE"))
            {
                if (masakan.TabWord[0] == 'M' && kodeToInt(masakan) != -1)
                {
                    inputValid = true;
                }
            }
        }

        if (isIn(orderList, kodeToInt(masakan)))
        {
            if (stringEQWord(command, "COOK")) // Jika command == "COOK"
            {
                m_add = find(orderList, kodeToInt(masakan));
                DURASI(m_add) += 1;
                addOrder(&cooking, m_add);
                printf("\nBerhasil memasak M%d\n", kodeToInt(masakan));
            }

            else // Jika command == "SERVE"
            {
                if (isIn(cooking, kodeToInt(masakan)))
                {
                    if (DURASI(find(cooking, kodeToInt(masakan))) > 0)
                    {
                        printf("M%d belum dapat disajikan karena belum selesai dimasak, tunggu %d putaran lagi\n", kodeToInt(masakan), DURASI(find(cooking, kodeToInt(masakan))));
                        inputValid = false;
                    }
                    else
                    {
                        if (NOMOR(HEAD(orderList)) == kodeToInt(masakan))
                        {
                            deleteOrderAt(&cooking, &m_del, kodeToInt(masakan));
                            deleteOrderAt(&orderList, &m_del, kodeToInt(masakan));
                            printf("\nBerhasil mengantar M%d\n", kodeToInt(masakan));
                            saldo += HARGA(m_del);
                            served++;
                        }
                        else
                        {
                            printf("M%d belum dapat disajikan karena M%d belum selesai\n", kodeToInt(masakan), NOMOR(HEAD(orderList)));
                            inputValid = false;
                        }
                    }
                }
                else
                {
                    printf("M%d belum dimasak\n", kodeToInt(masakan));
                    inputValid = false;
                }
            }
        }
        else
        {
            printf("M%d tidak ada di pesanan\n", kodeToInt(masakan));
            inputValid = false;
        }

        if (inputValid)
        {
            for (int i = 0; i <= IDX_TAIL(cooking); i++)
            {
                if (DURASI(ELMT(cooking, i)) > 0)
                {
                    DURASI(ELMT(cooking, i)) -= 1;
                    if (DURASI(ELMT(cooking, i)) == 0)
                    {
                        printf("Makanan M%d telah selesai dimasak\n", NOMOR(ELMT(cooking, i)));
                    }
                }
                else
                {
                    KETAHANAN(ELMT(cooking, i)) -= 1;
                    if (KETAHANAN(ELMT(cooking, i)) == 0)
                    {
                        deleteOrderAt(&cooking, &m_del, i);
                    }
                }
            }

            CreateMasakan(&m, NOMOR(TAIL(orderList)) + 1);
            addOrder(&orderList, m);
        }

        if (IDX_TAIL(orderList) == 7)
        {
            printf("Kamu kalah karena antrian telah melebihi 7 pelanggan\n");
            gameOn = false;
        }
        else if (served == 15)
        {
            printf("Kamu berhasil menang karena sudah melayani 15 pelanggan\n");
            gameOn = false;
        }
    }
}
