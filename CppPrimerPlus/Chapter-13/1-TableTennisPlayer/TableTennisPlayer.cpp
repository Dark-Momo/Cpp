#include <iostream>

#include "TableTennisPlayer.hpp"

// Base class
TableTennisPlayer::TableTennisPlayer(const std::string & fn, const std::string & ln, bool ht) : firstName(fn), lastName(ln), hasTable(ht) { }
/*
{
    firstName = fn;
    lastName = ln;
    hasTable = ht;
}
*/

// Above are 2 forms of constructor. Difference, taking "firstName(fn) vs firstName = fn;" as example:
// 1. Member initialize list form only executes firstName(fn). This only calls the copy constructor of std::string to initialize a string object;
// 2. "firstName = fn" will first call default ctor of std::string to setup object 'firstname', then call "=" to do assignment.
// So, 2 will have one more step. 

void TableTennisPlayer::showName() const
{
    std::cout << "TableTennisPlayer name is [" << firstName << " " << lastName << "]\n";
}

// Dericed class
RatedPlayer::RatedPlayer(unsigned int r, const std::string & fn, const std::string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}

// Below use default copy constructor for TableTennisPlayer(ttp). Both are fine, so in Member Initialize List, order doesn't matter.
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & ttp) : rating(r), TableTennisPlayer(ttp) {}
// RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & ttp) : TableTennisPlayer(ttp), rating(r) {}

// Public derication.
// 1. Derived class can't directly access base class's private data. It must be through base class's public method.
//    So we can't directly initilize base class's data member --> We need to use base class's ctor in derived class's ctor.
//
// 2. Base class object must be constructed before we start to construct derived class object.
//    ---------------------------------------------------------------------------------------------------------------------
//    So we can't call base class's ctor inside ctor body of derived class, since at that time, we have started to construct derived class.
//    So we use Member Initialize List, which is executed before going to derived class's ctor body.
