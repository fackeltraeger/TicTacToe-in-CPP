#pragma once

#include <iostream>
#include <vector>

using std::cout, std::vector, std::cin, std::endl;


vector<vector<char>> vec{ {'1','2','3'},{'4','5','6'},{'7','8','9'} };

int g_IntCurrentPlayer = -1;
char g_ChCurrentMarker;
int g_boardLopper = 0;
int g_IntPlyerWon = 0;
