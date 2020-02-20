#include <string>
#include "Library.hh"

class DataSet {
public:
  std::vector<Library> libraries;
  std::vector<Library> books;
  int days;

  static DataSet Parse(const std::string &fileName) {
    return DataSet();
  }
};
