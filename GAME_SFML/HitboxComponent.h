#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class HitboxComponent
{
private:
	sf::RectangleShape hitbox;

public:
	HitboxComponent(float offset_x, float offset_y, sf::Vector2f size, sf::Vector2f playerPosition); //vector sf=mean float
	~HitboxComponent();

	void Update(sf::Vector2f playerPosition, float offset_x, float offset_y);
	void Draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f position) { hitbox.setPosition(position);  }

	sf::FloatRect getGlobalBounds() {
		return hitbox.getGlobalBounds();
	}
};

