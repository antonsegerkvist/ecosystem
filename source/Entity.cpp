#include "Entity.hpp"

Entity::Entity()
: m_neurtalNetwork(0)
, m_currentAction(Spawned)
, m_food(1)
{ }

Entity::~Entity()
{ }
