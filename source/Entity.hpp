#ifndef ENTITY_HPP
#define ENTITY_HPP

enum EntityAction
{
  Spawned,

  MoveUp,
  MoveRight,
  MoveDown,
  MoveLeft,
  
  AttackUp,
  AttackRight,
  AttackDown,
  AttackLeft
};

class Entity
{
private:

  EntityAction m_currentAction;

  unsigned int m_food;
  unsigned int m_x;
  unsigned int m_y;

public:

  Entity(unsigned int x, unsigned int y);

  ~Entity();

  inline EntityAction getCurrentAction()
  { return m_currentAction; }

  inline unsigned int getFood()
  { return m_food; }

  inline unsigned int getX()
  { return m_x; }

  inline unsigned int getY()
  { return m_y; }

  inline void setCurrentAction(EntityAction action)
  { m_currentAction = action; }

  inline void setFood(unsigned int food)
  { m_food = food; }

  inline void setX(unsigned int x)
  { m_x = x; }
  
  inline void setY(unsigned int y)
  { m_y = y; }

};

#endif // ENTITY_HPP