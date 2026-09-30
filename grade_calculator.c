/*
 * Student Grade Calculator in C
 * -----------------------------
 * This program prompts for a student's name and marks (0-100),
 * validates the input, and calculates their grade using a switch statement.
 *
 * Grade Scale:
 *   90 - 100 : A
 *   80 - 89  : B
 *   70 - 79  : C
 *   60 - 69  : D
 *   40 - 59  : E
 *   Below 40 : Fail
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100];
    int marks;

    // Step 1: Input the student's name
    printf("Enter student's name: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // Remove trailing newline character added by fgets, if present
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';
        }
    }

    // Step 2: Input student's marks
    printf("Enter marks (0 - 100): ");
    if (scanf("%d", &marks) != 1) {
        printf("\nError: Invalid input! Marks must be an integer number.\n");
        return 1;
    }

    // Step 3: Input validation - check if marks are within valid range (0 - 100)
    if (marks < 0 || marks > 100) {
        printf("\nError: Invalid marks! Marks must be between 0 and 100.\n");
        return 1;
    }

    // Step 4: Display Student Information
    printf("\n========================================\n");
    printf("            STUDENT RESULT              \n");
    printf("========================================\n");
    printf("Name  : %s\n", name);
    printf("Marks : %d / 100\n", marks);

    // Step 5: Determine grade using a switch statement
    // Explanation: Integer division by 10 maps ranges to single digits:
    // 100 -> 10, 90-99 -> 9 (Grade A)
    // 80-89 -> 8 (Grade B)
    // 70-79 -> 7 (Grade C)
    // 60-69 -> 6 (Grade D)
    // 50-59 -> 5, 40-49 -> 4 (Grade E)
    // 0-39 -> 0, 1, 2, 3 (Fail)
    switch (marks / 10) {
        case 10:
        case 9:
            printf("Grade : A\n");
            break;

        case 8:
            printf("Grade : B\n");
            break;

        case 7:
            printf("Grade : C\n");
            break;

        case 6:
            printf("Grade : D\n");
            break;

        case 5:
        case 4:
            printf("Grade : E\n");
            break;

        case 3:
        case 2:
        case 1:
        case 0:
            printf("Grade : Fail\n");
            break;

        default:
            // Safety fallback (should not be reached due to prior validation)
            printf("Grade : Unknown\n");
            break;
    }

    printf("========================================\n");

    return 0;
}
