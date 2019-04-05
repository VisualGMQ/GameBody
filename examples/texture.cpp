#include <SDL2/SDL.h>
#include "../src/GameBody.hpp"
using namespace std;

class MyBody: public GameBody{
public:
   MyBody():GameBody("texture", 500, 500, SDL_WINDOW_SHOWN, 30){
       texture = texturefactory->getTextureFromImage("./1.bmp"); 
       if(texture->get() == nullptr)
               SDL_Log("Texture load failed");
        texture->setPos(100, 0);
   } 

   void update() override{
        texture->update();
   }
private:
   gbTexture* texture;
};

RUN_APP(MyBody);
