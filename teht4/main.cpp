#include <iostream>

#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas aapeli("Aapeli", 1000);
    aapeli.showSaldo();

    cout << endl;

    aapeli.talletus(250);
    aapeli.luotonNosto(150);
    aapeli.showSaldo();

    cout << endl;

    Asiakas bertta("Bertta", 1000);
    bertta.showSaldo();

    cout << endl;

    cout << aapeli.getNimi() << endl;
    aapeli.showSaldo();
    aapeli.tilisiirto(50, bertta);

    cout << endl;

    cout << bertta.getNimi() << endl;
    bertta.showSaldo();

    return 0;
}
