#ifndef __GEOMENTRY_HPP__
#define __GEOMENTRY_HPP__
/**
 * @file geomentry.hpp
 * @author VisualGMQ
 * @brief 一些小的几何类
 *
 * 这里面有一些类来表示几何概念，比如大小，点和矩形
 */
#include <SDL2/SDL.h>
#include "header.hpp"

/**
 * @class gbRect
 * @brief 矩形类
 */
class gbRect{
public:
    gbRect();
	gbRect(int x,int y,int w,int h);
	gbRect(SDL_Rect rect);
	bool operator==(gbRect) const;
	bool operator!=(gbRect) const;
	GB_GET_BASIC_SOURCE(SDL_Rect&,rect)
	GB_CREATE_GETSETFUNC(int,X,rect.x)
	GB_CREATE_GETSETFUNC(int,Y,rect.y)
	GB_CREATE_GETSETFUNC(int,Width,rect.w)
	GB_CREATE_GETSETFUNC(int,Height,rect.h)
private:
	SDL_Rect rect;
};

/**
 * @class gbPoint
 * @brief 点类
 */
class gbPoint{
public:
    gbPoint();
	gbPoint(int x,int y);
	gbPoint(SDL_Point p);
	bool operator==(gbPoint) const;
	bool operator!=(gbPoint) const;
	GB_GET_BASIC_SOURCE(SDL_Point&,point)
	GB_CREATE_GETSETFUNC(int,X,point.x)
	GB_CREATE_GETSETFUNC(int,Y,point.y)
private:
	SDL_Point point;
};

/**
 * @class gbSize
 * @brief 大小类
 *
 * 这个类的定义其实和gbPoint类是一模一样的，只不过将x,y变成了w,h
 */
class gbSize{
public:
    gbSize();
	gbSize(int w,int h);
	bool operator==(gbSize) const;
	bool operator!=(gbSize) const;
	GB_GET_BASIC_SOURCE(SDL_Point&,size)
	GB_CREATE_GETSETFUNC(int,Width,size.x)
	GB_CREATE_GETSETFUNC(int,Height,size.y)
private:
	SDL_Point size;
};

/**
 * @class gbColor
 * @brief 颜色类
 *
 * 支持RGBA，其实是封装了SDL的SDL_Color
 */
class gbColor{
public:
	gbColor();
	gbColor(SDL_Color color);
	gbColor(int r,int g,int b,int a = 255);
	GB_GET_BASIC_SOURCE(SDL_Color&,color);
	GB_CREATE_GETSETFUNC(Uint8,R,color.r)
	GB_CREATE_GETSETFUNC(Uint8,G,color.g)
	GB_CREATE_GETSETFUNC(Uint8,B,color.b)
	GB_CREATE_GETSETFUNC(Uint8,A,color.a)
private:
	SDL_Color color;
};
#endif
