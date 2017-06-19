#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {MATH, HISTORY, ENGLISH, SCIENCE} subject_t;

typedef struct {
    subject_t subject;
    int value;
} grade_t;

typedef struct {
    char name[128];
    int age;
    grade_t* grades;
    int grade_count;
} student_t;

// TODO:
// Create a function the constructs a Student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0
#define ALLOCATE_GRADES 5
student_t* student_maker(char* name, int age)
{
     grade_t* grades = (grade_t*)calloc(ALLOCATE_GRADES, sizeof(grade_t));

     student_t* student = (student_t*)malloc(sizeof(student_t));
     student->age = age;
     strcpy(student->name, name);
     student->grades = grades;
     student->grade_count = 0;

     return student;
}

// TODO:
// Create a function that takes 3 parameters:
// A pointer to a Student
// A Subject
// An int (1-5)
// It should set the last grade's values with the given arguments
void Grades(student_t* student, subject_t subject, int num)
{
    student->grades[student->grade_count].subject = subject;
    student->grades[student->grade_count].value = num;
    student->grade_count++;
}
// TODO:
// Create a function that takes a Student as a pointer and returns the subject
// that the student has worst grade in
subject_t worst_subject_grade(student_t* student)
{
    grade_t* worst_grade_pointer;
    int worst_grade_value = 5;
    for (int i = 0; i < student->grade_count; i++){
        if (worst_grade_value > student->grades[i].value) {
            worst_grade_value = student->grades[i].value;
            worst_grade_pointer = &(student->grades[i]);
        }
    }
    return worst_grade_pointer->subject;
}

// TODO:
// Create a function that deconstructs a Student
// It should take a pointer that points to the student
// It should free each Grade and the Student itself
void deconstructs_student(student_t* student)
{
    free(student->grades);
    free(student);
}

int main()
{
    student_t* Bela = student_maker("Bela", 11);
    Grades (Bela, HISTORY, 5);
    Grades (Bela, ENGLISH, 2);
    Grades (Bela, SCIENCE, 4);
    Grades (Bela, MATH, 1);

    printf("%s's worst grade subject is: %d\n", Bela->name, worst_subject_grade(Bela));

    return 0;
}
