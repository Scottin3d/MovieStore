# Movie Store

## Replace all TODO with actual information

Author(s): scott shirley 0760484

GitHub URL: TODO

Expected Mark: A

## Checklist

Development Platform: Windows

Tested on CSS Linux Lab: Yes, see output.txt

Tested on Travis: Yes

clang-tidy messages:

store_test.cpp:148:3: warning: delete called on non-final 'ComedyFactory' that has virtual functions but non-virtual destructor [-Wdelete-non-virtual-dtor]
  delete FF;
  ^
store_test.cpp:149:3: warning: delete called on non-final 'ClassicFactory' that has virtual functions but non-virtual destructor [-Wdelete-non-virtual-dtor]
  delete CF;
  ^
store_test.cpp:150:3: warning: delete called on non-final 'DramaFactory' that has virtual functions but non-virtual destructor [-Wdelete-non-virtual-dtor]
  delete DF;
  ^
store_test.cpp:151:3: warning: delete called on non-final 'BorrowFactory' that has virtual functions but non-virtual destructor [-Wdelete-non-virtual-dtor]
  delete BC;
  ^
store_test.cpp:152:3: warning: delete called on non-final 'ReturnFactory' that has virtual functions but non-virtual destructor [-Wdelete-non-virtual-dtor]
  delete RC;
  ^
store_test.cpp:153:3: warning: delete called on non-final 'HistoryFactory' that has virtual functions but non-virtual destructor [-Wdelete-non-virtual-dtor]
  delete HC;
  ^
store_test.cpp:154:3: warning: delete called on non-final 'InventoryFactory' that has virtual functions but non-virtual destructor [-Wdelete-non-virtual-dtor]
  delete IC;
  ^

Because I preregisted  factorie in the store_test.cpp, these warnings populate.  I tried various different ways to address them, but could not find a solution

valgrind messages:
==15312==
==15312== HEAP SUMMARY:
==15312==     in use at exit: 0 bytes in 0 blocks
==15312==   total heap usage: 1,567 allocs, 1,567 frees, 91,521 bytes allocated
==15312==
==15312== All heap blocks were freed -- no leaks are possible
==15312==
==15312== For counts of detected and suppressed errors, rerun with: -v
==15312== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


## Command Functionality Checklist

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: 
command.cpp - if string passed has an unregistered command char, it will return a nullptr, thus an invlaid command

invalid movie type: 
movie.cpp - if string passed has an unregistered movie genre char, it will return a nullptr, thus an invlaid movie 

invalid customer ID: 
customer.cpp - only valid info will call valid constructors
 
invalid movie: 
inventory.cpp -  if the movie is able to be added to the map of movies

factory classes: 
commands-- command.cpp , movies-- comedy.cpp, drama.cpp, classic.cpp

hashtable: hashmap.cpp 
a custom made hashmap container
- stores movies based on hashkey based on an A-Z char
- objects places into container based on key

container used for comedy movies: 
map<string, Movie *>

function for sorting comedy movies: 
map is sorted ascending.  operator> overload in comedy.cpp (override from movie.cpp)

function where comedy movies are sorted: 
comedy.cpp operator> override

functions called when retrieving a comedy movie based on title and year:
command.cpp
auto BPair = Stock->borrowMovie(Genre, CheckString);
where checkstring is movie key

functions called for retrieving and printing customer history: 
moviestore.cpp
C->execute(Customers[C->getCustomerID()], &Stock);
command.cpp
Cust->displayAllTransactions();
customer.cpp
CustomerTransactionHistroy->displayAllTransactions();
history.cpp
displayRentals();
displayReturns();

container used for customer history:
two std::vector<Trasnactions *>, one for rentals and one for returns

functions called when borrowing a movie:
moviestore.cpp
C->execute(Customers[C->getCustomerID()], &Stock);
command.cpp
auto BPair = Stock->borrowMovie(Genre, CheckString);
inventory.cpp
  std::pair<Movie *, bool> BPair = MovieHashMap.find(Genre - 'A', Key);
  BPair.first->checkout();
Cust->recordTransaction('B', BPair.first);

explain borrowing a movie that does not exist:
command will search movie genre map for key, if not in map, will return false

explain borrowing a movie that has 0 stock:
if command finds movie, it will then check the stock of the Movie *, if <=0, will return false

explain returning a movie that customer has not checked out:
check the vector<Trasnactions> for the movie, if in true, else false

any static_cast or dynamic_cast used:
static_cast<int>(some string) to parse the customer ID


