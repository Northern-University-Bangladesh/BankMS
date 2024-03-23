#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define FILENAME "accounts.txt"

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int account_number;
    char name[50];
    Date dob; // Date of birth
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

// Function prototypes
void create_account();
void update_account();
void transactions();
void check_account();
void delete_account();
void view_customer_list();
void bank_loan();
void foreign_currency_exchange();
void save_data();
void load_data();

int main() {
    load_data();
    int choice;

    do {
        printf("\nBank Management System\n");
        printf("1. Create new account\n");
        printf("2. Update existing account\n");
        printf("3. Transactions Module\n");
        printf("4. Check existing account details\n");
        printf("5. Delete Account\n");
        printf("6. View Customer List\n");
        printf("7. Bank loan\n");
        printf("8. Foreign currency exchange\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account();
                break;
            case 2:
                update_account();
                break;
            case 3:
                transactions();
                break;
            case 4:
                check_account();
                break;
            case 5:
                delete_account();
                break;
            case 6:
                view_customer_list();
                break;
            case 7:
                bank_loan();
                break;
            case 8:
                foreign_currency_exchange();
                break;
            case 9:
                save_data();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 9);

    return 0;
}

void create_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Limit reached.\n");
        return;
    }

    Account new_account;
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);

    printf("Enter name: ");
    getchar(); // Consume the newline character left in the buffer
    fgets(new_account.name, sizeof(new_account.name), stdin);
    new_account.name[strcspn(new_account.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &new_account.dob.day, &new_account.dob.month, &new_account.dob.year);

    printf("Enter initial balance: ");
    scanf("%f", &new_account.balance);

    accounts[num_accounts++] = new_account;
    printf("Account created successfully.\n");
}

void update_account() {
    int account_num;
    printf("Enter account number to update: ");
    scanf("%d", &account_num);

    int found = 0;
    for (int i = 0; i < num_accounts; ++i) {
        if (accounts[i].account_number == account_num) {
            printf("Enter new name: ");
            getchar(); // Consume the newline character left in the buffer
            fgets(accounts[i].name, sizeof(accounts[i].name), stdin);
            accounts[i].name[strcspn(accounts[i].name, "\n")] = '\0'; // Remove trailing newline

            printf("Enter new date of birth (DD MM YYYY): ");
            scanf("%d %d %d", &accounts[i].dob.day, &accounts[i].dob.month, &accounts[i].dob.year);

            printf("Enter new balance: ");
            scanf("%f", &accounts[i].balance);
            found = 1;
            printf("Account updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}



void transactions() {
    // Implement transaction functionality here
    printf("This feature is not implemented yet.\n");
}

void check_account() {
    int account_num;
    printf("Enter account number to check: ");
    scanf("%d", &account_num);

    int found = 0;
    for (int i = 0; i < num_accounts; ++i) {
        if (accounts[i].account_number == account_num) {
            printf("Account number: %d\n", accounts[i].account_number);
            printf("Name: %s\n", accounts[i].name);
            printf("Date of Birth: %d-%d-%d\n", accounts[i].dob.day, accounts[i].dob.month, accounts[i].dob.year);
            printf("Balance: %.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void view_customer_list() {
    printf("Customer List:\n");
    for (int i = 0; i < num_accounts; ++i) {
        printf("Account number: %d, Name: %s, Date of Birth: %d-%d-%d, Balance: %.2f\n",
               accounts[i].account_number, accounts[i].name, accounts[i].dob.day, accounts[i].dob.month,
               accounts[i].dob.year, accounts[i].balance);
    }
}

void delete_account() {
    int account_num;
    printf("Enter account number to delete: ");
    scanf("%d", &account_num);

    int found = 0;
    for (int i = 0; i < num_accounts; ++i) {
        if (accounts[i].account_number == account_num) {
            for (int j = i; j < num_accounts - 1; ++j) {
                accounts[j] = accounts[j + 1];
            }
            num_accounts--;
            found = 1;
            printf("Account deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void bank_loan() {
    // Implement bank loan functionality here
    printf("This feature is not implemented yet.\n");
}

void foreign_currency_exchange() {
    // Implement foreign currency exchange functionality here
    printf("This feature is not implemented yet.\n");
}

void save_data() {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < num_accounts; ++i) {
        fprintf(fp, "%d %s %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }

    fclose(fp);
}

void load_data() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (!feof(fp)) {
        fscanf(fp, "%d %s %f\n", &accounts[num_accounts].account_number, accounts[num_accounts].name, &accounts[num_accounts].balance);
        num_accounts++;
    }

    fclose(fp);
}
