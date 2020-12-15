#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Collider.h"
#include "HitboxComponent.h"
class Boss
{
public:
	Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Boss();

	void Update(float deltaTime, float px);
	void draw(sf::RenderWindow &window);
	void dead();
	void damaged(int dmg);

	int GetHp() { return hp; }
	sf::Vector2f GetPosition() { return body.getPosition(); }
private:
	Animation animation;
	sf::Vector2f velocity;
	sf::RectangleShape body;
	bool faceRight;
	int hp;
	float main;
	float mainn;
};

