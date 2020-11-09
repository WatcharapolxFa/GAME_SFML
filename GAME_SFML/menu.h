#pragma once
#include <SFML/Graphics.hpp>
#define Max_ITEM 3
class menu
{
public :
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
private :
	int selectedItem = 0;
	sf::Font font;
	sf::Text menu[Max_ITEM];
};

