/*
scott shirley 0760484
css343 winter2020

inventory.cpp
how a movies store interacts with stored movies
*/

#include "inventory.h"

// displays inventory
void Inventory::displayMap() {
  for (int Index = 0; Index < 26; Index++) {
    MovieHashMap.printHash(Index);
  }
}

// add a movie to inventory
bool Inventory::addMovie(char Case, const std::string &FileInput) {
  if (Movie::Moviefactories.find(Case) != Movie::Moviefactories.end()) {
    Movie *M = Movie::create(Case, FileInput);
    return MovieHashMap.addElement(Case, M);
  }

  return false;
}

// comedy = title, year
// drama = director, title
// classic = year, major actor
std::pair<Movie *, bool> Inventory::borrowMovie(char Genre,
                                                const std::string &Key) {
  // find movie
  std::pair<Movie *, bool> BPair = MovieHashMap.find(Genre - 'A', Key);
  // check if found
  if (!BPair.second) {
    // debug
    std::cout << "Movie not found...\n";
    return BPair;
  }

  // check stock
  if (BPair.first->getStock() <= 0) {
    BPair.second = false;
    // debug
    std::cout << "Movie not in stock...\n";
    return BPair;
  }

  // check out
  BPair.first->checkout();
  return BPair;
}

// return borrowed movie from store
std::pair<Movie *, bool> Inventory::returnMovie(char Genre,
                                                const std::string &Key) {
  // find movie
  std::pair<Movie *, bool> BPair = MovieHashMap.find(Genre - 'A', Key);

  // check if found
  if (!BPair.second) {
    // debug
    std::cout << "Movie not found...\n";
    return BPair;
  }

  // check out
  BPair.first->checkin();
  return BPair;
}