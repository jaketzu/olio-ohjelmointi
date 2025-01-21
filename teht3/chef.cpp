#include <string>
#include <iostream>
#include "chef.h"

using namespace std;

Chef::Chef(string name)
{
    Chef::chefName = name;
    cout << "Chef " << name << " konstruktori" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << Chef::chefName << " destruktori" << endl;
}

string Chef::getName()
{
    return Chef::chefName;
}

int Chef::makeSalad(int ingredientAmount)
{
    int portions = ingredientAmount / 5;
    cout << "Chef " << Chef::chefName << " with " << ingredientAmount << " items can make salad " << portions << " portions" << endl;
    return portions;
}

int Chef::makeSoup(int ingredientAmount)
{
    int portions = ingredientAmount / 3;
    cout << "Chef " << Chef::getName() << " with " << ingredientAmount << " items can make soup " << portions << " portions" << endl;
    return portions;
}
