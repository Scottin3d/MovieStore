#ifndef COMMAND_H
#define COMMAND_H

/*
scott shirley 0760484
css343 winter2020

command.h
provides abstract command types for program execution
*/

#include "customer.h"
#include "inventory.h"

#include <map>
#include <string>

// forward declaration
class Command;

// abstract command factory
class CommandFactory {
public:
  virtual ~CommandFactory() = default;
  virtual Command *create(const std::string &CommandInput) const = 0;
};

// abstract command class
class Command {
public:
  // destructor
  virtual ~Command() = default;

  // register new command
  static void registerType(char Case, CommandFactory* CF);

  // abstract create command
  static Command *create(char Case, const std::string &CommandInput);

  // abstract execute command
  virtual void execute(Customer *Cust, Inventory *Stock) = 0;

  // return command customer ID
  int getCustomerID();

  // container
  static std::map<char, CommandFactory*> CommandFactories;
protected:
  // protected variables
  char Genre = ' ';
  int CustomerID = 0;
  std::string Title;
  std::string ReleaseYear;
  std::string Director;
  std::string MajorActor;
};

/*
borrow command
*/
class BorrowCommand : public Command {
public:
  BorrowCommand(char Genre, int CustomerID,
	  const std::string &MovieTitle, const std::string &ReleaseYear,
	  const std::string &MovieDirector, const std::string &MajorActor);
  void execute(Customer *Cust, Inventory *Stock) override;
private:

};

class BorrowFactory : public CommandFactory {
public:
  Command *create(const std::string &CommandInput) const override;
};

/*
 return command
 */
class ReturnCommand : public Command {
public:
  ReturnCommand(char Genre, int CustomerID,
	  const std::string &MovieTitle, const std::string &ReleaseYear,
	  const std::string &MovieDirector, const std::string &MajorActor);
  void execute(Customer *Cust, Inventory *Stock) override;
private:
};

class ReturnFactory : public CommandFactory {
public:
  Command *create(const std::string &CommandInput) const override;
};

/*
  history command
  */
class HistoryCommand : public Command {
public:
  explicit HistoryCommand(int CustomerID);
  void execute(Customer *Cust, Inventory *Stock) override;
private:
};

class HistoryFactory : public CommandFactory {
public:
  Command *create(const std::string &CommandInput) const override;
};

/*
inventory command
*/
class InventoryCommand : public Command {
public:
  InventoryCommand() = default;
  void execute(Customer *Cust, Inventory *Stock) override;
private:
};
class InventoryFactory : public CommandFactory {
public:
  Command *create(const std::string &CommandInput) const override;
};

#endif // !COMMAND_H

