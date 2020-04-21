#ifndef HASHMAP_H
#define HASHMAP_H

/*
scott shirley 0760484
css343 winter2020

hashmap.h
a custom made hashmap container
- stores movies based on hashkey based on an A-Z char
- objects places into container based on key
*/

#include "movie.h"

#include <array>
#include <map>
#include <string>
#include <utility>
#include <vector>

class HashMap {
public:
  // default constructor
  HashMap() = default;

  // destructor
  ~HashMap();

  // add element
  bool addElement(char Genre, Movie *M);

  // find element
  std::pair<Movie*, bool> find(char Genre, const std::string &Key);

  // print values in map
  void printHash(int Index);

private:
  // container
  // std::array<std::vector<Movie*>, 26> Elements; // legacy
  std::array<std::map<std::string, Movie*>, 26> MapElements;
};

#endif // !HASHMAP_H
