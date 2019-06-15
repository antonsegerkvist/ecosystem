#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <SDL2/SDL.h>

class Simulation
{
private:

  unsigned int m_width;
  unsigned int m_height;

  bool m_quit;
  unsigned int m_step;

  Simulation* m_simulation;

public:

  Simulation(unsigned int width, unsigned int height);

  ~Simulation();

  void run();

  void draw();

};

#endif // SIMULATION_HPP