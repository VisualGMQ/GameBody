#include "GameBody.hpp"
using namespace std;

GameBody::GameBody(const string title,int width,int height,Uint32 flag,int delaytime):error(false),gamequit(false),delaytime(delaytime),render(nullptr){
    win = new gbWindow(title,width,height,flag);
	render = win->getRender();
    texturefactory = new textureFactory(render);
    drawTool = new gbDrawTool(render);
}

void GameBody::dealEvent(){
 	while(SDL_PollEvent(&event))
        eventHandle(event);
}

void GameBody::renderBegin(){
	SDL_SetRenderTarget(render,win->getCanva());
    gbColor color = win->getBackgroundColor();
	SDL_SetRenderDrawColor(render, color.getR(), color.getG(), color.getB(), color.getA());
	SDL_RenderClear(render);	
}

void GameBody::eventHandle(SDL_Event& event){
    if(event.type == SDL_QUIT)
        gameExit();
}

void GameBody::renderEnd(){
	SDL_SetRenderTarget(render,nullptr);
	SDL_RenderCopy(render,win->getCanva(),nullptr,nullptr);
	SDL_RenderPresent(render);
}

void GameBody::delay(int millisec){
	SDL_Delay(millisec);
}

void GameBody::step(){
	renderBegin();
    dealEvent();
	update();
	renderEnd();
	delay(delaytime);
}

GameBody::~GameBody(){
	clean();
    if(win != nullptr)
        delete win;
    if(drawTool != nullptr)
        delete drawTool;
    if(texturefactory != nullptr)
        delete texturefactory;
    win = nullptr;
    render = nullptr;
    drawTool = nullptr;
    texturefactory = nullptr;
}
