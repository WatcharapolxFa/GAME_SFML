#include "friebg.h"
#include "Animation.h"

#include <math.h>
friebg::friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float x,float y) :
	animation(texture, imageCount, switchTime)
{
	body.setTexture(texture);
	body.setPosition(x, y);
	body.setSize(sf::Vector2f(400.f, 150.0f));
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);

	row = 0;
}

friebg::~friebg()
{
}

void friebg::Update(float deltaTime,Player player)
{
	animation.Updatefrie(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void friebg::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

