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

  unsigned int m_neurtalNetwork;

  EntityAction m_currentAction;

  unsigned int m_food;

public:

  Entity();

  ~Entity();

  inline unsigned int getNeuralNetwork()
  { return m_neurtalNetwork; }

  inline EntityAction getCurrentAction()
  { return m_currentAction; }

  inline unsigned int getFood()
  { return m_food; }

  inline void setNeuralNetwork(unsigned int neuralNetwork)
  { m_neurtalNetwork = neuralNetwork; }

  inline void setCurrentAction(EntityAction action)
  { m_currentAction = action; }

  inline void setFood(unsigned int food)
  { m_food = food; }

};

#endif // ENTITY_HPP