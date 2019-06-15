#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <iostream>
#include <SDL2/SDL.h>

class Renderer
{
public:

  static SDL_Window* m_window;
  static SDL_Surface* m_surface;

  static bool Init()
  {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      std::cout << "==> ERROR: SDL_INIT : " << SDL_GetError();
      return false;
    }

    return true;
  }

  static void Free()
  {
    if (m_surface != NULL)
    {
      m_surface = NULL;
    }
    if (m_window != NULL)
    {
      SDL_DestroyWindow(m_window);
      m_window = NULL;
    }
    SDL_Quit();
  }

};

#endif // RENDERER_HPP