#include "Book.h"

namespace Library
{
    namespace Books
    {
        // operator<< tanımı
        ostream &operator<<(ostream &os, const Book &book)
        {
            book.printDetails();
            return os; // Ensure this return is present
        }

        // FictionBook
        void FictionBook::printDetails() const
        {
            cout << "Fiction Book: " << title << endl;
        }

        void NonFictionBook::printDetails() const
        {
            cout << "Non-Fiction Book: " << title << endl;
        }

        void Magazine::printDetails() const
        {
            cout << "Magazine: " << title << endl;
        }
    } // namespace Books
} // namespace Library
