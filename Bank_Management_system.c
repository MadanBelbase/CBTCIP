//Bank mangement system
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Account {
    char username[50];
    char password[50];
    char address[56];
    long int citizanship_number;
    float balance;  
    long int Account_number;
    char account_type[67];
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
    printf("Enter username: \n");
    getchar();  
    fgets(a.username, sizeof(a.username), stdin);
    strtok(a.username, "\n"); 
    printf("Enter your address: \n");
    getchar();
    fgets(a.address, sizeof(a.address), stdin);
    strtok(a.address, "\n");
    printf("Enter Account Type: \n");
     printf("1.Checking account\n2.salary Account\n3.saving Account\n");
    getchar();
    fgets(a.account_type, sizeof(a.account_type), stdin);
    strtok(a.account_type, "\n"); 
    printf("Enter your citizanship number: \n");
    getchar();
    scanf("%ld",&a.citizanship_number);
    printf("Password must be in character\n");
    printf("Enter your password: ");
    getchar();
    fgets(a.password, sizeof(a.password), stdin);
    strtok(a.password, "\n");
    printf("Enter today's date(dd/mm/yyyy): \n");
    scanf("%d/%d/%d",&d.dd,&d.mm,&d.yy);
    a.balance = 0.0f;
    // Write account details to the file
    fwrite(&a, sizeof(struct Account), 1, fp);
    fwrite(&d, sizeof(struct date), 1, fp);

    // Close the file
    fclose(fp);
    printf("\nNew account created:\n");
    printf("ACcount type: %s\n",a.account_type);
    printf("Username: %s\n",a.username);
    printf("Address:  %s\n",a.address);
    printf("Your account number: %ld\n",a.Account_number);
    printf("Password: %s\n",a.password);
    printf("Balance: $%.f\n", a.balance);
    printf("Date: %d/%d/%d\n",d.dd,d.mm,d.yy);
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
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            a.balance += amount; // Update balance
            printf("Your current Amount: %f\n", a.balance);
            fwrite(&a, sizeof(struct Account), 1, tmp);
        } else {
            printf("Enter correct account number");
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
        } else 
        {
            printf("Enter correct account number and type");
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
    float interst_rate;
    long int acc_no;
    float interst;
    int time = 1, data;
    FILE *fp, *tmp;
    
    fp = fopen("Account_list.txt", "rb+");
    tmp = fopen("temp.txt", "wb+");
    
    if (fp == NULL || tmp == NULL)
    {
        printf("Error: File cannot be opened.\n");
        return;
    }
    
    printf("Enter your account number: ");
    scanf("%ld", &acc_no);
    getchar(); 
    
    while (fread(&a, sizeof(struct Account), 1, fp) == 1) 
    {   
        printf("Enter your account type\n");
        printf("1. For Checking account enter 1\n");
        printf("2. For Salary Account enter 2\n");
        printf("3. For Saving Account enter 3\n");
        scanf("%d", &data);
        getchar(); 
        
        if (a.Account_number == acc_no && data == 1) 
        {   
            interst_rate = 0.1;
            interst = (a.balance * interst_rate * time) / 100;
            printf("Your interest is: %f\n", interst);
            a.balance += interst;
            printf("Your current Amount: %f\n", a.balance);
            fwrite(&a, sizeof(struct Account), 1, tmp);
        }
        else if (a.Account_number == acc_no && data == 2) 
        {   
            interst_rate = 0.15;
            interst = (a.balance * interst_rate * time) / 100;
            printf("Your interest is: %f\n", interst);
            a.balance += interst;
            printf("Your current Amount: %f\n", a.balance);
            fwrite(&a, sizeof(struct Account), 1, tmp);
        }
        else if (a.Account_number == acc_no && data == 3) 
        {   
            interst_rate = 0.2;
            interst = (a.balance * interst_rate * time) / 100;
            printf("Your interest is: %f\n", interst);
            a.balance += interst;
            printf("Your current Amount: %f\n", a.balance);
            fwrite(&a, sizeof(struct Account), 1, tmp);
        }
        else 
        {
            printf("Enter correct account number and type");
            fwrite(&a, sizeof(struct Account), 1, tmp);
        }
    }
    
    fclose(fp);
    fclose(tmp);
    remove("Account_list.txt"); 
    rename("temp.txt", "Account_list.txt");
}