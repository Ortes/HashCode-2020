#include "DataSet.hh"

int main(int argc, char *argv[]) {

  DataSet dataSet = DataSet::Parse(argv[1] ? argv[1] : "file");

  std::vector<Library*> libraries = dataSet.libraries;
  std::sort(libraries.begin(), libraries.end(), [](auto a, auto b) -> bool { return a->signUpTime > b->signUpTime; });

  for (int i = 0; i < dataSet.days;) {

  }

  return 0;
}
