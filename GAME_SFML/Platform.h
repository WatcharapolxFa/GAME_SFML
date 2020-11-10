#pragma once
#include<SFML\Graphics.hpp>
#include"Collider.h"
class Platform
{
public:
	Platform(sf::Texture*texture,sf::Vector2f size,sf::Vector2f position);
	~Platform();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }

	sf::RectangleShape getBody() { return this->body;  };

	void setBody(sf::IntRect animation) { this->body.setTextureRect(animation); };

private :
	sf::RectangleShape body;

};

