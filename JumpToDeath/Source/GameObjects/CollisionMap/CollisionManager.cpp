#include "CollisionManager.h"
int CollisionManager::check = -1;

CollisionManager::CollisionManager(HitBox& hitBox) : hitBox(hitBox) {
	
}

CollisionManager::~CollisionManager() {

}

bool CollisionManager::checkCollider(CollisionManager other) {
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	if (intersectX <= 0.0f && intersectY <= 0.0f) {
		if ((intersectX) > (intersectY))
		{
			if (deltaX > 0.0f)
			{
				other.Move(-intersectX+1, 0.0f);
				check = -1;
			}
			else 
			{
				other.Move(intersectX-1, 0.0f);
				check = 1;
			}
		}
		else {
			if (deltaY > 0.0f)
			{
				other.Move(0.0f, -intersectY);
				check = -2;
			}
			else 
			{
				other.Move(0.0f, intersectY);
				check = 2;
			}
		}
		return true;
	}
	return false;	
}

