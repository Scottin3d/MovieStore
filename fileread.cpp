/*
scott shirley 0760484
css343 winter2020

fileread.cpp
converts a txt file into read about strings
- stores strings in a queue
*/

#include "fileread.h"

// reads txt file and covnerts to strings
void FileRead::readFromFile(const std::string &FileInput) {
  std::ifstream InFile;
  InFile.open(FileInput);

  if (!InFile) {
    // debug
    std::cout << "Unable to open file\n";
    return;
  }

  clear();
  std::string Str;
  getline(InFile, Str);

  while (!Str.empty()) {
    // debug
    // std::cout << "Queuing " << Str << "\n";
    ReadLines.push(Str);
    getline(InFile, Str);
  }
}

// clear the container
void FileRead::clear() {
  while (!ReadLines.empty()) {
    ReadLines.pop();
  }
}