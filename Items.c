#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Items.h"

#include <time.h>

// Generate weapon name in format: prefix - weapon - suffix
void randomWeaponName(int weaponType, char *out, size_t size)
{
    // prefix
    char *prefix[] = {
        "Amazing ",
        "Awesome ",
        "Epic ",
        "Diabolical ",
        "Mythical "
    };

    char* randomPrefix = prefix[rand() % 5];

    // weapon types
    char *meleeWeapon[] = {
        "Machete ",
        "Blade ",
        "Sword ",
        "Claymore ",
        "Hatchet "
    };

    char *rangedWeapon[] = {
        "Bow ",
        "Staff ",
        "Crossbow ",
        "Javelin ",
        "Throwing Axe "
    };

    // choosing an appropriate weapon name for the weapon type
    char *randomWeapon;
    if (weaponType == 1)
    {
        randomWeapon = meleeWeapon[rand() % 5];
    } else
    {
        randomWeapon = rangedWeapon[rand() % 5];
    }

    // suffix
    char *suffix[] = {
        "of Death",
        "of Destruction",
        "of Annihilation",
        "of Doom",
        "of Insanity"
    };

    char* randomSuffix = suffix[rand() % 5];

    snprintf(out, size, "%s%s%s", randomPrefix, randomWeapon, randomSuffix);
}

// get random item for character SUBJECT TO CHANGE
Items getRandomItem()
{
    int choice = rand() % 3;        // MODIFY THIS TO CHANGE DROP CHANCES
    int item = rand() % 5;

    // List of healing items
    Items healingItems[5] = {
        {{}, {false, 20, 1}, {}, "Fizzy Pop"},            // Fizzy Pop
        {{}, {true, 5, 5}, {}, "Suspicious Slop"},        // Suspicious Slop
        {{}, {false, 50, 1}, {},  "Gummy Bears"},         // Gummy Bears
        {{}, {true, -10, 3}, {}, "Radioactive Sludge"},   // Radioactive Sludge
        {{}, {false, 30, 1}, {}, "Stale Crackers"}        // Stale Crackers
    };

    // List of buffing items
    Items buffingItems[5] = {
        {{}, {}, {1, 0, 30, 3}, "HealUp"},            // HealUp
        {{}, {}, {2, 0.5, 0, 2}, "Punchdown Punch"},  // Punchdown Punch
        {{}, {}, {1, 10, 10, 3}, "Envigor-Aid"},      // Envigor-Aid
        {{}, {}, {2, 0, 0.25, 5}, "Herbal Salve"},    // Herbal Salve
        {{}, {}, {2, 0.2, 0.2, 4}, "Ranch"}           // Ranch
    };

    if (choice == 0)
    {
        return healingItems[item];
    }

    if (choice == 1)
    {
        return buffingItems[item];
    }

    if (choice == 2)
    {
        bool weaponType = rand() % 2;
        Weapon newWeapon = {weaponType, rand() % 20 + 10, rand() % 2, rand() % 10, false, 0};
        Items newItem = {newWeapon, {}, {}, ""};
        randomWeaponName(weaponType, newItem.name, sizeof(newItem.name));
        return newItem;
    }

    return healingItems[item];
}


