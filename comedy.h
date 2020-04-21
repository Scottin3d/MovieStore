#ifndef COMEDY_H
#define COMEDY_H

/*
scott shirley 0760484
css343 winter2020

comedy.h
-creates a comedy movie
*/

#include "movie.h"
#include <string>

class Comedy : public Movie {
public:
  // constructor
  Comedy(const std::string &Director, const std::string &Title, const std::string &ReleaseYear);

  // greater than overload
  bool operator>(const Movie& M) const override;
};

class ComedyFactory : public MovieFactory {
public:
  // create override
  Movie* create(const std::string &MovieInput) const override;

};
#endif // !COMEDY_H

