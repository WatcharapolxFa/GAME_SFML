#pragma once
#include<SFML\Graphics.hpp>
#include"Collider.h"

class Platform2
{
public:
	Platform2(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform2();
	void col();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;

};



