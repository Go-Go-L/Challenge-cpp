#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "emailMsg.h"
#include "user.h"
#include "mobileMsg.h"

class msgManager
{
public:
    std::map <std::string , user> user_m;
    std::vector<std::unique_ptr<msg>> ptr_vec;

public:
    void addUser(const user&);
    void addMsg(msg* );
    void getEmailsFrom(std::string ) const;
    void saveOnFile(std::string filename);
    friend std::ostream& operator<<(std::ostream&, msgManager&);
};