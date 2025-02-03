#include "notifikaattori.h"

Notifikaattori::Notifikaattori()
{
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *seuraaja)
{
    seuraaja->next = Notifikaattori::seuraajat;
    Notifikaattori::seuraajat = seuraaja;

    cout << "Notifikaattori lisää seuraajan " << seuraaja->getNimi() << endl;
}

void Notifikaattori::poista(Seuraaja *seuraaja)
{
    Seuraaja *ptr = Notifikaattori::seuraajat;
    while(ptr != nullptr)
    {
        if(ptr->next == seuraaja)
        {
            cout << "Notifikaattori poistaa seuraajan " << ptr->next->getNimi() << endl;
            ptr->next = ptr->next->next;
        }

        ptr = ptr->next;
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja *ptr = Notifikaattori::seuraajat;
    while(ptr != nullptr)
    {
        cout << ptr->getNimi() << endl;
        ptr = ptr->next;
    }
}

void Notifikaattori::postita(string message)
{
    cout << "Notifikaattori postaa viestin " << message << endl;
    Seuraaja *ptr = Notifikaattori::seuraajat;
    while(ptr != nullptr)
    {
        ptr->paivitys(message);
        ptr = ptr->next;
    }
}
