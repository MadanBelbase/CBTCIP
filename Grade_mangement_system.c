#include<stdio.h>
#include<stdlib.h>
void student_information();
void calculation();
void didsplay();
struct student
{
   char name[45];
   int roll_no;
   char address[90];
   char faculty[67];
   char subject[67][45];
   float average;
   float lowest;
   float highest;
   char grade[87];

};
int main()
{
int choice;
printf("****STUDENT GRADE MANAGEMENT****");
while(1)
{
printf(" \n 1 For input students record.\n 2 For  calculating Grade,Percentage and average score.\n 3 For Display information  of student.\n 4 For Exit from program");
printf("Enter choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
    void student_information();
    break;
case 2:
    void  calculation();
    break;
case 3:
    void  didsplay();
    break;
case 4:
    printf("Exiting the program.\n");
    exit(0);
    break;
default:
    printf("You enter wrong choice \n");
    printf("Please select correct choice \n");
    break;
}
}
return 0;
} 
void student_information()
{
   int i,n,m,j;
    struct student s[n];
    FILE *fp;
    fp = fopen("Account_list.txt","wb+");
    if(fp == NULL)
    {
     printf("Error: File cannot be opened.\n");
    }
    printf("Enter the number of students to be listed: ");
    scanf("%d", &n);
    printf("Enter the information of students");
    for(i=0;i<n;i++)
    {
    printf("Enter name of students: ");
    scanf("%s", &s[i].name);
    printf("Enter address of students: ");
    scanf("%d", &s[i].address);
    printf("enter rolll no");
    scanf("%d",&s[i].roll_no);
    printf("Enter number of subject");
    printf("Enter number of subjects for student %d: ", i + 1);
    scanf("%d", &m);
    for (j = 0; j < m; j++) {
            printf("Enter subject %d for student %d: ", j + 1, i + 1);
            scanf(" %44s", s[i].subject[j]);
        }

    }
    }

void display()
 {
    FILE *fp = fopen("Account_list.txt", "wb+");
    if (fp == NULL) 
    {
        printf("Error: File cannot be opened.\n");
        return;
    }
}
void calculation()
{    
    int i,n,m,j;
    float sum = 0.0;
        for (j = 0; j < m; j++) {
            sum += 80.0; // Assuming all subjects have a score of 80
        }
        s[i].average = sum / m;
        if (s[i].average >= 90) {
            strcpy(s[i].grade, "A");
        } else if (s[i].average >= 80) {
            strcpy(s[i].grade, "B");
        } else if (s[i].average >= 70) {
            strcpy(s[i].grade, "C");
        } else if (s[i].average >= 60) {
            strcpy(s[i].grade, "D");
        } else {
            strcpy(s[i].grade, "F");
        }
}