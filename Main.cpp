#include "pch.h"

void start()
{
    while (true)
    {
        g_ChCurrentMarker = '_';
        cout << "Player1 choose ur marker : like 'X or O' : ";
        cin >> g_ChCurrentMarker;
        bool bWinner = false;

        g_IntCurrentPlayer = 1;
        g_ChCurrentMarker = toupper(g_ChCurrentMarker);

        if (g_ChCurrentMarker != 'O' && g_ChCurrentMarker != 'X')
        {
            cout << "\nwrong selection, please select proper option\n";
            continue;
        }

        displayOnScreen();
        cout << endl;

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
                bWinner = true;
                break;
            }
            cout << endl;

            g_IntCurrentPlayer = (g_IntCurrentPlayer == 1) ? 2 : 1;
            g_ChCurrentMarker = (g_ChCurrentMarker == 'X') ? 'O' : 'X';

        }
        if (false == bWinner)
            cout << "the game is tie" << endl;

        while (true)
        {
            char playcheck = '_';
            cout << "Continue to play? (y/n): ";
            cin >> playcheck;
            playcheck = tolower(playcheck);
            if (playcheck == 'y')
                break;
            else if (playcheck == 'n')
                return;
            else
                cout << "\nselect proper option\n";
        }

        vec = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
        cout << endl;
    }
    return;
}

int main()
{
    start();
    return 0;
}