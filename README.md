# CIS 25 FINAL PROJECT

I made a turn-based RPG battle, entitled "Solemn Deity", that allows the user to choose from one of three characters 
(Warrior, Mage, Archer) to fight a dragon. Each character has unique values for their attack stats (strength, magic, 
and critical attack), and the user can choose which type of attack to use as you alternate turns with the dragon during
the fight. Each turn presents the user with a menu that allows them to choose from 1) Attack, 2) Magic, 3) Critical (Attack),
and 4) Items. 

There are four items at your disposal (two that heal the player and two that deal damage to the opponent),
and the program also keeps track of how many of each item are used/remaining in the player's inventory.

When the dragon's health drops to roughly 1/5 of it's max health, it uses a special attack before the player's turn.

I used classes to override the methods for each attack type depending on the user's choice of character, and also added
borders using 'X' to make it visually appealing.
