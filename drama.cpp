/*
scott shirley 0760484
css343 winter2020

drama.pp
-creates a drama movie
*/

#include "drama.h"

// constructor
Drama::Drama(const std::string &DDirector, const std::string &DTitle,
             const std::string &DReleaseYear) {
  this->Stock = 10;
  this->YearRelease = DReleaseYear;
  this->Title = DTitle;
  this->Director = DDirector;
  this->Key = DDirector + DTitle;
}

// creates drama movie
Movie *DramaFactory::create(const std::string &MovieInput) const {
  std::stringstream SS(MovieInput);
  std::string Getter;
  char Delimiter = ',';
  std::string DDirector;
  std::string DTitle;
  std::string DReleaseYear;

  std::getline(SS, Getter, Delimiter);
  std::getline(SS, Getter, Delimiter);
  std::getline(SS, Getter, Delimiter);
  DDirector = Getter.substr(1);
  std::getline(SS, Getter, Delimiter);
  DTitle = Getter.substr(1);
  std::getline(SS, Getter, Delimiter);
  DReleaseYear = Getter.substr(1);

  return new Drama(DDirector, DTitle, DReleaseYear);
}

// greater than overload
// Dramas (‘D’) sorted by Director, Title
bool Drama::operator>(const Movie &M) const {
  /*
    if (a.PrimaryCondition < b.PrimaryCondition) return true;
    if (b.PrimaryCondition < a.PrimaryCondition) return false;

   // a=b for primary condition, go to secondary
   if (a.SecondaryCondition < b.SecondaryCondition) return true;
   if (b.SecondaryCondition < a.SecondaryCondition) return false;
  */

  // primary condition
  if (this->Director < M.getDirector()) {
    return true;
  }
  if (M.getDirector() < this->Director) {
    return false;
  }

  // secondary condition
  if (this->Title < M.getTitle()) {
    return true;
  }
  if (M.getTitle() < this->Title) {
    return false;
  }

  return false;
}