#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Renderer
{
public:

  static SDL_Window* m_window;
  static SDL_Renderer* m_renderer;

  static bool Init()
  {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      std::cout << "==> ERROR: SDL_Init : " << SDL_GetError() << std::endl;
      return false;
    }

    if(TTF_Init() < 0)
    {
      std::cout << "==> ERROR: TTF_Init : " << TTF_GetError() << std::endl;
      return false;
    }

    m_window = SDL_CreateWindow(
      "Ecosystem",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      800, 640,
      SDL_WINDOW_SHOWN
    );
    if (m_window == NULL)
    {
      std::cout << "==> ERROR: SDL_CreateWindow : " << SDL_GetError() << std::endl;
      Free();
      return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == NULL)
    {
      std::cout << "==> ERROR: SDL_GetWindowSurface : " << SDL_GetError() << std::endl;
      Free();
      return false;
    }

    return true;
  }

  static void Free()
  {
    if (m_renderer != NULL)
    {
      SDL_DestroyRenderer(m_renderer);
      m_renderer = NULL;
    }
    if (m_window != NULL)
    {
      SDL_DestroyWindow(m_window);
      m_window = NULL;
    }
    TTF_Quit();
    SDL_Quit();
  }

  static void ClearRenderer(int r, int g, int b)
  {
    SDL_SetRenderDrawColor(m_renderer, r, g, b, 0xFF);
    SDL_RenderClear(m_renderer);
  }

  static void DrawRect(int r, int g, int b, int x, int y, int w, int h)
  {
    SDL_Rect fillRect = { x, y, w, h };
    SDL_SetRenderDrawColor(m_renderer, r, g, b, 0xFF);
    SDL_RenderFillRect(m_renderer, &fillRect);
  }

  static void UpdateScreen()
  {
    SDL_RenderPresent(m_renderer);
  }

};

#endif // RENDERER_HPP