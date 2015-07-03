#pragma once

#include "level.h"
#include "weaponType.h"

enum UnitType
{
    UnitType_None,
    UnitType_Hero,
    UnitType_Orc,
    UnitType_Skeleton,
    UnitType_Spider
};

const char* UnitName_None     = "None";
const char* UnitName_Hero     = "Hero";
const char* UnitName_Orc      = "Orc";
const char* UnitName_Skeleton = "Skeleton";
const char* UnitName_Spider   = "Spider";

const char* GetUnitName(UnitType type)
{
    switch (type)
    {
    case UnitType_Hero:     return UnitName_Hero;
    case UnitType_Orc:      return UnitName_Orc;
    case UnitType_Skeleton: return UnitName_Skeleton;
    case UnitType_Spider:   return UnitName_Spider;
    }
    return UnitName_None;
}

WeaponType GetUnitDefaultWeapon(UnitType unitType)
{
    switch (unitType)
    {
    case UnitType_Hero:     return WeaponType_Fist;
    case UnitType_Orc:      return WeaponType_Club;
    case UnitType_Skeleton: return WeaponType_Saber;
    case UnitType_Spider:   return WeaponType_Scythe;
    }
    return WeaponType_None;
}

int GetUnitDefaultHealth(UnitType unitType)
{
    switch (unitType)
    {
    case UnitType_Hero:     return 400;
    case UnitType_Orc:      return 60;
    case UnitType_Skeleton: return 80;
    case UnitType_Spider:   return 140;
    }
    return 0;
}

UnitType GetUnitTypeFromSymbol(unsigned char symbol)
{
    switch (symbol)
    {
    case CELL_SYMBOL_HERO:     return UnitType_Hero;
    case CELL_SYMBOL_ORC:      return UnitType_Orc;
    case CELL_SYMBOL_SKELETON: return UnitType_Skeleton;
    case CELL_SYMBOL_SPIDER:   return UnitType_Spider;
    }
    return UnitType_None;
}
