#include "Player.h"
#include "Door.h"
#include <iostream>
#include <memory>
#include <stack>
#include <cstdlib>
#include <ctime>

void gameLoop(Player& player) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int currentFloor = 1;
    std::stack<int> floorStack;
    floorStack.push(currentFloor);

    while (currentFloor <= 9 && player.isAlive()) {
        std::cout << "\nYou are on floor " << currentFloor << ".\n";
        std::cout << "Choose a door to open (1, 2, or 3):\n";

        // Generate random doors
        std::unique_ptr<Door> doors[3];
        for (int i = 0; i < 3; ++i) {
            int doorType = rand() % 5;  // Adjust range as more door types are added
            switch (doorType) {
            case 0: doors[i] = std::make_unique<SafeDoor>(); break;
            case 1: doors[i] = std::make_unique<VendingMachineDoor>(); break;
            case 2: doors[i] = std::make_unique<GhostDoor>(); break;
            case 3: doors[i] = std::make_unique<MysteryBoxDoor>(); break;
            case 4: doors[i] = std::make_unique<DownstairsDoor>(); break;
            }
        }

        // Display doors
        for (int i = 0; i < 3; ++i) {
            std::cout << "Door " << (i + 1) << ": ???\n";
        }

        // Player chooses a door
        int choice;
        while (true) {
            std::cout << "Enter your choice (1, 2, or 3): ";
            std::cin >> choice;
            if (choice >= 1 && choice <= 3) break;
            std::cout << "Invalid choice. Please choose 1, 2, or 3.\n";
        }

        // Interact with the chosen door
        doors[choice - 1]->interact(player);

        // Check if player survives and moves to the next floor
        if (player.isAlive()) {
            if (dynamic_cast<DownstairsDoor*>(doors[choice - 1].get())) {
                if (floorStack.size() > 1) {
                    floorStack.pop();  // Move back to the previous floor
                    currentFloor = floorStack.top();
                    std::cout << "You moved back to floor " << currentFloor << ".\n";
                }
                else {
                    std::cout << "You can't go lower than the ground floor.\n";
                }
            }
            else {
                currentFloor++;
                floorStack.push(currentFloor);
            }
        }
        else {
            std::cout << "Game Over. You didn't survive the haunted house.\n";
            break;
        }
    }

    // Winning condition
    if (currentFloor > 9) {
        std::cout << "Congratulations! You reached the 9th floor and escaped the haunted house!\n";
    }
}

int main() {
    Player player("Player", 5);  // Initialize player with 5 health
    std::cout << "Welcome to the Haunted House!\n";
    gameLoop(player);  // Start the game loop
    return 0;
}
