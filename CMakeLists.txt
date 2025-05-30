cmake_minimum_required(VERSION 3.15)
project(blackjack)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "C:/libraries/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

include_directories(headers)

add_executable(blackjack
        src/main.cpp
        src/Menu.cpp
        headers/Menu.h
        src/Card.cpp
        headers/Card.h
        src/Deck.cpp
        headers/Deck.h
        src/Player.cpp
        headers/Player.h
        src/Dealer.cpp
        headers/Dealer.h
        src/Game.cpp
        headers/Game.h
)

target_link_libraries(blackjack PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)

add_custom_command(TARGET blackjack POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:blackjack>/assets)