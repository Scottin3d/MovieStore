#ifndef TRANSACTION_H
#define TRANSACTION_H

/*
scott shirley 0760484
css343 winter2020

transaction.h
abstract transaction class
- stores a movie object as a transaction
*/

#include "movie.h"

#include <iostream>
#include <string>

class Transaction {
  friend std::ostream &operator<<(std::ostream &Os, const Transaction &T);
public:
  // no default constructor
  Transaction() = delete;
  
  // constructor
  explicit Transaction(Movie *M);

  // default destructor
  ~Transaction() = default;
private:
  // variables
  std::string TransX;
};

#endif // TRANSACTION_H
