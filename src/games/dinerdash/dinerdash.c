#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinerdash.h"
#include "../../adt/kata/kata.h"

int kodeToInt(char *kode)
{
    int num = 0;
    int countNumber = 0;
    for (int i = 0; i < 3; i++)
    {
        if (kode[i] >= 48 && kode[i] <= 57)
        {
            countNumber += 1;
            num = num * 10 + kode[i] - 48;
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

int main()
{
    Order orderList, cooking;
    Masakan m, m_add, m_del;

    char command[5];
    char *masakan = malloc(3 * sizeof(char));
    int saldo = 0, served = 0;
    boolean gameOn = true;

    CreateOrder(&orderList);
    CreateOrder(&cooking);

    for (int i = 0; i < 3; i++)
    {
        NOMOR(m) = i;
        DURASI(m) = 0 + 1;
        KETAHANAN(m) = 0 + 1;
        HARGA(m) = rand() % 5001 + 10000;

        addOrder(&orderList, m);
    }

    printf("Selamat Datang di Diner Dash!\n");

    while (gameOn)
    {
        int count = 0;
        boolean inputValid = false;

        printf("\nSALDO: %d\n\n", saldo);

        // Display Table
        displayOrder(orderList);
        displayCooking(cooking);
        displayReady(cooking);

        // Validasi Input
        while (!inputValid)
        {
            printf("\nMASUKKAN COMMAND: ");
            scanf("%s", command);
            scanf("%s", masakan);

            if (isSame(command, "COOK") || isSame(command, "SERVE"))
            {
                if (masakan[0] == 'M' && kodeToInt(masakan) != -1)
                {
                    inputValid = true;
                }
            }
        }

        if (isIn(orderList, kodeToInt(masakan)))
        {
            if (isSame(command, "COOK")) // Jika command == "COOK"
            {
                if (!isIn(cooking, kodeToInt(masakan)))
                {
                    m_add = find(orderList, kodeToInt(masakan));
                    DURASI(m_add) += 1;
                    addOrder(&cooking, m_add);
                    printf("\nBerhasil memasak %s\n", masakan);
                }
                else
                {
                    printf("\nMasakan %s sudah diproses\n", masakan);
                    inputValid = false;
                }
            }

            else // Jika command == "SERVE"
            {
                if (isIn(cooking, kodeToInt(masakan)))
                {
                    if (DURASI(find(cooking, kodeToInt(masakan))) > 0)
                    {
                        printf("%s belum dapat disajikan karena belum selesai dimasak, tunggu %d putaran lagi\n", masakan, DURASI(find(cooking, kodeToInt(masakan))));
                        inputValid = false;
                    }
                    else
                    {
                        if (NOMOR(HEAD(orderList)) == kodeToInt(masakan))
                        {
                            deleteOrderAt(&cooking, &m_del, kodeToInt(masakan));
                            deleteOrderAt(&orderList, &m_del, kodeToInt(masakan));
                            printf("\nBerhasil mengantar %s\n", masakan);
                            saldo += HARGA(m_del);
                            served++;
                        }
                        else
                        {
                            printf("%s belum dapat disajikan karena M%d belum selesai\n", masakan, NOMOR(HEAD(orderList)));
                            inputValid = false;
                        }
                    }
                }
                else
                {
                    printf("%s belum dimasak\n", masakan);
                    inputValid = false;
                }
            }
        }
        else
        {
            printf("Masakan tidak ada di pesanan\n");
            inputValid = false;
        }

        printf("==========================================================\n");

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
            printf("Kalah");
            gameOn = false;
        }
        else if (served == 15)
        {
            printf("Menang");
            gameOn = false;
        }
    }
    return 0;
}
