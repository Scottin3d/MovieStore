/*
scott shirley 0760484
css343 winter2020

history.cpp
stores the transaction history of a customer
- stores transaction objects
*/

#include "history.h"

#include <iostream>

// records a transaction
void History::recordTransaction(char Case, Movie *M) {
  // create a new transaction
  auto *TX = new Transaction(M);
  // save last transaction
  LastTransaction = TX;

  if (Case == 'B') {
    RentalHistory.push_back(TX);
    // debug
    std::cout << "Rental Recorded.\n";
  } else if (Case == 'R') {
    ReturnHistory.push_back(TX);
    // debug
    std::cout << "Rental Recorded.\n";
  }
}

// clear histories
void History::clearHistory() {
  // delete rentals
  for (auto R : RentalHistory) {
    delete R;
  }
  // delete returns
  for (auto R : ReturnHistory) {
    delete R;
  }

  // clear containers
  RentalHistory.clear();
  ReturnHistory.clear();
  // debug
  // std::cout << "Histories cleared.\n";
}

// display the last transaction
void History::displayLastTransaction() const {
  std::cout << "Last Transaction: " << LastTransaction;
}

// display all transactions
void History::displayAllTransactions() const {
  displayRentals();
  std::cout << "\n";
  displayReturns();
}

// display all returns
void History::displayReturns() const {
  std::cout << "Returns:\n";
  for (auto Tx : ReturnHistory) {
    std::cout << "\t" << *Tx << std::endl;
  }
}

// display all rentals
void History::displayRentals() const {
  std::cout << "Rentals:\n";
  for (auto Tx : RentalHistory) {
    std::cout << "\t" << *Tx << std::endl;
  }
}
