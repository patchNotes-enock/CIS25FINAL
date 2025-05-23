#include <iostream>
#include <fstream>
using namespace std;

int playerHP;
int dragonHP = 64;
int warriorHP = 30;
int mageHP = 25;
int archerHP = 27;
string name;

class Attack { // base class for attack function, default for Warrior
    public:
        void attack() {
            dragonHP -= 8;
            cout << "                     " << name << " attacks for 8 damage!\n\n";
        }
};

class MageAttack : public Attack { // derived class for Mage attack
    public:
        void attack() {
            dragonHP -= 3;
            cout << "                     " << name << " attacks for 3 damage!\n\n";
        }
};

class ArcherAttack : public Attack { // derived class for Archer attack
    public:
        void attack() {
            dragonHP -= 5;
            cout << "                     " << name << " attacks for 5 damage!\n\n";
        }
};

class Magic { // base class for magic function, default for Warrior
    public:
        void magic() {
            dragonHP -= 3;
            cout << "                     " << name << "'s spell does 3 damage!\n\n";
        }
};

class MageMagic : public Magic { // derived class for Mage magic
    public:
        void magic() {
            dragonHP -= 9;
            cout << "                     " << name << "'s spell does 9 damage!\n\n";
        }
};

class ArcherMagic : public Magic { // derived class for Archer magic
    public:
        void magic() {
            dragonHP -= 5;
            cout << "                     " << name << "'s spell does 5 damage!\n\n";
        }
};

class Critical { // base class for critical attack function, default for Warrior
    public: 
        void critical() {
            if (dragonHP <= 32) {
                dragonHP -= 13;
                cout << "                             CRITICAL HIT!\n\n";
                cout << "                       " << name << " deals 13 damage!\n\n";
            } else {
                cout << "                        CRITICAL ATTACK MISSED...\n\n";
            }
        }
};

class MageCritical : public Critical { // derived class for Mage critical attack
    public:
        void critical() {
            if (dragonHP >= 24) {
                dragonHP -= 11;
                cout << "                            CRITICAL HIT!\n\n";
                cout << "                        " << name << " deals 11 damage!\n\n";
            } else {
                cout << "                         CRITICAL ATTACK MISSED...\n\n";
            }
        }
};

class ArcherCritical : public Critical { // derived class for Archer critical attack
    public:
        void critical() {
            if (dragonHP >= 46) {
                dragonHP -= 17;
                cout << "                            CRITICAL HIT!\n\n";
                cout << "                       " << name << " deals 17 damage!\n\n";
            } else {
                cout << "                         CRITICAL ATTACK MISSED...\n\n";
            }
        }
};

void dragonHeavy(){ // default attack for Cave Dragon
    playerHP -= 5;
    cout << "                   Cave Dragon attacks for 5 damage!\n\n";
}

void dragonLight(){ // light attack after player uses item
    playerHP -= 3;
    cout << "                   Cave Dragon attacks for 3 damage!\n\n";
}

void dragonFire(){ // special attack used once HP drops below certain point
    playerHP -= 8;
    cout << "                       Cave Dragon breathes fire!\n\n";
    cout << "                         Attack deals 8 damage!\n\n";
}

void dragonDead(){ // used to print Dragon Defeated at end of game when dragonHP <=0
    cout << "                          Dragon Defeated!\n\n\n";
    cout << "                              VICTORY!\n\n\n";
}

void gameOver() { // used to print Game Over message when playerHP <=0
    cout << "                         You've Been Slain...\n\n\n";
    cout << "                              GAME OVER\n\n\n";
}

int main() {  
    
    int characterSelect; // 1) Warrior, 2) Mage, 3) Archer
    int actionSelect;
    int potionCount = 4;
    int hipotionCount = 2;
    int zeusCount = 6;
    int frostCount = 1;

    cout << "               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << "               X                                   X\n";
    cout << "               X           SOLEMN  DEITY           X\n";
    cout << "               X                                   X\n";
    cout << "               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n";
    cout << "                         Choose Adventurer          \n\n";
    cout << "                    (1)         (2)          (3)    \n";
    cout << "                  Warrior       Mage       Archer   \n";
    cout << "                  HP: 30       HP: 25      HP: 27   \n";
    cout << "                  ATK: 8       ATK: 3      ATK: 5   \n";
    cout << "                  MAG: 3       MAG: 9      MAG: 5   \n";
    cout << "                  CRT: 13      CRT: 11     CRT: 17  \n";
    cout << "                  DEF: 6       DEF: 5      DEF: 3   \n\n";
    
    do {
        cout << "                       Choose 1, 2, or 3: ";
        cin >> characterSelect;
        cout << "\n";

        if (characterSelect == 1) {
                playerHP = warriorHP;
                cout << "                     You've selected Warrior\n\n";
                break;
        } else if (characterSelect == 2) {
                playerHP = mageHP;
                cout << "                       You've selected Mage\n\n";
                break;
        } else if (characterSelect == 3) {
                playerHP = archerHP;
                cout << "                      You've selected Archer\n\n";
                break;
        } else if (characterSelect != 1 || 2 || 3){ 
                cout << "                               Invalid entry\n\n";
        }    
    } while (characterSelect != 1 || 2 || 3);

    cout << "                         Name: ";
    cin >> name;
    cout << "\n";
    cout << "   While searching a cave for treasure, " << name << " encounters a dragon!\n\n"; // STORY ABOUT FANTASY LEADING TO DRAGON FIGHT

    do {
        cout << "                       HP: " << dragonHP << "    Cave Dragon         \n\n";
        cout << "                       HP: " << playerHP << "    " << name << "        \n";
        cout << "                       1) Attack      2) Magic        \n";
        cout << "                       3) Critical    4) Item         \n\n";
        cout << "                          Select Action: ";
        cin >> actionSelect;
        cout << "\n";

        if (dragonHP <= 13) { // when Cave Dragon's health is 13 or lower, it attacks before player action
            dragonFire();
            if (playerHP <= 0) {
                gameOver();
                break;
            }
        }

        if (actionSelect == 1){ // ATTACK 
            if (characterSelect == 1) {
                Attack warAtt;
                warAtt.attack();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            } else if (characterSelect == 2){
                MageAttack mageAtt;
                mageAtt.attack();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            } else if (characterSelect == 3){
                ArcherAttack archerAtt;
                archerAtt.attack();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            }
        } else if (actionSelect == 2){ // MAGIC
            if (characterSelect == 1) {
                Magic warMag;
                warMag.magic();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }   
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            } else if (characterSelect == 2) {
                MageMagic mageMag;
                mageMag.magic();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            } else if (characterSelect == 3) {
                ArcherMagic archerMag;
                archerMag.magic();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            }
        } else if (actionSelect == 3){ // CRITICAL ATTACK
            if (characterSelect == 1) {
                Critical warCrit;
                warCrit.critical();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            } else if (characterSelect == 2){
                MageCritical mageCrit;
                mageCrit.critical();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            } else if (characterSelect == 3){
                ArcherCritical archerCrit;
                archerCrit.critical();
                if (dragonHP <= 0){
                    dragonDead();
                    break;
                }
                dragonHeavy();
                if (playerHP <= 0){
                    gameOver();
                    break;
                }
            }
        } else if (actionSelect == 4){ // ITEM
                int itemSelect;
                cout << "                                 ITEMS \n";
                cout << "                 1) Potion (x" << potionCount << ")      2) Hi-Potion (x" << hipotionCount << ")   \n"; // lists items and count in player inventory
                cout << "                 3) Zeus' Roar (x" << zeusCount << ")  4) Frost Bite (x" << frostCount << ")  \n\n";
                cout << "                          Select Item: ";
                cin >> itemSelect;
                cout << "\n";
                if (itemSelect == 1) {
                    if (potionCount == 0) {
                        cout << "                            Out of Potions\n\n";
                    } else {
                        playerHP += 7;
                        potionCount -= 1;
                        cout << "                       " << name << " healed 7 HP!\n\n";
                    }
                    dragonLight();
                } else if (itemSelect == 2) {
                    if (hipotionCount == 0) {
                        cout << "                         Out of Hi-Potions\n\n";
                    } else {
                        playerHP += 14;
                        hipotionCount -= 1;
                        cout << "                       " << name << " healed 14 HP!\n\n";
                    }
                    dragonLight();
                } else if (itemSelect == 3) {
                    if (zeusCount == 0) {
                        cout << "                         Out of Zeus' Roar\n\n";
                    } else {
                        dragonHP -= 4;
                        zeusCount -= 1;
                        cout << "                      " << name << " did 4 damage...\n\n";
                        cout << "                    Lightning isn't very effective....\n\n";
                        if (dragonHP <=0){
                            dragonDead();
                            break;
                        } 
                    }
                    dragonLight();
                } else if (itemSelect == 4) {
                    if (frostCount == 0) {
                        cout << "                         Out of Frost Bite\n\n";
                    } else {
                        dragonHP -= 12;
                        frostCount -= 1;
                        cout << "                       " << name << " did 12 damage!\n\n";
                        cout << "                      Dragon is weak to Ice!\n\n";
                        if (dragonHP <= 0){
                        dragonDead();
                        break;
                        }
                    }
                    dragonLight();
                } else if (itemSelect != 1 || 2 || 3 || 4) { 
                    cout << "                            Invalid entry\n\n";
                }
        } else if (actionSelect == 5){
            break;
        } else if (actionSelect != 1 || 2 || 3 || 4 || 5){ 
            cout << "                            Invalid entry\n\n";
        }
    } while ((actionSelect == 1 || 2 || 3 || 4) || (actionSelect != 1 || 2 || 3 || 4));
    return 0;
}