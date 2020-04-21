/*
scott shirley 0760484
css343 winter2020

transaction.h
abstract transaction class
- stores a movie object as a transaction
*/

#include "transaction.h"

// ostream overload
std::ostream &operator<<(std::ostream &Os, const Transaction &T) {
  Os << T.TransX;
  return Os;
}

// constructor
Transaction::Transaction(Movie *M) { TransX = M->getTitle(); }
