#ifndef MOVIESTORE_H
#define MOVIESTORE_H

/*
scott shirley 0760484
css343 winter2020

moviestore.h
the main brain of the program
- handles store population
- handles customers
- store inventory
- execute commands
*/

#include "command.h"
#include "customer.h"
#include "fileread.h"
#include "hashmap.h"
#include "inventory.h"
#include "movie.h"

#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

class MovieStore {
public:
  // default constructor
  MovieStore() = default;

  // destructor
  ~MovieStore();
  
  // add a single customer
  bool addCustomer(const std::string &CustomerInput);

  // add multiple customers
  bool addCustomers(const std::string &FileInput);

  // stock inventory from file
  bool stockInventory(const std::string &FileInput);

  // read commands from file
  void readCommands(const std::string &FileInput);

  // execute stored commands
  void executeCommands();

  // moviestore functions
  void mapInventory();
  
  // customer container
  std::map<int, Customer*> Customers;
  
private:
  // private variables
  std::queue<std::string> CustomersToBeAdded;
  Inventory Stock;
  FileRead CommandFileInput;
};

#endif // MOVIESTORE_H