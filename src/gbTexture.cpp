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
    size.x = w;
    size.y = h;
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
    size.x = width;
    size.y = height;
}

void gbTexture::setPos(int x, int y){
    position.x = x;
    position.y = y;
}

void gbTexture::setKeyColor(SDL_Color color){
    keyColor = color;
    Uint32 c = SDL_MapRGB(surface->format, color.r, color.g, color.b);
    SDL_Log("%x", c);
    if(isKeyColor)
        SDL_SetColorKey(surface, SDL_TRUE, c); 
    else
        SDL_SetColorKey(surface, SDL_FALSE, c); 
    SDL_DestroyTexture(texture);
    texture = SDL_CreateTextureFromSurface(render, surface);
}

void gbTexture::scale(int width,int height){
    size.x = width;
    size.y = height;
}

void gbTexture::scale(float s){
    size.x = int(size.x*s);
    size.y = int(size.y*s);
}

void gbTexture::update(){
    SDL_Rect rect={position.x, position.y,size.x,size.y};
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
