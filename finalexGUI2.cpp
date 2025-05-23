#include <iostream>
#include <fstream>
using namespace std;

int playerHP;
int dragonHP = 64;
int warriorHP = 30;
int mageHP = 25;
int archerHP = 27;
string name;

void allX() {
    cout << "               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
}

void sideX() {
    cout << "               X                                   X\n";
}

void comboX() {
    cout << "               X                                   X\n";
    cout << "               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << "               X                                   X\n";
}

void endX() {
    cout << "               X                                   X\n";
    cout << "               X                                   X\n";
    cout << "               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
}

void invalid() {
    cout << "               X           Invalid entry           X\n";
    comboX();
}


class Attack { // base class for attack function, default for Warrior
    public:
        void attack() {
            dragonHP -= 8;
            cout << "               X   " << name << " slashes for 8 damage!    X\n";
            sideX();
        }
};

class MageAttack : public Attack { // derived class for Mage attack
    public:
        void attack() {
            dragonHP -= 3;
            cout << "               X   " << name << " attacks for 3 damage!    X\n";
            sideX();
        }
};

class ArcherAttack : public Attack { // derived class for Archer attack
    public:
        void attack() {
            dragonHP -= 5;
            cout << "               X   " << name << "'s arrow does 5 damage!   X\n";
            sideX();
        }
};

class Magic { // base class for magic function, default for Warrior
    public:
        void magic() {
            dragonHP -= 3;
            cout << "               X   " << name << "'s spell does 3 damage!   X\n";
            sideX();
        }
};

class MageMagic : public Magic { // derived class for Mage magic
    public:
        void magic() {
            dragonHP -= 9;
            cout << "               X   " << name << "'s spell does 9 damage!   X\n";
            sideX();
        }
};

class ArcherMagic : public Magic { // derived class for Archer magic
    public:
        void magic() {
            dragonHP -= 5;
            cout << "               X   " << name << "'s spell does 5 damage!   X\n";
            sideX();
        }
};

class Critical { // base class for critical attack function, default for Warrior
    public: 
        void critical() {
            if (dragonHP <= 32) {
                dragonHP -= 13;
                cout << "               X           CRITICAL HIT!           X\n";
                sideX();
                cout << "               X      " << name << " deals 13 damage!     X\n";
                sideX();
            } else {
                cout << "               X     CRITICAL ATTACK MISSED...     X\n";
                sideX();
            }
        }
};

class MageCritical : public Critical { // derived class for Mage critical attack
    public:
        void critical() {
            if (dragonHP >= 24) {
                dragonHP -= 11;
                cout << "               X           CRITICAL HIT!           X\n";
                sideX();
                cout << "               X       " << name << " deals 11 damage!     X\n";
                sideX();
            } else {
                cout << "               X     CRITICAL ATTACK MISSED...     X\n";
                sideX();
            }
        }
};

class ArcherCritical : public Critical { // derived class for Archer critical attack
    public:
        void critical() {
            if (dragonHP >= 46) {
                dragonHP -= 17;
                cout << "               X           CRITICAL HIT!           X\n";
                sideX();
                cout << "               X      " << name << " deals 17 damage!     X\n";
                sideX();
            } else {
                cout << "               X     CRITICAL ATTACK MISSED...     X\n";
                sideX();
            }
        }
};

void dragonHeavy(){ // default attack for Cave Dragon
    playerHP -= 5;
    cout << "               X Cave Dragon attacks for 5 damage! X\n";
    comboX();
}

void dragonLight(){ // light attack after player uses item
    playerHP -= 3;
    cout << "               X  Cave Dragon claws for 3 damage!  X\n";
    comboX();
}

void dragonFire(){ // special attack used once HP drops below certain point
    playerHP -= 8;
    cout << "               X    Cave Dragon breathes fire!     X\n";
    sideX();
    cout << "               X      Attack deals 8 damage!       X\n";
    comboX();
}

void dragonDead(){ // used to print Dragon Defeated at end of game when dragonHP <=0
    comboX();
    sideX();
    cout << "               X          Dragon Defeated!         X\n";
    sideX();
    sideX();
    cout << "               X              VICTORY!             X\n";
    endX();
}

void gameOver() { // used to print Game Over message when playerHP <=0
    cout << "               X        You've Been Slain...       X\n";
    sideX();
    sideX();
    cout << "               X             GAME OVER             X\n";
    endX();
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
    cout << "               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << "               X                                   X\n";
    cout << "               X         " << "\033[4m" << "Choose Adventurer" << "\033[0m" << "         X\n";
    cout << "               X                                   X\n";
    cout << "               X    (1)         (2)          (3)   X\n";
    cout << "               X  Warrior       Mage       Archer  X\n";
    cout << "               X  HP: 30       HP: 25      HP: 27  X\n";
    cout << "               X  ATK: 8       ATK: 3      ATK: 5  X\n";
    cout << "               X  MAG: 3       MAG: 9      MAG: 5  X\n";
    cout << "               X  CRT: 13      CRT: 11     CRT: 17 X\n";
    cout << "               X                                   X\n";
    cout << "               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << "               X                                   X\n";
    
    do {
        cout << "               X       Choose 1, 2, or 3: ";
        cin >> characterSelect;
        comboX();

        if (characterSelect == 1) {
                playerHP = warriorHP;
                cout << "               X             Warrior               X\n";
                comboX();
                break;
        } else if (characterSelect == 2) {
                playerHP = mageHP;
                cout << "               X               Mage                X\n";
                comboX();
                break;
        } else if (characterSelect == 3) {
                playerHP = archerHP;
                cout << "               X              Archer               X\n";
                comboX();
                break;
        } else if (characterSelect != 1 || 2 || 3){
            invalid();
        }
    } while (characterSelect != 1 || 2 || 3);

    cout << "               X         Name: ";
    cin >> name;
    comboX();
    cout << "               X  While searching ruins for gold,  X\n";
    cout << "               X    " << name << " encounters a dragon!    X\n"; // STORY ABOUT FANTASY LEADING TO DRAGON FIGHT
    comboX();

    do
    {
        cout << "               X       HP: " << dragonHP << "    Cave Dragon       X\n";
        sideX();
        cout << "               X       HP: " << playerHP << "    " << name << "            X\n";
        comboX();
        cout << "               X      1) Attack      2) Magic      X\n";
        cout << "               X      3) Critical    4) Item       X\n";
        sideX();
        cout << "               X         Select Action: ";
        cin >> actionSelect;
        comboX();

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
                cout << "               X               " << "\033[4m" << "ITEMS" << "\033[0m" << "               X\n";
                sideX();
                cout << "               X 1)Potion(x" << potionCount << ")     2)Hi-Potion (x" << hipotionCount << ") X\n"; // lists items and count in player inventory
                cout << "               X 3)Zeus' Bolt(x" << zeusCount << ") 4)Frost Bite (x" << frostCount << ")X\n";
                sideX();
                cout << "               X          Select Item: ";
                cin >> itemSelect;
                comboX();
                if (itemSelect == 1) {
                    if (potionCount == 0) {
                        cout << "               X           Out of Potions          X\n";
                        sideX();
                    } else {
                        playerHP += 7;
                        potionCount -= 1;
                        cout << "               X        " << name << " healed 7 HP!        X\n";
                        sideX();
                    }
                    dragonLight();
                } else if (itemSelect == 2) {
                    if (hipotionCount == 0) {
                        cout << "               X         Out of Hi-Potions         X\n";
                        sideX();
                    } else {
                        playerHP += 14;
                        hipotionCount -= 1;
                        cout << "               X       " << name << " healed 14 HP!        X\n";
                        sideX();
                    }
                    dragonLight();
                } else if (itemSelect == 3) {
                    if (zeusCount == 0) {
                        cout << "               X         Out of Zeus' Bolts        X\n";
                        sideX();
                    } else {
                        dragonHP -= 4;
                        zeusCount -= 1;
                        cout << "               X       " << name << " did 4 damage...      X\n";
                        cout << "               X Lightning isn't very effective... X\n";
                        sideX();
                        if (dragonHP <= 0){
                            dragonDead();
                            break;
                        }
                    }
                    dragonLight();
                } else if (itemSelect == 4) {
                    if (frostCount == 0) {
                        cout << "               X         Out of Frost Bite         X\n";
                        sideX();
                    } else {
                        dragonHP -= 12;
                        frostCount -= 1;
                        cout << "               X       " << name << " did 12 damage!       X\n";
                        cout << "               X      Dragon is weak to Ice!       X\n";
                        sideX();
                        if (dragonHP <= 0)
                        {
                            dragonDead();
                            break;
                        }
                    }
                    dragonLight();
                } else if (itemSelect != 1 || 2 || 3 || 4) { 
                    invalid();
                }
        } else if (actionSelect == 5){
            break;
        } else if (actionSelect != 1 || 2 || 3 || 4 || 5){ 
            invalid();
        }
    } while ((actionSelect == 1 || 2 || 3 || 4) || (actionSelect != 1 || 2 || 3 || 4));
    return 0;
}