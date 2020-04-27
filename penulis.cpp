#include<iostream>
#include"penulis.h"
#include"novel.h"

void createList(ListP &L) {
    first(L) = NULL;
}

adrP createNewP(string nama) {
    adrP P = new penulis;
    info(P) = nama;
    next(P) = NULL;
    firstR(P) = NULL;
    return P;
}

adrR createNewR(string judul) {
    adrR P = new yagimana;
    infoR(P) = judul;
    nextR(P) = NULL;
    return P;

}

void addP(ListP &L, adrP P) {
    if (first(L) != NULL) {
        adrP Q = first(L);
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

void addR(adrP P, adrR R) {
    if (P != NULL) {
        adrR Q = firstR(P);
        if (Q != NULL) {
            while(nextR(Q) != NULL) {
            Q = nextR(Q);
            }
            nextR(Q) = R;
            nextR(R) = NULL;
        } else {
            firstR(P) = R;
            nextR(R) = NULL;
        }
    } else {
        firstR(P) = R;
        nextR(R) = NULL;
    }
}

adrP findP(ListP L, string nama) {
    if (first(L) != NULL) {
        adrP P = first(L);
        do {
            if (info(P) != nama) {
                P = next(P);
            } else {
                return P;
            }
        } while (P != NULL);
    } else {
        return NULL;
    }
}

adrR findR(adrP P) {
    if (firstR(P) != NULL) {
        adrR Q = firstR(P);
        do {
            if (infoR(Q) != info(P) ) {
                Q = nextR(Q);
            } else {
                return Q;
            }
        } while (Q != NULL);
    } else {
        return NULL;
    }
}

void relasi(adrP P, adrR R) {
    if (P != NULL && R != NULL) {
        addR(P, R);
    } else {
        cout<<"Penulis tidak ditemukan."<<endl;
    }
}

void showP(ListP L) {
    adrP P = first(L);
    while (P != NULL) {
        cout << "Penulis: " << info(P) << endl;
        adrR Q = firstR(P);
        if (Q != NULL) {
            while (Q != NULL) {
                cout<<">>Novel: "<<infoR(Q)<<endl;
                Q = nextR(Q);
            }
            cout<<endl;
        } else {
            cout<<"Tidak ada Novel."<<endl;
            cout<<endl;
        }
        P = next(P);
    }
}
