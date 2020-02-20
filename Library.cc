#include "Library.hh"

Library::Library(int id) : id(id) {

}

int Library::Score() {
  int totalScore = 0;
  for (const auto& book: books) {
    totalScore += book->score;
  }
  return totalScore;
}
