bankaccount: main.o bankaccount.o 
	g++  main.o  bankaccount.o  -o BankAccount
main.o: main.cpp bankaccount.h
	g++ -c  main.cpp
bankaccount.o: bankaccount.cpp bankaccount.h
	g++ -c bankaccount.cpp
clean:
	rm *.o BankAccount

