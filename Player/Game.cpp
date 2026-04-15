#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() 
{
    std::srand(std::time(0));
}

void Game::setup() 
{
    int numPlayers;
    std::cout << "Enter number of players (2-4): ";
    std::cin >> numPlayers;

    while (numPlayers < 2 || numPlayers > 4) 
    {
        std::cout << "Invalid. Enter 2-4 players: ";
        std::cin >> numPlayers;
    }

    for (int i = 0; i < numPlayers; i++) 
    {
        std::string name;
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin >> name;
        players.push_back(Player(name));
    }
}

int Game::rollDice() 
{
    return rand() % 6 + 1;
}

void Game::play() 
{
    bool gameWon = false;

    while (!gameWon) 
    {
        for (auto& player : players) 
        {
            std::cout << "\n" << player.getName() << "'s turn.";
            std::cout << "\nPress enter to roll dice...";
            std::cin.ignore();
            std::cin.get();

            int dice = rollDice();
            std::cout << "Rolled: " << dice << std::endl;

            int newPos = player.getPosition() + dice;

            if (newPos > 100) 
            {
                std::cout << "Need exact roll to reach 100.\n";
                continue;
            }

            player.setPosition(newPos);

            int checkedPos = board.checkPosition(newPos);

            if (checkedPos < newPos) 
            {
                std::cout << "Oh no! Snake! Down to " << checkedPos << "\n";
            }
            else if (checkedPos > newPos) 
            {
                std::cout << "Yay! Ladder! Up to " << checkedPos << "\n";
            }

            player.setPosition(checkedPos);

            std::cout << player.getName() << " is now at "
                << player.getPosition() << "\n";

            if (player.getPosition() == 100) 
            {
                std::cout << "\n🎉 " << player.getName() << " wins!\n";
                gameWon = true;
                break;
            }
        }
    }
}