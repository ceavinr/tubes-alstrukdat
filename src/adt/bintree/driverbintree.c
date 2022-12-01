#include "bintree.h"
#include <stdio.h>

int main()
{
    int daun;
    BinTree tree1 = Tree(3, AlokNode(20), AlokNode(30));
    BinTree tree2 = Tree(2, AlokNode(35), AlokNode(45));
    BinTree tree3;
    // tree3 = Tree(1, tree, tree2);
    MakeTree(1, tree1, tree2, &tree3);

    STARTWORD("data/amogusdata/recipe.txt");

    BinTree recipe = NULL;
    int idx = 0;
    ADVWORD();
    BuildTreeFromWord(&recipe, currentWord, &idx);
    PrintTree(recipe, 2);

    printf("\n");

    printf("Sebelum:\n");
    PrintTree(tree3, 2);

    printf("Jumlah node tree3: %d\n", NbNode(tree3));
    printf("Jumlah daun tree3: %d\n", NbDaun(tree3));
    printf("Tinggi: %d\n", Tinggi(tree3));

    DelDaun(&tree3, 20);
    printf("\nSetelah 20 didelete:\n");
    PrintTree(tree3, 2);
    DelDaunTerkiri(&tree3, &daun);
    printf("\nSetelah daun terkiri, yaitu %d didelete:\n", daun);
    PrintTree(tree3, 2);
    AddDaunTerkiri(&tree3, daun);
    printf("\nSetelah daun %d ditambahkan lagi di paling kiri:\n", daun);
    PrintTree(tree3, 2);
    printf("\nLevel dari %d: %d\n", daun, Level(tree3, daun));

    printf("\n");

    addrNode tesSearchChild = SearchByChild(tree3, 35, 45);
    if (tesSearchChild)
    {
        PrintTree(tesSearchChild, 2);
    }
    else
    {
        printf("Not found!\n");
    }

    tesSearchChild = SearchByChild(tree3, 1, 2);
    if (tesSearchChild)
    {
        PrintTree(tesSearchChild, 2);
    }
    else
    {
        printf("Not found!\n");
    }
    return 0;
}
