#ifndef INVENTORY_H
#define INVENTORY_H

/*
scott shirley 0760484
css343 winter2020

inventory.h
how a movies store interacts with stored movies
*/

#include "hashmap.h"
#include "movie.h"

class Inventory {
public:
  // default constructor
  Inventory() = default;

  // default destructor
  ~Inventory() = default;

  // display inventory
  void displayMap();

  // add a movie to inventory
  bool addMovie(char Case, const std::string &FileInput);

  // borrow a movie from the store
  std::pair<Movie*, bool> borrowMovie(char Genre, const std::string &Key);

  // return borrowed movie from store
  std::pair<Movie*, bool> returnMovie(char Genre, const std::string &Key);
private:
  // map that stores movies with genre as key
  HashMap MovieHashMap;
};

#endif // !INVENTORY_H
