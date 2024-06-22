#include<stdio.h>
#include<stdlib.h>
void Expense();
void viewEx();
int main()
{
    int choice;
    printf("**---- Expense Tracker----**");
    while(1)
    {
        printf("\n1 For Add Expense.\n2 For View Expense.\n3.For Exit from program");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        { 
            case 1:
                Expense();
                break;
            case 2:
                viewEx();
                break;
            case 3:
             printf("Exiting the program.\n");
             exit(0);
             break;
        
        default:
               printf("You enter wrong choice ");
               printf("Please select correct choice \n");
               break;
        }

    }
    return 0;
}
void Expense()
{
    FILE*fp;
    fp = fopen("Expense_list.txt","wb+");
    if(fp == NULL)
    {
        printf("Error: File cannot be opened.\n");
    }
    printf("wellcome to your Expense tracker Mangement system");
    
}