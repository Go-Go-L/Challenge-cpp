#include <iostream>
#include <fstream>
#include  "../headers/user.h"
#include "../headers/emailMsg.h"
#include "../headers/mobileMsg.h"
#include "../headers/msgManager.h"
#include <sstream>
using namespace std;
void partA();

void partB();

void partC();

int main() {

    partA();

    //partB();

    //partC();

    return 0;
}

void partB(){
    cout << endl << "*** Part B ***" << endl << endl;

    msgManager m;

    m.addUser(user("Maria", "m@ua.pt", "+351234370500"));
    m.addUser(user("Ana", "a@ua.pt", "+351234370555"));
    m.addUser(user("Ze", "z@ua.pt", "+351234234234"));
    m.addUser(user("Bernardo", "b@ua.pt", "+351234370111"));

    m.addMsg(new emailMsg("The PpO exam is today!", "m@ua.pt", "a@ua.pt"));
    m.addMsg(new emailMsg("I am ready :-)", "a@ua.pt", "m@ua.pt"));
    m.addMsg(new mobileMsg("The PpO exam is indeed today!", "+351234370000", "+351234370111"));
    m.addMsg(new emailMsg("The content is what I studied.", "a@ua.pt", "z@ua.pt"));
    m.addMsg(new mobileMsg("I love programming.", "+351234370555", "+351234370500"));

    cout << m << endl;

    cout << "Sent emails from a@ua.pt: " << endl;
    m.getEmailsFrom("a@ua.pt");

    m.saveOnFile("messages.txt");
}

void partC(){
    cout << endl << "*** Part C ***" << endl;
    msgManager m;
    std::ifstream file("messages.txt");
    std::string line, word, w1, w2,w3;
    std::string type = "User";
    int count = 0;
    while (std::getline(file, line))   //retira uma linha
    {
        count = 0;
        std::stringstream ss(line);
        while (std::getline(ss,word,'\t'))
        {
            std::cout<<type<<'\n';
            switch (count)
            {
            case 0:
                type = word;
                break;
            case 1:
                w1 = word;
                break;
            case 2:
                w2 = word;
            case 3:
                w3 = word;
                break;
            default:
                break;
            }
            count++;
        }
        if (type == "User")
        {
            user us(w1,w2,w3);
            m.addUser(us);
        }
        if (type == "Email")
        {
            m.addMsg(new emailMsg(w3,w1,w2));
        }
        if (type=="Mobile")
        {
            m.addMsg(new mobileMsg(w3,w1,w2));
        }
        
    }

   std::cout << m << endl;    

}

void partA()
{
cout << "Parte A" << endl << endl;

user u1("Maria", "m@ua.pt", "+351234370500");
cout << u1 << endl;

user u2;
cout << "new user (name email mobile)? ";
cin >> u2;
cout << u2 << endl;

user u3(u1);
cout << u3 << endl;
u3.setname("Manuel"); u3.setemail("mm@ua.pt"); u3.setmobile("+351234370522");
cout << u3.getname() << " ; " << u3.getemail() << " ; " << u3.getmobile() << endl;

if(u1 < u3) // comparison by email
    cout << "first is " << u1 << endl;
else
    cout << "first is " << u3 << endl;

cout <<"------------------------------------------------" <<  endl;

emailMsg e1("The PpO exam is today!", "m@ua.pt", "mm@ua.pt");
cout << e1 << endl;

emailMsg e2;
string dummy;
std::getline(cin, dummy); // remove any lost \n
cout << "new email (first the content in one line, then the from and to addresses)? ";
cin >> e2;
cout << e2 << endl;

emailMsg e3(e2);
cout << "e3 id: " << e3.getId() << endl;

mobileMsg m1("The PpO exam is indeed today!", "+351234370500", "+351234370522");
cout << m1 << endl;

mobileMsg m2;
std::getline(cin, dummy); // remove any lost \n
cout << "new mobile (first the content in one line, then the from and to mobiles)? ";
cin >> m2;
cout << m2 << endl;

mobileMsg m3(m2);
cout << "m3 id: " << m3.getId() << " and type " << m3.getType() << endl;
}