#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
using namespace std;

namespace Library
{
    namespace Books
    {
        class Book
        {
        public:
            Book(const string n, const string a, int y) : title(n), author(a), year(y), isAvailable(true) {}; // Default isAvailable to true
            virtual void printDetails() const = 0;                                                            // Virtual function for printing details
            virtual ~Book() {}

            // Getter for availability status
            bool getAvailability() const { return isAvailable; }

            // Setter for availability status"
            void setAvailability(bool available) { isAvailable = available; }

            string getTitle() const { return title; }

            friend ostream &operator<<(ostream &os, const Book &book);

        protected:
            string title;
            string author;
            int year;
            bool isAvailable; // Changed to bool for availability status
        };

        class FictionBook : public Book
        {
        public:
            FictionBook(const string n, const string a, int y) : Book(n, a, y) {}
            void printDetails() const override;
            virtual ~FictionBook() {}
        };

        class NonFictionBook : public Book
        {
        public:
            NonFictionBook(const string n, const string a, int y) : Book(n, a, y) {}
            void printDetails() const override;
            virtual ~NonFictionBook() {}
        };

        class Magazine : public Book
        {
        public:
            Magazine(const string n, const string a, int y) : Book(n, a, y) {}
            void printDetails() const override;
            virtual ~Magazine() {}
        };
    }
}

#endif
