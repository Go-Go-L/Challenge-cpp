partC: main_challenge.o mobileMsg.o emailMsg.o user.o msgManager.o
	g++ -o partC main_challenge.o mobileMsg.o emailMsg.o user.o msgManager.o
	
main_challege.o: main_challenge.cpp emailMsg.h user.h mobileMsg.h msgManager.h
	g++ -c main_challenge.cpp

user.o: user.cpp user.h
	g++ -c user.cpp

emailMsg.o: emailMsg.cpp message.h
	g++ -c emailMsg.cpp

mobileMsg.o: mobileMsg.cpp message.h
	g++ -c mobileMsg.cpp

msgManager.o: msgManager.cpp msgManager.h message.h mobileMsg.h emailMsg.h
	g++ -c msgManager.cpp