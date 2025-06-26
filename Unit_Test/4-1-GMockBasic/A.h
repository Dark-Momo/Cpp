#ifndef _A_H_
#define _A_H_

#include "Database.h"

// Class A is the class that we want to test, and it contains the interface class.

class A {
public:
    A(Database* db) : m_db(db) {}

    bool Initialize(const std::string& db_url) {
        return m_db->Connect(db_url);
    }

private:
    Database* m_db;
};

#endif