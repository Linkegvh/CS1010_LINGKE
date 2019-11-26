#include <stdio.h>

typedef struct{
    int year;
    int month;
    int day;
}date_t;

typedef struct{
    char name[50];
    char maric[10];
    date_t dob;
}student_t;

void print_student (student_t);

int main (){
    // first one
    student_t student = {"First guy", "A0189238N"};
    student.dob.year = 1999;
    student.dob.month = 1;
    student.dob.day = 1;
    print_student(student);

    //second one
    student_t student1 = {"Second guy", "A123238Y", {1999,1,1}};
    print_student(student1);

    //third one
    student_t student2;
    student_t student3 = {"Third guy", "A2382938N", {1999, 1}};
    student2 = student3;
    student3.dob.day = 1;
    print_student(student2);

    print_student(student3);

    return 0;
}

void print_student(student_t student){
    printf("=====================\n");
    printf("Name: %s\n", student.name);
    printf("Matric Number: %s\n", student.maric);
    printf("Date of Birth: %d, %d, %d\n", student.dob.day, student.dob.month, student.dob.year);
    return;
}