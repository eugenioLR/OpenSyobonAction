lib-flags = `sdl-config --libs` -lSDL_gfx -lSDL_image -lSDL_mixer -lSDL_ttf
flags = -g -Wall -Wno-narrowing

SyobonAction:main.o loadg.o DxLib.o stageReader.o
	g++ $(flags) main.o loadg.o DxLib.o stageReader.o -o SyobonAction $(lib-flags)
main.o: main.cpp
	g++ $(flags) -c main.cpp
loadg.o: loadg.cpp
	g++ $(flags) -c loadg.cpp
DxLib.o: DxLib.cpp
	g++ $(flags) -c DxLib.cpp
stageReader.o: stageReader.cpp
	g++ $(flags) -c stageReader.cpp


clean:
	rm *.o SyobonAction
