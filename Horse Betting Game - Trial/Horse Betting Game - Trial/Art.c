#include "Header.h"

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Mystery Box
void printBox() {

    printf(ORA" ----------------------------------------------------- \n"RESET);
    printf(RED"|                      __   __                        |\n"RESET);
    printf(RED"|                     |  |_|  |                       |\n"RESET);
    printf(RED"|                     |__   __|                       |\n"RESET);
    printf(RED"|                        |_|                          |\n"RESET);
    printf(ORA"|                   _____________                     |\n"RESET);
    printf(ORA"|                   |___________|                     |\n"RESET);
    printf(ORA"|                    |         |                      |\n"RESET);
    printf(ORA"|                    |    ?    |                      |\n"RESET);
    printf(ORA"|                    |         |                      |\n"RESET);
    printf(ORA"|                    -----------                      |\n"RESET);
    printf(RED" ----------------------------------------------------- \n"RESET);

}


void printHorse() {
    printf(CYAN" ----------------------------------------------------- \n"RESET);
    printf(CYAN"|                          /|___/|                    |\n"RESET);
    printf(CYAN"|                         /|    0 |                   |\n"RESET);
    printf(CYAN"|                        /_|    /                     |\n"RESET);
    printf(CYAN"|                        / |___|                      |\n"RESET);
    printf(CYAN"|                       /__|___|                      |\n"RESET);
    printf(CYAN" ----------------------------------------------------- \n"RESET);

}
// Function to check if all achievements are unlocked
int allAchievementsUnlocked() {
    if (user_balance < 10000 || consecutive_wins < 5 || mystery_tries < 20 || wins < 20) {
        return 0;  // Not all achievements met
    }

    return 1;  // All achievements are unlocked
}

// To display Achievments
void Achievements(int wins) {
    clearScreen();

    printf("\n------------------ - Acheivements-------------------- - \n");


    if (wins == 0) {
        printf("\nTrophy Locked: You have NOT WON the game once.\n");
        printf("   //_//\n");
        printf("  ( x.x )\n");
        printf("   > ^ <\n");
    }
    else if (wins >= 1) {
        printf(BLUE"\nTrophy UNLOCKED: You have WON the game once.\n"RESET);
        printf(BLUE"   //_//\n" RESET);
        printf(BLUE"  ( o.o )\n"RESET);
        printf(BLUE"   > ^ <\n"RESET);

    }

    if (wins < 20) {
        printf("\nTrophy Locked: You have NOT WON the game 20 times.\n");
        printf("  ,,,,,\n");
        printf(" | x x |\n");
        printf(" |  >  |\n");
        printf("  `===' \n");
    }

    else if (wins >= 20) {
        printf(PINK"\nTrophy UNLOCKED: You have WON the game 20 times.\n"RESET);
        printf(PINK"  ,,,,,\n"RESET);
        printf(PINK" | o o |\n"RESET);
        printf(PINK" |  >  |\n"RESET);
        printf(PINK"  `===' \n"RESET);

    }
    // Green
    if (user_balance < 10000) {
        printf("\nTrophy Locked: You have NOT collected 10,000 coins.\n");
        printf("   .-.\n");
        printf("  ( x )\n");
        printf("   `-'\n");
    }
    else if (user_balance >= 10000) {
        printf(GREEN"\nTrophy UNLOCKED: You have collected 10,000 coins.\n"RESET);
        printf(GREEN"   .-.\n"RESET);
        printf(GREEN"  ( o )\n"RESET);
        printf(GREEN"   `-'\n"RESET);
    }

    // Lucky Charm, when the user wins 5 times in a row, color cyan 
    if (consecutive_wins < 5) {
        printf("\nTrophy Locked: You have NOT WON the game 5 times in a row\n");
        printf(" //_//\n");
        printf(" (x.x)\n");
        printf(" (> <)\n");
    }

    else if (consecutive_wins >= 5) {
        printf(ORA"\nTrophy UNLOCKED: You have WON the game 5 times in a row\n"RESET);
        printf(ORA" //_//\n"RESET);
        printf(ORA" (o.o)\n"RESET);
        printf(ORA" (> <)\n"RESET);
    }

    // Mystery Box lover, when u have played the mystery box atleast 20 times color purple
    if (mystery_tries >= 20) {
        printf(RED"Trophy UNLOCKED: you have played the mystery box atleast 20 times\n"RESET);
        printBox();
    }

    int are_UNlocked = allAchievementsUnlocked();
    if (are_UNlocked) {
        printf(CYAN"Trophy UNLOCKED: All Acheivements are UNLOCKED\n"RESET);
        printHorse();
    }
    printf("Press Enter to continue...");
    (void)getchar();

}