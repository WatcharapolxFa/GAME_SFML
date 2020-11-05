#include "friebg.h"
#include <math.h>
friebg::friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	animation(texture, imageCount, switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;

	body.setTexture(texture);
	body.setPosition(500.0f, 1200.0f);
	body.setSize(sf::Vector2f(120.f, 160.0f));
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);


	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);

}

friebg::~friebg()
{

}

void friebg::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
	animation.Updatefrie(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	
}

void friebg::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void friebg::position(sf::Vector2f fireposition)
{
	body.setPosition(fireposition.x,fireposition.y);
}

