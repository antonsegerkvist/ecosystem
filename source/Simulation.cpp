#include "Simulation.hpp"

const int Simulation::s_tileWidth = 16;
const int Simulation::s_tileHeight = 16;

Simulation::Simulation(unsigned int width, unsigned int height)
: m_height(height)
, m_width(width)
, m_quit(false)
, m_step(0)
, m_viewX(0)
, m_viewY(0)
, m_ecosystem(NULL)
{
  m_ecosystem = new Ecosystem(width, height);
  m_ecosystem->addMultipleFoodToRandomTiles((int)((m_width * m_height)/2));
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
    m_ecosystem->addMultipleFoodToRandomTiles(5);
    ++m_step;
    draw();
  }
}

void Simulation::draw()
{
  Renderer::ClearRenderer(0xD2, 0x69, 0x1E);
  for (int i = 0; i < m_width; ++i)
  {
    for (int j = 0; j < m_height; ++j)
    {
      if (m_ecosystem->getTile(i, j)->getFood() > 0)
      {
        Renderer::DrawRect(
          0xFF, 0xFF, 0,
          i * s_tileWidth + 3 - m_viewX,
          j * s_tileHeight + 3 - m_viewY,
          s_tileWidth - 3,
          s_tileHeight - 3
        );
      }
    }
  }
  Renderer::UpdateScreen();
}