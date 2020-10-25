#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdio.h>
#include<vector>
#include"Player.h"
#include"Platform.h"





int main()
{
	//Set screen and Set title name.
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Watcharapol Yotade 63010870", sf::Style::Close | sf::Style::Resize);//Resize Size as you like.
	//Declare variablees.
	sf::Texture princess;
	sf::Texture prince;
	//Load File
	princess.loadFromFile("charecter/princess.png");
	prince.loadFromFile("charecter/prince.png");
	


	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080, 720));


	Player player(&princess, sf::Vector2u(5, 8), 0.5f, 300.0f, 200);

	std::vector<Platform> platfroms;

	//cob
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(-50.0f, 679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(1880.5f, 679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 1408.5f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, -50.0f)));

	

	platfroms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 40.0f), sf::Vector2f(140.0f, 1350.0f)));
	//platfroms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 10.0f), sf::Vector2f(500.0f, 1200.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(380.0f, 40.0f), sf::Vector2f(860.0f, 1350.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(380.0f, 40.0f), sf::Vector2f(1630.0f, 1350.0f)));


	sf::Texture bg01;
	bg01.loadFromFile("charecter/black01.png");
	sf::RectangleShape back01(sf::Vector2f(1830.5f, 1358.5f));
	back01.setPosition(0.0f, 0.0f);
	back01.setTexture(&bg01);


	float deltaTime = 0.0f;
	sf::Clock clock;


	//OPEN WINDOW
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed: // When you press close.
				window.close();
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
		sf::Vector2f direction;


		for (Platform& platfrom : platfroms)
			if (platfrom.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		view.setCenter(player.GetPosition());
		window.clear();
		window.draw(back01);
		window.setView(view);
		player.Draw(window);
		for (Platform& platfrom : platfroms)
			platfrom.Draw(window);

		window.display();
	}
}
