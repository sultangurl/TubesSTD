#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define firstR(P) P->firstR
#define next(P) P->next
#define info(P) P->info
#define nextR(P) P->nextR
#define infoR(P) P->infoR

using namespace std;
typedef struct penulis *adrP;
typedef struct yagimana *adrR;

struct penulis {
    string info;
    adrP next;
    adrR firstR;
};

struct yagimana {
    adrR nextR;
    string infoR;
};

struct ListP {
    adrP first;
};


void createList(ListP &L);
adrP createNewP(string nama);
adrR createNewR(string judul);
void addP(ListP &L, adrP P);
void addR(adrP P, adrR R);
adrR findR(adrP P);
adrP findP(ListP L, string nama);
void relasi(adrP P, adrR R);
void showP(ListP L);

#endif // PENULIS_H_INCLUDED
