#pragma once
#define __STDC_WANT_LIB_EXT1__ 1
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> 
#include <windows.h>

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"
#define PINK   "\x1B[38;5;207m"  
#define ORA     "\x1b[38;2;255;215;0m"

// Global variables
extern char horse_names[5][20]; // List to store horse names (assuming there are 5 horses)
extern float horse_odds[5];  // List to store horse odds (assuming there are 5 horses)
extern float user_balance;  // Initial balance for the user
extern char username[100];
extern int wins;
extern int consecutive_wins;
extern int mystery_tries;


// Declare a global variable to store the winning horse name
char winning_horse[20];
#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50



extern struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

extern struct User users[MAX_USERS];
extern int numUsers;

// Function prototypes
void WriteData();
void ReadData();
void DisplayData();
void MysteryBox();
void HorseOptions();
char* HorseNameGenerator();
void WinningGenerator(int* multiplier);
void WinningScreen(int multiplier);
void ReplayGame();

// The updated game
void GameMenu();
void Instructions();
void clearScreen();
void Achievements(int wins);
void printBox();
void printHorse();
void Logo();