#include <vector>
#include "Book.hh"

class Library {
public:
    int id;
    std::vector<Book> books;
    int signUpTime;

    Library(const std::vector<Book> &books);

    int beginSignUpAt = -1;
    std::vector<Book> scanned;
};
