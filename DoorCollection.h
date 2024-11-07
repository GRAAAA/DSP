#ifndef DOORCOLLECTION_H
#define DOORCOLLECTION_H

#include "Door.h"
#include <vector>
#include <memory>

class DoorCollection {
private:
    std::vector<std::unique_ptr<Door>> doors;

public:
    // Add a door to the collection
    void addDoor(std::unique_ptr<Door> door) {
        doors.push_back(std::move(door));
    }

    // Nested iterator class for DoorCollection
    class Iterator {
    private:
        std::vector<std::unique_ptr<Door>>::iterator it;

    public:
        explicit Iterator(std::vector<std::unique_ptr<Door>>::iterator init) : it(init) {}

        bool operator!=(const Iterator& other) const { return it != other.it; }
        Door& operator*() const { return **it; }
        Iterator& operator++() { ++it; return *this; }
    };

    // begin() and end() functions to use the iterator
    Iterator begin() { return Iterator(doors.begin()); }
    Iterator end() { return Iterator(doors.end()); }

    // Access specific door
    Door& getDoor(int index) { return *doors.at(index); }
};

#endif // DOORCOLLECTION_H
