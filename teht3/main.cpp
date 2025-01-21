#include <iostream>
#include <chef.h>
#include <italianchef.h>

using namespace std;

int main()
{
    Chef chef("Gordon");

    chef.makeSalad(11);
    chef.makeSoup(14);

    ItalianChef italianChef("Mario");
    italianChef.makeSalad(9);
    italianChef.askSecret("pizza", 12, 12);

    return 0;
}
