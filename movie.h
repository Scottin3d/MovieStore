
#ifndef MOVIE_H
#define MOVIE_H

/*
scott shirley 0760484
css343 winter2020

movie.h
the base abstract object of movie
- stores information about a movie

*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// forward declarations
class Movie;
class Customer;
class Inventory;

// abstract movie factory
class MovieFactory {
public:
    // abstract create
    virtual ~MovieFactory() = default;
    virtual Movie *create(const std::string& MovieInput) const = 0;
private:
};

// abstract movie class
class Movie {
    // outstream overload
    friend std::ostream &operator<<(std::ostream &Os, const Movie &M);
public:
    // abstract create
    static Movie *create(char Genre, const std::string& MovieInput);

    // default destructor
    virtual ~Movie() = default;

    //register a movie factory for expansion
    static void registerType(char Genre, MovieFactory* MF);

    // greater than overload
    virtual bool operator>(const Movie &M) const = 0;

    // container for factories
    static std::map<char, MovieFactory*> Moviefactories;

    // return title
    std::string const& getTitle() const;

    // return director
    std::string const& getDirector() const;

    // return release year
    std::string const& getReleaseYear() const;

    // return major actor
    std::string const& getMajorActor() const;

    // return key
    std::string const& getKey() const;

    // return stock
    int const& getStock() const;

    // check movie out
    void checkout();

    // check movie in
    void checkin();
protected:
    // protected vairalbs of movie
    int Stock = 10;
    std::string Title;
    std::string YearRelease;
    std::string Director;
    std::string MajorActor;
    std::string Key;
};

#endif // MOVIE_H
