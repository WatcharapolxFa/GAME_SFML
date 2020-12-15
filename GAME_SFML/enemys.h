#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Collider.h"
#include "HitboxComponent.h"
class enemys
{
public:
	enemys(sf::Vector2f position, sf::Texture* penois);
	~enemys();

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

