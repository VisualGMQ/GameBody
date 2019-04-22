#include <SDL2/SDL.h>
#include "../src/GameBody.hpp"
#include <iostream>
using namespace std;

class myBody:public GameBody{
public:
    myBody():GameBody("test scale image", 400, 400, SDL_WINDOW_SHOWN, 30){
            /*
            SDL_Rect rect={0, 0, image->w/3, image->h/3};
            SDL_Surface* dst = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
            SDL_FillRect(dst, nullptr, 0xffffffff);
            SDL_BlitScaled(image, nullptr, dst, &rect);
            IMG_SavePNG(dst, "result.png");
            */
        SDL_Color color={0,0,0,255};
        win->setBackgroundColor(color);
        texture = texturefactory->getTextureFromImage("./2.png");
        texture->setPos(0, 0);
        texture->enableKeyColor(true);
        SDL_Color color2={255,255,255,255};
        texture->setKeyColor(color2);
    }

    void update() override{
        texture->update();
    }
private:
    SDL_Surface* image;
    gbTexture* texture;
};

RUN_APP(myBody)