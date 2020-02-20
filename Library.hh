#include <vector>
#include "Book.hh"

class Library {
public:
    int id;
    std::vector<Book*> books;
    int signUpTime;
    int nbScanPerDay;

    Library(int id);

    int beginSignUpAt = -1;
    std::vector<Book*> scanned;

    int Score();
};
