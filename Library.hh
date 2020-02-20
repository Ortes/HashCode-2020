#include <vector>
#include "Book.hh"

class Library {
  public:
  std::vector<Book> books;
  int signUpTime;

  static Library GetFastestSignUpLibrary() {
    return Library();
  }
};
