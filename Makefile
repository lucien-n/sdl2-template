all:
	g++ -I include -L lib -o main src/*.cpp -Wall -pedantic -std=c++17 -O2 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image