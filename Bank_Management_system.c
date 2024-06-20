#include<stdio.h>
#include<stdlib.h>
struct Account {
    char username[50];
    char password[50];
    char address[56];
    long int citizanship_number;
    float balance;
}a;
void create_account();
void deposit();
void withdraw();
void check_balance();
void interest();
int main()
{ 
    int choice;
    printf("****Wellcome to XYZ Bank");
    printf("\nClick 1 to create a new account.\nClick 2 to deposit money.\nClick 3 to withdraw money.\nClick 4 to check balance.\nClick 5 to check your interest.\nClick 6 to exit the program.\n");
    while(1)
    {
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
             deposit();
             break;
        case 3:
             withdraw();
             break;
        case 4:
           check_balance();
           break;
        case 5:
           interest();
           break;
        case 6:
            printf("Exiting the program.\n");
             exit(0);
             break;
        
        default:
               printf("You enter wrong choice ");
               printf("Please select correct  choice");
        }
    }
    return 0 ;
}
void create_account()
{
    printf("Enter username: ");
    fflush(stdin);
    gets(a.username);
    printf("Enter your address");
    fflush(stdin);
    gets(a.address);
    printf("Enter your citizanship number");
    fflush(stdin);
    gets(a.citizanship_number);

    printf("Enter a password: ");
    fflush(stdin);
    gets(a.password);
    a.balance = 0.0f;
    printf("\nNew account created:\n");
    printf("Username: %s\n",a.username);
    printf("Password: %s\n",a.password);
    printf("Balance: $%.2f\n", a.balance);
}

void deposit()
{
    printf("Deposit function called.\n");
}

void withdraw()
{
    printf("Withdraw function called.\n");
}

void check_balance()
{
    printf("Check balance function called.\n");
}

void interest()
{
    printf("Interest function called.\n");
}