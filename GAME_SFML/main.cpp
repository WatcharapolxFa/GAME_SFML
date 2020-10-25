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


	Player player(&prince, sf::Vector2u(5, 8), 0.5f, 300.0f, 300);

	std::vector<Platform> platfroms;

	//cob
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(-50.0f, 679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(1880.5f, 679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 1408.5f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, -50.0f)));

	

	platfroms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 40.0f), sf::Vector2f(140.0f, 1350.0f)));

	platfroms.push_back(Platform(nullptr, sf::Vector2f(380.0f, 40.0f), sf::Vector2f(860.0f, 1350.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(380.0f, 40.0f), sf::Vector2f(1630.0f, 1350.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(380.0f, 40.0f), sf::Vector2f(1630.0f, 1350.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(190.0f, 90.0f), sf::Vector2f(1740.0f, 1281.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(165.0f, 125.0f), sf::Vector2f(1800.0f, 1190.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1590.0f, 25.0f), sf::Vector2f(800.0f, 972.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 25.0f), sf::Vector2f(1675.0f, 1000.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(185.0f, 180.0f), sf::Vector2f(90.0f, 900.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1590.0f, 25.0f), sf::Vector2f(1080.0f, 748.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 25.0f), sf::Vector2f(335.0f, 735.0f)));

	

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
		std::cout << "x = " << player.GetPosition().x << " y = " << player.GetPosition().y << std::endl;
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

		
		
		sf::Vector2f direction;
		player.Update(deltaTime,direction);

		for (Platform& platfrom : platfroms)
			if (platfrom.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		//set 
		view.setCenter(sf::Vector2f(player.GetPosition()));
		if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(540.0f, 360.0f);//window
			}
			if (view.getCenter().y + 360.0f >= 1358.5f)
			{
				view.setCenter(540.0f, 998.5f);//window
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1358.5f)
			{
				view.setCenter(540.0f, player.GetPosition().y);
			}

		}
		if (view.getCenter().x + 540.0f >= 1830.5f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(1290.5f, 360.0f);//window 1248-540 collision right 
			}
			if (view.getCenter().y + 360.0f >= 1358.5f)
			{
				view.setCenter(1290.5f, 998.5f);//window 1248-540
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1358.5f)
			{
				view.setCenter(1290.5f, player.GetPosition().y);
			}
		}
		if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 1830.5f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(player.GetPosition().x, 360.0f);
			}
			if (view.getCenter().y + 360.0f >= 1358.5f)
			{
				view.setCenter(player.GetPosition().x, 998.5f);
			}
		}
		window.clear();
		window.draw(back01);
		window.setView(view);
		player.Draw(window);
		for (Platform& platfrom : platfroms)
			platfrom.Draw(window);

		window.display();
	}
}
