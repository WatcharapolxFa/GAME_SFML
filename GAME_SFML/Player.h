#pragma once
#include <SFML/Graphics.hpp>
#include"Animation.h"
#include "Collider.h"
#include"hitboxComponent.h"
class Player
{
public : 
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
private : 
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;

	hitboxComponent* hitbox;
	
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};
