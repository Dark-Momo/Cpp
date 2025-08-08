#ifndef _MOCKFOOLINTERFACE_HPP_
#define _MOCKFOOLINTERFACE_HPP_

// Here, we defined a Fake class which inherits the interface of the real class.
// We inherit the interface because we want to test it.

#include <gmock/gmock.h>
#include <string>

#include "5-1-FoolInterface.hpp"

// 1. MOCK_METHODn is OLD way, while MOCK_METHOD is the NEW one.
// 2. The MOCK_METHOD macro in gMock DOES NOT CREATE A NEW method in the sense of 
//    adding a completely novel function to a class that didn't previously exist. 
//    Instead, it is used to generate a mock IMPLEMENTATION of an EXISTING method, 
//    typically a virtual method from a base class or interface.

class MockFoolInterface : public FoolInterface {
public:
    
    // OLD Way:
    // MOCK_METHOD0(getArbitraryString, std::string());

    // 3rd argument is () since the prototype of getArbitraryString() is with ();
    // If getArbitraryString(void), then 3rd argument should be (void);
    MOCK_METHOD(std::string, getArbitraryString, (), (override));

    MOCK_METHOD(void, setStringValue, (std::string& strValue), (override));
    MOCK_METHOD(void, setIntValue, (int x, int y), (override));

    MOCK_METHOD(int, getParameter, (std::string* name,  std::string* value), (override));
};

#endif