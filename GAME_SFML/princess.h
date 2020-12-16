#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Collider.h"
#include "HitboxComponent.h"
class princess
{
public:
	princess(sf::Vector2f position, sf::Texture* princess);
	~princess();

	void update(float deltaTime);
	void dead();
	void re();
	void draw(sf::RenderWindow& window);

	Collider GetCollider() { return Collider(hitbox); }
private:
	Animation animation;
	sf::RectangleShape hitbox;
	sf::RectangleShape body;
	sf::Vector2f position;
	sf::Vector2f velocity;
	bool faceRight;
	float turn;
};



