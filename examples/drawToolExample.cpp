#include "gbDrawTool.hpp"
#include "gbWindow.hpp"

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_EVERYTHING);
    gbWindow window("this is draw tool example", 400, 400, SDL_WINDOW_SHOWN);
    SDL_Event event;
    bool isquit = false;
    SDL_Renderer* render = window.getRender();
    gbDrawTool drawtool(render);
    SDL_Point center={200, 200};
    SDL_Color color={255, 0, 0, 255};
    SDL_Color mcolor={0, 255, 0, 255};
    SDL_Color rcolor={0, 0, 255, 255};
    while(!isquit){
        SDL_RenderClear(render);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isquit = true;
        }    
        drawtool.drawCircle(nullptr, center, 50, color); 
        drawtool.drawLine(nullptr, 0, 0, 300, 300, mcolor);
        drawtool.drawRect(nullptr, 100, 100, 200, 200, rcolor);
        SDL_RenderPresent(render);
        SDL_Delay(60);
    }
    SDL_Quit();
    return 0;
}