#include <iostream>
#include "lib/Canvas.h"
#include "lib/TextureManager.h"

using namespace std;

int main(int argc,char *argv[])
{
    if (true==TheCanvas::Instance()->init("HelloWorld",100,100,680,450,0))
    {
       cout<<"游戏加载成功";
        while (TheCanvas::Instance()->running())
        {
            TheCanvas::Instance()->handleEvents();
            TheCanvas::Instance()->update();
            TheCanvas::Instance()->render();
        }
       // SDL_Delay(3000);
    }
    else
    {
            cout<<"游戏加载失败" <<SDL_GetError()<< endl;
    }
    return 0;
}