#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdio.h>
int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Watcharapol Yotade 63010870", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	 player.setPosition(206.0f, 206.0f);
	 sf::Texture princess;

	 princess.loadFromFile("charecter/princess.png");
	 player.setTexture(&princess);

	 sf::Vector2u textureSize = princess.getSize();
	 textureSize.x /= 5;
	 textureSize.y /= 8;

	 player.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y * 7, textureSize.x, textureSize.y));
 	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout <<" New window width : "<< evnt.size.width << " New window height  : " << evnt.size.height << std :: endl ;
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128)
				{
					char show = evnt.text.unicode;
					std::cout << show << std::endl;  // Show input Keyboard
				}
			}
		}
		// Line 32-48 input and move 
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.1f);
		}
		
		
		window.clear();
		window.draw(player);
		window.display();
	}
	return 0;
}
