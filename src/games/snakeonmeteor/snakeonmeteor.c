#include "snakeonmeteor.h"

void Move(ListDP *L, char input)
{
    addressDP P = Last(*L);
    if (!isBodyExceptHead(*L, input))
    {
        while (Prev(P) != NULL)
        {
            (P)->Pos.X = Prev(P)->Pos.X;
            (P)->Pos.Y = Prev(P)->Pos.Y;
            P = Prev(P);
        }
        moveHead(L, input);
    }
}

void createSnake(ListDP *L)
{
    CreateEmptyDP(L);
    addressDP P1 = AlokasiDP(72);
    InsertLastDP(L, P1);
    srand(time(NULL));
    boolean temp = false;
    // (*P1).Pos.X = rand() % 5;
    // (*P1).Pos.Y = rand() % 5;
    P1->Pos.X = rand() % 5;
    P1->Pos.Y = rand() % 5;
    POINT obstacle = MakePOINT(-999, -999);
    addTail(L, &temp, obstacle);
    addTail(L, &temp, obstacle);
    // if (P1->Pos.X == 0)
    // {
    //     if (P1->Pos.Y == 0)
    //     {
    //         P2->Pos.X = P1->Pos.X;
    //         P3->Pos.X = P1->Pos.X;
    //         P2->Pos.Y = P1->Pos.Y + 1;
    //         P3->Pos.Y = P1->Pos.Y + 2;
    //     }
    //     else
    //     {
    //         P2->Pos.X = P1->Pos.X;
    //         P3->Pos.X = P1->Pos.X;
    //         if (P1->Pos.Y == 1)
    //         {
    //             P2->Pos.Y = P1->Pos.Y + 1;
    //             P3->Pos.Y = P1->Pos.Y + 2;
    //         }
    //         else
    //         {
    //             P2->Pos.Y = P1->Pos.Y - 1;
    //             P3->Pos.Y = P1->Pos.Y - 2;
    //         }
    //     }
    // }
    // else
    // {
    //     if (P1->Pos.Y == 0)
    //     {
    //         if (P1->Pos.X == 1)
    //         {
    //             P2->Pos.X = P1->Pos.X - 1;
    //             P3->Pos.X = P1->Pos.X - 1;
    //             P2->Pos.Y = P1->Pos.Y;
    //             P3->Pos.Y = P1->Pos.Y + 1;
    //         }
    //         else
    //         {
    //             P2->Pos.X = P1->Pos.X - 1;
    //             P3->Pos.X = P1->Pos.X - 2;
    //             P2->Pos.Y = P1->Pos.Y;
    //             P3->Pos.Y = P1->Pos.Y;
    //         }
    //     }
    //     else
    //     {
    //         P2->Pos.X = P1->Pos.X - 1;
    //         P2->Pos.Y = P1->Pos.Y;
    //         if (P2->Pos.X == 0)
    //         {
    //             P3->Pos.X = P2->Pos.X;
    //             P3->Pos.Y = P2->Pos.Y - 1;
    //         }
    //         else
    //         {
    //             P3->Pos.X = P2->Pos.X - 1;
    //             P3->Pos.Y = P2->Pos.Y;
    //         }
    //     }
    // }
    // InsertLastDP(L, P1);
    // InsertLastDP(L, P2);
    // InsertLastDP(L, P3);
}

void printMap(ListDP L, POINT food, POINT meteor, POINT obstacle)
{

    int i;
    int j;
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {

            if (i % 2 == 0 && j % 2 == 0)
            {
                printf("+");
            }
            else if (i % 2 == 0)
            {
                printf("---");
            }
            else if (j % 2 == 0)
            {
                printf("|");
            }
            else if (meteor.X == ((j + 1) / 2) - 1 && meteor.Y == ((i + 1) / 2) - 1)
            {
                printf(" M ");
            }
            else if (obstacle.X == ((j + 1) / 2) - 1 && obstacle.Y == ((i + 1) / 2) - 1)
            {
                printf(" # ");
            }
            else if (addressMemberPoint(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1))
            {
                if (Info(addressMemberPoint(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)) == 72)
                {
                    printf(" %c ", (char)Info(addressMemberPoint(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)));
                }
                else
                {
                    if (Info(addressMemberPoint(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)) <= 9)
                    {
                        printf(" %d ", Info(addressMemberPoint(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)));
                    }
                    else
                    {
                        printf("%d ", Info(addressMemberPoint(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)));
                    }
                }
            }
            else if (food.X == ((j + 1) / 2) - 1 && food.Y == ((i + 1) / 2) - 1)
            {
                printf(" O ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}

addressDP addressMemberPoint(ListDP L, int i, int j)
{
    addressDP P = First(L);
    boolean found = false;
    while (!found && (P) != NULL)
    {
        if ((*P).Pos.X == i && (*P).Pos.Y == j)
        {
            found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    if (found)
    {
        return P;
    }
    else
    {
        return NULL;
    }
}

void moveHead(ListDP *L, char input)
{
    addressDP P = First(*L);
    // if (!isBody(*L,input)){
    if (input == 'a')
    {
        if ((*P).Pos.X == 0)
        {
            (*P).Pos.X = 4;
        }
        else
        {
            (*P).Pos.X -= 1;
        }
    }
    else if (input == 'd')
    {
        if ((*P).Pos.X == 4)
        {
            (*P).Pos.X = 0;
        }
        else
        {
            (*P).Pos.X += 1;
        }
    }
    else if (input == 'w')
    {
        if ((*P).Pos.Y == 0)
        {
            (*P).Pos.Y = 4;
        }
        else
        {
            (*P).Pos.Y -= 1;
        }
    }
    else if (input == 's')
    {
        if ((*P).Pos.Y == 4)
        {
            (*P).Pos.Y = 0;
        }
        else
        {
            (*P).Pos.Y += 1;
        }
    }
}
//}

void addMeteor(POINT *meteor, POINT food, POINT obstacle)
{
    srand(time(NULL));
    int X = rand() % 5;
    int Y = rand() % 5;
    boolean found = false;
    int i = 0;
    while (!found)
    {
        if (X != food.X && Y != food.Y && X != obstacle.X && Y != obstacle.Y)
        {
            found = true;
            meteor->X = X;
            meteor->Y = Y;
        }
        else
        {
            if (i % 3 == 0)
            {
                X = (X + 1) % 5;
                Y = (Y - 1) % 5;
            }
            else if (i % 3 == 1)
            {
                Y = (Y + 1) % 5;
                X = (X - 1) % 5;
            }
            else
            {
                X = (X + 1) % 5;
                Y = (Y + 1) % 5;
            }
        }
        if (X < 0 || Y < 0)
        {
            X = rand() % 5;
            Y = rand() % 5;
        }
        i++;
    }
}

boolean isEat(ListDP *L, POINT P)
{
    boolean found = EQ(First(*L)->Pos, P);
    return found;
}

boolean isAvail(ListDP L, int X, int Y, POINT obstacle)
{
    addressDP Q = First(L);
    boolean found = true;
    if (X == -1)
    {
        X = 4;
    }
    else if (X == 5)
    {
        X = 0;
    }
    if (Y == -1)
    {
        Y = 4;
    }
    else if (Y == 5)
    {
        Y = 0;
    }
    while (found && Q != NULL)
    {
        if (((*Q).Pos.X == (X % 5) && (*Q).Pos.Y == (Y % 5)) || (obstacle.X == (X % 5) && obstacle.Y == (Y % 5)))
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isBody(ListDP L, char input)
{
    addressDP P = First(L);
    addressDP Q = Next(P);
    // ini salah cook
    int X = P->Pos.X;
    int Y = P->Pos.Y;
    if (input == 'w')
    {
        Y--;
        if (Y == -1)
        {
            Y = 4;
        }
    }
    else if (input == 's')
    {
        Y++;
        if (Y == 5)
        {
            Y = 0;
        }
    }
    else if (input == 'a')
    {
        X--;
        if (X == -1)
        {
            X = 4;
        }
    }
    else if (input == 'd')
    {
        X++;
        if (X == 5)
        {
            X = 0;
        }
    }
    boolean found = false;
    while (!found && Q != NULL)
    {
        if (X == Q->Pos.X && Y == Q->Pos.Y)
        {
            found = true;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isBodyExceptHead(ListDP L, char input)
{
    addressDP P = First(L);
    addressDP Q = Next(P);
    int X = P->Pos.X;
    int Y = P->Pos.Y;
    if (input == 'w')
    {
        Y--;
        if (Y == -1)
        {
            Y = 4;
        }
    }
    else if (input == 's')
    {
        Y++;
        if (Y == 5)
        {
            Y = 0;
        }
    }
    else if (input == 'a')
    {
        X--;
        if (X == -1)
        {
            X = 4;
        }
    }
    else if (input == 'd')
    {
        X++;
        if (X == 5)
        {
            X = 0;
        }
    }
    boolean found = false;
    while (!found && Next(Q) != NULL)
    {
        if (X == Q->Pos.X && Y == Q->Pos.Y)
        {
            found = true;
        }
        Q = Next(Q);
    }
    return found;
}

void addTail(ListDP *L, boolean *hit, POINT obstacle)
{
    addressDP P;
    if (Info(Last(*L)) == 72)
    {
        P = AlokasiDP(1);
    }
    else
    {
        P = AlokasiDP(((int)Info(Last(*L))) + 1);
    }
    addressDP Q = (Last(*L));
    int X = Q->Pos.X;
    int Y = Q->Pos.Y;
    if (isAvail(*L, (X - 1) % 5, Y, obstacle))
    {
        if (X - 1 >= 0)
        {
            X = X - 1;
        }
        else
        {
            X = 4;
        }
    }
    else if (isAvail(*L, X, Y - 1, obstacle))
    {
        if (Y - 1 >= 0)
        {
            Y = Y - 1;
        }
        else
        {
            Y = 4;
        }
    }
    else if (isAvail(*L, X, Y + 1, obstacle))
    {
        if (Y + 1 <= 4)
        {
            Y = Y + 1;
        }
        else
        {
            Y = 0;
        }
    }
    else if (isAvail(*L, X + 1, Y, obstacle))
    {
        if (X + 1 <= 4)
        {
            X = X + 1;
        }
        else
        {
            X = 0;
        }
    }
    else
    {
        *hit = true;
        printf("tidak ada ruang disekitar ekor");
    }
    if (!*hit)
    {
        P->Pos.X = X;
        P->Pos.Y = Y;
        InsertLastDP(L, P);
    }
}

void addFood(POINT *food, ListDP L, POINT obstacle)
{
    srand(time(NULL));
    int X = rand() % 5;
    int Y = rand() % 5;
    boolean found = false;
    int i = 0;
    if (lengthSnake(L) < 22)
    {
        while (!found)
        {
            if (isAvail(L, X, Y, obstacle)) //&& X != obstacle.X && Y != obstacle.Y)
            {
                found = true;
                food->X = X;
                food->Y = Y;
            }
            else
            {
                if (i % 3 == 0)
                {
                    X = (X + 1) % 5;
                    Y = (Y - 1) % 5;
                }
                else if (i % 3 == 1)
                {
                    Y = (Y + 1) % 5;
                    X = (X - 1) % 5;
                }
                else
                {
                    X = (X + 1) % 5;
                    Y = (Y + 1) % 5;
                }
            }
            if (X < 0 || Y < 0)
            {
                X = rand() % 5;
                Y = rand() % 5;
            }
            i++;
        }
    }
}

boolean isMeteorPanas(ListDP L, POINT meteor, char input)
{
    addressDP P = First(L);
    int X = P->Pos.X;
    int Y = P->Pos.Y;
    if (input == 'w')
    {
        return (meteor.Y == (Y - 1) % 5 && X == meteor.X);
    }
    else if (input == 'a')
    {
        return (meteor.X == (X - 1) % 5 && Y == meteor.Y);
    }
    else if (input == 's')
    {
        return (meteor.Y == (Y + 1) % 5 && X == meteor.X);
    }
    else if (input == 'd')
    {
        return (meteor.X == (X + 1) % 5 && Y == meteor.Y);
    }
}

void MeteorHitBody(ListDP *L, POINT food, POINT meteor, POINT obstacle)
{
    addressDP P = First(*L);
    addressDP Q = Last(*L);
    boolean found = false;
    while (!found && P != NULL)
    {
        if (P->Pos.X == meteor.X && P->Pos.Y == meteor.Y)
        {
            found = true;
        }
        P = Next(P);
    }
    clear();
    if (found)
    {
        printf("Berikut merupakan peta permainan:\n");
        printf("Anda terkena meteor!\n");
        if (P == Next(First(*L)))
        {
            DelFirstDP(L, &Q);
        }
        else if (P == NULL)
        {
            DelLastDP(L, &Q);
        }
        else
        {
            while (Q != Prev(P))
            {
                Q->info = Prev(Q)->info;
                //     Q->Pos.X=Prev(Q)->Pos.X;
                //     Q->Pos.Y=Prev(Q)->Pos.Y;
                //     printf("%d %d\n",Q->Pos.X,Q->Pos.Y);
                //     Q=Prev(Q);
                Q = Prev(Q);
            }
            DelBeforeDP(L, &Q, P);
        }
        printMap(*L, food, meteor, obstacle);
    }
    else
    {
        printf("Berikut merupakan peta permainan:\n\n");
        printMap(*L, food, meteor, obstacle);
        printf("Anda beruntung tidak terkena meteor! ");
    }
}

boolean isMeteorHitHead(ListDP L)
{
    addressDP P = First(L);
    return (P->info != 'H');
}

void snakeOnMeteor(int *skor)
{
    *skor = 0;
    srand(time(NULL));
    ListDP L;
    ElmtListDP newtail;
    createSnake(&L);
    char input;
    POINT obstacle = MakePOINT(-999, -999);
    POINT food = MakePOINT(-999, -999);
    POINT meteor = MakePOINT(-999, -999);

    printf("Selamat datang di snake on meteor!\n");
    printf("Mengenerate peta, snake dan makanan...\n");
    sleep(1000);
    printf("Berhasil digenerate!\n");
    printf("------------------------------\n");

    printf("\nEnter to continue...");
    startInput();
    clear();

    printf("Berikut merupakan peta permainan:\n\n");
    addObstacle(L, &obstacle);
    addFood(&food, L, obstacle);
    printMap(L, food, meteor, obstacle);
    int i = 1;
    boolean hit = false;
    while (!hit)
    {
        printf("TURN %d:\n", i);
        printf("Silahkan masukkan command anda: ");

        startInputWord();
        input = currentWord.TabWord[0];

        if (currentWord.Length == 1 && (input == 'w' || input == 'a' || input == 's' || input == 'd'))
        {
            if (!isBodyExceptHead(L, input)) // isInputValid(L, input))// && !isBody(L,input))
            {
                if (!isMeteorPanas(L, meteor, input))
                {
                    // newtail = *(Last(L));
                    Move(&L, input);
                    printf("\nBerhasil bergerak!\n");
                    if (isEat(&L, food))
                    {
                        addTail(&L, &hit, obstacle); //, newtail);
                        addFood(&food, L, obstacle);
                    }
                    addMeteor(&meteor, food, obstacle);
                    MeteorHitBody(&L, food, meteor, obstacle);
                    // printMap(L, food, meteor, obstacle);
                    if (isMeteorHitHead(L))
                    {
                        printf("Kepala snake terkena meteor.\n");
                        *skor = lengthSnake(L) * 2;
                        printf("Game berakhir. skor : %d\n", *skor);
                        hit = true;
                    }
                    else if (isHeadHitObstacle(L, obstacle))
                    {
                        printf("Head Snake mengenai obstacle.\n");
                        *skor = lengthSnake(L) * 2;
                        printf("Game berakhir. skor : %d\n", *skor);
                        hit = true;
                    }
                    else if (isNoMoreHeadSpace(L))
                    {
                        printf("Tidak ada tempat tersedia untuk bergerak.\n");
                        *skor = (lengthSnake(L) + 1) * 2;
                        printf("Game berakhir. skor : %d\n", *skor);
                        hit = true;
                    }
                    else if (lengthSnake(L) == 23)
                    {
                        *skor = 46;
                        printf("skor anda %d\n", *skor);
                        hit = true;
                    }
                    else
                    {
                        if (hit == true)
                        {
                            *skor = (lengthSnake(L) + 1) * 2;
                            printf("skor anda %d\n", *skor);
                        }
                        else
                        {
                            printf("Silahkan lanjutkan permainan\n");
                            i++;
                        }
                    }
                }
                else
                {
                    printf("Meteor masih panas! Silahkan input ulang command\n");
                }
            }
            else
            {
                printf("Anda tidak dapat bergerak ke tubuh sendiri\n");
            }
        }
        else
        {
            printf("Command tidak sesuai! Silahkan input command menggunakan w/a/s/d\n");
        }
    }
}

boolean isHeadHitObstacle(ListDP L, POINT obstacle)
{
    return (EQ(First(L)->Pos, obstacle));
}

void addObstacle(ListDP L, POINT *obstacle)
{
    srand(time(NULL));
    int X = rand() % 5;
    int Y = rand() % 5;
    boolean found = false;
    int i = 0;
    while (!found)
    {
        if (isAvail(L, X, Y, *obstacle))
        { //&& X!=meteor.X && Y!=meteor.Y && X!=obstacle.X && Y!=obstacle.Y){
            found = true;
            obstacle->X = X;
            obstacle->Y = Y;
        }
        else
        {
            if (i % 3 == 0)
            {
                X = (X + 1) % 5;
                Y = (Y - 1) % 5;
            }
            else if (i % 3 == 1)
            {
                Y = (Y + 1) % 5;
                X = (X - 1) % 5;
            }
            else
            {
                X = (X + 1) % 5;
                Y = (Y + 1) % 5;
            }
        }
        if (X < 0 || Y < 0)
        {
            X = rand() % 5;
            Y = rand() % 5;
        }
        i++;
    }
}

int lengthSnake(ListDP L)
{
    return (Info(Last(L)));
}

boolean isLeftHeadEmpty(ListDP L)
{
    addressDP P = First(L);
    addressDP Q = Next(P);
    boolean found = true;
    while (found && Next(Q) != NULL)
    {
        if ((P->Pos.X - 1) % 5 == Q->Pos.X && P->Pos.Y == Q->Pos.Y)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isTopHeadEmpty(ListDP L)
{
    addressDP P = First(L);
    addressDP Q = Next(P);
    boolean found = true;
    while (found && Next(Q) != NULL)
    {
        if ((P->Pos.Y - 1) % 5 == Q->Pos.Y && P->Pos.X == Q->Pos.X)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isRightHeadEmpty(ListDP L)
{
    addressDP P = First(L);
    addressDP Q = Next(P);
    boolean found = true;
    while (found && Next(Q) != NULL)
    {
        if ((P->Pos.X + 1) % 5 == Q->Pos.X && P->Pos.Y == Q->Pos.Y)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isBotHeadEmpty(ListDP L)
{
    addressDP P = First(L);
    addressDP Q = Next(P);
    boolean found = true;
    while (found && Next(Q) != NULL)
    {
        if ((P->Pos.Y + 1) % 5 == Q->Pos.Y && P->Pos.X == Q->Pos.X)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isLeftTailEmpty(ListDP L)
{
    addressDP P = Last(L);
    addressDP Q = Next(P);
    boolean found = true;
    while (found && Q != NULL)
    {
        if ((P->Pos.X - 1) % 5 == Q->Pos.X && P->Pos.Y == Q->Pos.Y)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isTopTailEmpty(ListDP L)
{
    addressDP P = Last(L);
    addressDP Q = Next(P);
    boolean found = true;
    while (found && Q != NULL)
    {
        if ((P->Pos.Y - 1) % 5 == Q->Pos.Y && P->Pos.X == Q->Pos.X)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isRightTailEmpty(ListDP L)
{
    addressDP P = Last(L);
    addressDP Q = Next(P);
    boolean found = true;
    while (found && Q != NULL)
    {
        if ((P->Pos.X + 1) % 5 == Q->Pos.X && P->Pos.Y == Q->Pos.Y)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isBotTailEmpty(ListDP L)
{
    addressDP P = Last(L);
    addressDP Q = Next(P);
    boolean found = true;
    while (found && Q != NULL)
    {
        if ((P->Pos.Y + 1) % 5 == Q->Pos.Y && P->Pos.X == Q->Pos.X)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

boolean isNoMoreHeadSpace(ListDP L)
{
    return ((!isBotHeadEmpty(L) && !isLeftHeadEmpty(L) && !isRightHeadEmpty(L) && !isTopHeadEmpty(L)));
}

// boolean isInputValid(ListDP L, char input)
// {
//     addressDP P = First(L);
//     if (input == 'w' && Next(P)->Pos.Y == (P->Pos.Y - 1) % 5 && P->Pos.X==Next(P)->Pos.X)
//     {
//         return false;
//     }
//     else if (input == 's' && Next(P)->Pos.Y == (P->Pos.Y + 1) % 5 && P->Pos.X==Next(P)->Pos.X)
//     {
//         return false;
//     }
//     else if (input == 'a' && Next(P)->Pos.X == (P->Pos.X - 1) % 5 && P->Pos.Y==Next(P)->Pos.Y)
//     {
//         return false;
//     }
//     else if (input == 'd' && Next(P)->Pos.X == (P->Pos.X + 1) % 5 && P->Pos.Y==Next(P)->Pos.Y)
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }
// }
