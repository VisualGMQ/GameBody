SRC_FILE=src/GameBody.cpp src/gbDrawTool.cpp src/gbTexture.cpp src/gbWindow.cpp src/geomentry.cpp
HEADER_FILE=src/*.hpp 
TTF_FILE=src/*.ttf
DST_DIR=/usr/local/include/GameBody
LIB_DIR=/usr/local/lib

all:${SRC_FILE}
	-mkdir lib 
	-mkdir lib/shared
	g++ ${SRC_FILE} -o lib/shared/libGameBody.so -fPIC -shared -std=c++11 `sdl2-config --libs --cflags` `pkg-config --libs --cflags sdl2_image sdl2_ttf sdl2_mixer`

.PHONY:
install:
	-mkdir ${DST_DIR} 
	-cp -r ${HEADER_FILE} ${DST_DIR}
	-cp -r ${TTF_FILE} ${DST_DIR}
	echo "header file installed"
	-cp -r lib/shared/libGameBody.so ${LIB_DIR}
	echo "lib installed"
clean:
	-rm -rf /lib/shared/*