#pragma once
#include <stdint.h>

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


static const int InitialWidth = 1200;
static const int InitialHeight = 800;

#ifdef PAL
#define NUP1S 10
#else
#define NUP1S 9
#endif
#define NUP0S 5

//
// GAME CONSTS
//

const uint8_t TOP = 0xA0;
const uint8_t DEAD = 0xD0;
const uint8_t SUPRESS = 0XFF;
const uint8_t FBSPEED = 2;
const uint8_t WINDOW = 20;
const uint8_t CAVECLR = 0x0A;

//
// SOUND ENUM
//

typedef enum Sounds {
	FIRES,
	BONSND,
	JUMPS,
	EXSND,
	DEATHS
} Sounds;

//
// GLOBALS
//

static uint16_t RAND = 0;
static uint8_t FLAGS = 0; //D7 = 0 = LOGO, D6 = 1, SHOW VERSION NUM D0 = RESET SWITCH
static uint8_t EYETOP = 0; //UPPER LIMIT OF EYE
static uint8_t EYEBOT = 0; //LOWER LIMIT OF EYE
static uint8_t NEWCNT = 0; //COUNTER FOR NEW BOARD SETUP
static uint8_t ATTRACT = 0;
static uint8_t GAMESTAT = 0; //D7 RESET = CASTLE SCREEN, D6 RESET = ATTR
static uint8_t PLYRSTAT = 0; //D7 SET=PLAYER INIT
static uint8_t DRAGSTAT = 0; //D6 SET=FLAMING
static uint8_t REFSHAD = 0; //REFLECT FOR PLAYER
static uint8_t GSEL = 0; //SELECT TIMER
static uint8_t GAMNUM = 0; //GAME NUMBER
static uint8_t T0 = 0;
static uint8_t T1 = 0;
static uint8_t T2 = 0;
static uint8_t T3 = 0;
static uint8_t CX = 0; //COLLISION POINTER
static uint16_t LIVES = 0; //LIFE COUNTERS
static uint8_t P1POINT = 0;
static uint8_t P0POINT = 0;
static uint8_t COUNT = 0;

typedef struct{
	uint8_t P0XS[NUP0S];
	uint8_t DRAGONX;
	uint8_t EYEX;
	uint8_t PLAYERX;
}Positions;
static Positions XPOS = { 0 };

static uint8_t PLAYERY = 0;
static uint8_t PLAYNO = 0; //PLAYER UP
static uint8_t WAVENO = 0; //WAVE NUM
static uint16_t FRAME = 0; //16 BIT FRAME COUNTER
static uint8_t DEATH = 0; //DEATH FLAG

static uint8_t PLAYERLX = 0;
static uint8_t PLAYERLY = 0;
static uint8_t PLAYERDX = 0;
static uint8_t PLAYERDY = 0;

static uint8_t DRAGONDX = 0; //DRAGON DELTA

static uint16_t SCOREL0 = 0; //LO SCORE
static uint16_t SCOREM0 = 0; 
static uint16_t SCOREH0 = 0;

static uint8_t P1HMS[NUP1S] = { 0 }; //LIST OF HMOVES FOR P1'S
static uint8_t P0HMS[NUP0S] = { 0 };
static uint8_t DRAGONHM = 0;
static uint8_t EYEHM = 0;
static uint8_t PLAYERHM = 0;

static uint8_t P0YS[NUP0S] = { 0 };
static uint8_t P0Y = 0;
static uint8_t P1ID[NUP1S] = { 0 };
static uint8_t P0ID[NUP0S] = { 0 };

typedef enum Player0IDs {
	RATTIME, //RAT TIMER
	ARROWTIM, //ARROW TIMER
	RATHM, //RAT HMOVE
	ARROWHM //ARROW HMOVE
}Player0IDs;

static uint8_t PLAYERID = 0;
static uint8_t* P1INDCLR = NULL;
static uint8_t* P0INDCLR = NULL;
static uint8_t* P1IND = NULL;
static uint8_t* P0IND = NULL;

static uint8_t DRAGTIME = 0; //DRAGON FLAMING TIMER
static uint8_t DRAGONAN = 0;

static uint16_t DRAGH0 = 0;
static uint16_t DRAGH1 = 0;
static uint16_t DRAGH2 = 0;
static uint16_t DRAGH3 = 0;
static uint16_t DELAY = 0;
static uint16_t SIXIND5 = 0;
static uint8_t CAVESHAD = 0; //SHADOW CAVE COLOR
static uint8_t SND1 = 0; //SOUND ID
static uint8_t SND1TIME = 0; //SOUND TIMER
static uint8_t JUMPTIME = 0;
static uint8_t SELTIME = 0; //SELECT SWITCH TIMER
static uint8_t SEA = 0;



static uint8_t* ROM = NULL;
const uint16_t OffsetATREAS = 0xD00;
const uint16_t OffsetMAN0 = 0xC00;
const uint16_t OffsetTREASCLR = 0xF00;
const uint16_t OffsetMAN0C = 0xE80;
const uint16_t OffsetOFFSET = 0xF9C;