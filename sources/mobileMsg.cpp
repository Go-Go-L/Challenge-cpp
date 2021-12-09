#include "../headers/mobileMsg.h"
#include <string>
#include <iostream>
unsigned int mobileMsg::staticmobileid = 100;
mobileMsg::mobileMsg(std::string cbody, std::string csrcPhoneNo, std::string cdstPhoneNo)
{
    _body = cbody;
    srcPhoneNo = csrcPhoneNo;
    dstPhoneNo = cdstPhoneNo;
    id = staticmobileid;
    staticmobileid++;
}
mobileMsg::mobileMsg()
{
    _body = "";
    srcPhoneNo = "";
    id = staticmobileid;
    staticmobileid++;
}

void mobileMsg::setbody(std::string bd){   _body = bd;}
void mobileMsg::setsrc(std::string src){srcPhoneNo = src;}
void mobileMsg::setdst(std::string dst){dstPhoneNo = dst;}
std::string mobileMsg::getsrc()const {return srcPhoneNo;}
std::string mobileMsg::getdst()const{return dstPhoneNo;}
std::string mobileMsg::getType(){return "Mobile";}

std::ostream &operator << (std::ostream & os , mobileMsg & message)
{
    os  << "Message: " <<message._body<<"\n Source: "<<message.srcPhoneNo<<"\n Dest: "<<message.dstPhoneNo<<"\n Id: "<<message.id;
    return os;
}


std::istream &operator >> (std::istream & is , mobileMsg &message)
{
    std::string bdy, src, dst;
    std::getline(is ,bdy );
    is >> message.srcPhoneNo >> message.dstPhoneNo;
    return is;
}