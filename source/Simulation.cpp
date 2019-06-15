#include "Simulation.hpp"

Simulation::Simulation(unsigned int width, unsigned int height)
: m_height(height)
, m_width(width)
, m_quit(false)
, m_step(0)
, m_ecosystem(NULL)
{
  m_ecosystem = new Ecosystem(width, height);
}

Simulation::~Simulation()
{
  delete m_ecosystem;
}

void Simulation::run()
{
  SDL_Event event;
  draw();

  while(!m_quit)
  {
    while (SDL_PollEvent(&event) != 0)
    {
      switch (event.type)
      {
        case SDL_QUIT:
          m_quit = true;
          break;
      }
    }
    ++m_step;
    draw();
  }
}

void Simulation::draw()
{

}