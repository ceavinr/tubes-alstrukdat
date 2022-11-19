#include "tree.h"
#include <stdio.h>

int main()
{
    Tree tree = NewTree(3, newTreeNode(20), newTreeNode(30));
    Tree tree2 = NewTree(2, newTreeNode(35), newTreeNode(45));
    Tree tree3 = NewTree(1, tree, tree2);

    displayTree(tree3, 2);
    return 0;
}
