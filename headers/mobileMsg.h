#pragma once
#include <iostream>
#include <string>

#include "message.h"

class mobileMsg : public msg
{
    private:
        unsigned int static staticmobileid;  //id is static. Depends on id of previous object.
        std::string srcPhoneNo;
        std::string dstPhoneNo;

    public:
        mobileMsg(std::string body, std::string srcPhoneNO, std::string dstPhone);
        mobileMsg();
        std::string getsrc() const override; //{return srcPhoneNo;};
        std::string getdst() const override;
        std::string getType() override;
        void setbody(std::string);
        void setsrc(std::string);
        void setdst(std::string);
        friend std::istream& operator>>(std::istream&, mobileMsg&);
        friend std::ostream& operator<<(std::ostream&, mobileMsg&);
};