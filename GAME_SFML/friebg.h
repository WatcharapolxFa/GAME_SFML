#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
class friebg
{
public:
	friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~friebg();

	void Update(int row, float deltaTime);
	void draw(sf::RenderWindow& window);
	void position(sf::Vector2f fireposition);

public:
	sf::IntRect uvRect;

private:
	Animation animation;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::RectangleShape body;

	float totalTime;
	float switchTime;


};