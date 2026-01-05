#pragma once

#include <iostream>
#include <vector>

using std::cout, std::vector, std::cin, std::endl;


vector<vector<char>> vec{ {'1','2','3'},{'4','5','6'},{'7','8','9'} };

int g_IntCurrentPlayer = -1;
char g_ChCurrentMarker;
int g_boardLopper = 0;
int g_IntPlyerWon = 0;


void displayOnScreen()
{
    cout << "-----------" << endl;
    for (auto& i : vec)
    {
        cout << " " << i[0] << " | " << i[1] << " | " << i[2] << endl;
        g_boardLopper++;
        if (g_boardLopper < 3)
            cout << " - | - | - " << endl;
        else
            g_boardLopper = 0;
    }
    cout << "-----------" << endl;
}

bool isNotOccupied(int& IntVal)
{
    int row = (IntVal - 1) / 3;
    int col = (IntVal - 1) % 3;

    if ((vec[row][col] == 'O' || vec[row][col] == 'X'))
        return false;
    else
    {
        vec[row][col] = g_ChCurrentMarker; // if not occupied place the value to it.
        return true;
    }
}

int bCheckWinner()
{
    for (size_t i = 0; i < 3; i++)
    {
        if ((vec[0][i] == vec[1][i] && vec[1][i] == vec[2][i]) || (vec[i][0] == vec[i][1] && vec[i][1] == vec[i][2]))
            return g_IntCurrentPlayer;
    }
    if (vec[0][0] == vec[1][1] && vec[1][1] == vec[2][2])
        return g_IntCurrentPlayer;
    else if (vec[2][0] == vec[1][1] && vec[1][1] == vec[0][2])
        return g_IntCurrentPlayer;
    else
        return -1;
}
