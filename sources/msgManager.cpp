#include "../headers/msgManager.h"
#include "../headers/message.h"
#include "../headers/emailMsg.h"
#include "../headers/mobileMsg.h"
#include <fstream>
void msgManager::addUser(const user& us)
{
    std::pair <std::string  , user> pair= std::make_pair(us.getemail() , us);
    _userMap.insert(pair);
}
void msgManager::addMsg(msg *message)
{
    _ptrVec.push_back(std::unique_ptr<msg> (message));
}

void msgManager::getEmailsFrom(std::string mail) const
{
    for (auto& it : _ptrVec)
        {
            if (it->getsrc() == mail)
            {
                std::cout<<'\n'<<"Recipient name: " <<it->getsrc()<< "; Message: "<< it->getbody();
            }
        }
}

std::ostream& operator<<(std::ostream& os, msgManager& msg)
{
    for (auto& it : msg._ptrVec)
    {
        std::cout<<"Type: "<<it->getType()<<'\n'<<"Source: "<<it->getsrc()<<" ; Destination: "<<it->getdst()<<"; Body: "<<it->getbody()<<std::endl<<"--"<<std::endl;
    }
    return os;
}

void msgManager::saveOnFile(std::string filename)
{
    std::ofstream outfile(filename);
    for (auto it1 : _userMap)
    {
        user currentuser = it1.second;
        outfile<<"User"<<'\t'<<currentuser.getname()<<'\t'<<currentuser.getemail()<<'\t'<<currentuser.getmobile()<<std::endl;
    }
    for (auto &it: _ptrVec)
    {
        outfile<<it->getType()<<'\t'<<it->getsrc()<<'\t'<<it->getdst()<<'\t'<<it->getbody()<<std::endl;
    }
}


