#pragma once

#include <vector>

class Library;

class Book {
public:
  int id;
  int score;

  std::vector<Library> iAmInLibraries;
  Library* scannedBy;
};
