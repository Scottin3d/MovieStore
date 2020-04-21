#ifndef FILEREAD_H
#define FILEREAD_H

/*
scott shirley 0760484
css343 winter2020

fileread.h
converts a txt file into read about strings
- stores strings in a queue
*/

#include <fstream>
#include <iostream>
#include <queue>
#include <string>

class FileRead {
public:
  // default constructor
  FileRead() = default;

  // default destructor
  ~FileRead() = default;

  // reads txt file and converts to strings
  void readFromFile(const std::string &FileInput);

  // clears the container
  void clear();

  // container of strings
  std::queue<std::string> ReadLines;
};

#endif // !FILEREAD_H
