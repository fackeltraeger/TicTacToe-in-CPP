
#include "pch.h"

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

void start()
{
    char markerP1;
    cout << "Player1 choose ur marker : like 'X or O' : ";
    cin >> markerP1;

    g_IntCurrentPlayer = 1;
    g_ChCurrentMarker = markerP1;

    displayOnScreen();

    for (size_t i = 0; i < 9; i++)
    {
        int slotVal = 0;
        cout << "it's player " << g_IntCurrentPlayer << "'s chance please select the from the vacent slot : ";
        cin >> slotVal;

        if (slotVal < 1 || slotVal > 9)
        {
            cout << "Invalid Slot value selected, please try again.";
            i--;
            continue;
        }
        else if (false == isNotOccupied(slotVal))
        {
            cout << "Slot is already occupied try again";
            i--;
            continue;
        }

        displayOnScreen();

        if (-1 != bCheckWinner())
        {
            cout << endl << "player" << g_IntCurrentPlayer << " won" << endl;
            break;
        }
        cout << endl;

        g_IntCurrentPlayer = (g_IntCurrentPlayer == 1) ? 2 : 1;
        g_ChCurrentMarker = (g_ChCurrentMarker == 'X') ? 'O' : 'X';

    }
}

int main()
{
    start();
    return 0;
}