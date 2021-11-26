#include "user.h"
#include <string>
#include <iostream>


//constructors

//getters and setters
////////////////////////////////////////////////////////////

user::user(std::string cname, std::string cemail, std::string cmobile) : name(cname) , email(cemail), mobile(cmobile) {}

user::user():  name("") , email(""), mobile("") {}

std::string user::getname() const{return name;}
std::string user::getemail() const{return email;}
std::string user::getmobile() const{return mobile;}
void user::setname(std::string cname){name = cname;}
void user::setemail(std::string cemail){email = cemail;}
void user::setmobile(std::string cmobile){mobile = cmobile;}
bool user::operator<(const user &u1)
{
    return email < u1.getemail();
}
std::ostream &operator << (std::ostream & os ,user & us)
{
    os  << "Name:  " <<us.getname()<<"; Email: "<<us.getemail()<<"; Mobile: "<<us.getmobile();
    return os;
}


std::istream &operator >> (std::istream & is , user &us)
{
    std::string name, mail, mobile;
    std::getline(is, name );
    std::getline(is, mail);
    std::getline(is, mobile);
    us.setemail(mail);
    us.setmobile(mobile);
    us.setname(name);
    return is;
}