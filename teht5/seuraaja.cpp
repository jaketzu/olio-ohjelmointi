#include "seuraaja.h"

Seuraaja::Seuraaja(string name): nimi(name)
{
    cout << "Luodaan seuraaja " << Seuraaja::getNimi() << endl;
}

string Seuraaja::getNimi()
{
    return Seuraaja::nimi;
}

void Seuraaja::paivitys(string message)
{
    cout << "Seuraaja " << Seuraaja::getNimi() << " sai viestin " << message << endl;
}
