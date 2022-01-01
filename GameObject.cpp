#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
	
}
bool GameObject::setPos(CellPosition pos) {
	if (pos.IsValidCell())
	{
		position = pos;
		return true;
	}
	else
		return false;
}
CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}