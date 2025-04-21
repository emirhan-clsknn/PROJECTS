#ifndef MEMBER_H
#define MEMBER_H

#include <vector>
#include "Book.h"
#include "Person.h"
#include <string>
#include <iostream>

namespace Library
{
    namespace Members
    {
        class Member : public Person
        {
        public:
            Member(const std::string &firstName, const std::string &lastName, int mId)
                : Person(firstName, lastName), memberId(mId) {}

            // Kitap ödünç alma
            void borrowBook(Books::Book *book)
            {
                if (book->getAvailability())
                {
                    books.push_back(book);
                    book->setAvailability(false); // Kitap ödünç alındı
                }
                else
                {
                    std::cout << "Book is already borrowed." << std::endl;
                }
            }

            // Kitap iade etme
            void returnBook(const std::string &title)
            {
                for (auto it = books.begin(); it != books.end(); ++it)
                {
                    if ((*it)->getTitle() == title)
                    {
                        (*it)->setAvailability(true); // Kitap geri alındı, kullanılabilir hale getirildi
                        books.erase(it);
                        return;
                    }
                }
                std::cout << "Book not found in borrowed list.\n";
            }

            // Ödünç alınan kitapları yazdırma
            void printBooks() const
            {
                std::cout << "Borrowed Books:\n";
                for (const auto &book : books)
                {
                    std::cout << *book << "\n"; // `operator<<` tanımı olduğundan emin olun
                }
            }

            // Destructor, kitapları serbest bırakır
            ~Member()
            {
                for (auto book : books)
                {
                    delete book; // Kitapların belleğini serbest bırak
                }
            }

        private:
            int memberId;
            std::vector<Books::Book *> books;
        };
    } // namespace Members
} // namespace Library

#endif
