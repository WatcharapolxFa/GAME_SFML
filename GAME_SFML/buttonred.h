#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Player.h"
#include"Collider.h"
class buttonred
{
public:
	buttonred(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position);
	~buttonred();

	void Update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getBody();



private:
	Animation animation;
	sf::RectangleShape body;
	sf::RectangleShape hitbox;

	float totalTime;
	float switchTime;

	unsigned int row;
};

