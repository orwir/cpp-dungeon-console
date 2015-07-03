#pragma once

#include "consoleColor.h"

const int WIDTH = 35;
const int HEIGHT = 15;

const unsigned char CELL_SYMBOL_EMPTY    = ' ';
const unsigned char CELL_SYMBOL_WALL     = '#';
const unsigned char CELL_SYMBOL_HERO     = 'h';
const unsigned char CELL_SYMBOL_EXIT     = 'e';
const unsigned char CELL_SYMBOL_ORC      = 'o';
const unsigned char CELL_SYMBOL_SKELETON = 's';
const unsigned char CELL_SYMBOL_STICK    = '1';
const unsigned char CELL_SYMBOL_CLUB     = '2';
const unsigned char CELL_SYMBOL_SPEAR    = '3';
const unsigned char CELL_SYMBOL_SABER    = '4';
const unsigned char CELL_SYMBOL_FLAIL    = '5';
const unsigned char CELL_SYMBOL_SCYTHE   = '6';
const unsigned char CELL_SYMBOL_CLAIMORE = '7';
const unsigned char CELL_SYMBOL_FOG      = 'f';
const unsigned char CELL_SYMBOL_SPIDER   = 'a';

const unsigned char LEVEL_DATA_O[HEIGHT][WIDTH + 1] =
{
    "###################################",
    "#   # ##      o           s       #",
    "# # o  #o############## ######### #",
    "# ###### #   # #3  s  # ##s##   # #",
    "#  s       # # ###### # #s4   #s# #",
    "###### # ### #      # # ##s##   # #",
    "##  o# # # # #### # #   ##### # # #",
    "#  #   # # o    # ## ######s#   # #",
    "######## # ####         #   # # #s#",
    "#  2#    #      ####### # # #   # #",
    "# ### #### ######   o   # #   #   #",
    "#  o       #      ####### #########",
    "############ ######   #1# # s #   #",
    "#h                  #   #   #s  # #",
    "#################################e#"
};


unsigned char GetRenderCellSymbol(unsigned char cellSymbol)
{
    switch (cellSymbol)
    {
    case CELL_SYMBOL_EMPTY:    return ' ';
    case CELL_SYMBOL_WALL:     return 177;
    case CELL_SYMBOL_HERO:     return 2;
    case CELL_SYMBOL_ORC:      return 2;
    case CELL_SYMBOL_SKELETON: return 2;
    case CELL_SYMBOL_STICK:    return 47;
    case CELL_SYMBOL_CLUB:     return 33;
    case CELL_SYMBOL_SPEAR:    return 24;
    case CELL_SYMBOL_SABER:    return 108;
    case CELL_SYMBOL_FLAIL:    return 64;
    case CELL_SYMBOL_SCYTHE:   return 251;
    case CELL_SYMBOL_CLAIMORE: return 197;
    case CELL_SYMBOL_EXIT:     return 178;
    case CELL_SYMBOL_FOG:      return 176;
    case CELL_SYMBOL_SPIDER:   return 190;
    }
}

ConsoleColor GetRenderCellSymbolColor(unsigned char cellSymbol)
{
    switch (cellSymbol)
    {
    case CELL_SYMBOL_EMPTY:    return ConsoleColor_Black;
    case CELL_SYMBOL_WALL:     return ConsoleColor_White;
    case CELL_SYMBOL_HERO:     return ConsoleColor_Yellow;
    case CELL_SYMBOL_ORC:      return ConsoleColor_Green;
    case CELL_SYMBOL_SKELETON: return ConsoleColor_White;
    case CELL_SYMBOL_STICK:    return ConsoleColor_DarkYellow;
    case CELL_SYMBOL_CLUB:     return ConsoleColor_DarkRed;
    case CELL_SYMBOL_SPEAR:    return ConsoleColor_DarkCyan;
    case CELL_SYMBOL_SABER:    return ConsoleColor_Cyan;
    case CELL_SYMBOL_FLAIL:    return ConsoleColor_DarkBlue;
    case CELL_SYMBOL_SCYTHE:   return ConsoleColor_Blue;
    case CELL_SYMBOL_CLAIMORE: return ConsoleColor_Magenta;
    case CELL_SYMBOL_EXIT:     return ConsoleColor_DarkRed;
    case CELL_SYMBOL_FOG:      return ConsoleColor_Grey;
    case CELL_SYMBOL_SPIDER:   return ConsoleColor_DarkGrey;
    }
}
