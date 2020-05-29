#include "gbDrawTool.hpp"

gbDrawTool::gbDrawTool(SDL_Renderer* render){
	if(render == nullptr)
		abort();
	this->render = render;	
	fontMap[FANGSONG] = preFontPath + "Fangsong.ttf";
	fontMap[KAITI]    = preFontPath + "./Kaiti.ttf";
	fontMap[HEITI]    = preFontPath + "./SimHei.ttf";

	fontPath = fontMap[FANGSONG];
}

bool gbDrawTool::changeTTF(const string path){
	TTF_Font* font = nullptr;
	font = TTF_OpenFont(fontPath.c_str(),10);
	if(font == nullptr)
			return false;
	fontPath = path;
	TTF_CloseFont(font);
	return true;
}

void gbDrawTool::drawText(SDL_Texture* dst,string text,int x,int y,int w,int h,int ptsize,SDL_Color color){
	SDL_Rect rect={x,y,w,h};
	drawText(dst,text, rect,ptsize,color);
}

void gbDrawTool::drawText(SDL_Texture* dst,string text,SDL_Rect drect,int ptsize,SDL_Color color){
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(),ptsize);
	if(font == nullptr){
		SDL_Log("font can't be load");
		return;
	}
	SDL_Surface* surface = TTF_RenderUTF8_Blended(font,text.c_str(),color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render,surface);
	SDL_Color tmp = startDraw(dst, color);
	SDL_RenderCopy(render,texture,nullptr,&drect);
	endDraw(tmp);
	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void gbDrawTool::drawTextShaded(SDL_Texture* dst,string text,int x,int y,int w,int h,int ptsize,SDL_Color fontColor,SDL_Color shadeColor){
	SDL_Rect rect = {x,y,w,h};
	drawTextShaded(dst,text,rect,ptsize,fontColor,shadeColor);
}

void gbDrawTool::drawTextShaded(SDL_Texture* dst,string text,SDL_Rect drect,int ptsize,SDL_Color fontColor,SDL_Color shadeColor){
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(),ptsize);
	if(font == nullptr){
		SDL_Log("font can't be load");
		return;
	}
	SDL_Surface* surface = TTF_RenderUTF8_Shaded(font,text.c_str(),fontColor,shadeColor);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render,surface);
	SDL_Color tmp = startDraw(dst, fontColor);
	SDL_RenderCopy(render,texture,nullptr,&drect);
	endDraw(tmp);
	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

SDL_Color gbDrawTool::startDraw(SDL_Texture* dst,SDL_Color color){
	if(dst != nullptr)
		SDL_SetRenderTarget(render,dst);
	SDL_Color tcolor;
	SDL_GetRenderDrawColor(render,&tcolor.r,&tcolor.g,&tcolor.b,&tcolor.a);
	SDL_SetRenderDrawColor(render,color.r,color.g,color.b,color.a);
	return tcolor;
}

void gbDrawTool::endDraw(SDL_Color color){
	SDL_SetRenderTarget(render,nullptr);
	SDL_SetRenderDrawColor(render,color.r,color.g,color.b,color.a);
}

void gbDrawTool::drawLine(SDL_Texture* dst,int x1,int y1,int x2,int y2,SDL_Color color){
		SDL_Color tmp = startDraw(dst,color);
		SDL_RenderDrawLine(render,x1,y1,x2,y2);	
		endDraw(tmp);
}

void gbDrawTool::drawLine(SDL_Texture* dst,SDL_Point p1,SDL_Point p2,SDL_Color color){
		drawLine(dst,p1.x,p1.y,p2.x,p2.y,color);
}

void gbDrawTool::drawCircle(SDL_Texture* dst,int centerx,int centery,int radius,SDL_Color color){
		SDL_Color tmp = startDraw(dst,color);
		for(int i=1;i<60;i++)
			SDL_RenderDrawLine(render,centerx+cos(6*i*M_PI/180)*radius,centery+sin(6*i*M_PI/180)*radius,centerx+cos(6*(i+1)*M_PI/180)*radius,centery+sin(6*(i+1)*M_PI/180)*radius);	
			SDL_RenderDrawLine(render,centerx+radius,centery,centerx+cos(6*M_PI/180)*radius,centery+sin(6*M_PI/180)*radius);	
		endDraw(tmp);
}

void gbDrawTool::drawCircle(SDL_Texture* dst,SDL_Point center,int radius,SDL_Color color){
	drawCircle(dst,center.x,center.y,radius,color);
}

void gbDrawTool::drawRect(SDL_Texture* dst,SDL_Rect rect,SDL_Color color){
	SDL_Color tmp = startDraw(dst,color);
	SDL_RenderDrawRect(render,&rect);
	endDraw(tmp);
}

void gbDrawTool::drawRect(SDL_Texture* dst,int x,int y,int w,int h,SDL_Color color){
	SDL_Rect rect={x,y,w,h};
	drawRect(dst,rect,color);
}

void gbDrawTool::drawRect(SDL_Texture* dst,SDL_Point lt,SDL_Point size,SDL_Color color){
	SDL_Rect rect={lt.x,lt.y,size.x,size.y};
	drawRect(dst,rect,color);
}

void gbDrawTool::fillRect(SDL_Texture* dst,SDL_Rect rect,SDL_Color color){
	SDL_Color tmp = startDraw(dst,color);
	SDL_RenderFillRect(render,&rect);
	endDraw(tmp);
}

void gbDrawTool::fillRect(SDL_Texture* dst,SDL_Point lt,SDL_Point size,SDL_Color color){
	SDL_Rect rect={lt.x,lt.y,size.x,size.y};
	fillRect(dst,rect,color);
}

void gbDrawTool::fillRect(SDL_Texture* dst,int x,int y,int w,int h,SDL_Color color){
	SDL_Rect rect={x,y,w,h};
	fillRect(dst,rect,color);
}


void gbDrawTool::drawSolidRect(SDL_Texture* texture,SDL_Rect rect,SDL_Color outline,SDL_Color fillColor){
	fillRect(texture,rect,fillColor);
	drawRect(texture,rect,outline);	
}

void gbDrawTool::drawSolidRect(SDL_Texture* texture,int x,int y,int w,int h,SDL_Color outline,SDL_Color fillColor){
	SDL_Rect rect = {x,y,w,h};
	drawSolidRect(texture,rect,outline,fillColor);	
}
