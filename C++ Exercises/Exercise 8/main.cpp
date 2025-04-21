#include <iostream>
#include <string>

using namespace std;

class User
{
private:
    string name;
    int age;

public:
    User() : name(""), age(0) {} // Default constructor

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    void setName(string n)
    {
        name = n;
    }

    void setAge(int a)
    {
        age = a;
    }

    User *getUser(string name, User users[], int totalUser)
    {
        for (int i = 0; i < totalUser; i++)
        {
            if (users[i].name == name)
            {
                return &users[i];
            }
        }
        return nullptr;
    }

    void addUser(string name, int age, User users[], int &totalUser)
    {
        users[totalUser].setName(name);
        users[totalUser].setAge(age);
        totalUser++;
    }

    void listUsers(User users[], int totalUser)
    {
        for (int i = 0; i < totalUser; i++)
        {
            cout << "User " << i + 1 << ": " << users[i].getName() << ", Age: " << users[i].getAge() << endl;
        }
    }
};

int main()
{
    User users[10];
    char a;
    int totalUser = 0;

    while (a != 'f')
    {
        cout << "\nUser Management System" << endl;
        cout << "a. Add User" << endl;
        cout << "b. Delete User" << endl;
        cout << "c. Update User" << endl;
        cout << "d. Search User" << endl;
        cout << "e. List All Users" << endl;
        cout << "f. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> a;

        switch (a)
        {
        case 'a':
        {
            string name;
            int age;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            users[0].addUser(name, age, users, totalUser); // 0. indexteki nesne üzerinden çağırma
            break;
        }
        case 'b':
            // Delete user işlemi
            break;
        case 'c':
            // Update user işlemi
            break;
        case 'd':
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            User *user = users[0].getUser(name, users, totalUser); // 0. indexteki nesne üzerinden çağırma
            if (user != nullptr)
            {
                cout << "Found User: " << user->getName() << ", Age: " << user->getAge() << endl;
            }
            else
            {
                cout << "User not found!" << endl;
            }
            break;
        }
        case 'e':
            users[0].listUsers(users, totalUser); // 0. indexteki nesne üzerinden listeleme
            break;
        case 'f':
            cout << "Exiting the program..." << endl;
            return 0;
        default:
            cout << "Invalid input. Please enter a valid option." << endl;
            break;
        }
    }

    return 0;
}
