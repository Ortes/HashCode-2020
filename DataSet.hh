#include <string>
#include <unordered_set>
#include "Library.hh"

class DataSet {
public:
    std::vector<Library*> libraries;
    std::vector<Book*> books;
    int days;

    std::unordered_set<Book*> scanned;
    std::vector<Library*> signedUpLibraries;

    DataSet(const std::string& fileName);

    static DataSet Parse(const std::string& fileName) {
      return DataSet(fileName);
    }

    static void write(const DataSet&, const std::string&);

    bool ScanBook(Book*, Library*);
};
