#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "RenderWindow.hpp"
#include "Sprite.hpp"
#include "Camera.hpp"
#include "Text.hpp"

RenderWindow::RenderWindow(const char *p_title, int p_width, int p_height, float p_renderScale) : window(NULL), renderer(NULL), camera(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_width, p_height, SDL_WINDOW_SHOWN);

    if (window == NULL)
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Window init failed", SDL_GetError(), 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    renderScale = p_renderScale;
}

SDL_Window *RenderWindow::getWindow()
{
    return window;
}

SDL_Renderer *RenderWindow::getRenderer()
{
    return renderer;
}

SDL_Texture *RenderWindow::loadTexture(const char *filePath)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, filePath);

    if (texture == NULL)
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Texture load failed", SDL_GetError(), 0);

    return texture;
}

void RenderWindow::setCamera(Camera *camera_)
{
    camera = camera_;
}

void RenderWindow::destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::render(Sprite &sprite)
{
    SDL_Rect src = sprite.getRect();

    SDL_Rect dest;
    if (camera != NULL)
    {
        dest.x = (sprite.getX() * renderScale - camera->getScrollX()) - sprite.getRect().w / 2;
        dest.y = (sprite.getY() * renderScale - camera->getScrollY()) - sprite.getRect().h / 2;
    }
    else
    {
        dest.x = sprite.getX() * renderScale;
        dest.y = sprite.getY() * renderScale;
    }
    dest.w = sprite.getRect().w * renderScale;
    dest.h = sprite.getRect().h * renderScale;

    SDL_RenderCopy(renderer, sprite.getTexture(), &src, &dest);
}

void RenderWindow::render(Text &text, int x, int y)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;

    dest.w *= renderScale * 2;
    dest.h *= renderScale * 2;

    SDL_RenderCopy(renderer, text.getTexture(), nullptr, &dest);
    SDL_DestroyTexture(text.getTexture());
}