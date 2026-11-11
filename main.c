#include <stdio.h>

typedef struct {
    char player_name[50];   
    int health;        
    const int max_health;    
    int gold;          
    int attack_power;  
} player;

int main() {
    int choice;
    int choice2;

    int *ptr1 = &choice;
    int *ptr2 = &choice2;

    player p1 = {"Curl", 50, 100, 20, 15};

    player *ptr3 = &p1;

    printf("========================================\n");
    printf("        WELCOME TO SHADOW REALM        \n");
    printf("========================================\n\n");

    printf("Player Name: %s\n", ptr3->player_name);
    printf("Player Health: %d\n", ptr3->health);
    printf("Player Gold: %d\n", ptr3->gold);
    printf("Player Attack Power: %d\n\n", ptr3->attack_power);

    while (1) {
        printf("=== MAIN MENU ===\n");
        printf("1. Play\n");
        printf("2. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", ptr1);

        switch (*ptr1) {
            case 1:
                printf("\nYou entered the dark gate of the cave. There are two paths in front of you.\n");
                printf("1. Left path (A dim light is visible)\n");
                printf("2. Right path (Pitch dark, strange noises coming)\n");
                
                printf("What is your choice? (1 or 2): ");
                scanf("%d", &choice);

                if (*ptr1 == 1) {
                    ptr3->health += 20;
                    printf("\nYou walked towards the dim light and found an old shop! The merchant gave you a free health potion. (Current Health: %d)\n\n", p1.health);
                } else if (choice == 2) {
                    ptr3->health -= 15;
                    printf("\nAs you stepped into the darkness, you slipped and fell into a pit! (Current Health: %d)\n\n", p1.health);
                } else {
                    printf("\nInvalid path selection!\n\n");
                }
                
                printf("Moving forward, you reach the main chamber of the cave! A giant red dragon is sleeping there.\n");
                printf("Behind the dragon, there is a chest filled with gold!\n\n");
                printf("1. Attack the dragon.\n");
                printf("2. Sneak past and steal the gold.\n");
                printf("3. Flee from the cave to survive.\n");

                printf("What is your choice? (1, 2, or 3): ");
                scanf("%d", ptr2);

                if (*ptr2 == 1) {
                    if (ptr3->attack_power >= 15) {
                        printf("\nYou bravely charged with your sword and defeated the dragon!\n");
                        printf(" YOU WIN THE GAME!\n\n");
                    } else {
                        printf("\nThe dragon woke up and unleashed fire! You couldn't survive.\n");
                        printf(" GAME OVER!\n\n");
                    }
                } else if (*ptr2 == 2) {
                    if (ptr3->health > 40) {
                        ptr3->gold += 500;
                        printf("\nYou carefully walked past the dragon and stole the treasure! (Current Gold: %d)\n", p1.gold);
                        printf(" SECRET ENDING UNLOCKED!\n\n");
                    } else {
                        printf("\nYour low health made you stumble. The dragon woke up and devoured you!\n");
                        printf(" GAME OVER!\n\n");
                    }
                } else if (*ptr2 == 3) {
                    printf("\nYou ran out of the cave in fear! You survived, but gained no treasure.\n\n");
                } else {
                    printf("\nInvalid action choice!\n\n");
                }
                break; 

            case 2:
                printf("Exiting game... Goodbye!\n");
                return 0; 

            default:
                printf("Invalid choice! Try again.\n\n");
        }
    }

    return 0;
}
