#include <iostream>
#include"penulis.h"
#include"novel.h"
#include"menu.h"

using namespace std;

int main()
{
    ListN LN;
    ListP LP;

    createList(LP);
    createList(LN);

    menu(LP, LN);

    return 0;

}
