#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define possible classes with enum and an array to map enum values to class names as strings
typedef enum { Warrior, Mage, Ranger, Paladin, Barbarian } Class;
const char *classNames[] = { "Warrior", "Mage", "Ranger", "Paladin", "Barbarian" };

// Define struct for characters
typedef struct {
    Class characterClass;
    int hp;
    int attack;
    int defense;
    int specialPercentage;
} Character;

// Function to determine the attacker
Character* getAttacker(Character party[], int partySize) {
    Character *attacker = &party[0];  // Assume the first character is the best candidate

    for (int i = 1; i < partySize; i++) {
        // Compare initiative ratio (HP / Attack)
        double currentRatio = (double)party[i].hp / party[i].attack;
        double bestRatio = (double)attacker->hp / attacker->attack;

        if (currentRatio > bestRatio) {
            attacker = &party[i];
        }
    }
    return attacker;
}

// Function to get a random opponent from another party
Character* getRandomOpponent(Character party[], int partySize) {
    return &party[rand() % partySize];  // Randomly selects an opponent
}

// Function to execute combat
void performAttack(Character *attacker, Character *defender) {
    int damage = attacker->attack - defender->defense;
    if (damage < 0) damage = 1;  // Ensure a minimum of 1 damage
    defender->hp -= damage;

    printf("%s attacks %s for %d damage!\n", 
        classNames[attacker->characterClass], 
        classNames[defender->characterClass], 
        damage);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int seed = rand() % 100;

    // Instantiate characters
    Character warrior = {Warrior, 100, 20, 10, 20};
    Character mage = {Mage, 100, 30, 5, 25};
    Character ranger = {Ranger, 100, 18, 8, 15};
    Character paladin = {Paladin, 100, 15, 12, 30};
    Character barbarian = {Barbarian, 100, 25, 6, 100};

    // Allocate characters into two parties
    Character partyOne[5] = {warrior, mage, ranger, paladin, barbarian};
    int partyOneLength = sizeof(partyOne) / sizeof(partyOne[0]);

    Character partyTwo[5] = {warrior, mage, ranger, paladin, barbarian};
    int partyTwoLength = sizeof(partyTwo) / sizeof(partyTwo[0]);

    // First encounter
    Character *attacker = getAttacker(partyOne, partyOneLength);
    Character *opponent = getRandomOpponent(partyTwo, partyTwoLength);

    performAttack(attacker, opponent);

    return 0;
}
