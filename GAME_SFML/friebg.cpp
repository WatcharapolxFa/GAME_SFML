#include "friebg.h"
#include "Animation.h"
#include <math.h>
friebg::friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :
	animation(texture, imageCount, switchTime)
{
	body.setTexture(texture);
	body.setPosition(500.0f, 1200.0f);
	body.setSize(sf::Vector2f(200.f, 75.0f));
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);

	row = 0;
}

friebg::~friebg()
{
}

void friebg::Update(float deltaTime, sf::Vector2f direction)
{
	animation.Updatefrie(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void friebg::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

//void friebg::position(sf::Vector2f fireposition)
//{
//	body.setPosition(fireposition.x,fireposition.y);
//}

