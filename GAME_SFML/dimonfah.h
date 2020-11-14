#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Player.h"
#include"Collider.h"
class dimonfah
{
public:
	dimonfah(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position);
	~dimonfah();

	void Update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getBody();
	Collider GetCollider() { return Collider(hitbox); }
	void pickup();

private:
	Animation animation;
	sf::RectangleShape body;

	float totalTime;
	float switchTime;
	sf::RectangleShape hitbox;
	unsigned int row;
};

