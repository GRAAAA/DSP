#ifndef DOOR_H
#define DOOR_H

#include "Player.h"
#include <memory>

class Door {
public:
    virtual void interact(Player& player) = 0;
    virtual ~Door() = default;
};

class SafeDoor : public Door {
public:
    void interact(Player& player) override;
};

class VendingMachineDoor : public Door {
public:
    void interact(Player& player) override;
};

class GhostDoor : public Door {
public:
    void interact(Player& player) override;
};

class MysteryBoxDoor : public Door {
public:
    void interact(Player& player) override;
};

class DownstairsDoor : public Door {
public:
    void interact(Player& player) override;
};

#endif // DOOR_H
