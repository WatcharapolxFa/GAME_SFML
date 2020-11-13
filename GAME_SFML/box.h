#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Collider.h"
#include "HitboxComponent.h"

class box
{
public:
	box(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position);
	~box();

	void Update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getBody();

	Collider GetCollider() {  return Collider(body);	}
	void OnCollision(sf::Vector2f direction);
	void OnCollision2(sf::Vector2f direction);


private:
	Animation animation;
	sf::RectangleShape body;
	sf::Vector2f velocity;
	sf::RectangleShape hitbox;
	float totalTime;
	float switchTime;

	unsigned int row;

	bool canJump;
	bool fire;
	float jumpHeight;
};
