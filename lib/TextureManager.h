﻿#ifndef _TextureManager_H
#define _TextureManager_H


#include <iostream>
#include <string>
#include <map>
#include "SDL2/SDL.h"

class TextureManager
{
public:

    static TextureManager* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }

        return s_pInstance;
    }

    bool load(SDL_Surface * pSurface,std::string id,SDL_Renderer * pRenderer);
    bool load(SDL_Texture * pTex, std::string id);

    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

    void clearTextureMap();
    void clearFromTextureMap(std::string id);

    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, double angle, int alpha, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawTile(std::string id, int margin, int spacing, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer);

    std::map<std::string, SDL_Texture*> getTextureMap() { return m_textureMap; }

private:

    TextureManager() {}
    ~TextureManager() {}

    TextureManager(const TextureManager&);
	TextureManager& operator=(const TextureManager&);

    std::map<std::string, SDL_Texture*> m_textureMap;

    static TextureManager* s_pInstance;
};

typedef TextureManager TheTextureManager,TEX;
//#define TextureManager::Instance() TEX


#endif