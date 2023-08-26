#include "Header.h"

char horse_names[5][20]; // Definition of global variables
float horse_odds[5];
float user_balance = 1000.0;
char username[100];

struct User users[MAX_USERS];
int numUsers = 0;

char winning_horse[20] = { "\0" };
int wins = 0;
int consecutive_wins = 0;
int mystery_tries = 0;

// Function to write data to a file
void WriteData() {
    FILE* file = fopen("horse_betting_data.txt", "w");
    if (file != NULL) {
        // Generate and write horse names and odds to the file
        for (int i = 0; i < 5; i++) {
            horse_odds[i] = (rand() % 100) / 10.0 + 1.0; // Random odds between 1.0 and 10.0
            fprintf(file, "%s %f\n", HorseNameGenerator(), horse_odds[i]);
        }
        fprintf(file, "%.2f\n", user_balance);
        fclose(file);
    }
}


// Function to read data from a file
void ReadData() {
    FILE* file = fopen("horse_betting_data.txt", "r");
    if (file != NULL) {
        for (int i = 0; i < 5; i++) {
            fscanf(file, "%s %f", horse_names[i], &horse_odds[i]);
        }
        fscanf(file, "%f", &user_balance);
        fclose(file);
    }
    else {
        // Create a default set of horse_names and horse_odds
        strcpy(horse_names[0], "Horse1");
        horse_odds[0] = 2.0;
        strcpy(horse_names[1], "Horse2");
        horse_odds[1] = 3.5;
        strcpy(horse_names[2], "Horse3");
        horse_odds[2] = 4.2;
        strcpy(horse_names[3], "Horse4");
        horse_odds[3] = 5.1;
        strcpy(horse_names[4], "Horse5");
        horse_odds[4] = 6.8;
        WriteData();
    }
}

// Function to generate the winning horse and multiplier
void WinningGenerator(int* multiplier) {
    int index = rand() % 5;
    strcpy(winning_horse, horse_names[index]);
    *multiplier = horse_odds[index];
}


// Function to display user's data
void DisplayData() {
    printf("Your current balance: %.2f\n", user_balance);
    printf("Horse options and their odds:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - %.2f\n", horse_names[i], horse_odds[i]);
    }
}


// Function to provide a mystery box reward
void MysteryBox() {
    int reward = rand() % 50 + 1;
    user_balance += reward;
    printf("Congratulations! You won %.2f from the mystery box!\n", (float)reward);
    mystery_tries++;
    (void)getchar();
}

// Function to display horse options for betting
void HorseOptions() {
    DisplayData();
    printf("Choose a horse to bet on: \n");
}


// Function to generate a random horse name
char* HorseNameGenerator() {
    static char horse_name[20];
    char* names[] = { "Pegasus", "Thunderbolt", "Silver Shadow", "Golden Hoof", "Blazing Comet", "Golden Hoof", "Blazing Comet", "Silver Shadow", "Dancing Star", "Midnight Thunder", "Royal Majesty", "Sapphire Dream", "Emerald Starlight", "Crimson Firefly", "Whispering Willow", "Majestic Moonbeam", "Amber Aurora", "Velvet Sky", "Radiant Rose", "Mystic Mirage", "Enchanted Ember", "Charming Serenade", "Dazzling Dewdrop", "Gentle Breeze", "Graceful Gallop", "Moonlit Melody", "Twilight Symphony", "Sunny Mirage", "Glimmering Gaze", "Whimsical Whisper", "Velvet Moonlight", "Spirited Sparkle", "Eternal Echo", "Magic Mist", "Harmony's Heart", "Celestial Cascade", "Starlight Sonata", "Ebon Nightfall", "Sparkling Stardust", "Violet Veil", "Ivory Illusion", "Fleeting Fireworks", "Silent Serenity", "Radiant Raindrop", "Majestic Mirage", "Golden Glitter", "Mystical Mariposa", "Azure Zephyr", "Crimson Harmony", "Midnight Mirage", "Dreamy Drizzle", "Moonlit Melody", "Whispering Willow", "Dancing Dusk" };
    int index = rand() % 50;
    strcpy(horse_name, names[index]);
    return horse_name;
}




// Function to display the winning/losing screen
void WinningScreen(int multiplier) {
    clearScreen();
    char chosen_horse[20] = { "\0" };
    int user_bet;
    int i;

    // Generate the winning horse and multiplier before betting
    WinningGenerator(&multiplier);

    while (1) { // Loop until a valid horse choice is made
        clearScreen();
        printHorse();
        HorseOptions();
        scanf("%s", chosen_horse);

        for (i = 0; i < 5; i++) {
            if (strcmp(chosen_horse, horse_names[i]) == 0)
                break;
        }

        if (i == 5) {
            printf("Invalid horse selection. Please try again.\n");
        }
        else {
            break; // Valid horse choice, exit the loop
        }

    }

    printf("Enter your bet amount: ");
    scanf("%d", &user_bet);

    clearScreen();
    if (user_bet <= user_balance) {
        int payout = user_bet * multiplier;
        printHorse();
        printf("The race is over! The winning horse is: %s\n", winning_horse);

        if (strcmp(chosen_horse, winning_horse) == 0) {

            user_balance += payout;
            printf("Congratulations! Your horse '%s' won! You won %d!\n", winning_horse, payout);
            printf("Your current balance: %.2f\n", user_balance);
            wins++;
            consecutive_wins++;
            (void)getchar();
            ReplayGame();
        }
        else {

            user_balance -= user_bet;
            printf("Unfortunately, your horse '%s' lost. You lost %d.\n", chosen_horse, user_bet);
            printf("Your current balance: %.2f\n", user_balance);
            consecutive_wins == 0;
            (void)getchar();
            ReplayGame();
        }
    }
    else {
        printf("Insufficient balance. Please place a valid bet.\n");
    }
}

// To print the logo
void Logo() {
    printf(" ---------------------------------------------------------------- \n");
    printf("|                                                                |\n");
    printf("|                       Horse Betting Game                       |\n");
    printf("|                                                                |\n");
    printf(" ---------------------------------------------------------------- \n");
}

// To print the game menu
void GameMenu() {
    Logo();
    printf("\n\n\n1. Play ");
    printf("\n2. Achievements");
    printf("\n3. Instructions");
    printf("\n4. Exit");
    printf("\n");

}

// Function to replay the game
void ReplayGame() {
    if (user_balance <= 0) {
        printf("Not Enough Balance\n");
        return;
    }
    else {

        char play_again;
        printf("\nDo you want to play again? (y/n): ");
        scanf("%c", &play_again);
        (void)getchar(); // Clear the newline character left in the input buffer
        if (play_again == 'y' || play_again == 'Y') {
            WinningScreen(*HorseNameGenerator(), 2.0);
        }
        else {
            printf("Thank you for playing! Goodbye!\n");
            return 0; 
        }
    }
}

// Function for the WelcomeScreen()(will have instructions on how to play the game)
void Instructions() {
    Logo();
    printf("Welcome to the Horse Betting Game!\n");
    printf("Instructions: \n");
    printf("1. You start with $1000 in your balance.\n");
    printf("2. Choose a horse to bet on and enter your bet amount.\n");
    printf("3. If your chosen horse wins, you get the payout based on the odds.\n");
    printf("4. If your chosen horse loses, you lose your bet amount.\n");
    printf("5. You can also get a mystery box reward with a random amount between $1 and $50.\n");
    printf("6. Keep playing until you run out of money or choose to exit the game.\n");
    printf("7. Good luck and have fun!\n\n");
    (void)getchar();
}


