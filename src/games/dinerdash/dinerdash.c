#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dinerdash.h"
#include "../../gambar.h"

void displayOrder(Order o)
{
    Masakan m_del;
    printf("Daftar Pesanan\n");
    printf("Makanan         | Durasi memasak        | Ketahanan     | Harga\n");
    printf("-----------------------------------------------------------------------\n");
    if (!isEmpty(o))
    {
        do
        {
            deleteOrder(&o, &m_del);
            printf("M%d              | %d                     | %d             | %d        \n", NOMOR(m_del), DURASI(m_del), KETAHANAN(m_del), HARGA(m_del));
        } while (!isEmpty(o));
    }
    else
    {
        printf("                |                       |               |            ");
    }
}

void displayCooking(Array arr)
{
    int count = 0;
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan         | Sisa durasi memasak\n");
    printf("-------------------------------------\n");

    for (int i = 0; i <= COUNT(arr) - 1; i++)
    {
        if (DURASI(ARRELMT(arr, i)) > 0)
        {
            printf("M%d              | %d           \n", NOMOR(ARRELMT(arr, i)), DURASI(ARRELMT(arr, i)));
            count++;
        }
    }
    if (count == 0)
    {
        printf("                |              \n");
    }
}

void displayReady(Array arr)
{
    int count = 0;
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan         | Sisa ketahanan makanan\n");
    printf("----------------------------------------\n");

    for (int i = 0; i <= COUNT(arr) - 1; i++)
    {
        if (DURASI(ARRELMT(arr, i)) == 0 && KETAHANAN(ARRELMT(arr, i)) > 0)
        {
            printf("M%d              | %d            \n", NOMOR(ARRELMT(arr, i)), KETAHANAN(ARRELMT(arr, i)));
            count++;
        }
    }

    if (count == 0)
    {
        printf("                |              \n");
    }
}

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
    Order orderList;
    Array orderTaken;
    Masakan m, m_add, m_del;
    Word command, masakan;
    int saldo = 0, served = 0, banyakMasak = 0;
    boolean gameOn = true;

    CreateOrder(&orderList);
    CreateArray(&orderTaken);

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
        displayCooking(orderTaken);
        displayReady(orderTaken);

        // Validasi Input
        while (!inputValid)
        {
            printf("\nMASUKKAN COMMAND: ");
            startInputWord();
            akuisisiCommandWord(&command, currentWord, 1);
            akuisisiCommandWord(&masakan, currentWord, 3);

            if (stringEQWord(command, "SERVE"))
            {
                if (masakan.Length > 0)
                {
                    printf("Hanya bisa menyajikan 1 masakan dalam satu waktu\n");
                }
                else
                {
                    akuisisiCommandWord(&masakan, currentWord, 2);

                    if (masakan.TabWord[0] == 'M' && kodeToInt(masakan) != -1 && masakan.Length > 1)
                    {
                        if (!isIn(orderList, kodeToInt(masakan)))
                        {
                            printf("M%d tidak ada di pesanan\n", kodeToInt(masakan));
                        }
                        else if (!isMember(orderTaken, kodeToInt(masakan)))
                        {
                            printf("M%d belum dimasak\n", kodeToInt(masakan));
                        }
                        else if (DURASI(find(orderTaken, kodeToInt(masakan))) > 0)
                        {
                            printf("M%d belum dapat disajikan karena sedang dimasak\n", kodeToInt(masakan));
                        }
                        else if (NOMOR(HEAD(orderList)) != kodeToInt(masakan))
                        {
                            printf("M%d belum dapat disajikan karena M%d belum selesai\n", kodeToInt(masakan), NOMOR(HEAD(orderList)));
                        }
                        else
                        {
                            DeleteArrayAt(&orderTaken, &m_del, 0);
                            deleteOrder(&orderList, &m_del);
                            printf("\nBerhasil mengantar M%d\n", kodeToInt(masakan));
                            saldo += HARGA(m_del);
                            served++;
                            inputValid = true;
                        }
                    }
                }
            }
            else if (stringEQWord(command, "COOK"))
            {
                if (masakan.Length > 0)
                {
                    printf("Hanya bisa memasak 1 masakan dalam satu waktu\n");
                }
                else if (banyakMasak == 5)
                {
                    printf("Dapur sudah penuh, tidak bisa memasak\n");
                }
                else
                {
                    akuisisiCommandWord(&masakan, currentWord, 2);

                    if (masakan.TabWord[0] == 'M' && kodeToInt(masakan) != -1 && masakan.Length > 1)
                    {
                        if (!isIn(orderList, kodeToInt(masakan)))
                        {
                            printf("M%d tidak ada di pesanan\n", kodeToInt(masakan));
                        }
                        else
                        {
                            m_add = findOrder(orderList, kodeToInt(masakan));
                            DURASI(m_add) += 1;
                            Insert(&orderTaken, m_add);
                            printf("Berhasil memasak M%d\n", kodeToInt(masakan));
                            banyakMasak++;
                            inputValid = true;
                        }
                    }
                }
            }
            else if (stringEQWord(command, "SKIP"))
            {
                akuisisiCommandWord(&masakan, currentWord, 2);
                if (masakan.Length == 0)
                {
                    inputValid = true;
                }
            }
        }

        if (inputValid)
        {
            int i = 0;
            while (i <= COUNT(orderTaken) - 1)
            {
                if (DURASI(ARRELMT(orderTaken, i)) > 0)
                {
                    DURASI(ARRELMT(orderTaken, i)) -= 1;
                    if (DURASI(ARRELMT(orderTaken, i)) == 0)
                    {
                        printf("Makanan M%d telah selesai dimasak\n", NOMOR(ARRELMT(orderTaken, i)));
                        banyakMasak--;
                    }
                    i++;
                }
                else
                {
                    KETAHANAN(ARRELMT(orderTaken, i)) -= 1;
                    if (KETAHANAN(ARRELMT(orderTaken, i)) == 0)
                    {
                        DeleteArrayAt(&orderTaken, &m_del, i);
                    }
                    else
                    {
                        i++;
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
