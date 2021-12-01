# Challenge project for the "C++ Essential Training" Formation Course.

This program is a message manager. There are two message types: **e-mail** and **mobile**. Each message has an associated 'sender' and 'receiver' which is a user object type (phone no. or e-mail address in each case) as well as message body and ID.

The most important aspect of this program is a MsgManager class. This class stores a list of messages sorting them by ID. It has addmessage and retrievemessage methods and it can print to a formatted file.

This program also allows producing formatted files with a message list. The user can add and retrieve messages from that list, as well as user information.

# Project info
The "exercise" is divided in 3 parts: A, B and C. Each has a different task.



### Part A 
tests the class and subclasses in/out operators. 

### Part B
prints a set of e-mail messages (and associated sender/receiver) to a formatted file with "txt" extension

### Part C
Reads from a formatted file that was produced by code in B, and stores it in a MsgManager object.


## Setup
**Using bash shell, while in Challenge-cpp directory:**

* Create build directory (optional but recommended): ```mkdir project```
* Move to build directory and build using cmake: ```cd build``` ; ```cmake -s ../ ```
* Execute Makefile generated by cmake: ```make```
* *challenge* executable should be created.


