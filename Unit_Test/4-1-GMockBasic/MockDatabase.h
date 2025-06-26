#ifndef _MOCKDATABASE_H_
#define _MOCKDATABASE_H_

#include <gmock/gmock.h>
#include "Database.h"

// Here, we defined a Fake class which inherits the interface of the real class.
// We inherit the interface because we want to test it.

class MockDatabase : public Database {
public:
    MOCK_METHOD(bool, Connect, (const std::string& url), (override));
    MOCK_METHOD(bool, Query, (const std::string& query), (override));
};

#endif