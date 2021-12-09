#include "../headers/emailMsg.h"
#include <string>
#include <iostream>
unsigned int emailMsg::_staticId = 1;  
emailMsg::emailMsg(std::string cbody, std::string c_srcAddr, std::string c_dstAddr) : msg(cbody , _staticId),  _srcAddr(c_srcAddr), _dstAddr(c_dstAddr)
{

    _staticId++;

}
emailMsg::emailMsg()
{
    _body = "";
    _srcAddr = "";
    _dstAddr = "";
    id = _staticId;
    _staticId++;
}
std::string emailMsg::getType(){return "Email";}

void emailMsg::setbody(std::string bd){   _body = bd;}
void emailMsg::setsrc(std::string src){_srcAddr = src;}
void emailMsg::setdst(std::string dst){_dstAddr = dst;}
std::string emailMsg::getsrc()const {return _srcAddr;}
std::string emailMsg::getdst()const {return _dstAddr;}
std::ostream &operator << (std::ostream & os ,emailMsg & message)
{
    os  << "Message:" <<message.getbody()<<"\n Source: "<<message.getsrc()<<"\n Dest: "<<message.getdst()<<"\n Id: "<<message.getId();
    return os;
}


std::istream &operator >> (std::istream & is , emailMsg &message)
{
    std::string bdy, src, dst;
    std::getline(is ,bdy );
    is >> message._srcAddr >> message._dstAddr;
    message._body = bdy;
    return is;
}
