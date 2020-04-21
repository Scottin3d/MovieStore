/*
scott shirley 0760484
css343 winter2020

command.cpp
provides abstract command types for program execution
*/

#include "command.h"

#include <fstream>
#include <sstream>
#include <string>

// map of command factories
std::map<char, CommandFactory *> Command::CommandFactories;

// destructor -- legacy
/*
Command::~Command() {
  for (auto F : CommandFactories) {
    delete F.second;
  }
  CommandFactories.clear();
}
*/

// return customerID from command
int Command::getCustomerID() { return this->CustomerID; }

/*
base command class
-provides the basic structure of the command class
*/
Command *Command::create(char Case, const std::string &CommandInput) {

  if (CommandFactories.find(Case) == CommandFactories.end()) {
    return nullptr;
  }
  Command *C = CommandFactories[Case]->create(CommandInput);
  return C;
}

// reister type
void Command::registerType(char Case, CommandFactory *CF) {
  CommandFactories.emplace(Case, CF);
}

/*
borrow command
-removes a movie from the inventory
*/

// command constructor
BorrowCommand::BorrowCommand(char Genre, int CustomerID,
                             const std::string &MovieTitle,
                             const std::string &ReleaseYear,
                             const std::string &MovieDirector,
                             const std::string &MajorActor) {
  this->Genre = Genre;
  this->CustomerID = CustomerID;
  this->Title = MovieTitle;
  this->ReleaseYear = ReleaseYear;
  this->Director = MovieDirector;
  this->MajorActor = MajorActor;
}

// execute command
void BorrowCommand::execute(Customer *Cust, Inventory *Stock) {
  // check for bad customer
  if (Cust == nullptr) {
    return;
  }

  std::string CheckString;
  if (Genre == 'F') {
    CheckString = Title + ReleaseYear;
  } else if (Genre == 'C') {
    CheckString = ReleaseYear + MajorActor;
  } else if (Genre == 'D') {
    CheckString = Director + Title;
  }
  auto BPair = Stock->borrowMovie(Genre, CheckString);
  if (BPair.second) {
    Cust->recordTransaction('B', BPair.first);
  }
}

// borrow factory create
Command *BorrowFactory::create(const std::string &CommandInput) const {
  char Genre = CommandInput.at(9);
  int CustomerID = std::stoi(CommandInput.substr(2, 5));

  // stream variables
  std::stringstream SS(CommandInput.substr(11));
  std::istringstream IS(CommandInput.substr(11));
  std::string Getter;
  char Delimeter = ',';

  // main command variables
  std::string Director;
  std::string Title;
  std::string ReleaseYear;
  std::string MajorActor;

  // comedy
  if (Genre == 'F') {
    std::getline(SS, Title, Delimeter);
    std::getline(SS, ReleaseYear, Delimeter);
    ReleaseYear = ReleaseYear.substr(1);
  }

  // classic
  if (Genre == 'C') {
    std::string Month;
    std::string Year;
    std::string FName;
    std::string LName;
    IS >> Month >> Year >> FName >> LName;

    ReleaseYear = Month + " " + Year;
    MajorActor = FName + " " + LName;
  }

  // drama
  if (Genre == 'D') {
    std::getline(SS, Director, Delimeter);
    std::getline(SS, Title, Delimeter);
    Title = Title.substr(1);
  }

  // depends on genre
  return new BorrowCommand(Genre, CustomerID, Title, ReleaseYear, Director,
                           MajorActor);
}

/*
return command
- returns a movie back into the inventory
*/

// command constructor
ReturnCommand::ReturnCommand(char Genre, int CustomerID,
							          const std::string &MovieTitle,
							          const std::string &ReleaseYear,
							          const std::string &MovieDirector,
							          const std::string &MajorActor) {
  this->Genre = Genre;
  this->CustomerID = CustomerID;
  this->Title = MovieTitle;
  this->ReleaseYear = ReleaseYear;
  this->Director = MovieDirector;
  this->MajorActor = MajorActor;
}

// execute command
void ReturnCommand::execute(Customer *Cust, Inventory *Stock) {
  std::string CheckString;
  if (Genre == 'F') {
    CheckString = Title;
  } else if (Genre == 'C') {
    CheckString = ReleaseYear;
  } else if (Genre == 'D') {
    CheckString = Director;
  }
  auto BPair = Stock->returnMovie(Genre, CheckString);
  if (BPair.second) {
    Cust->recordTransaction('R', BPair.first);
  }

  // debug
  std::cout << "Movie returned...\n";
}

// return factory create
Command *ReturnFactory::create(const std::string &CommandInput) const {
  char Genre = CommandInput.at(9);
  int CustomerID = std::stoi(CommandInput.substr(2, 5));

  // stream variables
  std::stringstream SS(CommandInput.substr(11));
  std::fstream IS(CommandInput.substr(11));
  std::string Getter;
  char Delimeter = ',';

  // main command variables
  std::string Director;
  std::string Title;
  std::string ReleaseYear;
  std::string MajorActor;

  // comedy
  if (Genre == 'F') {
    std::getline(SS, Title, Delimeter);
    std::getline(SS, ReleaseYear, Delimeter);
  }

  // classic
  if (Genre == 'C') {
    std::string Month;
    std::string Year;
    std::string FName;
    std::string LName;
    IS >> Month >> Year >> FName >> LName;

    ReleaseYear = Month + " " + Year;
    MajorActor = FName + " " + LName;
  }

  // drama
  if (Genre == 'D') {
    std::getline(SS, Director, Delimeter);
    std::getline(SS, Title, Delimeter);
  }

  // depends on genre
  return new ReturnCommand(Genre, CustomerID, Title, ReleaseYear, Director,
                           MajorActor);
}

/*
history command
- prints the history of a given cutomer
*/

// command constructor
HistoryCommand::HistoryCommand(int CustomerID) {
  this->CustomerID = CustomerID;
}

// execute command
void HistoryCommand::execute(Customer *Cust, Inventory * /*Stock*/) {
  auto CustomerName = Cust->getName();
  std::cout << "Printing ";
  std::cout << CustomerName.first + " " + CustomerName.second;
  std::cout << " Rental History...\n";
  Cust->displayAllTransactions();
}

// history factory
Command *HistoryFactory::create(const std::string &CommandInput) const {
  int CustomerID = std::stoi(CommandInput.substr(2, 5));
  return new HistoryCommand(CustomerID);
}

/*
inventory command
- print the inventory of the movie store
*/

// execute command
void InventoryCommand::execute(Customer * /*Cust*/, Inventory *Stock) {
  Stock->displayMap();
}

// inventory factory
Command *InventoryFactory::create(const std::string & /*CommandInput*/) const {
  return new InventoryCommand();
}