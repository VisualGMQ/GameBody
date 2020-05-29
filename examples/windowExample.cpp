#include "gbWindow.hpp"

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
    gbWindow window("this is gbWindow", 400, 400, SDL_WINDOW_SHOWN);
    bool isquit = false;
    SDL_Event event;
    SDL_SetRenderDrawColor(window.getRender(), 100, 100, 100, 255);
    while(!isquit){
        SDL_RenderClear(window.getRender());
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isquit = true;
        }
        SDL_Delay(60);
        SDL_RenderPresent(window.getRender());
    }
    SDL_Quit();
}