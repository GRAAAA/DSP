#ifndef FLOORSTACK_H
#define FLOORSTACK_H

#include <stack>
#include <vector>

class FloorStack {
private:
    std::stack<int> floors;

public:
    void push(int floor) {
        floors.push(floor);
    }

    void pop() {
        if (!floors.empty()) {
            floors.pop();
        }
    }

    int top() const {
        return floors.top();
    }

    bool empty() const {
        return floors.empty();
    }

    size_t size() const {
        return floors.size();
    }

    // Nested Iterator class for FloorStack
    class Iterator {
    private:
        std::vector<int> floorHistory;
        size_t index;

    public:
        explicit Iterator(const std::stack<int>& originalStack) : index(0) {
            // Copy stack into a vector for safe reverse traversal
            std::stack<int> tempStack = originalStack;
            while (!tempStack.empty()) {
                floorHistory.push_back(tempStack.top());
                tempStack.pop();
            }
            // Reverse vector to iterate from bottom to top
            std::reverse(floorHistory.begin(), floorHistory.end());
        }

        bool hasNext() const { return index < floorHistory.size(); }

        int next() {
            return floorHistory[index++];
        }
    };

    // Begin method to provide iterator functionality
    Iterator begin() const { return Iterator(floors); }
};

#endif // FLOORSTACK_H
