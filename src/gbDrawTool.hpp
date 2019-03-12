#ifndef __DRAW_TOOL__
#define __DRAW_TOOL__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <cstdlib>
#include <map>
#include "header.hpp"
#include "geomentry.hpp"
using namespace std;

const string preFontPath = "./";

class gbDrawTool{
public:
	enum FontType{
		FANGSONG,
		KAITI,
		HEITI
	};
	gbDrawTool() = delete;
	gbDrawTool(SDL_Renderer*);
	void drawText(SDL_Texture*,string text,int x,int y,int w,int h,int ptsize,gbColor);
	void drawText(SDL_Texture*,string text,gbRect rect,int ptsize,gbColor);
	void drawTextShaded(SDL_Texture*,string text,int x,int y,int w,int h,int ptsize,gbColor fontColor,gbColor shadeColor);
	void drawTextShaded(SDL_Texture*,string text,gbRect rect,int ptsize,gbColor fontColor,gbColor shadeColor);
	void drawLine(SDL_Texture*,int x1,int x2,int y1,int y2,gbColor);
	void drawLine(SDL_Texture*,gbPoint p1,gbPoint p2,gbColor);
	void drawCircle(SDL_Texture*,int centerx,int centery,int radius,gbColor);
	void drawCircle(SDL_Texture*,gbPoint center,int radius,gbColor);
	void drawRect(SDL_Texture*,int x,int y,int w,int h,gbColor);
	void drawRect(SDL_Texture*,gbRect,gbColor);
	void drawRect(SDL_Texture*,gbPoint lt,gbSize size,gbColor);
	void fillRect(SDL_Texture*,int x,int y,int w,int h,gbColor);
	void fillRect(SDL_Texture*,gbRect,gbColor);
	void fillRect(SDL_Texture*,gbPoint p,gbSize size,gbColor);
	void drawSolidRect(SDL_Texture*,int x,int y,int w,int h,gbColor outline,gbColor fillColor);
	void drawSolidRect(SDL_Texture*,gbRect,gbColor outline,gbColor fillColor);
	bool changeTTF(const string path);
private:
	gbColor startDraw(SDL_Texture* dst,gbColor color);
	void endDraw(gbColor);
	SDL_Renderer* render;
	string fontPath;
	map<FontType, string> fontMap;
};
#endif
