/*
scott shirley 0760484
css343 winter2020

customer.h
customer object
- stores information about a customer
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "history.h"

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Customer {
	friend std::ostream &operator<<(std::ostream &Os, const Customer &C);
public:
	// default constructor
	Customer() = delete;

	// destructor
	~Customer();

	// constructor ID#, FName, LName
	Customer(int IDNumber, const std::string &FName, const std::string &LName);

	// no name customer
	explicit Customer(int IDNumber);

	// return customer ID#
	int getID() const;

	// return name <FName, LName>
	std::pair<std::string, std::string> getName() const;

	// record Tx
	void recordTransaction(char Case, Movie *M);

	// display last Tx
	void displayLastTransaction() const;

	// display all Tx
	void displayAllTransactions() const;

	// display all rentals
	void displayAllRentals() const;

	// display all returns
	void displayAllreturn() const;

private:
	// private variables
	int CustomerID = -1;
	std::pair<std::string, std::string> CustomerName;
	History *CustomerTransactionHistroy;
};

#endif //CUSTOMER_Hn