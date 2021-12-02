#pragma once
#include <string>
#include <iostream>
#include "message.h"
class emailMsg : public msg
{
private:
    unsigned int static staticid ;
    std::string srcAddr;
    std::string dstAddr;

public:
    emailMsg(std::string body, std::string srcAddr, std::string dstAddr);
    emailMsg();
    std::string getsrc() override; //{return srcAddr;};
    std::string getdst() override;
    std::string getType() override;
    void setbody(std::string);
    void setsrc(std::string);
    void setdst(std::string);
    friend std::istream& operator>>(std::istream&, emailMsg&);
    friend std::ostream& operator<<(std::ostream&, emailMsg&);
};