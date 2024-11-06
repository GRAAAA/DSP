#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
#include <memory>
#include <string>

class Inventory {
private:
    std::vector<std::shared_ptr<Item>> items;

public:
    void addItem(const std::shared_ptr<Item>& item);
    void removeItem(const std::string& itemName);
    bool empty() const;
    std::shared_ptr<Item> findItem(const std::string& itemName);
    void displayItems() const;
};

#endif // INVENTORY_H
