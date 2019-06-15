#include "Ecosystem.hpp"

Ecosystem::Ecosystem(unsigned int width, unsigned int height)
: m_entities(NULL)
, m_tiles(NULL)
, m_width(width)
, m_height(height)
{
  m_entities = new Entity**[m_width];
  m_tiles = new Tile**[m_width];

  for (int i = 0; i < m_width; ++i)
  {
    m_entities[i] = new Entity*[m_height];
    m_tiles[i] = new Tile*[m_height];
  }

  for (int i = 0; i < m_width; ++i)
  {
    for (int j = 0; j < m_height; ++j)
    {
      m_entities[i][j] = NULL;
      m_tiles[i][j] = new Tile();
    }
  }
}

Ecosystem::~Ecosystem()
{
  
}