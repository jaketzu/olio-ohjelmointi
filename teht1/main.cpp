#include <iostream>

using namespace std;

int game(int maxnum);

int main()
{
    srand(time(NULL));

    while(true) {
        int guesses = game(20);

        cout << "Voitit " << guesses << " arvauksella!" << endl;
    }

    return 0;
}

int game(int maxnum) {
    int guesses = 0;
    int randomInt = rand() % maxnum + 1;
    int guess = -1;

    while (guess != randomInt) {
        guesses++;

        cout << "Arvaa luku väliltä 1 - " << maxnum << endl;
        cin >> guess;

        if(guess != randomInt) {
            cout << "Väärin! ";
            if(guess < randomInt)
                cout << "Luku on suurempi." << endl;
            else
                cout << "Luku on pienempi." << endl;
        }
        else
            cout << "Oikein!" << endl;
    }

    return guesses;
}
