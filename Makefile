all:
	g++ -o main main.cpp -I./include -L./lib  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
