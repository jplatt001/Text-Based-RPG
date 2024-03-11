#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "combatgame.h"
using namespace std;

bool CombatGame(int weapon)
{
    int x;
    int y;
    int number = rand() % weapon + 1;
    int guess;
    int protectX;
    int protectY;
    int skull = -1;
    vector<int> memory(9);
    int m = -1;
    bool lose = false;
    int i;
    int rounds = 1;

    cout << "Welcome to tic-tac-toe combat!" << endl;
    cout << "Guess the secret number to block your opponent's attacks." << endl;
    cout << "You cannot block a tile with a skull already on it." << endl;
    cout << "The number only changes after you guess correctly so remember your guesses!" << endl;
    cout << "Prevent your opponent from getting 3 skulls in a row to survive." << endl;
    cout << "Getting 3 of your own pieces in a row will serve you no purpose." << endl;
    cout << "The only way to win is by surving all 9 rounds!" << endl;
    cout << "Good luck!" << endl;
    cout << endl;

    cout << "  1 2 3" << endl;
    cout << "1 ❤️ ❤️ ❤️ " << endl;
    cout << "2 ❤️ ❤️ ❤️ " << endl;
    cout << "3 ❤️ ❤️ ❤️ " << endl;
    cout << endl;

    while (lose == false)
    {
        cout << "~~~ Round " << rounds << " ~~~" << endl;
        cout << "Enter your guess between 1 and " << weapon << ": " << endl;
        cin >> guess;
        if (guess == number)
        {
            number = rand() % weapon + 1;
            cout << "Nice job! Enter the coordinates of the square you would like to protect: " << endl;
            cout << "X coordinate: " << endl;
            cin >> protectX;
            cout << "Y coordinate: " << endl;
            cin >> protectY;
        }
        else
        {
            cout << "Oh no, look out!" << endl;
            skull = rand() % 9;
            while (memory.at(skull) == 2 || memory.at(skull) == 1)
                skull = rand() % 9;
        }
        m = -1;
        cout << "    1  2  3" << endl;
        for (y = 1; y <= 3; ++y)
        {
            cout << y << " ";
            for (x = 1; x <= 3; ++x)
            {
                ++m;
                if (((x == protectX && y == protectY) || (memory.at(m) == 1)) && memory.at(m) != 2)
                {
                    cout << " 👼 ";
                    memory.at(m) = 1;
                }
                else
                {
                    if ((skull == m || memory.at(m) == 2) && memory.at(m) != 1)
                    {
                        cout << " 💀️ ";
                        memory.at(m) = 2;
                    }
                    else
                    {
                        cout << " ❤️ ";
                    }
                }
            }
            cout << endl;
        }
        // testing loss conditions------------------------------------------
        if (memory.at(0) == 2 && memory.at(1) == 2 && memory.at(2) == 2)
        {
            // first row
            lose = true;
        }
        else if (memory.at(3) == 2 && memory.at(4) == 2 && memory.at(5) == 2)
        {
            // second row
            lose = true;
        }

        else if (memory.at(6) == 2 && memory.at(7) == 2 && memory.at(8) == 2)
        {
            // third row
            lose = true;
        }

        else if (memory.at(0) == 2 && memory.at(3) == 2 && memory.at(6) == 2)
        {
            // first column
            lose = true;
        }
        else if (memory.at(1) == 2 && memory.at(4) == 2 && memory.at(7) == 2)
        {
            // second column
            lose = true;
        }
        else if (memory.at(2) == 2 && memory.at(5) == 2 && memory.at(8) == 2)
        {
            // third column
            lose = true;
        }
        else if (memory.at(0) == 2 && memory.at(4) == 2 && memory.at(8) == 2)
        {
            // negative diagonal
            lose = true;
        }
        else if (memory.at(2) == 2 && memory.at(4) == 2 && memory.at(6) == 2)
        {
            // positive diagonal
            lose = true;
        }
        if (lose == true)
        {
            cout << "No! Another soul claimed by the Demon King... " << endl;
            // RESET MEMORY
            for (i = 0; i < 9; ++i)
                memory.at(i) = 0;
        }
        ++rounds;
        cout << endl;
        // testing win condition----------------------------------------------
        if (rounds == 10)
        {
            if (lose == false)
            {
                cout << "You've survived! Excellent fighting!" << endl;
            }
            break;
        }
    }
    return (lose);
}
