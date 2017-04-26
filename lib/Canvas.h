#ifndef _MYSDL_Canvas_h_
#define _MYSDL_Canvas_h_
#include "SDL2/SDL.h"

#define _PE 0
#define _PC -1
#define _SDL_OK  _PE 

class Canvas
{
public:
    static Canvas* Instance()
    {
        if(s_pInstance == NULL)
        {
            s_pInstance = new Canvas();
            return s_pInstance;
        }

        return s_pInstance;
    }
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void render();
    void update();
    void handleEvents();
    void clean();

    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    SDL_Window* getWindow() const { return m_pWindow; }


    bool running() { return m_bRunning; }
    void quit() { m_bRunning = false; }

    int getGameWidth() const { return m_gameWidth; }
    int getGameHeight() const { return m_gameHeight; }


protected:
    Canvas();
    ~Canvas();
    Canvas(const Canvas& other)=default;
    Canvas& operator=(const Canvas& other)=default;
    //Canvas(Canvas&& other) = default;
    //Canvas& operator=(Canvas&& other) = default;
    SDL_Window * m_pWindow;
    SDL_Renderer * m_pRenderer;

    bool m_bRunning;

    int m_gameWidth;
    int m_gameHeight;

private:
    static Canvas* s_pInstance;
};

typedef Canvas TheCanvas,CVS;
//#define Canvas::Instance() CVS
#endif