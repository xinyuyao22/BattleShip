cmake_minimum_required(VERSION 3.13)
project(Battleship)

set(CMAKE_CXX_STANDARD 14)
set(BATTLESHIP_COMPILE_OPTIONS -Wall -Werror)

add_subdirectory(MVC)

add_executable(BattleShip main.cpp)
target_link_libraries(BattleShip PRIVATE BattleshipMVC)
target_compile_options(BattleShip PRIVATE ${BATTLESHIP_COMPILE_OPTIONS})
