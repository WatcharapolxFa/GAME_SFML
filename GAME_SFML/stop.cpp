#include "stop.h"
stop::stop(float width, float height)
{
	if (!font.loadFromFile("charecter/Pifont.ttf"))
	{
	}
	Stop[0].setFont(font);
	//menu[0].setCharacterSize(70);
	Stop[0].setFillColor(sf::Color::Red);
	Stop[0].setString("Play");
	Stop[0].setOrigin(Stop[0].getLocalBounds().width / 2, Stop[0].getLocalBounds().height / 2);
	Stop[0].setPosition(sf::Vector2f(width / 2, height / (Max_ITEM + 1) * 1));

	Stop[1].setFont(font);
	//menu[1].setFillColor(sf::Color::Red);
	Stop[1].setString("Leaderboard");
	Stop[1].setOrigin(Stop[1].getLocalBounds().width / 2, Stop[1].getLocalBounds().height / 2);
	Stop[1].setPosition(sf::Vector2f(width / 2, height / (Max_ITEM + 1) * 2));

	Stop[2].setFont(font);
	//menu[2].setFillColor(sf::Color::Red);
	Stop[2].setString("Exit");
	Stop[1].setOrigin(Stop[2].getLocalBounds().width / 2, Stop[2].getLocalBounds().height / 2);
	Stop[2].setPosition(sf::Vector2f(width / 2, height / (Max_ITEM + 1) * 3));


}
stop::~stop()
{

}
void stop::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_ITEM; i++)
	{
		window.draw(Stop[i]);
	}
}
void stop::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		Stop[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		Stop[selectedItem].setFillColor(sf::Color::Red);
	}

}
void stop::MoveDown()
{
	if (selectedItem + 1 < Max_ITEM)
	{
		Stop[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		Stop[selectedItem].setFillColor(sf::Color::Red);
	}

}
