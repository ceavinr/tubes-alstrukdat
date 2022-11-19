#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../mesin/mesinkata.h"

/*
   example n-ary tree:
            1           children(1): [2,3,4]
          / | \         children(2): [5,6]
         2  3  4        children(4): [7]
        / \     \       siblings(2): [3,4]
       5   6     7      siblings(5): [6]

   Tree ADT:
            1           CHILD(1): 2     SIBLING(2): 3
          /             CHILD(2): 5     SIBLING(3): 4
         2--3--4        CHILD(4): 7     SIBLING(5): 6
        /       \
       5---6     7

   deskripsi:
   setiap node memiliki address node child dan sibling dimana
   children dari node parent adalah childnya ditambah siblings
   dari child utamanya

   implementasi Tree resep:
   seluruh resep disimpan dalam 1 Tree. Root Tree yang berbeda disimpan
   pada sibling dari node parent utama.
   contoh:
        2-----4-----1
       /     /     /
      5--6  7     2--3--4
                 /       \
                5--6      7
   keterangan:
   terdapat 3 root resep yaitu resep ID 2, 4, dan 1.
   ID 2 memiliki child 5 dan 6.
   ID 4 memiliki chil 7.
   ID 1 memiliki child 2, 3, dan 4.
*/

/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.child=NULL, p↑.sibling=NULL
   Jika alokasi gagal, mengirimkan NULL */
Address newTreeNode(ElType val)
{
    Address p;

    p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        PARENT(p) = val;
        CHILD(p) = NULL;
        SIBLING(p) = NULL;
    }
    return p;
}

/* Menghasilkan sebuah pohon biner dari parent, child, dan sibling,
   jika alokasi berhasil.
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
Tree NewTree(ElType parent, Tree child_tree, Tree sibling_tree)
{
    Tree p;

    p = newTreeNode(parent);
    if (p != NULL)
    {
        CHILD(p) = child_tree;
        SIBLING(p) = sibling_tree;
    }
    return p;
}

/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, child, dan sibling, jika alokasi
   berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
void CreateTree(ElType parent, Tree child_tree, Tree sibling_tree, Tree *p)
{
    *p = NewTree(parent, child_tree, sibling_tree);
}

/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon p dari parent dengan child=sibling=NULL,
   jika alokasi berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
void CreateTreeNode(ElType parent, Tree *p)
{
    CreateTree(parent, NULL, NULL, p);
}

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. mengembalikan address pada tree dimana val ditemukan
   jika val tidak berada di tree, maka return NULL
*/
Address searchAdress(Tree p, ElType val)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (PARENT(p) == val)
    {
        return p;
    }

    Address x, y;
    x = searchAdress(CHILD(p), val);
    y = searchAdress(SIBLING(p), val);

    if (x == NULL && y == NULL)
    {
        return NULL;
    }
    if (x != NULL)
    {
        return x;
    }
    if (y != NULL)
    {
        return y;
    }
}

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. mengembalikan address pada sibling tree dimana val ditemukan
   jika val tidak berada di sibling tree, maka return NULL
*/
Address searchSiblingAdress(Tree p, ElType val)
{
    while (p != NULL)
    {
        if (PARENT(p) == val)
        {
            return p;
        }
        p = SIBLING(p);
    }
    return NULL;
}

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. mengembalikan address sibling paling belakang dari p
*/
Address lastSibling(Tree p)
{
    while (SIBLING(p) != NULL)
    {
        p = SIBLING(p);
    }
    return p;
}

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. melakukan alokasi sebuah node tree dan menambahkannya
   sebagai sibling p.
   jika alokasi gagal, I.S. = F.S.
*/
void insertSibling(Tree *parent, Tree sibling_tree)
{
    if (sibling_tree != NULL)
    {
        Address add;
        add = *parent;
        while (SIBLING(add) != NULL)
        {
            add = SIBLING(add);
        }
        SIBLING(add) = sibling_tree;
    }
}

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. melakukan alokasi sebuah node tree dan menambahkannya
   sebagai child p. Jika p sudah memiliki child utama, maka
   node ditambahkan sebagai sibling dari child.
   jika alokasi gagal, I.S. = F.S.
*/
void insertChild(Tree *parent, Tree child_tree)
{
    if (child_tree != NULL)
    {
        Address add;
        add = *parent;

        if (CHILD(add) == NULL)
        {
            CHILD(add) = child_tree;
        }
        else
        {
            add = CHILD(add);
            while (SIBLING(add) != NULL)
            {
                add = SIBLING(add);
            }
            SIBLING(add) = child_tree;
        }
    }
}

/* I.S. p terdefinisi
   F.S. Semua children p sudah ditulis dengan bracket
   jika p tidak memiliki childran maka tampilkan []
   contoh tree:
        1
      / | \
     2  3  4
   displayChildren(1) akan menampilkan output ke layar [2,3,4]
   */
void displayChildren(Tree p)
{
    if (p == NULL)
    {
        return;
    }

    printf("%d[", PARENT(p));

    if (CHILD(p) != NULL)
    {
        p = CHILD(p);
        printf("%d", PARENT(p));
        p = SIBLING(p);
        while (p != NULL)
        {
            printf(",%d", PARENT(p));
            p = SIBLING(p);
        }
    }

    printf("]");
}

/* I.S. p terdefinisi
   F.S. menampilkan seluruh parent di p beserta childrennya
   1[2,3[5,6],4] berarti parent 1 memiliki child 2, 3, 4
   dan 3 memiliki child 5, 6
   tree:
        1
      / | \
     2  3  4
       / \
      5   6
*/
void displayAllChildren(Tree p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%d[", PARENT(p));

    if (CHILD(p) != NULL)
    {
        p = CHILD(p);

        if (CHILD(p) != NULL)
        {
            displayAllChildren(p);
        }
        else
        {
            printf("%d", PARENT(p));
        }

        p = SIBLING(p);
        while (p != NULL)
        {

            printf(",");
            if (CHILD(p) != NULL)
            {
                displayAllChildren(p);
            }
            else
            {
                printf("%d", PARENT(p));
            }

            p = SIBLING(p);
        }
    }

    printf("]");
}

/* I.S. p terdefinisi
   F.S. Semua simpul p sudah ditulis dengan indentasi (spasi)
   Penulisan akar selalu pada baris baru (diakhiri newline)
   contoh tree:
            1
          / | \
         2  3  4
        / \     \
       5   6     7
    output ke layar:
    1
      2
        5
        6
      3
      4
        7
   */
void displayTree(Tree p, int depth)
{
    if (p != NULL)
    {
        int i;
        for (i = 0; i < depth; i++)
        {
            printf("  ");
        }
        printf("%d\n", PARENT(p));
        displayTree(CHILD(p), depth + 1);
        displayTree(SIBLING(p), depth);
    }
}

/*UNTUK SAAT INI MENGINPUT MENGGUNAKAN SCANF*/
/* Melakukan input Tree sesuai konfigurasi tugas.
   Konfigurasi disusun atas:
   1. Baris pertama, N resep
   2. N baris selanjutnya dibaca ID parent,
      M child, dan ID child sebanyak M
*/
void inputTree(Tree *p)
{
    int N, i, j;
    Tree q, f; // f : fodder
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        int x, n;
        scanf("%d", &x);

        // create new tree node for the first time
        if (i == 0)
        {
            CreateTreeNode(x, p);
            q = *p;
        }

        // insert sibling to existing tree
        else
        {
            CreateTreeNode(x, &f);
            insertSibling(p, f);
            q = lastSibling(*p);
        }

        // input child
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            int y;
            scanf("%d", &y);
            CreateTreeNode(y, &f);

            // if the child is an existing parent, insert 'grandchildren'
            Address r;
            r = searchSiblingAdress(*p, y);
            if (r != NULL)
            {
                insertChild(&f, CHILD(r));
            }

            insertChild(&q, f);
        }

        // if the sibling (new recipe) is an existing child,
        // insert 'grandchildren' to existing parent
        Address r, s;
        r = searchAdress(*p, x);
        s = searchSiblingAdress(*p, x);

        if (r != s)
        {
            insertChild(&r, CHILD(s));
        }
    }
}
