#include "geomentry.hpp"

gbRect::gbRect(){
    rect.x=0;
    rect.y=0;
    rect.w=0;
    rect.h=0;
}

gbRect::gbRect(int x,int y,int w,int h){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

gbRect::gbRect(SDL_Rect rect){
	this->rect = rect;
}

bool gbRect::operator==(gbRect r) const{
	return (rect.x == r.getX()) && (rect.y == r.getY()) && (rect.w == r.getWidth()) && (rect.h == r.getHeight());
}

bool gbRect::operator!=(gbRect r) const{
	return !(*this == r);
}

gbPoint::gbPoint(){
    point.x = 0;
    point.y = 0;
}

gbPoint::gbPoint(int x,int y){
	point.x = x;
	point.y = y;
}

gbPoint::gbPoint(SDL_Point p){
	point = p;
}

bool gbPoint::operator==(gbPoint p) const{
	return (point.x == p.getX()) && (point.y == p.getY());
}

bool gbPoint::operator!=(gbPoint p) const{
	return !(*this == p);
}

gbSize::gbSize(){
    size.x = 0;
    size.y = 0;
}

gbSize::gbSize(int w,int h){
	size.x = w;
	size.y = h;
}

bool gbSize::operator==(gbSize s) const{
	return (size.x == s.getWidth()) && (size.y == s.getHeight());
}

bool gbSize::operator!=(gbSize s) const{
	return !(*this == s);
}

gbColor::gbColor(){
	color.r = 0;
	color.g = 0;
	color.b = 0;
	color.a = 0;
}

gbColor::gbColor(int r,int g,int b,int a){
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

gbColor::gbColor(SDL_Color color){
	this->color = color;
}
