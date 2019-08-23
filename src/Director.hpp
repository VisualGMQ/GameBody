#ifndef __DIRECTOR__
#define __DIRECTOR__
#include <SDL2/SDL.h>
#include <string>
#include <map>
#include "gbScene.hpp"
#include "gbWindow.hpp"
#include "geomentry.hpp"
#include "gbDrawTool.hpp"
#include "gbTexture.hpp"
using namespace std;

class gbScene;

/**
 * @class GameBody
 * @brief 这个类封装了很多的SDL方法，方便你去快速构建一个应用
 * @warning 你的子类的构造函数不可以有参数，而且必须只有一个无参构造函数。
 *
 * 这个类的用法是这样：
 * 如果你对窗体的要求不是很高的话，可以只重写update()函数来添加你自己的功能。如果需要对事件处理进行改动的话你需要重写eventHandle()函数。你也可以重写clean()函数来清空资源。所有的虚函数都是可以重写的，但是我们不建议你写我们没有显式说明可以重写的函数
 * 基本的流程是这样：
 * ```
 * class myClass:public GameBody{
 * 	myClass():GameBody(yourtitle,yourwidth,yourheight,yourflag,yourmillisec){
 * 		//TODO Initialize....
 * 	}
 *	//TODO Other Override....
 * };
 *	
 * RUN_APP(myClass);
 * }
 * ```
 */
class GameBody{
public:
	/**
	 * @fn GameBody
	 * @brief 构造函数
	 * @param title 窗口的标题
	 * @param width 窗口宽度
	 * @param height 窗口高度
	 * @param flag 传递给SDL_CreateWindow()函数的参数，指定窗口的类型
	 * @param delaytime 每一帧延时的时间
	 */
	GameBody(const string title,int width,int height,Uint32 flag,int delaytime);
	/**
	 * @fn eventHandle()
	 * @brief 事件处理函数，你可以重写这个事件来给出你自己的处理过程。
     * @param evetn 传入的事件结构体
     *
     * 这个函数是开放给用户的事件接口。如果你不重写它，那么他会在窗口关闭的时候自动推出。但是如果你重写了它，你必须显式调用gameExit()函数退出。
	 */
	void eventHandle(SDL_Event& event);
	/**
	 * @fn update()
	 * @brief 每一帧要执行的代码，你几乎必须重写这个函数来实现你自己的功能（除非你想要一个不做任何事情的窗口）
	 */
	void update();
	/**
	 * @fn step()
	 * @brief 你必须在循环里面显式的调用这个函数。这个函数里面按照流程调用了update()和一些其他的函数
	 */
	void step();
	/**
	 * @fn delay(int millisec)
	 * @brief 每一帧延时的时间
	 * @param millisec 延时的时间，为微秒
	 */
	void delay(int millisec);

	void registerScene(string, gbScene*);
	void setScene(string);
	gbScene* getScene(){return currentScene;}
	/**
	 * @fn isQuit()
	 * @brief 你不应该重写这个函数，它是用于在循环里面判断是否退出程序的函数
	 */
	bool isQuit(){return gamequit;}
	/**
	 * @fn gameExit()
	 * 
	 * 退出游戏的函数，调用这个函数会退出游戏
	 */
    void gameExit(){gamequit = true;}
	/**
	 * fn clean()
	 * @brief 会在析构函数里面调用，用于程序最后的清楚
	 */
	void clean();
	/**
	 * @fn ~GameBody()
	 * @brief 析构函数
	 */
	~GameBody();
protected:
	gbWindow* win;
	SDL_Renderer* render;
	SDL_Event event;
	bool error;
	bool gamequit;
	int delaytime;
    gbDrawTool* drawTool;
    textureFactory* texturefactory;
	map<string, gbScene*> scenemap;
	gbScene* currentScene;
	void renderBegin();
	void renderEnd();
    void dealEvent();
};

class DirectorSiglton{
public:
	static GameBody* getInstance();
	static void freeInstance();
private:
	static GameBody* instance;
	const static unsigned int WINDOW_WIDTH;
	const static unsigned int WINDOW_HEIGHT;
	const static unsigned int WINDOW_FLAG;
	const static unsigned int DELAY_TIME;
	const static std::string TITLE;
};
#endif