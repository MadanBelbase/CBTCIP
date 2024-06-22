#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void student_information();
void calculation();
void display();
int i,j;

struct student {
    char name[45];
    int roll_no;
    char address[90];
    char faculty[67];
    char subject[67][45];
    float marks[67];
    int nsubject;
    float average;
    float percentage;
    char grade[2]; // Grade will be a single character like "A", "B", etc.
};

struct student s[100];
int student_count = 0;

int main() {
    int choice;
    printf("****STUDENT GRADE MANAGEMENT****");
    while (1) {
        printf("\n1 For input students record.\n2 For calculating Grade, Percentage, and average score.\n3 For Display information of student.\n4 For Exit from program");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                printf("You entered the wrong choice\n");
                printf("Please select the correct choice\n");
                break;
        }
    }
    return 0;
}

void student_information() {
    int n, m, i, j;
    FILE *fp;
    fp = fopen("student_list.txt", "wb+");
    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        return;
    }
    printf("Enter the number of students to be listed: ");
    scanf("%d", &n);

    for (i = student_count; i < student_count + n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %44s", s[i].name);
        printf("Enter address of student %d: ", i + 1);
        scanf(" %89s", s[i].address);
        printf("Enter roll no of student %d: ", i + 1);
        scanf("%d", &s[i].roll_no);
        printf("Enter faculty of student %d: ", i + 1);
        scanf(" %66s", s[i].faculty);
        printf("Enter number of subjects for student %d: ", i + 1);
        scanf("%d", &s[i].nsubject);

        for (j = 0; j < s[i].nsubject; j++) {
            printf("Enter subject %d for student %d: ", j + 1, i + 1);
            scanf(" %44s", s[i].subject[j]);
            printf("Enter marks for subject %s: ", s[i].subject[j]);
            scanf("%f", &s[i].marks[j]);
        }
        fwrite(&s[i], sizeof(struct student), 1, fp);
    }
    student_count += n;
    fclose(fp);
}

void display() {
    FILE *fp ;
    fp= fopen("student_list.txt", "rb+");
    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        return;
    }

    printf("Student Information:\n");
    while (fread(&s[i], sizeof(struct student), 1, fp)) {
        printf("\nName: %s\n", s[i].name);
        printf("Roll No: %d\n", s[i].roll_no);
        printf("Address: %s\n", s[i].address);
        printf("Faculty: %s\n", s[i].faculty);
        printf("Subjects and Scores:\n");
        for (j = 0; j < s[i].nsubject; j++) {
            printf("  %s: %.2f\n", s[i].subject[j], s[i].marks[j]);
        }
        printf("Average Score: %.2f\n", s[i].average);
        printf("Percentage: %.2f%%\n", s[i].percentage);
        printf("Grade: %s\n", s[i].grade);
    }
    fclose(fp);
}

void calculation() 
{
    FILE *fp = fopen("student_list.txt", "rb+");
    if (fp == NULL) {
        printf("Error: File cannot be opened.\n");
        return;
    }

    for (i = 0; i < student_count; i++) {
        float total_marks = 0.0;
        for (j = 0; j < s[i].nsubject; j++) {
            total_marks += s[i].marks[j];
        }
        s[i].average = total_marks / s[i].nsubject;
        s[i].percentage = (total_marks / (s[i].nsubject * 100)) * 100;

        if (s[i].percentage >= 90) {
            strcpy(s[i].grade, "A");
        } else if (s[i].percentage >= 80) {
            strcpy(s[i].grade, "B");
        } else if (s[i].percentage >= 70) {
            strcpy(s[i].grade, "C");
        } else if (s[i].percentage >= 60) {
            strcpy(s[i].grade, "D");
        } else {
            strcpy(s[i].grade, "F");
        }
    }

    freopen("student_list.txt", "wb+", fp);
    fwrite(s, sizeof(struct student), student_count, fp);
    fclose(fp);
}