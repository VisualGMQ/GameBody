/** @file gbDrawTool.hpp
 * @author VisualGMQ
 */

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

/* @var preFontPath 
 * @breif 字体文件的路径
 * 
 * 这里存放着字体文件的路径
 */
const string preFontPath = "./";

/** @class gbDrawTool 
 * @brief 用于绘制几何图像的类
 *
 * 这个类需要一个SDL_Renderer*来生成一个实例对象，可以绘制很多的图形
 */
class gbDrawTool{
public:
    /** @enum FontType 
     * @brief 字体类型，给定了三种类型：仿宋，楷体和黑体
     */
	enum FontType{
		FANGSONG,
		KAITI,
		HEITI
	};
	gbDrawTool() = delete;
    /** @fn gbDrawTool(SDL_Renderer*)
     * @param render 传入的渲染器
     * @brief 构造函数，需要传入一个render
     */
	gbDrawTool(SDL_Renderer*);
	void drawText(SDL_Texture*,string text,int x,int y,int w,int h,int ptsize,gbColor);
	void drawText(SDL_Texture*,string text,gbRect rect,int ptsize,gbColor);
	void drawTextShaded(SDL_Texture*,string text,int x,int y,int w,int h,int ptsize,gbColor fontColor,gbColor shadeColor);
	void drawTextShaded(SDL_Texture*,string text,gbRect rect,int ptsize,gbColor fontColor,gbColor shadeColor);
	void drawLine(SDL_Texture*,int x1,int y1,int x2,int y2,gbColor);
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
    /**@fn changeTTF(const string path)
     * @param path 新字体文件的路径
     * @brief 改变TTF的路径，也就是设置新的ttf文件。
     * @return 如果文件不存在或者无法载入，返回false，否则返回true.
     *
     * 这个函数会改变gbDrawTool使用的字体.
     */
	bool changeTTF(const string path);
private:
	gbColor startDraw(SDL_Texture* dst,gbColor color);
	void endDraw(gbColor);
	SDL_Renderer* render;
	string fontPath;
	map<FontType, string> fontMap;
};
#endif
