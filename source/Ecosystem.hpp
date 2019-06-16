#ifndef ECOSYSTEM_HPP
#define ECOSYSTEM_HPP

#include <stdio.h>
#include <stdlib.h>
#include "Entity.hpp"
#include "Tile.hpp"

class Ecosystem
{
private:

  Entity*** m_entities;
  Tile*** m_tiles;
  unsigned int m_width;
  unsigned int m_height;

public:

  Ecosystem(unsigned int width, unsigned int height);

  ~Ecosystem();

  inline unsigned int getWidth()
  { return m_width; }

  inline unsigned int getHeight()
  { return m_height; }

  inline const Entity* getTileEntity(unsigned int x, unsigned int y)
  { return m_entities[x][y]; }

  inline const Tile* getTile(unsigned int x, unsigned int y)
  { return m_tiles[x][y]; }

  void addFoodToRandomTile();

  void addMultipleFoodToRandomTiles(int count);

};

#endif // ECOSYSTEM_HPP