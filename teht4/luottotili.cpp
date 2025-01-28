#include <iostream>

#include "luottotili.h"

Luottotili::Luottotili(string o, double l): Pankkitili(o), luottoraja(l)
{
    Luottotili::saldo = Luottotili::luottoraja;
    cout << "Luottotili luotu " << Luottotili::omistaja << ":lle, luottoraja " << Luottotili::luottoraja << endl;
}

bool Luottotili::deposit(double amount)
{
    if(amount > 0 && Luottotili::saldo + amount <= Luottotili::luottoraja)
    {
        Luottotili::saldo += amount;
        cout << Luottotili::omistaja << " Luottotili: talletus " << amount << " tehty" << endl;
        return true;
    }
    else
        return false;
}

bool Luottotili::withdraw(double amount)
{
    if(amount > 0 && Luottotili::saldo - amount >= 0)
    {
        Luottotili::saldo -= amount;
        cout << Luottotili::omistaja << " Luottotili: nosto " << amount << " tehty, luottoa jäljellä " << Luottotili::getBalance() << endl;
        return true;
    }
    else
        return false;
}
