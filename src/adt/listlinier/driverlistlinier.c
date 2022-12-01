#include <stdio.h>
#include "listlinier.h"

int main()
{
    List L, L2;
    CreateEmpty(&L);
    CreateEmpty(&L2);
    address Q, Q2, P, P2;
    BinTree tree;
    BinTree tree1 = Tree(3, AlokNode(20), AlokNode(30));
    BinTree tree2 = Tree(2, AlokNode(35), AlokNode(45));
    BinTree tree3 = Tree(1, AlokNode(10), AlokNode(5));
    address Ptree1 = Alokasi(tree1);
    address Ptree2 = Alokasi(tree2);
    address Ptree3 = Alokasi(tree3);

    // Tes insert
    InsertFirst(&L, Ptree1);
    InsertLast(&L, Ptree2);
    InsertAfter(&L, Ptree3, Ptree1);

    InsVFirst(&L2, tree3);
    InsVFirst(&L2, tree1);
    InsVLast(&L2, tree2);

    printf("Jumlah elemen 1: %d\n", NbElmt(L));
    printf("Jumlah elemen 2: %d\n", NbElmt(L2));

    Q = Search(L, tree1);
    Q2 = Search(L2, tree1);

    if (IsListEmpty(L))
    {
        printf("List L kosong\n");
    }
    else
    {
        printf("List L tidak kosong\n");
    }
    if (IsListEmpty(L2))
    {
        printf("List L kosong\n");
    }
    else
    {
        printf("List L tidak kosong\n");
    }

    // Tes delete
    DelAfter(&L, &P, Q);
    DelP(&L2, tree3);
    printf("%d\n", Akar(Info(P)));
    DelFirst(&L, &P);
    DelVFirst(&L2, &tree);
    printf("%d\n", Akar(Info(P)));
    printf("%d\n", Akar(tree));
    DelLast(&L, &P);
    DelVLast(&L2, &tree);
    printf("%d\n", Akar(Info(P)));
    printf("%d\n", Akar(tree));

    if (IsListEmpty(L))
    {
        printf("List L kosong\n");
    }
    else
    {
        printf("List L tidak kosong\n");
    }

    Dealokasi(&P);
    return 0;
}