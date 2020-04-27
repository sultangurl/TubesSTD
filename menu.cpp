#include "novel.h"
#include "penulis.h"
#include "menu.h"

void AA(ListP &LP, adrP P, ListN LN) {
    string nama;
    bool f = false;
    cout<<"Masukkan nama penulis :"<<endl;
    while (!f) {
        cin>>nama;
        if (nama=="stop") {
            f = true;
        } else {
            P = createNewP(nama);
            addP(LP, P);
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void AN(ListN &LN, adrN N, ListP LP) {
    string judul;
    bool f = false;
    cout<<"Masukan judul novel :"<<endl;
    while (!f) {
        cin>>judul;
        if (judul=="stop") {
            f = true;
        } else {
            N = createNewN(judul);
            addN(LN, N);
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void conn(ListP &LP, ListN &LN) {
    bool f = false;
    string nama, judul;
    cout<<"Relasikan? Skuy."<<endl;
    cout<<"Masukkan nama penulis dan novel yang ingin direlasikan:"<<endl;
    while (!f) {
        cout<<"Nama Penulis:";
        cin>>nama;
        if (nama=="000") {
            break;
        }
        adrP P = findP(LP, nama);

        cout<<"Judul Novel:";
        cin>>judul;
        adrN N = findN(LN, judul);

        if (P != NULL && N != NULL) {
            adrR R = createNewR(info(N));
            relasi(P, R);
            cout<<"Relasi berhasil."<<endl;
        } else if (P == NULL && N != NULL) {
            cout<<"Relasi gagal, penulis belum terdaftar."<<endl;
        } else if (P != NULL && N == NULL) {
            cout<<"Relasi gagal, novel belum terdaftar."<<endl;
        } else {
            cout<<"Relasi gagal, penulis dan novel belum terdaftar."<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void DA();
void DN();
void SNP(ListN LN, ListP LP){
    adrN N = first(LN);
    while (N!=NULL) {
        bool f = false;
        cout<<"Novel "<<info(N)<<" ditulis oleh: "<<endl;
        adrP P = first(LP);
        while (P!=NULL) {
            adrR R = firstR(P);
            while (R!=NULL) {
                if (info(N)==infoR(R)) {
                    f = true;
                    cout<<"- "<<info(P)<<endl;
                }
                R=nextR(R);
            }
            P=next(P);
        }
        if (f = false) {
            cout<<"Unknown"<<endl;
        }
        N=next(N);
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void SNW(ListN LN, ListP LP) {
    bool f = false;
    adrN N = first(LN);
    cout<<"Novel yang ditulis oleh 2 penulis: "<<endl;
    while (N!=NULL) {
        int i = 0;
        adrP P = first(LP);
        while (P!=NULL) {
            adrR R = firstR(P);
            while (R!=NULL) {
                if (info(N)==infoR(R)) {
                    i++;
                }
                R=nextR(R);
            }
            P=next(P);
        }
        if (i==2) {
            f = true;
            cout<<"- "<<info(N)<<endl;
        }
        N=next(N);
    }
    if (f = false) {
        cout<<"None"<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void SNM(ListP LP, ListN LN) {
    adrP P = first(LP);
    adrP Q;
    int Max = 0;
    while (P!=NULL) {
        int i = 0;
        adrR R = firstR(P);
        while (R!=NULL) {
            i++;
            R=nextR(R);
        }
        if (Max<i){
            Max = i;
            Q = P;
        }
        P=next(P);
    }
    cout<<"Author who wrote the most is "<<info(Q)<<endl;
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void SCA(ListN LN, ListP LP) {
    adrP P = first(LP);
    cout<<"Penulis yang tidak berkolaborasi: "<<endl;
    while (P!=NULL) {
        int i = 0;
        adrR R = firstR(P);
        while (R!=NULL) {
            adrP Q = first(LP);
            while (Q!=NULL) {
                adrR S = firstR(Q);
                while (S!=NULL) {
                    if (info(P)==info(Q)) {
                        break;
                    }
                    if (infoR(R)==infoR(S)) {
                        i++;
                    }
                    S=nextR(S);
                }
                Q=next(Q);
            }
            R=nextR(R);
        }
        if (i==0) {
            cout<<"- "<<info(P)<<endl;
        }
        P=next(P);
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void menu(ListP &LP, ListN &LN) {
    int x;

    adrP P;
    adrN N;
    adrR R;

    cout<<"Menu Program: "<<endl;
	cout<<"1. Add Author"<<"                "<<"5. Delete Novel"<<endl;
	cout<<"2. Add Novel"<<"                 "<<"6. Show Novel with Particular Author"<<endl;
	cout<<"3. Connecting"<<"                "<<"7. Show Novel Written by 2 Author"<<endl;
	cout<<"4. Delete Author "<<"            "<<"8. Show Author Who Wrote The Most "<<endl;
	cout<<"9. Show Collabless Author"<<"    "<<"000. Close Program"<<endl;

	cout<<endl;
	cout<<"Pilih menu: ";
	cin>>x;
	if (x==1) {
        AA(LP, P, LN);
	} else if (x==2) {
        AN(LN, N, LP);
	} else if (x==3) {
        conn(LP, LN);
	} else if (x==4) {
       // DA();
	} else if (x==5) {
       // DN();
	} else if (x==6) {
        SNP(LN, LP);
	} else if (x==7) {
        SNW(LN, LP);
	} else if (x==8) {
        SNM(LP, LN);
	} else if (x==9) {
        SCA(LN, LP);
	} else if (x==000) {
        cout<<"Close Program"<<endl;
	} else {
        cout<<"Not found, Try again"<<endl;
        menu(LP, LN);
	}
}
