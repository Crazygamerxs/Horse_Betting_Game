#include "Header.h"

// The main code
int main() {
    srand(time(NULL)); // Seed the random number generator
    WriteData();
    ReadData();

    while (user_balance > 0) {
        clearScreen(); // Clear the screen before displaying new menu
        GameMenu();

        char option;
        scanf_s(" %c", &option);
        switch (option) {
        case '1':
            clearScreen();
            Logo();
            printf("\n\n\nChoose an option:\n");
            printf("1. Bet on the horse\n");
            printf("2. Mystery Box\n");
            printf("3. Display Data\n");
            printf("4. Return to the Main Screen.\n");
            scanf_s(" %c", &option); // Read the sub-option
            switch (option) {
            case '1':
                clearScreen();
                WinningScreen(*HorseNameGenerator(), 2.0);
                (void)getchar();
                printf("Press Enter to continue...");
                break;
            case '2':
                clearScreen();
                printBox();
                MysteryBox();
                printf("Press Enter to continue...");
                (void)getchar();
                break;
            case '3':
                clearScreen();
                Logo();
                DisplayData();
                printf("Press Enter to continue...");
                while (getchar() != '\n');
                (void)getchar();
                break;
            case '4':
                break;
            default:
                printf("Invalid sub-option. Press Enter to continue...\n");
                (void)getchar(); // Wait for Enter key
            }
            break;
        case '2':
            Achievements(wins);
            (void)getchar();
            break;
        case '3':
            clearScreen();
            Instructions();
            printf("Press Enter to continue...");
            (void)getchar(); // Wait for Enter key
            break;
        case '4':
            printf("Thank you for playing! Goodbye!\n");
            return 0;
        default:
            printf("Invalid option. Press Enter to continue...");
            while (getchar() != '\n'); // Clear the input buffer
            getchar(); // Wait for Enter key
        }
    }

    ReplayGame();
    return 0;
}

