#ifndef __GBTEXTURE__HPP__
#define __GBTEXTURE__HPP__ 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "geomentry.hpp"
#include "header.hpp"
#include <string>
#include <vector>
using namespace std;

class gbTexture{
public:
    gbTexture(SDL_Texture* texture, SDL_Renderer* render);
    gbTexture(const string path, SDL_Renderer* render);
    gbTexture(int width, int height, SDL_Renderer* render);
    bool isKeyColorEnable(){return isKeyColor;}
    void enableKeyColor(bool enable){isKeyColor = enable;}
    void setPos(int,int);
    GB_CREATE_GETSETFUNC(gbPoint,Pos,position);
    GB_CREATE_GETSETFUNC(float,Angle,angle);
    GB_CREATE_GETFUNC(gbColor,KeyColor,keyColor);
    void setKeyColor(gbColor);
    GB_GET_BASIC_SOURCE(SDL_Texture*,texture);
    gbSize getSize(){return size;}
    void scale(int,int);
    void scale(float);
    void flipX(){flip = SDL_FLIP_VERTICAL;}
    void flipY(){flip = SDL_FLIP_HORIZONTAL;}
    void flipXY(){flip = SDL_RendererFlip(SDL_FLIP_VERTICAL|SDL_FLIP_HORIZONTAL);}
    void fitOriginSize();
    virtual void update();
    ~gbTexture();

private:
    SDL_Texture* texture;
    gbColor keyColor;
    bool isKeyColor;
    gbPoint position;
    float angle;
    SDL_Surface* surface;
    gbSize size;
    SDL_Renderer* render;
    SDL_RendererFlip flip;
};

class textureFactory{
public:
    textureFactory(SDL_Renderer* render);
    gbTexture* getTextureFromImage(const string path);
    gbTexture* getTextureFromTexture(SDL_Texture* texture);
    gbTexture* getTexture(int,int);
    ~textureFactory();
private:
    vector<gbTexture*> textures;
    SDL_Renderer* render;
};
#endif
