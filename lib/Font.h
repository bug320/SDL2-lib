#ifndef _Font_H_
#define _Font_H_
#include "TextureManager.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>

static void copy_cg(SDL_Color & acg,const SDL_Color & bcg)
{
	acg.r = bcg.r;
	acg.g = bcg.g;
	acg.b = bcg.b;
}


static SDL_Surface * GetMsg(std::string msg,SDL_Color cg,int fsize, std::string fpath)
{
    TTF_Init();
    TTF_Font * pFont = 0;
    SDL_Surface * pfSUrface =0;
    pFont = TTF_OpenFont(fpath.c_str(),fsize);
    if ( !pFont )
    {
        std::cerr << "Create TTF_Font is error : " << TTF_GetError() << "\n";
    }
    else
    {
        pfSUrface = TTF_RenderUTF8_Blended(pFont,msg.c_str(),cg);
        if (!pfSUrface)
        {
        std::cerr << "Create SDL_Surface for TTF_Font is error : " << TTF_GetError() << "\n";
        }
        TTF_CloseFont(pFont);

    }
    TTF_Quit();
    return pfSUrface;
}

class Font{
public:
    Font(std::string fPath,int fSize, SDL_Color cg): m_fPath(fPath),m_fsize(fSize)
    {
        copy_cg(m_cg,cg);
    }
    friend void copy_cg(SDL_Color & acg,const SDL_Color & bcg);
    friend SDL_Surface * GetMsg(std::string msg,SDL_Color cg,int fsize, std::string fpath);
    SDL_Surface * surface(std::string msg,SDL_Color cg){
        return GetMsg(msg,cg,m_fsize,m_fPath);
    }
    SDL_Surface * surface(std::string msg){
        return GetMsg(msg,m_cg,m_fsize,m_fPath);
    }
    std::string & path() {return m_fPath; }
    int & size() { return  m_fsize; }
    SDL_Color & color() { return m_cg; }
protected :
    std::string m_fPath;
    SDL_Color m_cg;
    int m_fsize;
};

#endif // _Font_H_