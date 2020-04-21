#ifndef DRAMA_H
#define DRAMA_H

/*
scott shirley 0760484
css343 winter2020

drama.h
-creates a drama movie
*/

#include "movie.h"
#include <string>

class Drama : public Movie {

public:
  // constructor
  Drama(const std::string &Director, const std::string &Title,const std::string &ReleaseYear);
  
  // greater than overload
  bool operator>(const Movie& M) const override;
};

class DramaFactory : public MovieFactory {
public:
  // create override
  Movie* create(const std::string &MovieInput) const override;

};
#endif // !DRAMA_H
