#include "Book.h"
#include "Member.h"
#include <iostream>

int main()
{
    using namespace Library::Books;
    using namespace Library::Members;

    // Kitaplar
    Book *book1 = new FictionBook("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Book *book2 = new NonFictionBook("Sapiens", "Yuval Noah Harari", 2011);

    // Üye
    Member *member = new Member("John", "Doe", 123);

    // Kitap ödünç alma
    member->borrowBook(book1);
    member->borrowBook(book2);

    // Ödünç alınan kitapları yazdır
    member->printBooks();

    // Kitap iadesi
    member->returnBook("Sapiens");
    member->printBooks();

    // Belleği serbest bırak
    delete member;

    return 0;
}
