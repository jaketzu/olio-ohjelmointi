#include <iostream>

#include "pankkitili.h"

Pankkitili::Pankkitili(string o): omistaja(o)
{
    cout << "Pankkitili luotu " << Pankkitili::omistaja << ":lle " << endl;
}

double Pankkitili::getBalance()
{
    return Pankkitili::saldo;
}

bool Pankkitili::deposit(double amount)
{
    if(amount > 0)
    {
        Pankkitili::saldo += amount;
        cout << Pankkitili::omistaja << " Pankkitili: talletus " << amount << " tehty" << endl;
        return true;
    }
    else
        return false;
}

bool Pankkitili::withdraw(double amount)
{
    if(amount > 0 && Pankkitili::saldo - amount >= 0)
    {
        Pankkitili::saldo -= amount;
        cout << Pankkitili::omistaja << " Pankkitili: nosto " << amount << " tehty" << endl;
        return true;
    }
    else
        return false;
}
