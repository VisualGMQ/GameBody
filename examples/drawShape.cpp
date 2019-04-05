#include <SDL2/SDL.h>
#include <string>
#include "../src/GameBody.hpp"
using namespace std;

class OwnClass:public GameBody{
public:
	OwnClass():GameBody("drawTool",500,500,SDL_WINDOW_SHOWN,30){}
	void update() override{
        drawTool->drawLine(win->getCanva(),0,0,100,100,gbColor(0,0,0,255));
        drawTool->drawCircle(win->getCanva(), 50, 50, 50, gbColor(255,0,0,255));
        drawTool->drawRect(win->getCanva(), 100, 100, 50, 60, gbColor(0,255,0,255));
        drawTool->fillRect(win->getCanva(), 400, 400, 100, 100, gbColor(0,0,255,255));
		drawTool->drawCircle(win->getCanva(),200,200,100,gbColor(100,100,100,255));
		drawTool->drawSolidRect(win->getCanva(),300,300,100,100,gbColor(0,0,0,255),gbColor(0,255,0,255));
		drawTool->drawText(win->getCanva(),"Hello GameBody",0,0,300,50,20,gbColor(0,0,0));
		drawTool->drawText(win->getCanva(),"这里是中文哦",0,80,300,50,20,gbColor(0,0,0));
		drawTool->drawTextShaded(win->getCanva(),"这是带底色的文字",0,400,300,50,20,gbColor(255,0,0),gbColor(0,255,0));
	}
};

RUN_APP(OwnClass);
