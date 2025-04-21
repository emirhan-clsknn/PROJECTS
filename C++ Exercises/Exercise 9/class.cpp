#include <iostream>
#include <string>

using namespace std;

class Teacher
{
public:
    Teacher(string n, string l, int a, string c)
    {
        name = n;
        lastName = l;
        age = a;
        course = c;
    }
    Teacher()
    {
        name = "";
        lastName = "";
        age = 0;
        course = "";
    }
    string getName() const
    {
        return name;
    }
    string getLastName() const
    {
        return lastName;
    }
    int getAge() const
    {
        return age;
    }
    string getCourse() const
    {
        return course;
    }
    void setName(string n)
    {
        name = n;
    }
    void setLastName(string l)
    {
        lastName = l;
    }
    void setAge(int a)
    {
        age = a;
    }
    void setCourse(string c)
    {
        course = c;
    }
    void displayTeacherInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;
    }

private:
    string name;
    string lastName;
    int age;
    string course;
};

class Student
{
public:
    Student(string n, string l, int a, string m, int g)
    {
        name = n;
        lastName = l;
        age = a;
        major = m;
        grade = g;
    };
    Student()
    {
        name = "";
        lastName = "";
        age = 0;
        major = "";
        grade = 0;
    }

    void input()
    {
        cout << "Enter student's name: ";
        cin >> name;
        cout << "Enter student's last name: ";
        cin >> lastName;
        cout << "Enter student's age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter student's major: ";
        getline(std::cin, major);
        cout << "Enter student's grade: ";
        cin >> grade;
    }

    string getStudentName() const
    {
        return name;
    }

    string getStudentLastName() const
    {
        return lastName;
    }

    int getStudentAge() const
    {
        return age;
    }

    string getStudentMajor() const
    {
        return major;
    }

    int getStudentGrade() const
    {
        return grade;
    }

    void setStudentName(string n)
    {
        name = n;
    }

    void setStudentLastName(string l)
    {
        lastName = l;
    }

    void setStudentAge(int a)
    {
        age = a;
    }

    void setStudentMajor(string m)
    {
        major = m;
    }

    void setStudentGrade(int g)
    {
        grade = g;
    }
    void displayStudentInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Major: " << major << endl;
        cout << "Grade: " << grade << endl;
    }

private:
    string name;
    string lastName;
    int age;
    string major;
    int grade;
};

int main()
{
    Teacher teacher1("John", "Doe", 30, "Computer Science");
    Student student1("Alice", "Smith", 25, "Mathematics", 12);
    teacher1.displayTeacherInfo();
    cout << endl;
    student1.displayStudentInfo();
    Student student2;
    student2.input();
    cout << endl;
    student2.displayStudentInfo();
    return 0;
}