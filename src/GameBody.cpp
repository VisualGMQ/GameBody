//include gb files
#include "gbWindow.hpp"
#include "geomentry.hpp"
#include "gbDrawTool.hpp"
#include "header.hpp"
#include "gbTexture.hpp"
#include "Director.hpp"
//#include "gbInput.hpp"

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

int main(int argc,char** argv){
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		SDL_Log("SDL can't be init");
		return -1;
	}
	if(TTF_Init() < 0){
		SDL_Log("TTF can't init");
		return -1;
	}
	if(IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG) < 0){
		SDL_Log("IMG can't init");
		return -1;
	}
	GameBody* instance = DirectorSiglton::getInstance();
	while(!instance->isQuit())
		instance->step();
	DirectorSiglton::freeInstance();
	SDL_Quit();
	return 0;
}