
#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

BinTree Tree(ElType root, BinTree left_tree, BinTree right_tree) {
    Address p = (Address)(malloc(sizeof(BinTree)));
    if (p != NULL) {
        Akar(p) = root;
        Kiri(p) = left_tree;
        Kanan(p) = right_tree;
    }
    return p;
}
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    Address a = (Address)(malloc(sizeof(BinTree)));
    if (a != NULL) {
        Akar(a) = root;
        Kiri(a) = left_tree;
        Kanan(a) = right_tree;
    }
    *p = a;
}
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val) {
    Address p = (Address)(malloc(sizeof(BinTree)));
    if (p != NULL) {
        Akar(p) = val;
        Kiri(p) = NULL;
        Kanan(p) = NULL;
    }
    return p;
}
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode(Address p) {
    free(p);
}
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty(BinTree p) {
    return p == NULL;
}
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt(BinTree p) {
    if (!isTreeEmpty(p)) {
        return (Kiri(p) == NULL && Kanan(p) == NULL);
    } else {
        return false;
    }
}
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft(BinTree p) {
    if (!isTreeEmpty(p)) {
        return (Kiri(p) != NULL && Kanan(p) == NULL);
    } else {
        return false;
    }
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight(BinTree p) {
    if (!isTreeEmpty(p)) {
        return (Kiri(p) == NULL && Kanan(p) != NULL);
    } else {
        return false;
    }
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary(BinTree p) {
    if (!isTreeEmpty(p)) {
        return (Kiri(p) != NULL && Kanan(p) != NULL);
    } else {
        return false;
    }
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */
void printPreorder(BinTree p) {
    printf("(");
    if (p != NULL) {
        printf("%d", Akar(p));
        printPreorder(Kiri(p));
        printPreorder(Kanan(p));
    }
    printf(")");
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

void printInorder(BinTree p) {
    printf("(");
    if (p != NULL) {
        printInorder(Kiri(p));
        printf("%d", Akar(p));
        printInorder(Kanan(p));
    }
    printf(")");
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

void printPostorder(BinTree p) {
    printf("(");
    if (p != NULL) {
        printPostorder(Kiri(p));
        printPostorder(Kanan(p));
        printf("%d", Akar(p));
    }
    printf(")");
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void printSubTree(BinTree p, int h, int depth) {
    int i;
    if (!isTreeEmpty(p)) {
        for (i = 0; i < depth*h; i++) {
            printf("%s", " ");
        }
        printf("%d\n", Akar(p));
        printSubTree(Kiri(p), h, depth + 1);
        printSubTree(Kanan(p), h, depth + 1);
    }
}

void printTree(BinTree p, int h) {
    int i;
    if (!isTreeEmpty(p)) {
        printf("%d\n", Akar(p));
        printSubTree(Kiri(p), h, 1);
        printSubTree(Kanan(p), h, 1);
    }
}
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/