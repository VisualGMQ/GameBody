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
	void drawText(SDL_Texture*,string text,int x,int y,int w,int h,int ptsize,SDL_Color);
	void drawText(SDL_Texture*,string text,SDL_Rect rect,int ptsize,SDL_Color);
	void drawTextShaded(SDL_Texture*,string text,int x,int y,int w,int h,int ptsize,SDL_Color fontColor,SDL_Color shadeColor);
	void drawTextShaded(SDL_Texture*,string text,SDL_Rect rect,int ptsize,SDL_Color fontColor,SDL_Color shadeColor);
	void drawLine(SDL_Texture*,int x1,int y1,int x2,int y2,SDL_Color);
	void drawLine(SDL_Texture*,SDL_Point p1,SDL_Point p2,SDL_Color);
	void drawCircle(SDL_Texture*,int centerx,int centery,int radius,SDL_Color);
	void drawCircle(SDL_Texture*,SDL_Point center,int radius,SDL_Color);
	void drawRect(SDL_Texture*,int x,int y,int w,int h,SDL_Color);
	void drawRect(SDL_Texture*,SDL_Rect,SDL_Color);
	void drawRect(SDL_Texture*,SDL_Point lt,SDL_Point size,SDL_Color);
	void fillRect(SDL_Texture*,int x,int y,int w,int h,SDL_Color);
	void fillRect(SDL_Texture*,SDL_Rect,SDL_Color);
	void fillRect(SDL_Texture*,SDL_Point p,SDL_Point size,SDL_Color);
	void drawSolidRect(SDL_Texture*,int x,int y,int w,int h,SDL_Color outline,SDL_Color fillColor);
	void drawSolidRect(SDL_Texture*,SDL_Rect ,SDL_Color outline,SDL_Color fillColor);
    /**@fn changeTTF(const string path)
     * @param path 新字体文件的路径
     * @brief 改变TTF的路径，也就是设置新的ttf文件。
     * @return 如果文件不存在或者无法载入，返回false，否则返回true.
     *
     * 这个函数会改变gbDrawTool使用的字体.
     */
	bool changeTTF(const string path);
private:
	SDL_Color startDraw(SDL_Texture* dst,SDL_Color color);
	void endDraw(SDL_Color);
	SDL_Renderer* render;
	string fontPath;
	map<FontType, string> fontMap;
};
#endif
