#include "Player.h"
#include "Door.h"
#include "EventQueue.h"
#include <iostream>
#include <memory>
#include <stack>
#include <cstdlib>
#include <ctime>
#include "FloorStack.h"
#include "DoorCollection.h"

void gameLoop(Player& player) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int currentFloor = 1;
    FloorStack floorStack;
    floorStack.push(currentFloor);

    while (currentFloor <= 9 && player.isAlive()) {
        std::cout << "\nYou are on floor " << currentFloor << ".\n";
        std::cout << "Current Health: " << player.getHealth() << "\n";

        bool actionTaken = false;
        while (!actionTaken) {
            std::cout << "What would you like to do?\n";
            std::cout << "1. Choose a door\n";
            std::cout << "2. Open Inventory\n";
            std::cout << "Enter your choice: ";
            int actionChoice;
            std::cin >> actionChoice;

            if (actionChoice == 1) {
                actionTaken = true;
            } else if (actionChoice == 2) {
                player.showInventory();
                player.useItem();
                std::cout << "Current Health: " << player.getHealth() << "\n";
            } else {
                std::cout << "Invalid choice. Please choose again.\n";
            }
        }

        std::cout << "Choose a door to open (1, 2, or 3):\n";

        DoorCollection doorCollection;
        for (int i = 0; i < 3; ++i) {
            int doorType = rand() % 5;
            switch (doorType) {
                case 0: doorCollection.addDoor(std::make_unique<SafeDoor>()); break;
                case 1: doorCollection.addDoor(std::make_unique<VendingMachineDoor>()); break;
                case 2: doorCollection.addDoor(std::make_unique<GhostDoor>()); break;
                case 3: doorCollection.addDoor(std::make_unique<MysteryBoxDoor>()); break;
                case 4: doorCollection.addDoor(std::make_unique<DownstairsDoor>()); break;
            }
        }

        int doorNum = 1;
        for (auto it = doorCollection.begin(); it != doorCollection.end(); ++it, ++doorNum) {
            std::cout << "Door " << doorNum << ": ???\n";
        }

        int choice;
        while (true) {
            std::cout << "Enter your choice (1, 2, or 3): ";
            std::cin >> choice;
            if (choice >= 1 && choice <= 3) break;
            std::cout << "Invalid choice. Please choose 1, 2, or 3.\n";
        }

        // Interact with the chosen door; each door's interact method will manage its events
        Door& chosenDoor = doorCollection.getDoor(choice - 1);
        chosenDoor.interact(player);

        if (dynamic_cast<SafeDoor*>(&chosenDoor)) {
            std::cout << "You move to the next floor.\n";
        } else if (dynamic_cast<DownstairsDoor*>(&chosenDoor)) {
            if (floorStack.size() > 1) {
                floorStack.pop();
                currentFloor = floorStack.top();
                std::cout << "You moved back to floor " << currentFloor << ".\n";
            } else {
                std::cout << "You can't go lower than the ground floor.\n";
            }
        } else if (player.isAlive()) {
            currentFloor++;
            floorStack.push(currentFloor);
        }

        if (!player.isAlive()) {
            std::cout << "Game Over. You didn't survive the haunted house.\n";
            break;
        }
    }

    if (currentFloor > 9) {
        std::cout << "Congratulations! You reached the 9th floor and escaped the haunted house!\n";
    }
}


void showWelcomeStory() {
    std::cout << "Welcome to the Haunted House...\n";
    std::cout << "Press Enter to start game...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You find yourself standing before an ancient, abandoned mansion.\n";
    std::cout << "The wind howls, and the once-grand facade is now crumbling and overgrown.\n";
    std::cout << "Press Enter to continue...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Rumor has it that no one who entered ever made it out alive.\n";
    std::cout << "Some say the rooms are alive, shifting and twisting, trapping those who enter.\n";
    std::cout << "Armed with only a handful of supplies, you gather your courage to venture inside,\n";
    std::cout << "hoping to reach the top floor where the last visitor was seen... or never seen again.\n\n";

    std::cout << "Press Enter to continue...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    showWelcomeStory();
    Player player("Player", 5);  // Initialize player with 5 health
    gameLoop(player);  // Start the game loop
    return 0;
}
