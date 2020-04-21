/*
scott shirley 0760484
css343 winter2020

classic.cpp
-creates a classic movie
*/

#include "classic.h"

// constructor
Classic::Classic(const std::string &CDirector, const std::string &CTitle,
                 const std::string &CReleaseYear,
                 const std::string &CMajActor) {
  this->Stock = 10;
  this->Director = CDirector;
  this->Title = CTitle;
  this->YearRelease = CReleaseYear;
  this->MajorActor = CMajActor;
  this->Key = CReleaseYear + CMajActor;
}

// create classic movie
Movie *ClassicFactory::create(const std::string &MovieInput) const {
  std::stringstream SS(MovieInput);
  std::string Getter;
  char Delimiter = ',';

  std::string CDirector;
  std::string CTitle;
  std::string CReleaseMonth;
  std::string CReleaseYear;
  std::string CMajActorFN;
  std::string CMajActorLN;
  std::string CMajActor;

  std::getline(SS, Getter, Delimiter);
  std::getline(SS, Getter, Delimiter);
  std::getline(SS, Getter, Delimiter);
  CDirector = Getter.substr(1);
  std::getline(SS, Getter, Delimiter);
  CTitle = Getter.substr(1);
  std::getline(SS, Getter, Delimiter);
  std::istringstream IS(Getter);

  IS >> CMajActorFN >> CMajActorLN >> CReleaseMonth >> CReleaseYear;
  CMajActor = CMajActorFN + " " + CMajActorLN;
  CReleaseYear = CReleaseMonth + " " + CReleaseYear;

  return new Classic(CDirector, CTitle, CReleaseYear, CMajActor);
}

// greater than overload
// Classics (‘C’) sorted by Release date, Major actor
bool Classic::operator>(const Movie &M) const {
  /*
    if (a.PrimaryCondition < b.PrimaryCondition) return true;
    if (b.PrimaryCondition < a.PrimaryCondition) return false;

   // a=b for primary condition, go to secondary
   if (a.SecondaryCondition < b.SecondaryCondition) return true;
   if (b.SecondaryCondition < a.SecondaryCondition) return false;
  */

  // primary condition
  if (this->YearRelease < M.getReleaseYear()) {
    return true;
  }
  if (M.getReleaseYear() < this->YearRelease) {
    return false;
  }

  // secondary condition
  if (this->MajorActor < M.getMajorActor()) {
    return true;
  }
  if (M.getMajorActor() < this->MajorActor) {
    return false;
  }
  return false;
}