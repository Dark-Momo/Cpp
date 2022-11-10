#ifndef TABLETENNISPLAYER_HPP_
#define TABLETENNISPLAYER_HPP_

#include <string>

// Base Class
class TableTennisPlayer
{
    private:
        std::string firstName;
	std::string lastName;
        bool hasTable;

    public:
	TableTennisPlayer(const std::string & fn = "none", const std::string & ln = "none", bool ht = false); // Default argument in declaration here. 
        // Argument type is 'const string &', but default parameter passed in is C-Style "none".
	// Here actually utilizes the conversion from constructor of std::string.
	
	void showName() const;

        void setHasTable(bool t) { hasTable = t; }
        bool getHasTable() const { return hasTable; } 	

	// No copy constructor defined here. 
	// When we do intilize, or assignment with an existing object, where copy constructor is used, 
	// it will do member wise copying. It is fine here, since we use std::string. It will use std::string's copy constructor accordingly.
	
	// No destructor defined here since we use std::string, who can take care of itself when destruction.
};

// Derived Class
class RatedPlayer : public TableTennisPlayer // public derivation. See Page 3 of my paper version note for its meaning.
{
    private:
        unsigned int rating;

    public:
	// Common 2 forms of derived class constructor. One with all arguments, the other one with added new data argument, and base class object.
	RatedPlayer(unsigned int r = 0, const std::string & fn = "none", const std::string & ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer & ttp);
	
	unsigned int getRating() const { return rating; }
	void setRating(unsigned int r) { rating = r; }
};

#endif
