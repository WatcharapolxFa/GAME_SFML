#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Player.h"
#include"Collider.h"
class button
{
public:
	button(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position);
	~button();

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
