#pragma once
#include "../Component/HitBox.h"

class CollisionManager {
public:
	CollisionManager(HitBox& hitBox);
	~CollisionManager();
	void Move(float dx, float dy) { hitBox.move(dx, dy); }
	bool checkCollider(CollisionManager other);

	sf::Vector2f GetPosition() { return hitBox.getPosition(); }
	sf::Vector2f GetHalfSize() { return hitBox.getSize() / 2.f; }

	static int checkColl() { return check; };
	static void ResetColl() { check = 0; };
	static int check;
private:
	HitBox& hitBox;
	std::vector<HitBox*> m_listObj;
	
};