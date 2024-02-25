#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FoodItem {
    char name[50];
    double price;
    struct FoodItem* next;
};

struct FoodItem* createFoodItem(char* name, double price) {
    struct FoodItem* newItem = (struct FoodItem*)malloc(sizeof(struct FoodItem));
    if (newItem == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    strcpy(newItem->name, name);
    newItem->price = price;
    newItem->next = NULL;
    return newItem;
}

int main() {
    struct FoodItem* menuA = NULL; 
    struct FoodItem* menuB = NULL; 
    double totalExpense = 0;
    int choice, quantity;
    double budget;
    int townChoice;

    printf("Welcome to the Local Town Food Expense Calculator!\n");
    printf("**************************************************\n");
    printf("Enter your budget: ₹");
    scanf("%lf", &budget);
    printf("Choose your current town:\n");
    printf("1. Kalamassery\n");
    printf("2. Edappally\n");
    printf("Enter your choice: ");
    scanf("%d", &townChoice);
    while (1) {
        printf("\nFood Menu:\n");
        if (townChoice == 1) {
            printf("Kalamassery usual food list:\n");
        } else if (townChoice == 2) {
            printf("Edappally usual food list:\n");
        } else {
            printf("Invalid town choice. Please select a valid town.\n");
            break;
        }

        printf("1. Burger\n");
        printf("2. Fried Chicken\n");
        printf("3. Mandi\n");
        printf("4. Pasta\n");
        printf("5. Biriyani Full\n");
        printf("6. Fried Rice veg\n");
        printf("7. Fried Rice chicken\n");
        printf("8. Tea and Snack\n");
        printf("9. Meals\n");
        printf("10. Check Out\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9) {
            struct FoodItem* selectedMenu = (townChoice == 1) ? menuA : menuB;
            char itemName[50];
            double itemPrice;

            switch (choice) {
                case 1:
                    strcpy(itemName, "Burger");
                    itemPrice = (townChoice == 1) ? 120.0 : 180.0;
                    break;
                case 2:
                    strcpy(itemName, "Fried Chicken");
                    itemPrice = (townChoice == 1) ? 120.0 : 120.0;
                    break;
                case 3:
                    strcpy(itemName, "Mandi");
                    itemPrice = (townChoice == 1) ? 160.0 : 180.0;
                    break;
                case 4:
                    strcpy(itemName, "Pasta");
                    itemPrice = (townChoice == 1) ? 140.0 : 180.0;
                    break;
                case 5:
                    strcpy(itemName, "Biriyani Full");
                    itemPrice = (townChoice == 1) ? 120.0 : 160.0;
                    break;
                case 6:
                    strcpy(itemName, "Fried Rice veg");
                    itemPrice = (townChoice == 1) ? 70.0 : 75.0;
                    break;
                case 7:
                    strcpy(itemName, "Fried Rice chicken");
                    itemPrice = (townChoice == 1) ? 90.0 : 120.0;
                    break;
                case 8:
                    strcpy(itemName, "Tea and Snack");
                    itemPrice = (townChoice == 1) ? 32.0 : 40.0;
                    break;
                case 9:
                    strcpy(itemName, "Meals");
                    itemPrice = (townChoice == 1) ? 70.0 : 70.0;
                    break;
            }

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            struct FoodItem* newItem = createFoodItem(itemName, itemPrice);
            newItem->next = selectedMenu;
            if (townChoice == 1) {
                menuA = newItem;
            } else {
                menuB = newItem;
            }

            totalExpense += itemPrice * quantity;
            printf("Added %d %s. Total expense: ₹%.2f\n", quantity, itemName, totalExpense);
        } else if (choice == 10) {
            printf("Thank you for using the Food Expense Calculator!\n");

            if (totalExpense <= budget) {
                printf("Your expenses are within budget. Great job!\n");
            } else {
                printf("Your expenses exceeded the budget. Please consider revising your spending.\n");
            }
            break;
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }
    
    struct FoodItem* current = menuA;
    while (current != NULL) {
        struct FoodItem* temp = current;
        current = current->next;
        free(temp);
    }

    current = menuB;
    while (current != NULL) {
        struct FoodItem* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
