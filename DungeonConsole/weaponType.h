#pragma once
#include "level.h"

enum WeaponType
{
    WeaponType_None,
    WeaponType_Fist,
    WeaponType_Stick,
    WeaponType_Club,
    WeaponType_Spear,
    WeaponType_Saber,
    WeaponType_Flail,
    WeaponType_Scythe,
    WeaponType_Claimore
};

const char* WeaponName_None     = "None";
const char* WeaponName_Fist     = "Fist";
const char* WeaponName_Stick    = "Stick";
const char* WeaponName_Club     = "Club";
const char* WeaponName_Spear    = "Spear";
const char* WeaponName_Saber    = "Saber";
const char* WeaponName_Flail    = "Flail";
const char* WeaponName_Scythe   = "Scythe";
const char* WeaponName_Claimore = "Claimore";

const char* GetWeaponName(WeaponType type)
{
    switch (type)
    {
    case WeaponType_Fist:     return WeaponName_Fist;
    case WeaponType_Stick:    return WeaponName_Stick;
    case WeaponType_Club:     return WeaponName_Club;
    case WeaponType_Spear:    return WeaponName_Spear;
    case WeaponType_Saber:    return WeaponName_Saber;
    case WeaponType_Flail:    return WeaponName_Flail;
    case WeaponType_Scythe:   return WeaponName_Scythe;
    case WeaponType_Claimore: return WeaponName_Claimore;
    default: return WeaponName_None;
    }
}

int GetWeaponDamage(WeaponType type)
{
    switch (type)
    {
    case WeaponType_Fist:     return 2;
    case WeaponType_Stick:    return 16;
    case WeaponType_Club:     return 24;
    case WeaponType_Spear:    return 32;
    case WeaponType_Saber:    return 40;
    case WeaponType_Flail:    return 48;
    case WeaponType_Scythe:   return 60;
    case WeaponType_Claimore: return 100;
    }
    return 0;
}

WeaponType GetWeaponTypeBySymbol(unsigned char symbol)
{
    switch (symbol)
    {
    case CELL_SYMBOL_STICK:    return WeaponType_Stick;
    case CELL_SYMBOL_CLUB:     return WeaponType_Club;
    case CELL_SYMBOL_SPEAR:    return WeaponType_Spear;
    case CELL_SYMBOL_SABER:    return WeaponType_Saber;
    case CELL_SYMBOL_FLAIL:    return WeaponType_Flail;
    case CELL_SYMBOL_SCYTHE:   return WeaponType_Scythe;
    case CELL_SYMBOL_CLAIMORE: return WeaponType_Claimore;
    }
    return WeaponType_None;
}
