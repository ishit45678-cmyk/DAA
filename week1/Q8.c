//Student Result Analysis
//• Store the roll number, name, and marks in five subjects for N students using structures.
//• Calculate the total, percentage, and grade of each student.
//• Display the class topper, students who failed in one or more subjects, and the class average.
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
    int failed;
};

int main() {
    int n, i, j;
    float class_total_marks = 0.0;
    int topper_index = 0;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students.\n");
        return 0;
    }

    struct Student s[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);
        
        printf("Enter Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;
        s[i].failed = 0;

        for (j = 0; j < 5; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
            if (s[i].marks[j] < 40.0) {
                s[i].failed = 1;
            }
        }

        s[i].percentage = s[i].total / 5.0;

        if (s[i].failed) {
            s[i].grade = 'F';
        } else if (s[i].percentage >= 90) {
            s[i].grade = 'A';
        } else if (s[i].percentage >= 75) {
            s[i].grade = 'B';
        } else if (s[i].percentage >= 60) {
            s[i].grade = 'C';
        } else if (s[i].percentage >= 40) {
            s[i].grade = 'D';
        } else {
            s[i].grade = 'F';
        }

        class_total_marks += s[i].total;

        if (s[i].total > s[topper_index].total) {
            topper_index = i;
        }
    }

    printf("\n--- All Student Results ---\n");
    for (i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Total: %.2f | Percentage: %.2f%% | Grade: %c\n",
               s[i].roll, s[i].name, s[i].total, s[i].percentage, s[i].grade);
    }

    printf("\n--- Class Analysis ---\n");
    printf("Class Average Marks: %.2f\n", class_total_marks / n);
    printf("Class Average Percentage: %.2f%%\n", (class_total_marks / (n * 5.0)));

    printf("\nClass Topper:\n");
    printf("Roll: %d | Name: %s | Total: %.2f | Percentage: %.2f%%\n",
           s[topper_index].roll, s[topper_index].name, s[topper_index].total, s[topper_index].percentage);

    printf("\nStudents Who Failed in One or More Subjects:\n");
    int failed_count = 0;
    for (i = 0; i < n; i++) {
        if (s[i].failed) {
            printf("Roll: %d | Name: %s\n", s[i].roll, s[i].name);
            failed_count++;
        }
    }

    if (failed_count == 0) {
        printf("None\n");
    }

    return 0;
}