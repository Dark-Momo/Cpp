#ifndef _FOOLINTERFACE_HPP_
#define _FOOLINTERFACE_HPP_

#include <string>

// Below is the FoolInterface class that we want to test, but without
// full implementation. This is the case where Mock would play a role. 

class FoolInterface
{
// public so that this class can be inherited
public:
    // The dtor of FoolInterface class here must be virtual
    virtual ~FoolInterface() {}

    // This need to be virtual since mock class will inherit and replace its implementation
    virtual std::string getArbitraryString() = 0;

    // Below 2 functions are used to test argument matcher
    virtual void setStringValue(std::string& strValue)= 0;
    virtual void setIntValue(int x, int y) = 0;

    // Test to DoAll(a1, a2, …, an)	: 每次发动时执行a1到an的所有动作.
    virtual int getParameter(std::string* name,  std::string* value) = 0;
};

#endif