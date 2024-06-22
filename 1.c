#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student {
    char name[45];
    int roll_no;
    char address[90];
    char faculty[67];
    char subject[100][45];
    float average;
    float lowest;
    float highest;
    char grade[87];
};

void student_information();
void calculation();
void display();

struct student s[100]; // Array to hold student records
int i, j, m;
int main() {
    int choice;
    printf("****STUDENT GRADE MANAGEMENT****");
    while(1) {
        printf(" \n 1 For input students record.\n 2 For calculating Grade, Percentage, and average score.\n 3 For Display information of student.\n 4 For Exit from program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                student_information();
                break;
            case 2:
                calculation();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("You entered the wrong choice.\n");
                printf("Please select the correct choice.\n");
                break;
        }
    }
    return 0;
}

void student_information() {
    int i, n, j, m;
    FILE *fp;
    fp = fopen("student_list.txt", "ab+");
    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        return;
    }

    printf("Enter the number of students to be listed: ");
    scanf("%d", &n);

    printf("Enter the information of students\n");
    for (i = 0; i < n; i++) {
        printf("Enter name of student: ");
        scanf(" %44s", s[i].name);  
        printf("Enter address of student: ");
        scanf(" %89s", s[i].address); 
        printf("Enter roll no: ");
        scanf("%d", &s[i].roll_no);
        printf("Enter faculty: ");
        scanf(" %66s", s[i].faculty); 
        printf("Enter number of subjects for student %d: ", i + 1);
        scanf("%d", &m);
        for (j = 0; j < m; j++) {
            printf("Enter subject %d: ", j + 1);
            scanf(" %44s", s[i].subject[j]);
        }
        fwrite(&s[i], sizeof(struct student), 1, fp);
    }
    fclose(fp);
}

void calculation() {
    int i, j, m,n;
    FILE *fp;
    fp = fopen("Student_list.txt", "rb+");
    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fread(&s[i], sizeof(struct student), 1, fp);
        float sum = 0.0;
        float highest = 0.0;
        float lowest =0.0;
        for (j = 0; j < m; j++) {
            float score;
            printf("Enter score for %s in subject %s: ", s[i].name, s[i].subject[j]);
            scanf("%f", &score);
            sum += score;
            if (score > highest) {
                highest = score;
            }
            if (score < lowest) {
                lowest = score;
            }
        }
        s[i].average = sum / m;
        s[i].highest = highest;
        s[i].lowest = lowest;
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
        fseek(fp, -sizeof(struct student), SEEK_CUR);
        fwrite(&s[i], sizeof(struct student), 1, fp);
    }
    fclose(fp);
}

void display() {
    FILE *fp;
    fp = fopen("student_list.txt", "rb");
    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        return;
    }

    printf("Student Information:\n");
    while (fread(&s, sizeof(struct student), 1, fp)) {
        printf("\nName: %s\n", s[i].name);
        printf("Roll No: %d\n", s[i].roll_no);
        printf("Address: %s\n", s[i].address);
        printf("Faculty: %s\n", s[i].faculty);
        printf("Subjects and Scores:\n");
        for (int j = 0; j < m; j++) {
            printf("  %s\n", s[i].subject[j]);
        }
        printf("Average Score: %.2f\n", s[i].average);
        printf("Highest Score: %.2f\n", s[i].highest);
        printf("Lowest Score: %.2f\n", s[i].lowest);
        printf("Grade: %s\n", s[i].grade);
       i++;
    }
    fclose(fp);
}