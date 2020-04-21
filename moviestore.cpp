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

#include "moviestore.h"

// destructor
MovieStore::~MovieStore() {
  // delete customers
  for (auto IT : Customers) {
    delete IT.second;
  }
  // clear vector
  Customers.clear();
}

// add a customer
bool MovieStore::addCustomer(const std::string &CustomerInput) {
  int CustomerID;
  std::string FName;
  std::string LName;
  std::istringstream SS(CustomerInput);

  SS >> CustomerID >> FName >> LName;
  auto *C1 = new Customer(CustomerID, FName, LName);
  if (Customers.emplace(CustomerID, C1).second) {
    // debug
    // std::cout << *C1 << " added to customer list.\n";
    return true;
  }
  // debug
  std::cout << *C1 << " already in customer list.\n";
  delete C1;
  return false;
}

// adds multiple customers
bool MovieStore::addCustomers(const std::string &FileInput) {
  CommandFileInput.readFromFile(FileInput);

  if (CommandFileInput.ReadLines.empty()) {
    // debug
    std::cout << "Bad input...\n";
    return false;
  }

  while (!CommandFileInput.ReadLines.empty()) {
    if (!addCustomer(CommandFileInput.ReadLines.front())) {
      // debug
      std::cout << "Could not add\n";
    }

    CommandFileInput.ReadLines.pop();
  }

  return true;
}

// add movies to inventory
bool MovieStore::stockInventory(const std::string &FileInput) {
  CommandFileInput.readFromFile(FileInput);

  // check if empty
  if (CommandFileInput.ReadLines.empty()) {
    // debug
    std::cout << "Bad input...\n";
    return false;
  }

  // add movies while queue full
  while (!CommandFileInput.ReadLines.empty()) {
    char C = CommandFileInput.ReadLines.front().at(0);
    if (!Stock.addMovie(C, CommandFileInput.ReadLines.front())) {
      // debug
      std::cout << "Could not add\n";
    }
    CommandFileInput.ReadLines.pop();
  }
  return true;
}

// queue lines to read
void MovieStore::readCommands(const std::string &FileInput) {
  CommandFileInput.readFromFile(FileInput);
}

// execute commands
void MovieStore::executeCommands() {
  // debug
  std::cout << "Executing Commands....\n";
  Command *C;
  while (!CommandFileInput.ReadLines.empty()) {
    // test for command function
    std::string Front = CommandFileInput.ReadLines.front();
    char Case = Front.at(0);

    C = Command::create(Case, Front);
    // check if nullptr
    if (C == nullptr) {
      // bad command if nullptr
      // debug
      std::cout << "Bad command...\n";
      CommandFileInput.ReadLines.pop();
      continue;
    }

    C->execute(Customers[C->getCustomerID()], &Stock);
    delete C;
    CommandFileInput.ReadLines.pop();
  }
}

void MovieStore::mapInventory() { Stock.displayMap(); }