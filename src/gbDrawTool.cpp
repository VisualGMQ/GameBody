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

void gbDrawTool::drawText(SDL_Texture* dst,string text,int x,int y,int w,int h,int ptsize,gbColor color){
	drawText(dst,text,gbRect(x,y,w,h),ptsize,color);
}

void gbDrawTool::drawText(SDL_Texture* dst,string text,gbRect drect,int ptsize,gbColor color){
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(),ptsize);
	if(font == nullptr){
		SDL_Log("font can't be load");
		return;
	}
	SDL_Surface* surface = TTF_RenderUTF8_Blended(font,text.c_str(),color.get());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render,surface);
	gbColor tmp = startDraw(dst, color);
	SDL_Rect rect = drect.get();
	SDL_RenderCopy(render,texture,nullptr,&rect);
	endDraw(tmp);
	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void gbDrawTool::drawTextShaded(SDL_Texture* dst,string text,int x,int y,int w,int h,int ptsize,gbColor fontColor,gbColor shadeColor){
	drawTextShaded(dst,text,gbRect(x,y,w,h),ptsize,fontColor,shadeColor);
}

void gbDrawTool::drawTextShaded(SDL_Texture* dst,string text,gbRect drect,int ptsize,gbColor fontColor,gbColor shadeColor){
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(),ptsize);
	if(font == nullptr){
		SDL_Log("font can't be load");
		return;
	}
	SDL_Surface* surface = TTF_RenderUTF8_Shaded(font,text.c_str(),fontColor.get(),shadeColor.get());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render,surface);
	gbColor tmp = startDraw(dst, fontColor);
	SDL_Rect rect = drect.get();
	SDL_RenderCopy(render,texture,nullptr,&rect);
	endDraw(tmp);
	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

gbColor gbDrawTool::startDraw(SDL_Texture* dst,gbColor color){
	SDL_SetRenderTarget(render,dst);
	Uint8 r,g,b,a;
	SDL_GetRenderDrawColor(render,&r,&g,&b,&a);
	gbColor tcolor(r,g,b,a);
	SDL_SetRenderDrawColor(render,color.getR(),color.getG(),color.getB(),color.getA());
	return tcolor;
}

void gbDrawTool::endDraw(gbColor color){
	SDL_SetRenderTarget(render,nullptr);
	SDL_SetRenderDrawColor(render,color.getR(),color.getG(),color.getB(),color.getA());
}

void gbDrawTool::drawLine(SDL_Texture* dst,int x1,int x2,int y1,int y2,gbColor color){
		gbColor tmp = startDraw(dst,color);
		SDL_RenderDrawLine(render,x1,x2,y1,y2);	
		endDraw(tmp);
}

void gbDrawTool::drawLine(SDL_Texture* dst,gbPoint p1,gbPoint p2,gbColor color){
		drawLine(dst,p1.getX(),p1.getY(),p2.getX(),p2.getY(),color);
}

void gbDrawTool::drawCircle(SDL_Texture* dst,int centerx,int centery,int radius,gbColor color){
		gbColor tmp = startDraw(dst,color);
		for(int i=1;i<60;i++)
			SDL_RenderDrawLine(render,centerx+cos(6*i*M_PI/180)*radius,centery+sin(6*i*M_PI/180)*radius,centerx+cos(6*(i+1)*M_PI/180)*radius,centery+sin(6*(i+1)*M_PI/180)*radius);	
			SDL_RenderDrawLine(render,centerx+radius,centery,centerx+cos(6*M_PI/180)*radius,centery+sin(6*M_PI/180)*radius);	
		endDraw(tmp);
}

void gbDrawTool::drawCircle(SDL_Texture* dst,gbPoint center,int radius,gbColor color){
	drawCircle(dst,center.getX(),center.getY(),radius,color);
}

void gbDrawTool::drawRect(SDL_Texture* dst,gbRect rect,gbColor color){
	gbColor tmp = startDraw(dst,color);
	SDL_RenderDrawRect(render,&rect.get());
	endDraw(tmp);
}

void gbDrawTool::drawRect(SDL_Texture* dst,int x,int y,int w,int h,gbColor color){
	drawRect(dst,gbRect(x,y,w,h),color);
}

void gbDrawTool::drawRect(SDL_Texture* dst,gbPoint lt,gbSize size,gbColor color){
	gbRect rect(lt.getX(),lt.getY(),size.getWidth(),size.getHeight());
	drawRect(dst,rect,color);
}

void gbDrawTool::fillRect(SDL_Texture* dst,gbRect rect,gbColor color){
	gbColor tmp = startDraw(dst,color);
	SDL_RenderFillRect(render,&rect.get());
	endDraw(tmp);
}

void gbDrawTool::fillRect(SDL_Texture* dst,gbPoint lt,gbSize size,gbColor color){
	SDL_Rect rect={lt.getX(),lt.getY(),size.getWidth(),size.getHeight()};
	fillRect(dst,gbRect(rect),color);
}

void gbDrawTool::fillRect(SDL_Texture* dst,int x,int y,int w,int h,gbColor color){
	fillRect(dst,gbRect(x,y,w,h),color);
}


void gbDrawTool::drawSolidRect(SDL_Texture* texture,gbRect rect,gbColor outline,gbColor fillColor){
	fillRect(texture,rect,fillColor);
	drawRect(texture,rect,outline);	
}

void gbDrawTool::drawSolidRect(SDL_Texture* texture,int x,int y,int w,int h,gbColor outline,gbColor fillColor){
	drawSolidRect(texture,gbRect(x,y,w,h),outline,fillColor);	
}
