#pragma once
#include <string>
#include <iostream>
#include "message.h"
class emailMsg : public msg
{
private:
    unsigned int static _staticId ;
    std::string _srcAddr;
    std::string _dstAddr;

public:
    emailMsg(std::string _body, std::string _srcAddr, std::string _dstAddr);
    emailMsg();
    std::string getsrc() const override; //{return _srcAddr;};
    std::string getdst() const override;
    std::string getType() override;
    void setbody(std::string);
    void setsrc(std::string);
    void setdst(std::string);
    friend std::istream& operator>>(std::istream&, emailMsg&);
    friend std::ostream& operator<<(std::ostream&, emailMsg&);
};