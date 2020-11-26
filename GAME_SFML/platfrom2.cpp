#include "platfrom2.h"
Platform2::Platform2(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);

}
Platform2::~Platform2()
{

}
void Platform2::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}