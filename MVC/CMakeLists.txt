cmake_minimum_required(VERSION 3.13)
project(BattleshipMVC)

set(CMAKE_CXX_STANDARD 14)
#add_subdirectory(CursesWrapper)

add_library(BattleshipMVC STATIC
        Controller.cpp Controller.h
        View.cpp View.h
        Model.cpp Model.h Player.cpp Player.h Move.cpp Move.h HumanPlayer.cpp HumanPlayer.h AiPlayer.cpp AiPlayer.h PlayerConfiguration.cpp PlayerConfiguration.h StandardView.cpp StandardView.h Utility.cpp Utility.h GameAttributes.cpp GameAttributes.h EndGame.cpp EndGame.h Board.cpp Board.h ShipPlacement.cpp ShipPlacement.h Cell.cpp Cell.h Attack.cpp Attack.h AttackResult.cpp AttackResult.h CheatingAI.cpp CheatingAI.h RandomAI.cpp RandomAI.h HuntDestroyAI.cpp HuntDestroyAI.h)
target_include_directories(BattleshipMVC PUBLIC .)
#target_link_libraries(BattleshipMVC PUBLIC CursesWrapper)
target_compile_options(BattleshipMVC PRIVATE ${BATTLESHIP_COMPILE_OPTIONS})
target_compile_definitions(BattleshipMVC PRIVATE DEFAULT_CONFIGURATION_LOCATION="${CMAKE_SOURCE_DIR}/GameConfigurations/DefaultConfiguration.txt")
