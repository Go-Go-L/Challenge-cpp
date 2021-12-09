#pragma once
#include <string>
class msg
{
protected:
    std::string _body;
    unsigned int id;
    msg(std::string bd = "", unsigned int idd = 0) : _body(bd) , id(idd){};
public:
    virtual std::string getType() = 0;
    virtual std::string getsrc() const = 0;
    virtual std::string getdst() const = 0;
    unsigned int getId() const{return id;}
    const std::string getbody(){return _body;}
};