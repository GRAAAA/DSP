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
    // Inventory management functions
    void addItem(const std::shared_ptr<Item>& item);
    void removeItem(const std::string& itemName);
    bool empty() const;
    std::shared_ptr<Item> findItem(const std::string& itemName) const;
    void displayItems() const;

    // Iterator class to traverse inventory items
    class Iterator {
    private:
        using ItemIterator = std::vector<std::shared_ptr<Item>>::const_iterator;
        ItemIterator current;

    public:
        explicit Iterator(ItemIterator start) : current(start) {}

        Iterator& operator++() { ++current; return *this; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
        const std::shared_ptr<Item>& operator*() const { return *current; }  // Return a const reference to avoid modification
    };

    // Begin and end functions to use the iterator
    Iterator begin() const { return Iterator(items.cbegin()); }
    Iterator end() const { return Iterator(items.cend()); }
};

#endif // INVENTORY_H
