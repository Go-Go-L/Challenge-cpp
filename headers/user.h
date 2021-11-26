#include <string>
#include <iostream>
#pragma once

class user
{
protected:
    std::string name;
    std::string email;
    std::string mobile;

public:
    user(std::string name, std::string email, std::string mobile);
    user();
    std::string getname() const ;
    std::string getemail() const;
    std::string getmobile() const;
    void setname(std::string name);
    void setemail(std::string email);
    void setmobile(std::string mobile);
public:
    bool operator < (const user &u1);

};
std::istream &operator>>(std::istream&, user&);
std::ostream &operator<<(std::ostream&, user&);