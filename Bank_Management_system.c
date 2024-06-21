#include<stdio.h>
#include<stdlib.h>
struct Account {
    char username[50];
    char password[50];
    char address[56];
    long int citizanship_number;
    float balance;  
    long int Account_number;
}a;
struct date {
    int dd;
    int mm;
    int yy;
}d;
void create_account();
void deposit();
void withdraw();
void check_balance();
void interest();
long int number,Account_number;
int main()
{ 
    int choice;
    long int number;
    printf("****Wellcome to XYZ Bank");
    while(1)
    {
    
    printf("\nClick 1 to create a new account.\nClick 2 to deposit money.\nClick 3 to withdraw money.\nClick 4 to check balance.\nClick 5 to check your interest.\nClick 6 to exit the program.\n");
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
               printf("Please select correct choice \n");
        }
    }
    return 0 ;
}
void create_account()
{   
    a.Account_number = 166670986;
     a.Account_number++;
    FILE *fp;
    fp = fopen("Account_list.txt","wb+");
    if(fp == NULL)
    {
     printf("Error: File cannot be opened.\n");
    }
    printf("Enter username: ");
    fflush(stdin);
    gets(a.username);
    printf("Enter your address: ");
    fflush(stdin);
    gets(a.address);
    printf("Enter your citizanship number: ");
    scanf("%ld",&a.citizanship_number);
    printf("Enter a password: ");
    fflush(stdin);
    gets(a.password);
    printf("Enter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&d.dd,&d.mm,&d.yy);
    a.balance = 0.0f;
    // Write account details to the file
    fwrite(&a, sizeof(struct Account), 1, fp);
    fwrite(&d, sizeof(struct date), 1, fp);

    // Close the file
    fclose(fp);
    printf("\nNew account created:\n");
    printf("Username: %s\n",a.username);
    printf("Address:  %s\n",a.address);
    printf("Your account number: %ld\n",a.Account_number);
    printf("Password: %s\n",a.password);
    printf("Balance: $%.2f\n", a.balance);
    printf("Date: %0d-%d-%0d\n", d.mm, d.dd, d.yy);
}
void deposit()
{ 
 float amount;
 long int acc_no;
FILE *fp,*tmp;
fp = fopen("Account_list.txt", "rb+");
tmp = fopen("temp.txt", "wb+");
   if (fp == NULL || tmp == NULL)
    {
        printf("Error: File cannot be opened.\n");
        return;
    }
    printf("Enter your account number: ");
    scanf("%ld", &acc_no);  
    while (fread(&a, sizeof(struct Account), 1, fp) == 1) {
        if (a.Account_number == acc_no) {
            printf("Enter amount to deposit: $");
            scanf("%f", &amount);

            a.balance += amount; // Update balance
            printf("Your current Amount: %f\n", a.balance);
            fwrite(&a, sizeof(struct Account), 1, tmp);
        } else {
            fwrite(&a, sizeof(struct Account), 1, tmp);
        }
    }
    fclose(fp);
    fclose(tmp);
    remove("Account_list.txt"); 
    rename("temp.txt", "Account_list.txt");
}

void withdraw()
{
float amount;
 long int acc_no;
FILE *fp,*tmp;
fp = fopen("Account_list.txt", "rb+");
tmp = fopen("temp.txt", "wb+");
   if (fp == NULL || tmp == NULL)
    {
        printf("Error: File cannot be opened.\n");
        return;
    }
    printf("Enter your account number: ");
    scanf("%ld", &acc_no);  
    while (fread(&a, sizeof(struct Account), 1, fp) == 1) {
        if (a.Account_number == acc_no) {
            printf("Enter amount to withdraw: $");
            scanf("%f", &amount);

            a.balance  = a.balance - amount; // Update balance
            printf("Your current Amount: %f\n", a.balance);
            fwrite(&a, sizeof(struct Account), 1, tmp);
        } else {
            fwrite(&a, sizeof(struct Account), 1, tmp);
        }
    }
    fclose(fp);
    fclose(tmp);
    remove("Account_list.txt"); 
    rename("temp.txt", "Account_list.txt");
   
}

void check_balance()
{
    printf("Enter your account number ");
    scanf("%ld",&number);
    if(number == a.Account_number )
    {
        printf("Your Balance is = %f\n", a.balance);
    }
    else
    {
        printf(" Please  enter correct account number:\n");
    }

}
void interest()
{
float interst_rate=0.05;
long int acc_no;
float interst;
int time =1;
FILE *fp,*tmp;
fp = fopen("Account_list.txt", "rb+");
tmp = fopen("temp.txt", "wb+");
   if (fp == NULL || tmp == NULL)
    {
        printf("Error: File cannot be opened.\n");
        return;
    }
    printf("Enter your account number: ");
    scanf("%ld", &acc_no);  
    while (fread(&a, sizeof(struct Account), 1, fp) == 1) {
        if (a.Account_number == acc_no) {
            interst = (a.balance*interst_rate*time)/100;
            printf("Your interst is: %f\n",interst);
            a.balance=a.balance+interst;
            printf("Your current Amount: %f\n", a.balance);
            fwrite(&a, sizeof(struct Account), 1, tmp);
        } else {
            fwrite(&a, sizeof(struct Account), 1, tmp);
        }
    }
    fclose(fp);
    fclose(tmp);
    remove("Account_list.txt"); 
    rename("temp.txt", "Account_list.txt");
}