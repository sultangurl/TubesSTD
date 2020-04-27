#ifndef NOVEL_H_INCLUDED
#define NOVEL_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define nextR(P) P->nextR

using namespace std;
typedef struct novel *adrN;

struct novel {
    string info;
    adrN next;
};

struct ListN {
    adrN first;
};

void createList(ListN &L);
adrN createNewN(string nama);
void addN(ListN &L, adrN P);
adrN findN(ListN L, string nama);
void showN(ListN L);

#endif // NOVEL_H_INCLUDED
