#pragma once

#include "Library.hh"

class Book {
public:
  int id;
  int score;

  std::vector<Library> iAmInLibraries;
};
