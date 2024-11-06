#include "Door.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>

// SafeDoor implementation
void SafeDoor::interact(Player& player) {
    std::cout << "You pass safely to the next floor.\n";
}

// VendingMachineDoor implementation
void VendingMachineDoor::interact(Player& player) {
    std::cout << "A weird vending machine appears. You can trade 1 health for an item.\n";

    std::vector<std::shared_ptr<Item>> availableItems = {
        std::make_shared<Item>("Holy Water", Item::ItemType::HOLY_WATER),
        std::make_shared<Item>("Memo", Item::ItemType::MEMO),
        std::make_shared<Item>("Shin Ramen", Item::ItemType::SHIN_RAMEN),
        std::make_shared<Item>("Magical Teleport", Item::ItemType::MAGICAL_TELEPORT)
    };

    std::cout << "Available items:\n";
    for (size_t i = 0; i < availableItems.size(); ++i) {
        std::cout << i + 1 << ". " << availableItems[i]->getName() << "\n";
    }

    int choice;
    while (true) {
        std::cout << "Enter the number of the item you want to buy (1-" << availableItems.size() << "): ";
        std::cin >> choice;
        if (choice >= 1 && choice <= static_cast<int>(availableItems.size())) {
            break;
        }
        std::cout << "Invalid choice. Please select a valid item.\n";
    }

    player.takeDamage(1);
    player.addItem(availableItems[choice - 1]);
    std::cout << "You received: " << availableItems[choice - 1]->getName() << "\n";
}

// GhostDoor implementation
void GhostDoor::interact(Player& player) {
    std::cout << "A ghost jumps out! Prepare to roll the dice to escape!\n";

    std::string input;
    while (true) {
        std::cout << "Type 'roll' to roll the dice: ";
        std::cin >> input;
        if (input == "roll") break;
        std::cout << "Invalid input. Please type 'roll'.\n";
    }

    int diceRoll = rand() % 6 + 1;
    int safeLower = rand() % 6 + 1;
    int safeUpper = safeLower + (rand() % (7 - safeLower));

    std::cout << "You rolled a " << diceRoll << ".\n";
    std::cout << "The safe numbers were " << safeLower << " to " << safeUpper << ".\n";

    if (diceRoll >= safeLower && diceRoll <= safeUpper) {
        std::cout << "You escaped safely!\n";
    } else {
        std::cout << "The ghost attacks! You lose 1 health.\n";
        player.takeDamage(1);
    }
}

// MysteryBoxDoor implementation
void MysteryBoxDoor::interact(Player& player) {
    std::cout << "You found a Mystery Box! It could be dangerous or helpful.\n";

    std::string input;
    while (true) {
        std::cout << "Type 'open' to open the box: ";
        std::cin >> input;
        if (input == "open") break;
        std::cout << "Invalid input. Please type 'open'.\n";
    }

    int content = rand() % 2;
    if (content == 0) {
        std::cout << "The box contained a trap! You lose 1 health.\n";
        player.takeDamage(1);
    } else {
        std::cout << "The box contained a helpful item!\n";
        player.addItem(std::make_shared<Item>("Health Potion", Item::ItemType::EMPTY_BOTTLE));
    }
}

// DownstairsDoor implementation
void DownstairsDoor::interact(Player& player) {
    std::cout << "You find yourself back on a previous floor.\n";
    // Additional logic for moving the player back a floor can be added here.
}
