# BallBash

A bubble-shooter game written in C++ with SDL2, built as a first-year
programming project at Sharif University of Technology (2023).

Balls sit on a hexagonal grid; you aim and shoot from the bottom, and
matching clusters pop. Three modes (normal, timed, endless), power-ups
(bomb, plasma ball), selectable themes, adjustable music and SFX volume,
and a persistent multi-user scoreboard.

## Building

Requires SDL2 with SDL2_image, SDL2_ttf, SDL2_mixer and SDL2_gfx.

    cmake -B build
    cmake --build build

Run from inside the build directory — asset paths are relative (`../Data/`).

## Layout

    main.cpp            entry point and screen loop
    Scripts/Essentials.h    hex-grid geometry, shared structs
    Scripts/Game_*.h        the three game modes
    Scripts/MainMenue.h, GameSelect.h, Setting.h, Scoreboard.h, Gameover.h
    Data/               images, fonts, music, sound effects, saves

## Assets

UI sprites from Kenney (CC0). Music from chosic.com.

## Status

Coursework, not maintained. In `main.cpp` the normal and endless modes are
currently commented out of the screen loop; only timed mode is wired up.
