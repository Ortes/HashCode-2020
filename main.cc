#include <algorithm>
#include "DataSet.hh"

int main(int argc, char* argv[]) {

    DataSet dataSet = DataSet::Parse(argv[1] ? argv[1] : "file");

    std::vector<Library*> libraries = dataSet.libraries;
    std::sort(libraries.begin(), libraries.end(), [](auto a, auto b) -> bool { return a->signUpTime > b->signUpTime; });

    for (int i = 0; i < dataSet.days;) {
        libraries[0]->beginSignUpAt = i;
        i += libraries[0]->signUpTime;
    }
    std::copy_if(libraries.begin(), libraries.end(), std::back_inserter(dataSet.signedUpLibraries), [](auto e) -> bool {
        return e->beginSignUpAt != -1;
    });

    for (const auto& library: dataSet.signedUpLibraries) {
        for (const auto& book: library->books) {
            dataSet.ScanBook(book, library);
        }
    }

    return 0;
}
