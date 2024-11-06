#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Inventory.h"
#include <memory>

class Player : public Entity {
private:
    Inventory inventory;

public:
    Player(const std::string& name, int health);

    void addItem(const std::shared_ptr<Item>& item);
    void useItem();
    void showInventory() const;
};

#endif // PLAYER_H
