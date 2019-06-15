#include "Entity.hpp"

Entity::Entity(unsigned int x, unsigned int y)
: m_currentAction(Spawned)
, m_x(x)
, m_y(y)
{ }

Entity::~Entity()
{ }
