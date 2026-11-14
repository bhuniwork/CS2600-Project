#ifndef ITEMS
#define ITEMS

// Weapon struct
typedef struct
{
    bool damageType;            // Melee or Ranged
    float damage;               // how much flat damage does this weapon do?
    int cooldown;               // in turns
    float criticalChance;       // base critical chance inherent to the weapon
    bool trueDamageType;        // What kind of true damage? T - flat amount, F - percent multiplier
    float trueDamage;           // How much true damage (ignores buffs) to do
} Weapon;

// Healing Item struct
typedef struct
{
    bool healOverTime;          // does this item heal over time? T/F
    double healingAmount;        // flat healing amount, to be modified by buffs
    int duration;               // in turns
} HealingItem;

// Buffing Item struct
typedef struct
{
    int buffType;               // buff is additive or multiplicative
    double damageBuff;           // damage buff by how much
    double healingBuff;          // healing buff by how much
    int duration;               // in turns
} BuffingItem;

typedef struct
{
    // Weapon items
    Weapon weapon;

    // Healing items
    HealingItem healingItem;

    // Buffing items
    BuffingItem buffingItem;

    // general attributes
    char name[100];             // name of weapon/item
} Items;

void randomWeaponName(int weaponType, char *out, size_t size);

Items getRandomItem();

#endif