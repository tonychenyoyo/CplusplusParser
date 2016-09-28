parser:Parserini.o main.o
	g++ Parserini.o main.o -o parser
Parserini.o:Parserini.cpp Parserini.h
	g++  -c Parserini.cpp
main.o:main.cpp Parserini.h
	g++ -c  main.cpp 

clean:
	rm -rf *.o
	rm -rf parser
