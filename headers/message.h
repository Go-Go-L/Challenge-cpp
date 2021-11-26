#pragma once
#include <string>
class msg
{
protected:
    std::string body;
    unsigned int id;

public:
    virtual std::string getType() = 0;
    virtual std::string getsrc() = 0;
    virtual std::string getdst() = 0;
    const std::string getbody(){return body;}
    const int getId(){return id;}
};