# Ecosystem

Ecosystem is a small playground for feed forward neural networks. The system studied is a grid system populated by entities. The grid contains tiles which can contains food.

## Entity inputs

The entities can view the world around them. The inputs are described here.

* 8 grid inputs, one for each tile around them. Specifies how much food there is there.
* 8 grid inputs, one for each tile around them. Specifies if there is an entity there.
* Food input. Specifies the amount of energy the entity has.

## Entity actions

The entities can perform a set of actions. The actions are described below.

* MoveUp
* - Moves the entity up
* MoveRight
* - Moves the entity right
* MoveDown
* - Moves the entity down
* MoveLeft
* - Moves the entity left
* AttackUp
* - Attacks the tile above the entity without moving.
* AttackRight
* - Attacks the tile to the right of the entity without moving.
* AttackDown
* - Attacks the tile below the entity without moving.
* AttackLeft
* - Attacks the tile to the left of the entity without moving.