#include <SDL2/SDL.h>
#include <string>
#include "../src/GameBody.hpp"
using namespace std;

class OwnClass:public GameBody{
public:
	OwnClass():GameBody("drawTool",500,500,SDL_WINDOW_SHOWN,30){}
	void update() override{
		SDL_Color color = {255,255,255,255};
        drawTool->drawLine(win->getCanva(),0,0,100,100,color);
        drawTool->drawCircle(win->getCanva(), 50, 50, 50,color);
        drawTool->drawRect(win->getCanva(), 100, 100, 50, 60, color);
        drawTool->fillRect(win->getCanva(), 400, 400, 100, 100, color);
		drawTool->drawCircle(win->getCanva(),200,200,100,color);
		SDL_Color color2={0,255,0,255};
		drawTool->drawSolidRect(win->getCanva(),300,300,100,100,color,color2);
		drawTool->drawText(win->getCanva(),"Hello GameBody",0,0,300,50,20,color);
		drawTool->drawText(win->getCanva(),"这里是中文哦",0,80,300,50,20,color);
		drawTool->drawTextShaded(win->getCanva(),"这是带底色的文字",0,400,300,50,20,color,color2);
	}
};

RUN_APP(OwnClass);
