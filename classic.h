#ifndef CLASSIC_H
#define CLASSIC_H

/*
scott shirley 0760484
css343 winter2020

classic.h
-creates a classic movie
*/

#include "movie.h"
#include <string>

class Classic : public Movie {
public:
  // constructor
  Classic(const std::string &Director, const std::string &Title,
          const std::string &ReleaseYear, const std::string &MajActor);

  // greater than overload
  bool operator>(const Movie &M) const override;
};

class ClassicFactory : public MovieFactory {
public:
  // create override
  Movie* create(const std::string &MovieInput) const override;
};
#endif // !CLASSIC_H
