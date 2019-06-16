#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <SDL2/SDL.h>
#include "Ecosystem.hpp"
#include "Renderer.hpp"

class Simulation
{
private:

  static const int s_tileWidth;
  static const int s_tileHeight;

  unsigned int m_width;
  unsigned int m_height;

  bool m_quit;
  unsigned int m_step;

  int m_viewX;
  int m_viewY;

  Ecosystem* m_ecosystem;

public:

  Simulation(unsigned int width, unsigned int height);

  ~Simulation();

  void run();

  void draw();

};

#endif // SIMULATION_HPP