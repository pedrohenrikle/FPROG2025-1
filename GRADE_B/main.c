#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define possible classes and an array to map them to strings.
typedef enum { Warrior, Mage, Ranger, Paladin, Barbarian } Class;
const char *classNames[] = { "Warrior", "Mage", "Ranger", "Paladin", "Barbarian" };

typedef struct {
    Class characterClass;
    int hp;
    int attack;
    int defense;
    int specialPercentage; // Determines the chance (percentage) to trigger the special.
} Character;

// Function to execute a combat attack using specific modifiers from classes.
void performAttack(Character *attacker, Character *defender) {
    // Generate a random number [0,100] to determine miss/defense failure.
    int chance = rand() % 101;
    int damage = 0;
    
    // Generic attack print-out.
    printf(">> %s (HP: %d) attacks %s (HP: %d)\n", 
           classNames[attacker->characterClass], attacker->hp, 
           classNames[defender->characterClass], defender->hp);

    // Barbarian never misses.
    if (attacker->characterClass == Barbarian) {
        printf("-> A Barbarian never misses an attack!\n");
        damage = attacker->attack;
    } else {
        // 20% chance to completely miss the attack.
        if (chance < 20) {
            printf("-> Oh no! %s missed the attack on %s...\n", 
                   classNames[attacker->characterClass], classNames[defender->characterClass]);
            return;
        }
        
        // 20% chance that the defender completely fails to block.
        if (chance < 40) {
            printf("-> %s failed to defend against %s's attack!\n",
                   classNames[defender->characterClass], classNames[attacker->characterClass]);
            damage = attacker->attack;  // Full damage, ignoring defense.
        } else {
            damage = attacker->attack - defender->defense;
            if (damage < 0)
                damage = 0;
        }
        
        // Special ability modifiers based on the attacker's class.
        switch (attacker->characterClass) {
            case Warrior:
                if (rand() % 100 < attacker->specialPercentage) {
                    printf("-> Critical hit! %s deals double damage!\n", classNames[Warrior]);
                    damage *= 2;
                }
                break;
            case Mage:
                if (rand() % 100 < attacker->specialPercentage) { 
                    printf("-> The mage doesn't care how small the room is. HE CAST FIREBALL! Ignore defenses...\n");
                    damage -= defender->defense; // Effectively ignoring defense.
                }
                break;
            case Ranger:
                if (rand() % 100 < attacker->specialPercentage) { 
                    printf("-> Double Strike! %s gets a bonus attack!\n", classNames[Ranger]);
                    // Calculate the extra attack's damage.
                    int extraDamage = attacker->attack - defender->defense;
                    if (extraDamage < 0)
                        extraDamage = 0;
                    damage += extraDamage;
                }
                break;
            default:
                break;
        }
    }

    // Paladin's passive: when attacked, there is a chance to heal a percentage of the damage.
    if (defender->characterClass == Paladin) {
        if (rand() % 100 < defender->specialPercentage) {
            int heal = (int)(damage * 0.2);
            printf("-> May the sun shine upon myself, my Godness! Paladin heals %d HP.\n", heal);
            defender->hp += heal;
        }
    }
    
    // Ensure damage is not negative.
    if (damage < 0)
        damage = 0;
    
    // Apply damage to the defender.
    defender->hp -= damage;
    // If HP falls below 0, set it to 0.
    if (defender->hp < 0)
        defender->hp = 0;
    
    printf("-> %s attacks %s for %d damage! %s now has %d HP left.\n\n",
           classNames[attacker->characterClass],
           classNames[defender->characterClass],
           damage,
           classNames[defender->characterClass],
           defender->hp);
}

// Returns 1 if all characters in the party are defeated (HP <= 0), 0 otherwise.
int isPartyDefeated(Character party[], int partySize) {
    for (int i = 0; i < partySize; i++) {
        if (party[i].hp > 0)
            return 0;
    }
    return 1;
}

// Prints the current status of a party.
void printPartyStatus(const char *partyName, Character party[], int partySize) {
    printf("> %s\n", partyName);
    for (int i = 0; i < partySize; i++) {
         printf("- %s: HP %d\n", classNames[party[i].characterClass], party[i].hp);
    }
    printf("\n");
}

// Selects a random character from the party that is still alive (HP > 0).
Character* getRandomAliveCharacter(Character party[], int partySize) {
    int aliveIndices[partySize];
    int count = 0;
    
    for (int i = 0; i < partySize; i++) {
         if (party[i].hp > 0)
              aliveIndices[count++] = i;
    }
    
    if (count == 0)
         return NULL;
    
    int randomIndex = rand() % count;
    return &party[aliveIndices[randomIndex]];
}

int main(void) {
    srand(time(NULL));  // Seed the random number generator.
    
    // Instantiate characters—setting specialPercentage per class.
    Character warrior   = {Warrior,   100, 20, 10, 20};
    Character mage      = {Mage,      100, 30, 5,  25};
    Character ranger    = {Ranger,    100, 18, 8,  15};
    Character paladin   = {Paladin,   100, 15, 12, 30};
    Character barbarian = {Barbarian, 100, 25, 6,  100};
    
    // Allocate characters into two parties.
    int partySize = 5;
    Character partyOne[5] = { warrior, mage, ranger, paladin, barbarian };
    Character partyTwo[5] = { warrior, mage, ranger, paladin, barbarian };
    
    // Randomly draw a party to start the combat.
    int startingParty = rand() % 2;  // 0 means Party One starts; 1 means Party Two starts.
    printf("Randomly drawing the starting party...\n");
    if (startingParty == 0)
         printf("Party One will start the combat.\n\n");
    else
         printf("Party Two will start the combat.\n\n");
    
    int round = 1;
    
    // Main battle loop: each round, the drawn starting party attacks first,
    // then the other party attacks until one party is completely defeated.
    while (!isPartyDefeated(partyOne, partySize) && !isPartyDefeated(partyTwo, partySize)) {
        printf(">>> Round %d:\n\n", round);
        
        if (startingParty == 0) {
            // Party One attacks first.
            {
                Character *attackerOne = getRandomAliveCharacter(partyOne, partySize);
                Character *targetTwo   = getRandomAliveCharacter(partyTwo, partySize);
                if (attackerOne && targetTwo) {
                    printf("-= Party One's turn =-\n");
                    performAttack(attackerOne, targetTwo);
                }
            }
            // Check if Party Two is defeated before its turn.
            if (isPartyDefeated(partyTwo, partySize))
                break;
            
            {
                Character *attackerTwo = getRandomAliveCharacter(partyTwo, partySize);
                Character *targetOne   = getRandomAliveCharacter(partyOne, partySize);
                if (attackerTwo && targetOne) {
                    printf("-= Party Two's turn =-\n");
                    performAttack(attackerTwo, targetOne);
                }
            }
        } else {
            // Party Two attacks first.
            {
                Character *attackerTwo = getRandomAliveCharacter(partyTwo, partySize);
                Character *targetOne   = getRandomAliveCharacter(partyOne, partySize);
                if (attackerTwo && targetOne) {
                    printf("-= Party Two's turn =-\n");
                    performAttack(attackerTwo, targetOne);
                }
            }
            // Check if Party One is defeated before its turn.
            if (isPartyDefeated(partyOne, partySize))
                break;
            
            {
                Character *attackerOne = getRandomAliveCharacter(partyOne, partySize);
                Character *targetTwo   = getRandomAliveCharacter(partyTwo, partySize);
                if (attackerOne && targetTwo) {
                    printf("-= Party One's turn =-\n");
                    performAttack(attackerOne, targetTwo);
                }
            }
        }
        
        // Print the status after this round.
        printf(">>> Status after round %d:\n", round);
        printPartyStatus("Party One", partyOne, partySize);
        printPartyStatus("Party Two", partyTwo, partySize);
        printf("-------------------------------------------------\n\n");
        
        round++;
    }
    
    // Announce the result.
    if (isPartyDefeated(partyOne, partySize))
        printf("Party One has been defeated! Party Two wins!\n");
    else if (isPartyDefeated(partyTwo, partySize))
        printf("Party Two has been defeated! Party One wins!\n");
    else
        printf("It's a draw!\n");
    
    return 0;
}
