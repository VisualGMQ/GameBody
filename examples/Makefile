EXES=windowExample drawToolExample
CC=g++
SDL_LINK=`sdl2-config --libs --cflags` `pkg-config --libs --cflags SDL2_image SDL2_ttf`
CPP_STD=-std=c++11
HEADER_PATH=-I../include
CONFIG=${SDL_LINK} ${HEADER_PATH} ${CPP_STD}
OBJ_RELY=../obj/gbDrawTool.o ../obj/gbTexture.o ../obj/gbWindow.o ../obj/geomentry.o

message:
	@echo "please input your obj"
windowExample:windowExample.cpp
	${CC} windowExample.cpp ${OBJ_RELY} -o windowExample ${CONFIG}
drawToolExample:drawToolExample.cpp
	${CC} drawToolExample.cpp ${OBJ_RELY} -o drawToolExample ${CONFIG}
.PHONY:clean all
all:${EXES}
clean:
	@-rm ${EXES}
	
