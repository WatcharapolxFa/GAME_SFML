#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Player.h"
#include"Collider.h"
class friebg
{
public:
	friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,  float x, float y);
	~friebg();

	void Update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);
	void setPosition(float x, float y);
	//void position(sf::Vector2f fireposition);

private:
	Animation animation;
	sf::RectangleShape body;

	float totalTime;
	float switchTime;

	unsigned int row;
};