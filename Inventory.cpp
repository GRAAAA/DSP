#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const std::shared_ptr<Item>& item) {
    items.push_back(item);
}

void Inventory::removeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            items.erase(it);
            return;
        }
    }
}

bool Inventory::empty() const {
    return items.empty();
}

// Add const here to match the declaration in Inventory.h
std::shared_ptr<Item> Inventory::findItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

void Inventory::displayItems() const {
    for (const auto& item : items) {
        std::cout << "- " << item->getName() << "\n";
    }
}
