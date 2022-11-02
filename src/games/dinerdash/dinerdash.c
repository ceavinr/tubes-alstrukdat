#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinerdash.h"
#include "../../adt/kata/kata.h"

int kodeToInt(char *kode)
{
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        if (kode[i] >= 48 && kode[i] <= 57)
        {
            num = num * 10 + kode[i] - 48;
        }
    }
    return num;
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
        DURASI(m) = rand() % 5 + 1;
        KETAHANAN(m) = rand() % 5 + 1;
        HARGA(m) = rand() % 5001 + 10000;

        addOrder(&orderList, m);
    }

    printf("Selamat Datang di Diner Dash!\n");

    while (gameOn)
    {
        int count = 0;
        boolean inputValid = false;

        printf("\nSALDO: %d\n\n", saldo);
        displayOrder(orderList);
        displayCooking(cooking);
        displayReady(cooking);

        while (!inputValid)
        {
            printf("\nMASUKKAN COMMAND: ");
            scanf("%s", command);

            if (isSame(command, "COOK") || isSame(command, "SERVE"))
            {
                scanf("%s", masakan);
                if (masakan[0] == 'M')
                {
                    inputValid = true;
                }
            }
        }

        if (isSame(command, "COOK"))
        {
            if (isIn(orderList, kodeToInt(masakan)))
            {
                if (!isIn(cooking, kodeToInt(masakan)))
                {
                    m_add = ELMT(orderList, find(orderList, kodeToInt(masakan)));
                    DURASI(m_add) += 1;
                    addOrder(&cooking, m_add);
                    printf("\nBerhasil memasak %s\n", masakan);
                }
                else
                {
                    printf("\nMasakan %s sudah diproses\n", masakan);
                }
            }
            else
            {
                printf("Masakan tidak ada di pesanan");
            }
        }
        else
        {
            if (isIn(cooking, kodeToInt(masakan)))
            {
                if (DURASI(ELMT(cooking, find(cooking, kodeToInt(masakan)))) > 0)
                {
                    printf("%s belum dapat disajikan karena belum selesai dimasak, tinggal %d\n", masakan, DURASI(ELMT(cooking, find(cooking, kodeToInt(masakan)))));
                }
                else
                {
                    if (NOMOR(HEAD(orderList)) == kodeToInt(masakan))
                    {
                        deleteOrder(&cooking, &m_del);
                        deleteOrder(&orderList, &m_del);
                        printf("\nBerhasil mengantar %s\n", masakan);
                        saldo += HARGA(m_del);
                        served++;
                    }
                    else
                    {
                        printf("%s belum dapat disajikan karena M%d belum selesai\n", masakan, NOMOR(HEAD(orderList)));
                    }
                }
            }
        }
        printf("==========================================================\n");

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
                // if (KETAHANAN(ELMT(cooking, i)) == 0)
                // {
                // }
            }
        }

        CreateMasakan(&m, NOMOR(TAIL(orderList)) + 1);
        addOrder(&orderList, m);

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