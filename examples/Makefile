OBJS=../obj/GameBody.o ../obj/gbWindow.o ../obj/geomentry.o ../obj/gbDrawTool.o ../obj/gbTexture.o
exe:test drawShape texture main
test:test.cpp ${OBJS}
	g++ test.cpp ${OBJS} -o test `sdl2-config --libs --cflags` `pkg-config --libs --cflags sdl2_image sdl2_ttf` -std=c++11
drawShape:drawShape.cpp ${OBJS}
	g++ drawShape.cpp ${OBJS} -o drawShape `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -std=c++11
texture:texture.cpp ${OBJS}
	g++ texture.cpp ${OBJS} -o texture `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -std=c++11
main:main.cpp ${OBJS}
	g++ main.cpp ${OBJS} -o main `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -std=c++11
.PHONY:clean
clean:
	-rm Makefile~ test.cpp~ test drawShape texture
