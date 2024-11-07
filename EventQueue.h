#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include "Event.h"
#include <queue>
#include <memory>

class EventQueue {
private:
    std::queue<std::shared_ptr<Event>> events;

public:
    void addEvent(const std::shared_ptr<Event>& event) {
        events.push(event);
    }

    bool empty() const {
        return events.empty();
    }

    void processNextEvent(Player& player) {
        if (!events.empty()) {
            events.front()->trigger(player);
            events.pop();
        }
    }

    // Nested Iterator class
    class Iterator {
    private:
        std::queue<std::shared_ptr<Event>> tempQueue;

    public:
        explicit Iterator(const std::queue<std::shared_ptr<Event>>& originalQueue) : tempQueue(originalQueue) {}

        bool hasNext() const { return !tempQueue.empty(); }

        std::shared_ptr<Event> next() {
            if (tempQueue.empty()) return nullptr;
            auto event = tempQueue.front();
            tempQueue.pop();
            return event;
        }
    };

    // Begin and end methods to provide iterator functionality
    Iterator begin() const { return Iterator(events); }
};

#endif // EVENTQUEUE_H
