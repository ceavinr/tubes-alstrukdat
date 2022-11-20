#include "bintree.h"
#include <stdio.h>

int main()
{
    BinTree tree = Tree(3, AlokNode(20), AlokNode(30));
    BinTree tree2 = Tree(2, AlokNode(35), AlokNode(45));
    BinTree tree3 = Tree(1, tree, tree2);

    PrintTree(tree3, 2);
    return 0;
}