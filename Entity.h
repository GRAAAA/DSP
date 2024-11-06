#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
protected:
    std::string name;
    int health;

public:
    Entity(const std::string& name, int health);
    virtual ~Entity() = default;  // Virtual destructor

    const std::string& getName() const { return name; }
    int getHealth() const { return health; }

    virtual void takeDamage(int amount);
    bool isAlive() const { return health > 0; }
};

#endif // ENTITY_H
