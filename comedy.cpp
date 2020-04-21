/*
scott shirley 0760484
css343 winter2020

comedy.cpp
-creates a comedy movie
*/

#include "comedy.h"

// cosntructor
Comedy::Comedy(const std::string &FDirector, const std::string &FTitle,
               const std::string &FReleaseYear) {
  this->Stock = 10;
  this->YearRelease = FReleaseYear;
  this->Title = FTitle;
  this->Director = FDirector;
  this->Key = FTitle + FReleaseYear;
}

// creates comedy movie
Movie *ComedyFactory::create(const std::string &MovieInput) const {
  std::stringstream SS(MovieInput.substr(6));
  std::string Getter;
  char Delimiter = ',';
  std::string FDirector;
  std::string FTitle;
  std::string FReleaseYear;

  std::getline(SS, Getter, Delimiter);
  FDirector = Getter.substr(1);
  std::getline(SS, Getter, Delimiter);
  FTitle = Getter.substr(1);
  std::getline(SS, Getter, Delimiter);
  FReleaseYear = Getter.substr(1);

  return new Comedy(FDirector, FTitle, FReleaseYear);
}

// greater than overload
// Comedy (‘F’) sorted by Title, Year it released
bool Comedy::operator>(const Movie &M) const {
  /*
    if (a.PrimaryCondition < b.PrimaryCondition) return true;
    if (b.PrimaryCondition < a.PrimaryCondition) return false;

   // a=b for primary condition, go to secondary
   if (a.SecondaryCondition < b.SecondaryCondition) return true;
   if (b.SecondaryCondition < a.SecondaryCondition) return false;
  */

  // primary condition
  if (this->Title < M.getTitle()) {
    return true;
  }
  if (M.getTitle() < this->Title) {
    return false;
  }

  // secondary condition
  if (this->YearRelease < M.getReleaseYear()) {
    return true;
  }
  if (M.getReleaseYear() < this->YearRelease) {
    return false;
  }

  return false;
}