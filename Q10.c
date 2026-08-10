// ATM Transaction System
//• Create a menu-driven program to check balance, deposit money, withdraw money, and exit.
//• Prevent a withdrawal when the balance is insufficient.
//• Maintain and display the last five transactions.
#include <stdio.h>
#include <string.h>

struct Transaction {
    char type[20];
    float amount;
};

int main() {
    float balance = 0.0, amount;
    int choice, i;
    struct Transaction history[5];
    int trans_count = 0;

    printf("Enter initial account balance: ");
    scanf("%f", &balance);

    while (1) {
        printf("\n--- ATM Transaction System ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Last 5 Transactions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thank you for using the ATM System. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("\nCurrent Balance: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("Invalid amount! Deposit amount must be positive.\n");
                } else {
                    balance += amount;
                    printf("Successfully deposited $%.2f. New Balance: $%.2f\n", amount, balance);

                    if (trans_count < 5) {
                        strcpy(history[trans_count].type, "Deposit");
                        history[trans_count].amount = amount;
                        trans_count++;
                    } else {
                        for (i = 0; i < 4; i++) {
                            history[i] = history[i + 1];
                        }
                        strcpy(history[4].type, "Deposit");
                        history[4].amount = amount;
                    }
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("Invalid amount! Withdrawal amount must be positive.\n");
                } else if (amount > balance) {
                    printf("Insufficient balance! Withdrawal failed.\n");
                } else {
                    balance -= amount;
                    printf("Successfully withdrew $%.2f. Remaining Balance: $%.2f\n", amount, balance);

                    if (trans_count < 5) {
                        strcpy(history[trans_count].type, "Withdrawal");
                        history[trans_count].amount = amount;
                        trans_count++;
                    } else {
                        for (i = 0; i < 4; i++) {
                            history[i] = history[i + 1];
                        }
                        strcpy(history[4].type, "Withdrawal");
                        history[4].amount = amount;
                    }
                }
                break;

            case 4:
                printf("\n--- Last 5 Transactions ---\n");
                if (trans_count == 0) {
                    printf("No transactions performed yet.\n");
                } else {
                    for (i = 0; i < trans_count; i++) {
                        printf("%d. %s: $%.2f\n", i + 1, history[i].type, history[i].amount);
                    }
                }
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}