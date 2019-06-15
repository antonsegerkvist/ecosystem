#ifndef TILE_HPP
#define TILE_HPP

class Tile
{
private:

  unsigned int m_food;

public:

  Tile() : m_food(0)
  { }

  ~Tile()
  { }

  inline void emptyFood()
  { m_food = 0; }

  inline void addFood(unsigned int food)
  { m_food += food; }

  inline unsigned int getFood()
  { return m_food; }

};

#endif // TILE_HPP