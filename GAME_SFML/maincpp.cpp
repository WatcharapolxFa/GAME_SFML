#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdio.h>
#include"Player.h"
int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Watcharapol Yotade 63010870", sf::Style::Close | sf::Style::Resize);
	sf::Texture princess;
	princess.loadFromFile("charecter/princess.png");	 

	 Player player(&princess, sf::Vector2u(5, 8), 0.5f,100.0f);
	 float deltaTime = 0.0f;
	 sf::Clock clock;

	

 	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

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
					std::cout << show << std::endl;  // Show input Keyboards
				}
			}
		}
		
		
		player.Update(deltaTime);
		
		window.clear();
		player.Draw(window);
		window.display();
	}
}
