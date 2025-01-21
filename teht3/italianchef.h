#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include <string>
#include "chef.h"

class ItalianChef : public Chef
{
public:
    ItalianChef(string);
    ~ItalianChef();

    bool askSecret(string, int, int);

private:
    int makePizza(int, int);

    string password = "pizza";
    int flour;
    int water;
};

#endif // ITALIANCHEF_H
