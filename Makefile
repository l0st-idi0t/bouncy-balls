all:
	g++ -I src/include -L src/lib -o bounce main.cpp ball.cpp -lmingw32 -lSDL2main -lSDL2
