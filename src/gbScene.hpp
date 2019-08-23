#ifndef __GB_SCENE__
#define __GB_SCENE__
#include "Director.hpp"
#include "gbTexture.hpp"
#include "geomentry.hpp"

class gbScene{
public:
    gbScene();
    virtual void init(){};
    virtual void update() = 0;
    void changeToNextScene(string);/*TODO not considered*/
private:
   gbSize size; 
   gbTexture* canva;
};
#endif