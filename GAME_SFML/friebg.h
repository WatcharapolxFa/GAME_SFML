#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Player.h"
#include"Collider.h"
class friebg
{
public:
	friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position);
	~friebg();

	void Update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getBody();
	Collider GetCollider() { return Collider(hitbox); }
	
	
private:
	Animation animation;
	sf::RectangleShape body;

	float totalTime;
	float switchTime;
	sf::RectangleShape hitbox;

	unsigned int row;
};