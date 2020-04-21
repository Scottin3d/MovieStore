#ifndef HISTORY_H
#define HISTORY_H

/*
scott shirley 0760484
css343 winter2020

history.h
stores the transaction history of a customer
- stores transaction objects
*/

#include "transaction.h"

#include <string>
#include <vector>

class History {
public:
  // default constructor
  History() = default;

  // default destructor
  ~History() = default;

  // records a transaction
  void recordTransaction(char Case, Movie *M);

  // clear histories
  void clearHistory();

  // displays last transaction
  void displayLastTransaction() const;

  // displays all transactions
  void displayAllTransactions() const;

  // displays returns
  void displayReturns() const;

  // displays rentals
  void displayRentals() const;

private:
  // container for rentals
  std::vector<Transaction*> RentalHistory;

  // container for returns
  std::vector<Transaction*> ReturnHistory;

  // last transaction for account
  Transaction *LastTransaction = nullptr;
};


#endif // !HISTORY_H
