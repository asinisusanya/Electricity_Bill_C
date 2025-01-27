/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

void calculateBill(float units, float *charge) {
    if (units < 500) {
        *charge = units * 1.00;
    } else if (units < 600) {
        *charge = (500 * 1.00) + ((units - 500) * 1.80);
    } else if (units < 800) {
        *charge = (500 * 1.00) + (100 * 1.80) + ((units - 600) * 2.00);
    } else {
        *charge = (500 * 1.00) + (100 * 1.80) + (200 * 2.00) + ((units - 800) * 3.00);
    }
}

void printBill(char *customerID, char *customerName, float units, float charge) {
    printf("\n====================================\n");
    printf("         ELECTRICITY BILL            \n");
    printf("====================================\n\n");
    printf("Customer ID   : %s\n", customerID);
    printf("Customer Name : %s\n", customerName);
    printf("Units        : %.2f\n", units);
    printf("Total Amount : $%.2f\n", charge);
    printf("\nThank you!\n");
    printf("====================================\n");
}

int main() {
    char customerID[10];
    char customerName[MAX_NAME];
    float units, charge;
    char choice;

    do {
        // Clear the screen (works on both Windows and Unix-like systems)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\nELECTRICITY BILLING SYSTEM\n");
        printf("====================================\n\n");

        // Get customer details
        printf("Enter Customer ID: ");
        scanf("%s", customerID);
        
        // Clear input buffer
        while (getchar() != '\n');

        printf("Enter Customer Name: ");
        fgets(customerName, MAX_NAME, stdin);
        customerName[strcspn(customerName, "\n")] = 0; // Remove trailing newline

        printf("Enter Units Consumed: ");
        scanf("%f", &units);

        // Calculate bill
        calculateBill(units, &charge);

        // Print bill
        printBill(customerID, customerName, units, charge);

        printf("\nDo you want to calculate another bill? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Electricity Billing System!\n");

    return 0;
}