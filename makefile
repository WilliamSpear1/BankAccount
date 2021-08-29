bankaccount: main.o bankaccount.o 
	g++  -Wall -I/usr/include/cppcon main.o  bankaccount.o  -o BankAccount -L/usr/lib -lmysqlcppconn
main.o: main.cpp bankaccount.h
	g++ -c  main.cpp
bankaccount.o: bankaccount.cpp bankaccount.h
	g++ -c bankaccount.cpp
clean:
	rm *.o BankAccount

