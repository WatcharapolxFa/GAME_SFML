#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdio.h>
#include"Player.h"
#include"Platform.h"

static const float VIEW_HEIGHT = 512.0f;
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Watcharapol Yotade 63010870", sf::Style::Close | sf::Style::Resize);
	sf::Texture princess;
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	princess.loadFromFile("charecter/princess.png");	 

	 Player player(&princess, sf::Vector2u(5, 8), 0.5f,100.0f);
	 
	 Platform platfrom1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	 Platform platfrom2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

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
				ResizeView(window, view);
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
		platfrom1.GetCollider().CheckCollision(player.GetCollider(),0.0f);
		platfrom2.GetCollider().CheckCollision(player.GetCollider(),1.0f);

		view.setCenter(player.GetPosition());
		window.clear();
		window.setView(view);
		player.Draw(window);
		platfrom1.Draw(window);
		platfrom2.Draw(window);
		window.display();
	}
}
