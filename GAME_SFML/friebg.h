#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
class friebg
{
public:
	friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~friebg();

	void Update(float deltaTime, sf::Vector2f direction);
	void draw(sf::RenderWindow& window);
	//void position(sf::Vector2f fireposition);

private:
	Animation animation;
	sf::RectangleShape body;

	float totalTime;
	float switchTime;

	unsigned int row;
};