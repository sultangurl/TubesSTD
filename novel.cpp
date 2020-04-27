#include<iostream>
#include"novel.h"

void createList(ListN &L) {
    first(L) = NULL;
}

adrN createNewN(string nama) {
    adrN P = new novel;
    info(P) = nama;
    next(P) = NULL;
    return P;
}

void addN(ListN &L, adrN P) {
    if (first(L) != NULL) {
        adrN Q = first(L);
        while(next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = NULL;
    } else {
        first(L) = P;
        next(P) = NULL;
    }
}


adrN findN(ListN L, string judul) {
    if (first(L) != NULL) {
        adrN P = first(L);
        do {
            if (info(P) != judul) {
                P = next(P);
            } else {
                return P;
            }
        } while (P != NULL);
    } else {
        return NULL;
    }
}

void showN(ListN L) {
    adrN P = first(L);
    while (P != NULL) {
        cout << ">>" << info(P) << endl;
        P = next(P);
    }
}
