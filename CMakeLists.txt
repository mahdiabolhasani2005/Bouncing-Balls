cmake_minimum_required(VERSION 3.21.1)
project(BP_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(BP_Project main.cpp
        Scripts/MainMenue.h
        Scripts/GameSelect.h
        Scripts/Setting.h
        Scripts/Scoreboard.h
        Scripts/Game_time.h
        Scripts/Game_unlimited.h
        Scripts/Game_normal.h
        Scripts/Gameover.h
        Scripts/Essentials.h)

target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)


