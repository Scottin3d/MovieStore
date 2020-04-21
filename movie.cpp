/*
scott shirley 0760484
css343 winter2020

movie.cpp
the base abstract object of movie
- stores information about a movie

*/

#include "movie.h"
#include "comedy.h"

// container for moviefactories
std::map<char, MovieFactory *> Movie::Moviefactories;

// outstream overload
std::ostream &operator<<(std::ostream &Os, const Movie &M) {
  Os << "Stock: ";
  // in stock
  if (M.Stock > 0) {
    std::string Str = std::to_string(M.Stock) + "/10";
    Os << std::left << std::setw(15) << Str;
  } else {
  // out of stock
    Os << std::left << std::setw(15) << "Out of Stock";
  }
  Os << "Title: " << std::left << std::setw(40) << M.Title;
  Os << "Director: " << std::left << std::setw(20) << M.Director;
  Os << "Year Released: " << std::left << std::setw(10) << M.YearRelease;
  Os << "Major Actor: " << std::left << std::setw(20) << M.MajorActor;
  return Os;
}

// abstract movie creations
Movie *Movie::create(char Genre, const std::string &MovieInput) {
  // 'F' Comedy
  // 'D' Drama
  // 'C' Classic

  // for factory use
  // calls the corresponding factory for genre
  Movie *M = Moviefactories[Genre]->create(MovieInput);
  return M;
}

// registers a moviefactory for expansion
void Movie::registerType(char Genre, MovieFactory *MF) {
  Moviefactories.emplace(Genre, MF);
}

/*
// greater than overload
bool Movie::operator>(const Movie& M) const {
  // return this > M;
  //
  return true;
}
*/

// returns the title of the movie
std::string const &Movie::getTitle() const { return Title; }

// returns the director of the movie
std::string const &Movie::getDirector() const { return Director; }

// returns the release year of the movie
std::string const &Movie::getReleaseYear() const { return YearRelease; }

// return major actor
std::string const &Movie::getMajorActor() const { return MajorActor; }

// return key
std::string const &Movie::getKey() const { return Key; }

// returns the stock of movie
int const &Movie::getStock() const { return Stock; }

// checks movie out of inventory
void Movie::checkout() {
  Stock--;
  std::cout << "Movie Checked out. Stock at: " << Stock << "/10\n";
}

// check movie into inventory
void Movie::checkin() {
  Stock++;
  std::cout << "Movie Checked out. Stock at: " << Stock << "/10\n";
}