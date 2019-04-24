#include "Director.hpp"

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

void GameBody::update(){
    currentScene->update();
}

void GameBody::registerScene(string key, gbScene* scene){
    if(scenemap.count(key) ==0 )
        scenemap[key] = scene;
}

void GameBody::setScene(string name){
    if(scenemap.count(name) == 0)
        Log("the scene is not found:" + name);
    else{
        gbScene* scene = scenemap[name];
        currentScene = scene;
    }
}

void GameBody::clean(){
    //TODO not finished
    for(auto i = scenemap.begin(); i != scenemap.end(); i++)
        if(i->second != nullptr){
            delete i->second;
        }
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

GameBody* DirectorSiglton::instance = nullptr;
const string DirectorSiglton::TITLE = "GameBody";
const unsigned int DirectorSiglton::WINDOW_WIDTH = 800;
const unsigned int DirectorSiglton::WINDOW_HEIGHT = 800;
const unsigned int DirectorSiglton::WINDOW_FLAG = 800;
const unsigned int DirectorSiglton::DELAY_TIME = 800;

GameBody* DirectorSiglton::getInstance(){
    if(instance == nullptr)
        instance = new GameBody(DirectorSiglton::TITLE, DirectorSiglton::WINDOW_WIDTH, DirectorSiglton::WINDOW_HEIGHT, DirectorSiglton::WINDOW_FLAG, DirectorSiglton::DELAY_TIME);
    return instance;
}

void DirectorSiglton::freeInstance(){
    delete instance;
}