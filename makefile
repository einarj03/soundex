soundex: soundex.o main.o
	g++ -Wall -g soundex.o main.o -o soundex

main.o: main.cpp soundex.h
	g++ -Wall -c main.cpp

soundex.o: soundex.cpp soundex.h
	g++ -Wall -c soundex.cpp

clean:
	rm -rf soundex *.o