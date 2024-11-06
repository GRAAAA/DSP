cmake_minimum_required(VERSION 3.28)
project(DSP)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSP
        main.cpp
        Entity.cpp
        Player.cpp
        Door.cpp
        Inventory.cpp
        Item.cpp
        Event.cpp  # Make sure this line is present
)