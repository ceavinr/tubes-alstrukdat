#include "bintree.h"
#include "../word/word.h"
#include "../arraydin/arraydin.h"
#include <stdio.h>

int main()
{
    BinTree tree = Tree(3, AlokNode(20), AlokNode(30));
    BinTree tree2 = Tree(2, AlokNode(35), AlokNode(45));
    BinTree tree3 = Tree(1, tree, tree2);
    // PrintTree(tree3, 3);
    // arr1 = MakeArrayDin();
    // InsertAt(&arr1, currentWord, 0);

    // save("savefiles.txt", arr1);

    // PrintArrayDin(arr1, 1);
    STARTWORD("data/recipe.txt");
    int countPotion = wordToInt(currentWord);
    for (int i = 0; i < countPotion; i++)
    {
        BinTree recipe = NULL;
        int idx = 0;
        ADVWORD();
        printWord(currentWord);
        printf("\n");
        BuildTreeFromWord(&recipe, currentWord, &idx);
        PrintTree(recipe, 2);
    }

    printf("\n");

    return 0;
}
