#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// Lesson sınıfı tanımı
template <class T>
class Lesson
{
public:
    Lesson(T n, const char *d) : lessonName(n)
    {
        int size = strlen(d);
        describe = new char[size + 1];
        strcpy(describe, d);
    };
    ~Lesson()
    {
        delete[] describe;
    }
    void printDetails() const
    {
        cout << "Name: " << lessonName << endl
             << "Describe: " << describe << endl;
    }

private:
    T lessonName;
    char *describe;
};

// Person sınıfı tanımı
class Person
{
public:
    Person(const char *n, int a, const char *g) : age(a)
    {
        int size = strlen(n);
        name = new char[size + 1];
        strcpy(name, n);
        int size2 = strlen(g);
        gender = new char[size2 + 1];
        strcpy(gender, g);
    };
    virtual void printDetails() const = 0;
    virtual ~Person()
    {
        delete[] name;
        delete[] gender;
    };

protected:
    char *name;
    int age;
    char *gender;
};

// Student sınıfı tanımı
class Student : public Person
{
public:
    Student(const char *n, int a, const char *g, const char *j) : Person(n, a, g)
    {
        int size = strlen(j);
        job = new char[size + 1];
        strcpy(job, j);
    };
    ~Student()
    {
        delete[] job;
    }

    void addLesson(Lesson<int> &l)
    {
        for (auto lesson : lessons)
        {
            if (&l == lesson)
            {
                cerr << "Aynısı var zaten, eklenemedi.\n";
                return;
            }
        }
        lessons.push_back(&l);
    }

    void removeLesson(const Lesson<int> &l)
    {
        for (auto it = lessons.begin(); it != lessons.end(); ++it)
        {
            if (*it == &l)
            {
                lessons.erase(it);
                break;
            }
        }
    }

    void printDetails() const override
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Gender: " << gender << endl
             << "Job: " << job << endl
             << "Lessons: " << endl;
        int c = 1;
        for (auto lesson : lessons)
        {
            cout << c << ". ";
            lesson->printDetails();
            c++;
        }
    }

private:
    vector<Lesson<int> *> lessons;
    char *job;
};

// Teacher sınıfı tanımı
class Teacher : public Person
{
public:
    Teacher(const char *n, int a, const char *g, const char *j) : Person(n, a, g)
    {
        int size = strlen(j);
        job = new char[size + 1];
        strcpy(job, j);
    };
    ~Teacher()
    {
        delete[] job;
    }

    void addLesson(Lesson<int> &l)
    {
        for (auto lesson : lessons)
        {
            if (&l == lesson)
            {
                cerr << "Aynısı var zaten, eklenemedi.\n";
                return;
            }
        }
        lessons.push_back(&l);
    }

    void removeLesson(const Lesson<int> &l)
    {
        for (auto it = lessons.begin(); it != lessons.end(); ++it)
        {
            if (*it == &l)
            {
                lessons.erase(it);
                break;
            }
        }
    }

    void printDetails() const override
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Gender: " << gender << endl
             << "Job: " << job << endl
             << "Lessons: " << endl;
        int c = 1;
        for (auto lesson : lessons)
        {
            cout << c << ". ";
            lesson->printDetails();
            c++;
        }
    }

private:
    vector<Lesson<int> *> lessons;
    char *job;
};

// Main fonksiyonu
int main()
{
    // Öğrenci ve öğretmen oluştur
    Student student("Ali", 20, "Male", "Computer Engineering");
    Teacher teacher("Ayşe", 35, "Female", "Mathematics Teacher");

    // Ders oluştur
    Lesson<int> math(101, "Mathematics");
    Lesson<int> physics(102, "Physics");
    Lesson<int> programming(103, "Programming");

    // Dersleri öğrenciye ekle
    student.addLesson(math);
    student.addLesson(physics);

    // Dersleri öğretmene ekle
    teacher.addLesson(programming);

    // Detayları yazdır
    cout << "Student Details:" << endl;
    student.printDetails();
    cout << endl;

    cout << "Teacher Details:" << endl;
    teacher.printDetails();
    cout << endl;

    // Öğrenciden bir ders çıkar
    cout << "Removing Math Lesson from Student..." << endl;
    student.removeLesson(math);
    cout << endl;

    // Öğrencinin güncel detaylarını yazdır
    cout << "Updated Student Details:" << endl;
    student.printDetails();
    cout << endl;

    // Öğretmene başka bir ders ekle
    cout << "Adding Math Lesson to Teacher..." << endl;
    teacher.addLesson(math);
    cout << endl;

    // Öğretmenin güncel detaylarını yazdır
    cout << "Updated Teacher Details:" << endl;
    teacher.printDetails();

    return 0;
}
