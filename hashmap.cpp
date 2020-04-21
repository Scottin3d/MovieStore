/*
scott shirley 0760484
css343 winter2020

hashmap.cpp
a custom made hashmap container
- stores movies based on hashkey based on an A-Z char
- objects places into container based on key
*/

#include "hashmap.h"

// destructor
HashMap::~HashMap() {
  // delete all entries in map
  for (auto &MapElement : MapElements) {
    for (auto const &M : MapElement) {
      delete M.second;
    }
    MapElement.clear();
  }
}

/*
    Comedy (‘F’) sorted by Title, Year it released
    Dramas (‘D’) sorted by Director, Title
    Classics (‘C’) sorted by Release date, Major actor
*/
// add elemnet
bool HashMap::addElement(char Genre, Movie *M) {
  // zero out indicies
  int Index = Genre - 'A';

  // is it a valid char?
  if (Index <= 0 || Index >= 25) {
    std::cout << "Invalid index...\n";
    return false;
  }

  // push into map based on genre
  MapElements[Index].emplace(M->getKey(), M);

  // sort list
  return true;
}

// find element
std::pair<Movie *, bool> HashMap::find(char Genre, const std::string &Key) {
  // search for movie
  if (MapElements[Genre].find(Key) != MapElements[Genre].end()) {
    auto *Temp = MapElements[Genre].find(Key)->second;
    return std::make_pair(Temp, true);
  }
  return std::make_pair(nullptr, false);
}

// print values in map
void HashMap::printHash(int Index) {
  for (auto const &MapElement : MapElements[Index]) {
    std::cout << *MapElement.second << std::endl;
  }
}