#include <string>
#include "Library.hh"

class DataSet {
public:
    std::vector<Library *> libraries;
    std::vector<Book *> books;
    int days;

    std::vector<Book> scanned;

    DataSet(const std::string &fileName);

    static DataSet Parse(const std::string &fileName) {
        return DataSet(fileName);
    }

    bool ScanBook(Book);
};
