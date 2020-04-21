/*
scott shirley 0760484
css343 winter2020

customer.h
customer object
- stores information about a customer
*/

#include "customer.h"

// constructor ID#, FName, LName
Customer::Customer(int IDNumber) {
  CustomerID = IDNumber;
  CustomerName.first = "New";
  CustomerName.second = "Customer";
  CustomerTransactionHistroy = new History();
}

// constructor ID#, FName, LName
Customer::Customer(int IDNumber, const std::string &FName,
                   const std::string &LName) {
  CustomerID = IDNumber;
  CustomerName.first = FName;
  CustomerName.second = LName;
  CustomerTransactionHistroy = new History();
}

// destructor
Customer::~Customer() {
  CustomerTransactionHistroy->clearHistory();
  // debug
  // std::cout << "Deleteing " << this << std::endl;
  delete CustomerTransactionHistroy;
}

// ostream overload "1234: Scott Shirley"
std::ostream &operator<<(std::ostream &Os, const Customer &C) {
  Os << C.CustomerID << ": ";
  Os << C.CustomerName.first << " " << C.CustomerName.second;
  return Os;
}

// return customer ID#
int Customer::getID() const { return CustomerID; }

// return name <FName, LName>
std::pair<std::string, std::string> Customer::getName() const {
  return CustomerName;
}

// record Tx
void Customer::recordTransaction(char Case, Movie *M) {
  CustomerTransactionHistroy->recordTransaction(Case, M);
}

// display last Tx
void Customer::displayLastTransaction() const {
  CustomerTransactionHistroy->displayLastTransaction();
}

// display all Tx
void Customer::displayAllTransactions() const {
  CustomerTransactionHistroy->displayAllTransactions();
}

// display all rentals
void Customer::displayAllRentals() const {
  CustomerTransactionHistroy->displayRentals();
}

// display all returns
void Customer::displayAllreturn() const {
  CustomerTransactionHistroy->displayReturns();
}
