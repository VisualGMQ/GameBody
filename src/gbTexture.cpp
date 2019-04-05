#include "gbTexture.hpp"

textureFactory::textureFactory(SDL_Renderer* render){
    this->render = render;
}

gbTexture* textureFactory::getTextureFromImage(const string path){
    gbTexture* texture = new gbTexture(path, render);
    textures.push_back(texture);
    return texture;
}

gbTexture* textureFactory::getTexture(int width,int height){
    gbTexture* texture = new gbTexture(width, height, render);
    textures.push_back(texture);
    return texture;
}

gbTexture* textureFactory::getTextureFromTexture(SDL_Texture* texture){
    gbTexture* ntexture = new gbTexture(texture,render);
    textures.push_back(ntexture);
    return ntexture;
}

textureFactory:: ~textureFactory(){
    for(int i=0;i<textures.size();i++)
        if(textures[i] != nullptr)
            delete textures[i];
}


void gbTexture::fitOriginSize(){
    int w,h;
    SDL_QueryTexture(this->texture, nullptr, nullptr, &w, &h);
    size.setWidth(w);
    size.setHeight(h);
}

gbTexture::gbTexture(SDL_Texture* texture,SDL_Renderer* render):surface(nullptr),angle(0),isKeyColor(false),texture(nullptr),render(render),flip(SDL_FLIP_NONE){
    texture = texture; 
    this->render = render;
    fitOriginSize();
}


gbTexture::gbTexture(const string path, SDL_Renderer* render):angle(0),isKeyColor(false),render(render),flip(SDL_FLIP_NONE){
    surface = IMG_Load(path.c_str());
    this->render = render;
    if(surface != nullptr)
        this->texture = SDL_CreateTextureFromSurface(this->render, surface);
    fitOriginSize();
}

gbTexture::gbTexture(int width, int height, SDL_Renderer* render):surface(nullptr),angle(0),isKeyColor(false),texture(nullptr),render(render),flip(SDL_FLIP_NONE){
    texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    this->render = render;
    size.setWidth(width);
    size.setHeight(height);
}

void gbTexture::setPos(int x, int y){
    position.setX(x);
    position.setY(y);
}

void gbTexture::scale(int width,int height){
    size.setWidth(width);
    size.setHeight(height);
}

void gbTexture::scale(float s){
    size.setWidth(int(size.getWidth()*s));
    size.setHeight(int(size.getHeight()*s));
}

void gbTexture::update(){
    SDL_Rect rect={position.getX(), position.getY(),size.getWidth(),size.getHeight()};
    SDL_RenderCopyEx(render, texture, nullptr, &rect, angle, nullptr, flip);
}

gbTexture::~gbTexture(){
    if(texture != nullptr)
        SDL_DestroyTexture(texture);
    if(surface != nullptr)
        SDL_FreeSurface(surface);
    texture = nullptr;
    surface = nullptr;
}
