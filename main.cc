#include <algorithm>
#include "DataSet.hh"

void processFile(const std::string &fileName) {
    DataSet dataSet = DataSet::Parse(fileName);

    std::vector<Library*> libraries = dataSet.libraries;
    std::sort(libraries.begin(), libraries.end(), [](auto a, auto b) -> bool { return a->Score() > b->Score(); });

    int days = 0;
    for (int i = 0; days < dataSet.days && i < libraries.size(); ++i) {
        libraries[i]->beginSignUpAt = days;
        days += libraries[i]->signUpTime;
    }
    std::copy_if(libraries.begin(), libraries.end(), std::back_inserter(dataSet.signedUpLibraries), [](auto e) -> bool {
        return e->beginSignUpAt != -1;
    });

    for (const auto& library: dataSet.signedUpLibraries) {
        auto books = library->books;
        std::sort(library->books.begin(), library->books.end(), [](auto a, auto b) -> bool { return a->score < b->score; });
        for (const auto& book: books) {
            dataSet.ScanBook(book, library);
        }
    }

    DataSet::write(dataSet, fileName + ".output");
}

int main(int argc, char* argv[]) {

    for (int i = 1; i < argc; ++i)
        processFile(argv[i]);
    return 0;
}
