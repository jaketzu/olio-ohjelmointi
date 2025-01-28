#include <iostream>

#include "asiakas.h"

Asiakas::Asiakas(string n, double l): nimi(n), kayttotili(n), luottotili(n, l)
{
    cout << "Asiakkuus luotu " << Asiakas::getNimi() << ":lle." << endl;
}


string Asiakas::getNimi()
{
    return Asiakas::nimi;
}

void Asiakas::showSaldo()
{
    cout << Asiakas::getNimi() << " Käyttötilin saldo: " << Asiakas::kayttotili.getBalance() << endl;
    cout << Asiakas::getNimi() << " Luottotilin saldo: " << Asiakas::luottotili.getBalance() << endl;
}

bool Asiakas::talletus(double amount)
{
    if(Asiakas::kayttotili.deposit(amount))
        return true;
    else
        return false;
}

bool Asiakas::nosto(double amount)
{
    if(Asiakas::kayttotili.withdraw(amount))
        return true;
    else
        return false;
}

bool Asiakas::luotonMaksu(double amount)
{
    if(Asiakas::luottotili.deposit(amount))
        return true;
    else
        return false;
}

bool Asiakas::luotonNosto(double amount)
{
    if(Asiakas::luottotili.withdraw(amount))
        return true;
    else
        return false;
}

bool Asiakas::tilisiirto(double amount, Asiakas & asiakasRef)
{
    if(Asiakas::kayttotili.withdraw(amount))
    {
        asiakasRef.talletus(amount);
        cout << Asiakas::getNimi() << " Pankkitili: siirtää " << amount << " " << asiakasRef.getNimi() << ":lle" << endl;
        return true;
    }
    else
        return false;
}
