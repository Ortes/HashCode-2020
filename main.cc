#include <algorithm>
#include "DataSet.hh"

void processFile(const std::string &fileName) {
    DataSet dataSet = DataSet::Parse(fileName);

    std::vector<Library*> libraries = dataSet.libraries;
    std::sort(libraries.begin(), libraries.end(), [](auto a, auto b) -> bool { return a->signUpTime > b->signUpTime; });

    int days = 0;
    for (int i = 0; days < dataSet.days && i < libraries.size(); ++i) {
        libraries[i]->beginSignUpAt = days;
        days += libraries[i]->signUpTime;
    }
    std::copy_if(libraries.begin(), libraries.end(), std::back_inserter(dataSet.signedUpLibraries), [](auto e) -> bool {
        return e->beginSignUpAt != -1;
    });

    for (const auto& library: dataSet.signedUpLibraries) {
        for (const auto& book: library->books) {
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
