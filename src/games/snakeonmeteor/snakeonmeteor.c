#include "snakeonmeteor.h"
#include "../../interface.h"

void Move(ListDP *L, char input)
{
    addressDP P = Last(*L);
    POINT temp;
    if (input == 'w')
    {
        temp = (*Prev(P)).Pos;
        while (Prev(P) != NULL)
        {
            (*P).Pos = temp;
            P = Prev(P);
            if (Prev(P) != NULL)
            {
                temp = (*Prev(P)).Pos;
            }
        }
    }
    else if (input == 's')
    {
        temp = (*Prev(P)).Pos;
        while (Prev(P) != NULL)
        {
            (*P).Pos = temp;
            P = Prev(P);
            if (Prev(P) != NULL)
            {
                temp = (*Prev(P)).Pos;
            }
        }
    }
    else if (input == 'd')
    {
        temp = (*Prev(P)).Pos;
        while (Prev(P) != NULL)
        {
            (*P).Pos = temp;
            P = Prev(P);
            if (Prev(P) != NULL)
            {
                temp = (*Prev(P)).Pos;
            }
        }
    }
    else if (input == 'a')
    {
        temp = (*Prev(P)).Pos;
        while (Prev(P) != NULL)
        {
            (*P).Pos = temp;
            P = Prev(P);
            if (Prev(P) != NULL)
            {
                temp = (*Prev(P)).Pos;
            }
        }
    }
    moveHead(L, input);
}

void createSnake(ListDP *L)
{
    CreateEmptyDP(L);
    addressDP P1 = AlokasiDP(72);
    addressDP P2 = AlokasiDP(1);
    addressDP P3 = AlokasiDP(2);
    srand(time(NULL));
    Absis(P1->Pos) = rand() % 5;
    Ordinat(P1->Pos) = rand() % 5;
    if (Absis(P1->Pos) == 0)
    {
        if (Ordinat(P1->Pos) == 0)
        {
            Absis(P2->Pos) = Absis(P1->Pos);
            Absis(P3->Pos) = Absis(P1->Pos);
            Ordinat(P2->Pos) = Ordinat(P1->Pos) + 1;
            Ordinat(P3->Pos) = Ordinat(P1->Pos) + 2;
        }
        else
        {
            Absis(P2->Pos) = Absis(P1->Pos);
            Absis(P3->Pos) = Absis(P1->Pos);
            if (Ordinat(P1->Pos) == 1)
            {
                Ordinat(P2->Pos) = Ordinat(P1->Pos) + 1;
                Ordinat(P3->Pos) = Ordinat(P1->Pos) + 2;
            }
            else
            {
                Ordinat(P2->Pos) = Ordinat(P1->Pos) - 1;
                Ordinat(P3->Pos) = Ordinat(P1->Pos) - 2;
            }
        }
    }
    else
    {
        if (Ordinat(P1->Pos) == 0)
        {
            if (Absis(P1->Pos) == 1)
            {
                Absis(P2->Pos) = Absis(P1->Pos) - 1;
                Absis(P3->Pos) = Absis(P1->Pos) - 1;
                Ordinat(P2->Pos) = Ordinat(P1->Pos);
                Ordinat(P3->Pos) = Ordinat(P1->Pos) + 1;
            }
            else
            {
                Absis(P2->Pos) = Absis(P1->Pos) - 1;
                Absis(P3->Pos) = Absis(P1->Pos) - 2;
                Ordinat(P2->Pos) = Ordinat(P1->Pos);
                Ordinat(P3->Pos) = Ordinat(P1->Pos);
            }
        }
        else
        {
            Absis(P2->Pos) = Absis(P1->Pos) - 1;
            Ordinat(P2->Pos) = Ordinat(P1->Pos);
            if (Absis(P2->Pos) == 0)
            {
                Absis(P3->Pos) = Absis(P2->Pos);
                Ordinat(P3->Pos) = Ordinat(P2->Pos) - 1;
            }
            else
            {
                Absis(P3->Pos) = Absis(P2->Pos) - 1;
                Ordinat(P3->Pos) = Ordinat(P2->Pos);
            }
        }
    }
    InsertLastDP(L, P1);
    InsertLastDP(L, P2);
    InsertLastDP(L, P3);
}

void printPoint(POINT P)
{

    printf("<%d,%d>\n", Absis(P), Ordinat(P));
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
            else if (Absis(meteor) == ((j + 1) / 2) - 1 && Ordinat(meteor) == ((i + 1) / 2) - 1)
            {
                printf(" M ");
            }
            else if (Absis(obstacle) == ((j + 1) / 2) - 1 && Ordinat(obstacle) == ((i + 1) / 2) - 1)
            {
                printf(" # ");
            }
            else if (isPoinMember(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1))
            {
                if (Info(isPoinMember(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)) == 72)
                {
                    printf(" %c ", (char)Info(isPoinMember(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)));
                }
                else
                {
                    if (Info(isPoinMember(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)) < 9)
                    {
                        printf(" %d ", Info(isPoinMember(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)));
                    }
                    else
                    {
                        printf("%d ", Info(isPoinMember(L, ((j + 1) / 2) - 1, ((i + 1) / 2) - 1)));
                    }
                }
            }
            else if (Absis(food) == ((j + 1) / 2) - 1 && Ordinat(food) == ((i + 1) / 2) - 1)
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

addressDP isPoinMember(ListDP L, int i, int j)
{
    addressDP P = First(L);
    boolean found = false;
    while (!found && (P) != NULL)
    {
        if (Absis(P->Pos) == i && Ordinat(P->Pos) == j)
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

boolean isNotWall(ListDP L, char input)
{
    addressDP P = First(L);
    if (Absis(P->Pos) == 0 && input == 'a')
    {
        return false;
    }
    else if (Absis(P->Pos) == 5 && input == 'd')
    {
        return false;
    }
    else if (Ordinat(P->Pos) == 0 && input == 'w')
    {
        return false;
    }
    else if (Ordinat(P->Pos) == 5 && input == 's')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void moveHead(ListDP *L, char input)
{
    addressDP P = First(*L);
    if (input == 'a')
    {
        if (Absis(P->Pos) == 0)
        {
            Absis(P->Pos) = 4;
        }
        else
        {
            Absis(P->Pos) -= 1;
        }
    }
    else if (input == 'd')
    {
        if (Absis(P->Pos) == 4)
        {
            Absis(P->Pos) = 0;
        }
        else
        {
            Absis(P->Pos) += 1;
        }
    }
    else if (input == 'w')
    {
        if (Ordinat(P->Pos) == 0)
        {
            Ordinat(P->Pos) = 4;
        }
        else
        {
            Ordinat(P->Pos) -= 1;
        }
    }
    else if (input == 's')
    {
        if (Ordinat(P->Pos) == 4)
        {
            Ordinat(P->Pos) = 0;
        }
        else
        {
            Ordinat(P->Pos) += 1;
        }
    }
}

void addMeteor(POINT *meteor, POINT food)
{
    srand(time(NULL));
    int X = rand() % 5;
    int Y = rand() % 5;
    boolean found = false;
    int i = 0;
    while (!found)
    {
        if (X != Absis(food) && Y != Ordinat(food))
        {
            found = true;
            Absis(*meteor) = X;
            Ordinat(*meteor) = Y;
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
    return (Absis((*First(*L)).Pos) == Absis(P) && Ordinat((*First(*L)).Pos) == Ordinat(P));
}

boolean isAvail(ListDP L, int X, int Y)
{
    addressDP Q = First(L);
    boolean found = true;
    while (found && Q != NULL)
    {
        if (Absis((*Q).Pos) == X && Ordinat((*Q).Pos) == Y)
        {
            found = false;
        }
        Q = Next(Q);
    }
    return found;
}

void addTail(ListDP *L, ElmtListDP newtail)
{
    addressDP P = AlokasiDP(((int)Info(Last(*L))) + 1);
    Absis(P->Pos) = Absis(newtail.Pos);
    Ordinat(P->Pos) = Ordinat(newtail.Pos);
    InsertLastDP(L, P);
}

void addFood(POINT *food, ListDP L, POINT obstacle)
{
    srand(time(NULL));
    int X = rand() % 5;
    int Y = rand() % 5;
    boolean found = false;
    int i = 0;
    while (!found)
    {
        if (isAvail(L, X, Y) && X != Absis(obstacle) && Y != Ordinat(obstacle))
        {
            found = true;
            Absis(*food) = X;
            Ordinat(*food) = Y;
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

void MeteorHitBody(ListDP *L, POINT food, POINT meteor)
{
    addressDP P = First(*L);
    addressDP Q = Last(*L);
    boolean found = false;
    while (!found && P != NULL)
    {
        if (Absis(P->Pos) == Absis(meteor) && Ordinat(P->Pos) == Ordinat(meteor))
        {
            found = true;
        }
        P = Next(P);
    }
    if (found)
    {
        if (P == Next(First(*L)))
        {
            DelFirstDP(L, &Q);
            printf("Meteor mengenai bagian Head snake. Permainan berakhir\n");
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
                Q = Prev(Q);
            }
            DelBeforeDP(L, &Q, P);
        }
    }
}

boolean isMeteorHitHead(ListDP L)
{
    addressDP P = First(L);
    return (P->info != 'H');
}

boolean isHeadHitObstacle(ListDP L, POINT obstacle)
{
    return (Absis(First(L)->Pos) == Absis(obstacle) && Ordinat(First(L)->Pos) == Ordinat(obstacle));
}

boolean isLose(ListDP L, POINT meteor, POINT obstacle)
{
    addressDP P = First(L);
    P = Next(P);
    boolean found = false;
    while (P != NULL && !found)
    {
        if (Absis(P->Pos) == Absis(First(L)->Pos) && Ordinat(P->Pos) == Ordinat(First(L)->Pos))
        {
            found = true;
        }
        P = Next(P);
    }
    if (found)
    {
        printf("Anda Kalah.Head menabrak body Snake\n");
        return found;
    }
    else
    {
        if (isMeteorHitHead(L))
        {
            return true;
        }
        else if (isHeadHitObstacle(L, obstacle))
        {
            printf("Anda Kalah.Head menabrak obstacle\n");
            return true;
        }
        else
        {
            return false;
        }
    }
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
        if (isAvail(L, X, Y))
        {
            found = true;
            Absis(*obstacle) = X;
            Ordinat(*obstacle) = Y;
        }
        else
        {
            if (i % 3 == 0)
            {
                X = (X + 1) % 4;
                Y = (Y - 1) % 4;
            }
            else if (i % 3 == 1)
            {
                Y = (Y + 1) % 4;
                X = (X - 1) % 4;
            }
            else
            {
                X = (X + 1) % 4;
                Y = (Y + 1) % 4;
            }
        }
        if (X < 0 || Y < 0)
        {
            X = rand() % 4;
            Y = rand() % 4;
        }
        i++;
    }
}

int lengthSnake(ListDP L)
{
    return (Info(Last(L)));
}

boolean isInputValid(ListDP L, char input)
{
    addressDP P = First(L);
    if (input == 'w' || input == 'a' || input == 's' || input == 'd')
    {
        if (input == 'w' && Ordinat(Next(P)->Pos) == (Ordinat(P->Pos) - 1) % 5)
        {
            return false;
        }
        else if (input == 's' && Ordinat(Next(P)->Pos) == (Ordinat(P->Pos) + 1) % 5)
        {
            return false;
        }
        else if (input == 'a' && Absis(Next(P)->Pos) == (Absis(P->Pos) - 1) % 5)
        {
            return false;
        }
        else if (input == 'd' && Absis(Next(P)->Pos) == (Absis(P->Pos) + 1) % 5)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void snakeOnMeteor(int *skor)
{
    POINT obstacle, food = MakePOINT(-999, -999), meteor = MakePOINT(-999, -999);
    ListDP L;
    ElmtListDP newtail;
    char input;
    boolean hit = false;

    printf("Selamat datang di snake on meteor!\n");
    printf("Mengenerate peta, snake dan makanan ...\n");
    addObstacle(L, &obstacle);
    createSnake(&L);
    addFood(&food, L, obstacle);
    printf("Berhasil digenerate\n");

    printf("\nEnter to continue...");
    startInput();
    clear();

    printf("Berikut merupakan peta permainan\n");
    printMap(L, food, meteor, obstacle);

    int i = 1;
    while (!hit)
    {
        printf("TURN %d:\n", i);
        printf("Silahkan masukkan command anda: ");

        startInputWord();
        input = currentWord.TabWord[0];
        if (currentWord.Length == 1 && isInputValid(L, input))
        {
            newtail = *(Last(L));
            Move(&L, input);
            if (isEat(&L, food))
            {
                addTail(&L, newtail);
                addFood(&food, L, obstacle);
            }
            addMeteor(&meteor, food);

            clear();
            printf("Berikut merupakan peta permainan\n");
            printMap(L, food, meteor, obstacle);

            MeteorHitBody(&L, food, meteor);
            if (isLose(L, meteor, obstacle))
            {
                *skor = lengthSnake(L) * 2;
                printf("Skor anda %d\n", *skor);
                hit = true;
            }
            else
            {
                i++;
            }
        }
        else
        {
            printf("Perintah tidak valid.\n");
        }
    }
}
