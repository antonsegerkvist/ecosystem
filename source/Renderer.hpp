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
      std::cout << "==> ERROR: SDL_INIT : " << SDL_GetError() << std::endl;
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

    m_surface = SDL_GetWindowSurface(m_window);

    return true;
  }

  static void Free()
  {
    if (m_surface != NULL)
    {
      SDL_FreeSurface(m_surface);
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