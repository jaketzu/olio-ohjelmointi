#include <string>
#include <iostream>
#include "italianchef.h"

using namespace std;

ItalianChef::ItalianChef(string name):Chef(name)
{
    ItalianChef::chefName = name;
    cout << "ItalianChef " << ItalianChef::getName() << " konstruktori" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef " << ItalianChef::getName() << " destruktori" << endl;
}

bool ItalianChef::askSecret(string password, int flour, int water)
{
    if(password != ItalianChef::password)
        return false;
    else
    {
        cout << "Password ok!" << endl;
        ItalianChef::makePizza(flour, water);
        return true;
    }
}

int ItalianChef::makePizza(int flourAmount, int waterAmount)
{
    int flourPortions = flourAmount / 5;
    int waterPortions = waterAmount / 5;
    int portions = min(flourPortions, waterPortions);
    cout << "Chef " << Chef::getName() << " with " << flourAmount << " flour and " << waterAmount << " water can make " << portions << " pizzas" << endl;
    return portions;
}
