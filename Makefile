markov: main.o markov.o dictionary.o
	g++ -o markov main.o markov.o dictionary.o

main.o: main.h main.cpp
	g++ -std=c++11 -pedantic -Wall -g -c main.cpp

markov.o: markov.h markov.cpp
	g++ -std=c++11 -pedantic -Wall -g -c markov.cpp

dictionary.o: dictionary.h dictionary.cpp
	g++ -std=c++11 -pedantic -Wall -g -c dictionary.cpp

clean:
	rm *.o
