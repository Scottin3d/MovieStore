/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
  edited by: scott shirley 0760484
 * @date 19 Jan 2019
 */

#include "classic.h"
#include "comedy.h"
#include "customer.h"
#include "drama.h"
#include "inventory.h"
#include "moviestore.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

// tests the functionality of customer
// fileread
// add
void customerTest() {
  std::cout << "Start customerTest\n";
  std::cout << "======================\n";

  MovieStore Blockbuster;
  std::string CList = "data4customers.txt";

  Blockbuster.addCustomers(CList);

  Customer *C1 = Blockbuster.Customers.find(3333)->second;
  C1->displayAllTransactions();

  std::cout << "End customerTest\n";
}

void readCommandsTest() {
  std::cout << "Start readCommandsTest\n";
  std::cout << "======================\n";
  MovieStore Blockbuster;
  // add customers
  std::string CList = "data4customers.txt";
  Blockbuster.addCustomers(CList);

  // stock movies
  std::string CommandList = "data4movies.txt";
  Blockbuster.stockInventory(CommandList);

  // commands
  CommandList = "data4commands.txt";
  Blockbuster.readCommands(CommandList);
  Blockbuster.executeCommands();

  std::cout << "End readCommandsTest\n";
}
void readMoviesTest() {
  std::cout << "Start readMoviesTest\n";
  std::cout << "======================\n";
  MovieStore Blockbuster;
  std::string CommandList = "data4movies.txt";

  // stock inventory
  Blockbuster.stockInventory(CommandList);
  // print inventory
  Blockbuster.mapInventory();

  std::cout << "End readMoviesTest\n";
}

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string Cfile = "testcommands-1.txt";
  stringstream Out;
  ifstream FS(Cfile);
  assert(FS.is_open());
  char CommandType;
  string Discard;
  while (FS >> CommandType) {
    Out << CommandType;
    getline(FS, Discard);
  }
  FS.close();
  string Result = "IHHBRIBBIH";
  assert(Out.str() == Result);
  cout << "End testStore1" << endl;
}

void testHash() {
  std::cout << "Start testHash\n";
  std::cout << "======================\n";
  MovieStore Blockbuster;
  std::string CommandList = "data4movies.txt";

  // stock inventory
  Blockbuster.stockInventory(CommandList);
  // print inventory
  Blockbuster.mapInventory();
  std::cout << "======================\n";

  Blockbuster.mapInventory();

  std::cout << "End testHash\n";
}

void testAll() {
  // clang-format off
  // add movie factories
  auto *FF = new ComedyFactory();
  Movie::registerType('F', FF);
  auto *CF = new ClassicFactory();
  Movie::registerType('C', CF);
  auto *DF = new DramaFactory();
  Movie::registerType('D', DF);

  // add command factories
  auto *BC = new BorrowFactory();
  Command::registerType('B', BC);
  auto *RC = new ReturnFactory();
  Command::registerType('R', RC);
  auto *HC = new HistoryFactory();
  Command::registerType('H', HC);
  auto *IC = new InventoryFactory();
  Command::registerType('I', IC);

  // main test - all three main functions
  readCommandsTest();

  // test hashmap sorting
  // testHash();

  // customerTest(); // leak free 3/4
  // readMoviesTest();


  // testStore1();
  // testStore2();
  // testStoreFinal()
  // delete predefined factories
  /*
  delete FF;
  delete CF;
  delete DF;
  delete BC;
  delete RC;
  delete HC;
  delete IC;
  */
  // clang-format on
}
