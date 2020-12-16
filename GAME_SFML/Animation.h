#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime, bool faceRight, bool fire);
	void updateBu(int row, float deltaTime, bool faceleft);
	void Updatefrie(int row, float deltaTime);
	void Updatewater(int row, float deltaTime);
	void Updatepenois(int row, float deltaTime, bool faceRight);
	void Updateprinces(int row, float deltaTime, bool faceRight);
	

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

};

