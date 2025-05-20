/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event 
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial 
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you 
--  wrote the original software. If you use this software in a product, an acknowledgment 
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/

#include "raylib.h"
#include "raymath.h"

#include "game.h"   // an external header in this project
#include "lib.h"	// an external header in the static lib project

unsigned char _rotl(const unsigned char value, int shift) {
    if ((shift &= sizeof(value) * 8 - 1) == 0)
        return value;
    return (value << shift) | (value >> (sizeof(value) * 8 - shift));
}

unsigned char _rotr(const unsigned char value, int shift) {
    if ((shift &= sizeof(value) * 8 - 1) == 0)
        return value;
    return (value >> shift) | (value << (sizeof(value) * 8 - shift));
}

void SetupCastle() {
    GAMESTAT = _rotl(GAMESTAT, 1); // ??
    GAMESTAT = _rotr(GAMESTAT, 1);
    P0ID[ARROWHM] = 0x60;
    P0ID[RATHM] = 0x60;
    XPOS.PLAYERX = 0x8C;
    NEWCNT = NUP1S - 1;

    for (int i = 0; i < NUP0S - 1; i++) {
        P0YS[i] = DEAD;
    }
}

void GameInit()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(InitialWidth, InitialHeight, "Example");
    SetTargetFPS(144);

    int dataSize = 0;
    ROM = LoadFileData("GAME.BIN", &dataSize);

    // load resources

    // Initialise vars
    ATTRACT--;
    SetupCastle();

    XPOS.PLAYERX = 150;
    PLAYERY = 150;
    RAND = 0x9611;

    // Setup obj pointers
    P1IND = ROM + OffsetATREAS;
    P0IND = ROM + OffsetMAN0;
    P1INDCLR = ROM + OffsetTREASCLR;
    P0INDCLR = ROM + OffsetMAN0C;

    // SET UP DRAGONS EYE OR FLAME
    uint8_t offset = _rotl(DRAGONDX, 2) & 3 ;
}

void GameCleanup()
{
    UnloadFileData(ROM);

    CloseWindow();
}

bool GameUpdate()
{

    return true;
}

void GameDraw()
{
    BeginDrawing();
    ClearBackground(DARKGRAY);

    DrawText("Hello Raylib!", 10, 10, 20, GetTextColor());

    EndDrawing();
}

int main()
{
    GameInit();

    while (!WindowShouldClose())
    {
        if (!GameUpdate())
            break;

        GameDraw();
    }
    GameCleanup();

    return 0;
}