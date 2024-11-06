#ifndef EVENT_H
#define EVENT_H

#include "Player.h"
#include <string>
#include <memory>

class Event {
public:
    enum class EventType {
        ENCOUNTER_GHOST,
        FIND_ITEM,
        MOVE_TO_NEXT_FLOOR
    };

private:
    EventType type;
    std::string description;

public:
    Event(EventType type, const std::string& description);
    EventType getType() const { return type; }
    const std::string& getDescription() const { return description; }
    void trigger(Player& player) const;  // Triggers the event effect on the player
};

#endif // EVENT_H
