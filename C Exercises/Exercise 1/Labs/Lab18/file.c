#include <string.h>
#include <stdio.h>
#include <stdlib.h>




typedef struct Student{
    double id;
    char *name;
    double gpa;
    int age;
}Student;


void addStudent(Student *students, double id,char *name, double gpa,int age,int *count){

    
    students[(*count)].name=(char *)malloc(strlen(name+1)*sizeof(char));
    (*count)++;
}

int main(){
    Student *students;
    printf("How many students take this class? :");
    int numberOfStudent = 0;
    if(!scanf("%d",&numberOfStudent)){
        printf("Please enter integer value :");
        scanf("%d",&numberOfStudent);
    };
    students=(Student *)malloc(sizeof(Student)*numberOfStudent);
    int choice = 0;
    float gpa = 0.0;
    char name1[100];
    double id = 0;
    int age = 0;
    int count = 0;
    printf("Choose what do you want: \n");
    printf("1. Add student\n");
    printf("2. Print students\n");
    
    do{
        printf("Choose what do you want:");
        scanf("%d",&choice);
        switch (choice) 
        {
        case 1:
        {
            if(count==numberOfStudent){
                printf("You can not enter student more than students number!");
                break;
            }
            printf("Enter student id :\n");
            scanf("%lf",&id);
            printf("Enter student name :\n");
            scanf("%s",name1);
            printf("Enter student gpa :\n");
            scanf("%lf",&gpa);
            printf("Enter student age :\n");
            scanf("%d",&age);
            addStudent(students,id,name1,gpa,age,&count);
            break;
        }
        default:
            break;
        }
    }while(choice!=4);


}