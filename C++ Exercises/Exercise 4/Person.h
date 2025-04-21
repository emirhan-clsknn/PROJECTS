#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace Library
{
    namespace Members
    {
        class Person
        {
        public:
            Person(const std::string &n, const std::string &ln) : name(n), lastname(ln) {}

            virtual ~Person() {}

            // Getter methods
            std::string getName() const { return name; }
            std::string getLastName() const { return lastname; }

        private:
            std::string name;
            std::string lastname;
        };
    } // namespace Members
} // namespace Library

#endif
