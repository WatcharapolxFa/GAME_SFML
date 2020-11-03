#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace std;

class HitboxComponent
{
private:
	sf::RectangleShape hitbox;

public:
	HitboxComponent(float offset_x, float offset_y, sf::Vector2f size, sf::Vector2f playerPosition); //vector sf=mean float
	~HitboxComponent();

	bool checkIntersect(const sf::FloatRect& frect);
	void Update(sf::Vector2f playerPosition, float offset_x, float offset_y);
	void Draw(sf::RenderWindow& window);
};

