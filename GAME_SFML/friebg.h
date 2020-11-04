#pragma once
#include <SFML/Graphics.hpp>
class friebg
{
public:
	friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~friebg();

	void Update(int row, float deltaTime, bool faceRight, bool fire);
	

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

};