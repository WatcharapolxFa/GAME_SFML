#pragma once
#include <SFML/Graphics.hpp>
#include"Animation.h"
class Player
{
public : 
	Player();
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow window);
private : 
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

