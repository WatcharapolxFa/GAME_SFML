#pragma once
#include <SFML/Graphics.hpp>
#include"Collider.h"
class hitboxComponent
{
public :
	hitboxComponent(sf::Vector2f pos,sf::Vector2f size);

	~hitboxComponent();
	void move(sf::Vector2f move);
	void Draw(sf::RenderTarget* target);
	void setPosition(sf::Vector2f pos) { this->hitbox.setPosition(pos); };

	sf::Vector2f getPosition() { return this->hitbox.getPosition(); }
	Collider GetCollider() { return Collider(this->hitbox); }
	
private:
	sf::RectangleShape hitbox;


};

