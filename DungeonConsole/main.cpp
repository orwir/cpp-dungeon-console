#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>

#include "consoleColor.h"
#include "level.h"
#include "weaponType.h"
#include "unitType.h"
#include "unitData.h"

//////////////////////////////////
//constants
const int MAX_UNITS_COUNT = 35;

//Logic variables
HANDLE consoleHandle = 0;
bool isGameActive = true;
unsigned char levelData[HEIGHT][WIDTH];
UnitData unitsData[MAX_UNITS_COUNT];
int unitsCount = 0;
int heroIndex = 0;

void SetupSystem()
{
    srand(time(0));

    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void Initialize()
{
    unitsCount = 0;

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            unsigned char symbol = LEVEL_DATA_O[y][x];
            levelData[y][x] = symbol;
            switch (symbol)
            {
            case CELL_SYMBOL_HERO:
                heroIndex = unitsCount;
            case CELL_SYMBOL_ORC:
            case CELL_SYMBOL_SKELETON:
                UnitType unit = GetUnitTypeFromSymbol(symbol);
                unitsData[unitsCount].type = unit;
                unitsData[unitsCount].x = x;
                unitsData[unitsCount].y = y;
                unitsData[unitsCount].health = GetUnitDefaultHealth(unit);
                unitsData[unitsCount].weapon = GetUnitDefaultWeapon(unit);
                unitsCount++;
                break;
            }
        }
    }
}

void Render()
{
    COORD cursorCoord;
    cursorCoord.X = 0;
    cursorCoord.Y = 0;
    SetConsoleCursorPosition(consoleHandle, cursorCoord);

    SetConsoleTextAttribute(consoleHandle, ConsoleColor_Green);
    printf("\n\tDUNGEONS & ORCS");

    SetConsoleTextAttribute(consoleHandle, ConsoleColor_Red);
    printf("\n\n\tHP: ");
    SetConsoleTextAttribute(consoleHandle, ConsoleColor_White);
    printf("%i      ", unitsData[heroIndex].health);

    printf("\n\n\t");
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            unsigned char symbol = levelData[y][x];
            unsigned char renderSymbol = GetRenderCellSymbol(symbol);
            ConsoleColor color = GetRenderCellSymbolColor(symbol);
            SetConsoleTextAttribute(consoleHandle, color);
            printf("%c", renderSymbol);
        }
        printf("\n\t");
    }
}

void MoveUnitTo(UnitData* unit, int x, int y)
{
    if (unit->health <= 0)
    {
        return;
    }

    unsigned char unitSymbol = levelData[unit->y][unit->x];
    unsigned char destinationSymbol = levelData[y][x];
    bool canMove = false;

    switch (destinationSymbol)
    {
    case CELL_SYMBOL_EMPTY:
        canMove = true;
        break;
    case CELL_SYMBOL_HERO:
    case CELL_SYMBOL_ORC:
    case CELL_SYMBOL_SKELETON:
        UnitType destinationType = GetUnitTypeFromSymbol(destinationSymbol);
        if (unit->type != destinationType)
        {
            for (int u = 0; u < unitsCount; u++)
            {
                if (unitsData[u].health <= 0)
                {
                    continue;
                }

                if (unitsData[u].x == x && unitsData[u].y == y)
                {
                    int damage = GetWeaponDamage(unit->weapon);
                    unitsData[u].health -= damage;
                    if (unitsData[u].health <= 0)
                    {
                        levelData[y][x] = CELL_SYMBOL_EMPTY;
                        canMove = true;
                    }
                }
            }
        }
        break;
    }

    if (unit->type == UnitType_Hero)
    {
        switch (destinationSymbol)
        {
        case CELL_SYMBOL_STICK:
        case CELL_SYMBOL_CLUB:
        case CELL_SYMBOL_SPEAR:
        case CELL_SYMBOL_SABER:
        {
            canMove = true;
            WeaponType weapon = GetWeaponTypeBySymbol(destinationSymbol);
            if (unitsData[heroIndex].weapon < weapon)
            {
                unitsData[heroIndex].weapon = weapon;
            }
            break;
        }
        case CELL_SYMBOL_EXIT:
            isGameActive = false;
            break;
        }
    }

    if (canMove)
    {
        levelData[unit->y][unit->x] = CELL_SYMBOL_EMPTY;
        unit->x = x;
        unit->y = y;
        levelData[unit->y][unit->x] = unitSymbol;
    }
}

void UpdateAI()
{
    for (int u = 0; u < MAX_UNITS_COUNT; u++)
    {
        if (u == heroIndex || unitsData[u].health <= 0)
        {
            continue;
        }

        int distanceToHeroX = abs(unitsData[u].x - unitsData[heroIndex].x);
        int distanceToHeroY = abs(unitsData[u].y - unitsData[heroIndex].y);

        if (distanceToHeroX + distanceToHeroY == 1)
        {
            MoveUnitTo(&unitsData[u], unitsData[heroIndex].x, unitsData[heroIndex].y);
        }
        else
        {
            switch (rand() % 4)
            {
            case 0:
                MoveUnitTo(&unitsData[u], unitsData[u].x, unitsData[u].y - 1);
                break;
            case 1:
                MoveUnitTo(&unitsData[u], unitsData[u].x - 1, unitsData[u].y);
                break;
            case 2:
                MoveUnitTo(&unitsData[u], unitsData[u].x, unitsData[u].y + 1);
                break;
            case 3:
                MoveUnitTo(&unitsData[u], unitsData[u].x + 1, unitsData[u].y);
                break;
            }
        }
    }
}

void Update()
{
    unsigned char input = tolower(_getch());

    switch (input)
    {
    case 'w':
        MoveUnitTo(&unitsData[heroIndex], unitsData[heroIndex].x, unitsData[heroIndex].y - 1);
        break;
    case 'a':
        MoveUnitTo(&unitsData[heroIndex], unitsData[heroIndex].x - 1, unitsData[heroIndex].y);
        break;
    case 's':
        MoveUnitTo(&unitsData[heroIndex], unitsData[heroIndex].x, unitsData[heroIndex].y + 1);
        break;
    case 'd':
        MoveUnitTo(&unitsData[heroIndex], unitsData[heroIndex].x + 1, unitsData[heroIndex].y);
        break;
    case 'r':
        Initialize();
        break;
    }
    UpdateAI();
    if (unitsData[heroIndex].health <= 0)
    {
        isGameActive = false;
    }
    else if (unitsData[heroIndex].health < GetUnitDefaultHealth(unitsData[heroIndex].type))
    {
        unitsData[heroIndex].health++;
    }
}

void Shutdown()
{
    system("cls");
    printf("\n\tGame over...");
    _getch();
}

void main()
{
    SetupSystem();
    Initialize();

    do
    {
        Render();
        Update();
    } while (isGameActive);

    Shutdown();
}
