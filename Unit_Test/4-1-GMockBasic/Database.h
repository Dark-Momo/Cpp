#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <string>
#include <iostream>

// Here, we defined a interface class for a real class
class Database {
public:
    virtual ~Database() = default;
    virtual bool Connect(const std::string& url) = 0;
    virtual bool Query(const std::string& query) = 0;
};

#endif
