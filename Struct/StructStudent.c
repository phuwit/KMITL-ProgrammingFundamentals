#include <stdio.h>
#include <string.h>

int main () {
    const int STUDENT_COUNT = 3;
    struct student {
        int id;
        char name[100];
        int age;
    };

    struct student studentList[STUDENT_COUNT];
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Student %d ID : ", i + 1);
        scanf("%d", &studentList[i].id);
        printf("Student %d Name : ", i + 1);
        scanf("%s", studentList[i].name);
        printf("Student %d Age : ", i + 1);
        scanf("%d", &studentList[i].age);
    }


    printf("ID\tName\tAge\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        // printf("Student %d ID : ", i + 1);
        printf("%d\t", studentList[i].id);
        // printf("Student %d Name : ", i + 1);
        printf("%s\t", studentList[i].name);
        // printf("Student %d age : ", i + 1);
        printf("%d\n", studentList[i].age);
    }
}