#include "Entity.h"

Entity::Entity(const std::string& name, int health)
    : name(name), health(health) {}

void Entity::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}
