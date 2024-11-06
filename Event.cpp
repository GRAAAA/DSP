#include "Event.h"
#include <iostream>

Event::Event(EventType type, const std::string& description)
    : type(type), description(description) {}

void Event::trigger(Player& player) const {
    switch (type) {
        case EventType::ENCOUNTER_GHOST:
            std::cout << description << "\n";
        player.takeDamage(1);  // Encounter a ghost and take damage
        break;
        case EventType::FIND_ITEM:
            std::cout << description << "\n";
        player.addItem(std::make_shared<Item>("Health Potion", Item::ItemType::EMPTY_BOTTLE));  // Example item
        break;
        case EventType::MOVE_TO_NEXT_FLOOR:
            std::cout << description << "\n";
        // Logic to move to the next floor
        break;
    }
}
