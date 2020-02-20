#include <iostream>
#include "DataSet.hh"

int main(int argc, char *argv[]) {

  DataSet dataSet = DataSet::Parse(argv[1] ? argv[1] : "file");
  

  return 0;
}
