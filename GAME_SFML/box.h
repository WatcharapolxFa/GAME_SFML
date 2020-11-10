#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Player.h"
#include"Collider.h"
#include "Platform.h"

class box
{
public:
	box(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position);
	~box();

	void Update(float deltaTime, Player player);
	void draw(sf::RenderWindow& window);
	sf::RectangleShape getBody();

	Collider GetCollider() {
		Body = body.getBody();
		return Collider(Body);
	}


private:
	Animation animation;
	sf::RectangleShape Body;
	Platform body;

	float totalTime;
	float switchTime;

	unsigned int row;
};
