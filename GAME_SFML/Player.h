#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "HitboxComponent.h"

class Player
{
public : 
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime, sf::Vector2f direction,float cooldown);
	void backe(sf::RenderWindow& window, sf::Vector2f poses);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	void Warped(sf::RenderWindow& window);
	void Warped2(sf::RenderWindow& window);
	void setPosition(float x, float y);
	sf::Vector2f GetPosition() { return hitbox.getPosition(); }
	Collider GetCollider() { return Collider(hitbox); }

	bool checkIntersect(const sf::FloatRect& frect) {
		return hitbox.getGlobalBounds().intersects(frect);
	}

private : 
	float cooldowns;
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	Animation animation;
	unsigned int row;
	float speed;

	
	bool faceRight, fire;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	bool floorGravity;
	sf::RectangleShape body2;
};
