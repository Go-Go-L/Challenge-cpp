#include "../headers/emailMsg.h"
#include <string>
#include <iostream>
unsigned int emailMsg::staticid = 1;  
emailMsg::emailMsg(std::string cbody, std::string csrcAddr, std::string cdstAddr)
{
    body = cbody ; 
    srcAddr = csrcAddr;
    dstAddr = cdstAddr;
    id = staticid;
    staticid++;

}
emailMsg::emailMsg()
{
    body = "";
    srcAddr = "";
    dstAddr = "";
    id = staticid;
    staticid++;
}
std::string emailMsg::getType(){return "Email";}

void emailMsg::setbody(std::string bd){   body = bd;}
void emailMsg::setsrc(std::string src){srcAddr = src;}
void emailMsg::setdst(std::string dst){dstAddr = dst;}
std::string emailMsg::getsrc(){return srcAddr;}
std::string emailMsg::getdst(){return dstAddr;}
std::ostream &operator << (std::ostream & os ,emailMsg & message)
{
    os  << "Message: " <<message.getbody()<<"\n Source: "<<message.getsrc()<<"\n Dest: "<<message.getdst()<<"\n Id: "<<message.getId();
    return os;
}


std::istream &operator >> (std::istream & is , emailMsg &message)
{
    std::string bdy, src, dst;
    std::getline(is ,bdy );
    is >> src >> dst;
    message.setbody(bdy);
    message.setdst(dst);
    message.setsrc(src);
    return is;
}