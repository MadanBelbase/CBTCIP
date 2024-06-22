#include<stdio.h>
#include<stdlib.h>
void Expense();
void viewEx();
int expenes,i; 
int totol_amount=0;
struct Expense {
    char category[500];
    float amount;
    char description[1000];
};
struct Expense e[100];
int main()
{
    int choice;
    printf("**---- Expense Tracker----**");
    while(1)
    {
        printf("\n1 For Add Expense.\n2 For View Expense.\n3.For Exit from program");
        printf("\nEnter your choice: ");
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
               printf("You enter wrong choice\n");
               printf("Please select correct choice \n");
               break;
        }

    }
    return 0;
}
void Expense()
{   

    int totol_amount=0,n,i;
    FILE*fp;
    fp = fopen("Expense_list.txt","wb+");
    if(fp == NULL)
    {
        printf("Error: File cannot be opened.\n");
    }
    printf("enter number of expenses you made\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
   {
    printf("\nEnter Category: ");
    scanf("%s", e[i].category);

    printf("Enter Amount: $");
    scanf("%f", &e[i].amount);

    printf("Enter Description: ");
    scanf(" %s",& e[i].description);

    totol_amount=totol_amount+e[i].amount;
    fwrite(&e[i], sizeof(struct Expense ), 1, fp);

  }
  fclose(fp);
}     
void viewEx()
{
    FILE *fp ;
    fp= fopen("Expense_list.txt", "rb+");
    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        return;
    }

    printf("Expenses Information:\n");
    while (fread(&e[i], sizeof(struct Expense), 1, fp)) 
    {
        printf("category: %s\n", e[i].category);
        printf("Amount: %f\n", e[i].amount);
        printf("Description: %s\n", e[i].description);
        totol_amount=totol_amount+e[i].amount;
        
    }
    printf("Total Amount: %d\n", totol_amount);
    fclose(fp);
}