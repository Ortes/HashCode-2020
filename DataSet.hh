#include <string>
#include "Library.hh"

class DataSet {
public:
  std::vector<Library*> libraries;
  std::vector<Book*> books;
  int days;

  static DataSet Parse(const std::string &fileName) {
    return DataSet();
  }
};
