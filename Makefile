exe:	main.cpp
	g++ *.cpp src/*.cpp `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_mixer -lSDL2_ttf -Iincludes -I/opt/local/include/SDL2

run:
	./a.out

r:
	./a.out

clean:
	rm a.out

c:
	rm a.out

#command to make: make
#command to run: make run
