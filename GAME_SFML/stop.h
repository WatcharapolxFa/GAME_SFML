#pragma once
#include <SFML/Graphics.hpp>
#define Max_ITEM 3
class stop
{
public:
	stop(float width, float height);
	~stop();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem; }
private:
	int selectedItem = 0;
	sf::Font font;
	sf::Text Stop[Max_ITEM];
};

