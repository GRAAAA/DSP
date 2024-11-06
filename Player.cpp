#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, int health)
    : Entity(name, health) {}

void Player::addItem(const std::shared_ptr<Item>& item) {
    inventory.addItem(item);
}

void Player::useItem() {
    if (inventory.empty()) {
        std::cout << "No items to use!\n";
        return;
    }

    std::cout << "Select an item to use from your inventory:\n";
    inventory.displayItems();

    std::string itemName;
    std::cout << "Enter the item name: ";
    std::cin.ignore();  // Clear input buffer
    std::getline(std::cin, itemName);

    auto item = inventory.findItem(itemName);
    if (!item) {
        std::cout << "Item not found in inventory.\n";
        return;
    }

    switch (item->getType()) {
        case Item::ItemType::HOLY_WATER:
            std::cout << "Using Holy Water. Ghosts will flee.\n";
        inventory.removeItem(itemName);
        break;
        case Item::ItemType::MEMO:
            std::cout << "Using Memo. Revealing details.\n";
        inventory.removeItem(itemName);
        break;
        case Item::ItemType::SHIN_RAMEN:
            std::cout << "Using Shin Ramen. You gain 1 health.\n";
        health++;
        inventory.removeItem(itemName);
        break;
        case Item::ItemType::MAGICAL_TELEPORT:
            std::cout << "Using Magical Teleport. Moving to the next floor safely.\n";
        inventory.removeItem(itemName);
        break;
        default:
            std::cout << "Item cannot be used right now.\n";
    }
}

void Player::showInventory() const {
    std::cout << "Inventory:\n";
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        std::cout << "- " << (*it)->getName() << "\n";
    }
}
