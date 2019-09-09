HEADER_PATH=-I../include 
CC=g++ 
CPP_STD=-std=c++11 
SDL_HEADER=`sdl2-config --cflags` `pkg-config --cflags SDL2_image SDL2_ttf`
CONFIG=${HEADER_PATH} ${SDL_HEADER} ${CPP_STD}
BUILD_PATH=../obj
OBJS=gbDrawTool.o gbWindow.o geomentry.o gbTexture.o

message:
	@echo "please input the obj you want to compile"
gbDrawTool.o:
	${CC} gbDrawTool.cpp -c -o ${BUILD_PATH}/gbDrawTool.o ${CONFIG}
gbWindow.o: 
	${CC} gbWindow.cpp -c -o ${BUILD_PATH}/gbWindow.o ${CONFIG} 
geomentry.o: 
	${CC} geomentry.cpp -c -o ${BUILD_PATH}/geomentry.o ${CONFIG}
gbTexture.o: 
	${CC} gbTexture.cpp -c -o ${BUILD_PATH}/gbTexture.o ${CONFIG}

.PHONY:clean all
all:${OBJS}
clean:
	@-rm ../obj/*