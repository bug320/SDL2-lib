#	include "Canvas.h"
#include "TextureManager.h"
#include "Font.h"
#include <iostream>
#include "SDL2/SDL.h"
using namespace std;
Canvas * Canvas::s_pInstance = NULL;
Canvas::Canvas():
m_pWindow(0),
m_pRenderer(0),
m_bRunning(false)
{
    // add some level files to an array
    // start at this level
}
Canvas::~Canvas()
{
    // we must clean up after ourselves to prevent memory leaks
    m_pRenderer= 0;
    m_pWindow = 0;
}
bool Canvas::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    // store the Canvas width and height
    m_gameWidth = width;
    m_gameHeight = height;

    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    // attempt to initialise SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == _SDL_OK)
    {
        cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(m_pWindow != 0) // window init success
        {
            cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

            if(m_pRenderer != 0) // renderer init success
            {
                cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
            }
            else
            {
                cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        cout << "SDL init fail\n";
        return false; // SDL init fail
    }

    // add some sound effects - TODO move to better place

    //TheInputHandler::Instance()->initialiseJoysticks();

    // register the types for the Canvas
    TheTextureManager::Instance()->load("hello.png","HelloWorld",getRenderer());
    
    
    // start the menu state

    m_bRunning = true; // everything inited successfully, start the main loop
    return true;
}
void Canvas::render()
{
		//m_pCanvasStateMachine->render();
    SDL_RenderPresent(m_pRenderer);

    SDL_RenderClear(m_pRenderer);

}

void Canvas::update()
{
	//m_pCanvasStateMachine->update();
    TheTextureManager::Instance()->draw("HelloWorld",0,0,0,0,getRenderer());

}
void Canvas::handleEvents()
{
    //TheInputHandler::Instance()->update();
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type==SDL_QUIT)
    {
        quit();
        cout<<" 游戏退出";
    }
}

void Canvas::clean()
{
    cout << "cleaning Canvas\n";
    //TheInputHandler::Instance()->clean();
    //m_pCanvasStateMachine->clean();
    //m_pCanvasStateMachine = 0;
    //delete m_pCanvasStateMachine;
    //TheTextureManager::Instance()->clearTextureMap();
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}