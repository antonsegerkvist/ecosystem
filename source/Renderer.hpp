#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <iostream>

class Renderer
{

  static SDL_Window* window;
  static SDL_Surface* surface;

  static bool Init()
  {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      std::cout << "==> ERROR: SDL_INIT : " << SDL_GetError();
      return false;
    }

    return true;
  }

};

#endif // RENDERER_HPP