#ifndef TREE_H
#define TREE_H

#include "../../boolean.h"

typedef int ElType;
typedef struct treeNode *Address;
typedef struct treeNode
{
    ElType info;
    Address child;
    Address sibling;
} TreeNode;

#define PARENT(p) (p)->info
#define CHILD(p) (p)->child
#define SIBLING(p) (p)->sibling

typedef Address Tree;
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
   Jika alokasi gagal, mengirimkan NULL
*/
Address newTreeNode(ElType val);

/* Menghasilkan sebuah pohon dari parent, child, dan sibling,
   jika alokasi berhasil.
   Menghasilkan pohon kosong (NULL) jika alokasi gagal
*/
Tree NewTree(ElType parent, Tree child, Tree sibling);

/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon p dari parent, child, dan sibling, jika alokasi
   berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal
*/
void CreateTree(ElType parent, Tree child, Tree sibling, Tree *p);

/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon p dari parent dengan child=sibling=NULL,
   jika alokasi berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal
*/
void CreateTreeNode(ElType parent, Tree *p);

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. mengembalikan address pada tree dimana val ditemukan
   jika val tidak berada di tree, maka return NULL
*/
Address searchAdress(Tree p, ElType val);

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. mengembalikan address pada sibling tree dimana val ditemukan
   jika val tidak berada di sibling tree, maka return NULL
*/
Address searchSiblingAdress(Tree p, ElType val);

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. mengembalikan address sibling paling belakang dari p
*/

Address lastSibling(Tree p);

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. melakukan alokasi sebuah node tree dan menambahkannya
   sebagai sibling p.
   jika alokasi gagal, I.S. = F.S.
*/
void insertSibling(Tree *parent, Tree sibling_tree);

/* I.S. p terdefinisi, tidak mungkin kosong
   F.S. melakukan alokasi sebuah node tree dan menambahkannya
   sebagai child p. Jika p sudah memiliki child utama, maka
   node ditambahkan sebagai sibling dari child.
   jika alokasi gagal, I.S. = F.S.
*/
void insertChild(Tree *parent, Tree child_tree);

/* I.S. p terdefinisi
   F.S. Semua children p sudah ditulis dengan bracket
   contoh tree:
        1
      / | \
     2  3  4
   printChildren(1) akan menampilkan output ke layar [2,3,4]
*/
void displayChildren(Tree p);

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
void displayAllChildren(Tree p);

/* I.S. p terdefinisi
   F.S. Semua children p sudah ditulis dengan indentasi (spasi)
   Penulisan parent selalu pada baris baru (diakhiri newline)
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
void displayTree(Tree p, int depth);

/* Melakukan input Tree sesuai konfigurasi tugas.
   Konfigurasi disusun atas:
   1. Baris pertama, N resep
   2. N baris selanjutnya dibaca ID parent,
      M child, dan ID child sebanyak M
*/
void inputTree(Tree *p);

#endif // TREE_H
