#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    enum class ItemType {
        HOLY_WATER,
        MEMO,
        SHIN_RAMEN,
        MAGICAL_TELEPORT,
        KEY_PART,
        EMPTY_BOTTLE
    };

private:
    std::string name;
    ItemType type;

public:
    Item(const std::string& name, ItemType type);

    const std::string& getName() const { return name; }
    ItemType getType() const { return type; }
};

#endif // ITEM_H
