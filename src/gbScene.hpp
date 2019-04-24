#ifndef __GB_SCENE__
#define __GB_SCENE__
#include "Director.hpp"
#include "gbTexture.hpp"
#include "geomentry.hpp"

#define RegisterScene(scenename, sceneclass) \
GameBody* instance = DirectorSiglton::getInstance(); \
sceneclass scene; \
instance->registerScene(scenename, scene);

class gbScene{
public:
    gbScene();
    virtual void init() = 0;
    virtual void update() = 0;
    void changeToNextScene(string);/*TODO not considered*/
private:
   gbSize size; 
   gbTexture* canva;
};
#endif