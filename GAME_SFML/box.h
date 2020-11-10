#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Player.h"
#include"Collider.h"
class box
{
public:
	box(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position);
	~box();

	void Update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getBody();


private:
	Animation animation;
	sf::RectangleShape body;

	float totalTime;
	float switchTime;

	unsigned int row;
};
