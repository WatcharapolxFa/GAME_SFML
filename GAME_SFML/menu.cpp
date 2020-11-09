#include "Menu.h"
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("charecter/Pifont.ttf"))
	{ }
	menu[0].setFont(font);
	//menu[0].setCharacterSize(70);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (Max_ITEM + 1) * 1));

	menu[1].setFont(font);
	//menu[1].setFillColor(sf::Color::Red);
	menu[1].setString("Leaderboard");
	menu[0].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (Max_ITEM + 1) * 2));

	menu[2].setFont(font);
	//menu[2].setFillColor(sf::Color::Red);
	menu[2].setString("Exit");
	menu[0].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (Max_ITEM + 1) * 3));


}
Menu::~Menu()
{

}
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_ITEM; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
			selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}

}
void Menu::MoveDown()
{
	if (selectedItem + 1 <Max_ITEM)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}

}