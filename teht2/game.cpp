#include <iostream>
#include "game.h"

using namespace std;

Game::Game(int max) {
    srand(time(NULL));

    maxNumber = max;
    playerGuess = -1;
    randomNumber = 0;
    numOfGuesses = 0;

    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
}

Game::~Game() {
    cout << "GAME DECONSTRUCTOR: object cleared from stack memory";
}

void Game::play() {
    playerGuess = -1;
    numOfGuesses = 0;
    randomNumber = rand() % maxNumber + 1;

    while (playerGuess != randomNumber) {
        numOfGuesses++;

        cout << "Give your guess between 1 and " << maxNumber << endl;
        cin >> playerGuess;

        if(playerGuess != randomNumber) {
            if(playerGuess < randomNumber)
                cout << "Your guess is too small" << endl;
            else
                cout << "Your guess is too big" << endl;
        }
        else
            printGameResult();
    }
}

void Game::printGameResult() {
    cout << "Your guess is right = " << randomNumber << endl;
    cout << "You guessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses" << endl;
}
