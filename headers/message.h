#pragma once
#include <string>
class msg
{
protected:
    std::string body;
    unsigned int id;
public:
    virtual std::string getType() = 0;
    virtual std::string getsrc() const = 0;
    virtual std::string getdst() const = 0;
    unsigned int getId() const{return id;}
    const std::string getbody(){return body;}
};