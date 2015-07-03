#pragma once
#include "level.h"

enum WeaponType
{
    WeaponType_None,
    WeaponType_Fist,
    WeaponType_Stick,
    WeaponType_Club,
    WeaponType_Spear,
    WeaponType_Saber
};

const char* WeaponName_None  = "None";
const char* WeaponName_Fist  = "Fist";
const char* WeaponName_Stick = "Stick";
const char* WeaponName_Club  = "Club";
const char* WeaponName_Spear = "Spear";
const char* WeaponName_Saber = "Saber";

const char* GetWeaponName(WeaponType type)
{
    switch (type)
    {
    case WeaponType_Fist:  return WeaponName_Fist;
    case WeaponType_Stick: return WeaponName_Stick;
    case WeaponType_Club:  return WeaponName_Club;
    case WeaponType_Spear: return WeaponName_Spear;
    case WeaponType_Saber: return WeaponName_Saber;
    default: return WeaponName_None;
    }
}

int GetWeaponDamage(WeaponType type)
{
    switch (type)
    {
    case WeaponType_Fist: return 2;
    case WeaponType_Stick: return 16;
    case WeaponType_Club: return 24;
    case WeaponType_Spear: return 32;
    case WeaponType_Saber: return 40;
    }
    return 0;
}

WeaponType GetWeaponTypeBySymbol(unsigned char symbol)
{
    switch (symbol)
    {
    case CELL_SYMBOL_STICK: return WeaponType_Stick;
    case CELL_SYMBOL_CLUB:  return WeaponType_Club;
    case CELL_SYMBOL_SPEAR: return WeaponType_Spear;
    case CELL_SYMBOL_SABER: return WeaponType_Saber;
    }
    return WeaponType_None;
}
