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
	sf::Texture firee;
	sf::Texture heart;
	sf::IntRect data;
	//Load File
	princess.loadFromFile("charecter/princess.png");
	prince.loadFromFile("charecter/prince.png");
	firee.loadFromFile("charecter/frie.png");
	heart.loadFromFile("charecter/heart.png");

	Player player(&prince, sf::Vector2u(5, 8), 0.5f, 300.0f, 300);

	sf::RectangleShape heartt(sf::Vector2f(120.0f, 40.0f));
	
	
	data.top = 0;
	data.left = 0;
	data.width = 900;
	data.height = 300; 

	heartt.setTextureRect(data);
	heartt.setTexture(&heart);

	


	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080, 720));


	


	std::vector<Platform> platfroms;

	//cob
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(-50.0f, 679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(1880.5f, 679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 1408.5f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, -50.0f)));

	
	//back01
	
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
	platfroms.push_back(Platform(nullptr, sf::Vector2f(270.0f, 75.0f), sf::Vector2f(940.0f, 715.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 25.0f), sf::Vector2f(1480.0f, 728.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 180.0f), sf::Vector2f(1600.0f, 658.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 330.0f), sf::Vector2f(1725.0f, 588.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(170.0f, 35.0f), sf::Vector2f(1460.0f, 363.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(170.0f, 95.0f), sf::Vector2f(1400.0f, 300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(370.0f, 40.0f), sf::Vector2f(1220.0f, 272.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 40.0f), sf::Vector2f(390.0f, 272.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 60.0f), sf::Vector2f(330.0f,20.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 60.0f), sf::Vector2f(1480.0f, 20.0f)));

	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1500.0f), sf::Vector2f(23.0f, 600.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(45.0f, 1500.0f), sf::Vector2f(1820.0f, 600.0f)));
	
	//bg01

	//bg02
	/*
	platfroms.push_back(Platform(nullptr, sf::Vector2f(220.0f, 278.0f), sf::Vector2f(118.0f, 1225.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 30.0f), sf::Vector2f(600.0f, 1330.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(915.0f, 1290.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(1000.0f, 1230.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 150.0f), sf::Vector2f(1150.0f, 1205.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 150.0f), sf::Vector2f(1430.0f, 1185.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 150.0f), sf::Vector2f(1430.0f, 1300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 150.0f), sf::Vector2f(1730.0f, 1325.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1613.0f, 1233.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(95.0f, 30.0f), sf::Vector2f(1549.0f, 1100.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(95.0f, 45.0f), sf::Vector2f(1183.0f, 1105.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(95.0f, 45.0f), sf::Vector2f(1220.0f, 1133.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(40.0f, 30.0f), sf::Vector2f(1770.0f, 1233.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1400.0f), sf::Vector2f(1812.0f, 600.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1500.0f), sf::Vector2f(20.0f, 800.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(620.0f, 30.0f), sf::Vector2f(1485.0f, 863.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(145.0f, 30.0f), sf::Vector2f(1585.0f,675.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(325.0f, 30.0f), sf::Vector2f(1300.0f, 528.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(370.0f, 5.0f), sf::Vector2f(1630.0f, 545.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 30.0f), sf::Vector2f(1740.0f, 532.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 120.0f), sf::Vector2f(1150.0f, 584.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(390.0f, 5.0f), sf::Vector2f(1381.0f, 304.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 30.0f), sf::Vector2f(1620.0f, 298.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(440.0f, 30.0f), sf::Vector2f(965.0f, 296.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(450.0f, 5.0f), sf::Vector2f(520.0f, 304.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(240.0f, 30.0f), sf::Vector2f(257.0f, 296.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(250.0f, 5.0f), sf::Vector2f(160.0f, 545.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(55.0f, 530.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(45.0f, 80.0f), sf::Vector2f(310.0f, 560.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(130.0f, 45.0f), sf::Vector2f(350.0f, 580.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 420.0f), sf::Vector2f(400.0f, 810.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 30.0f), sf::Vector2f(313.0f, 955.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 550.0f), sf::Vector2f(963.0f, 555.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(250.0f, 30.0f), sf::Vector2f(835.0f, 720.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(220.0f, 40.0f), sf::Vector2f(680.0f, 625.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(750.0f, 680.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(135.0f, 120.0f), sf::Vector2f(445.0f, 955.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 330.0f), sf::Vector2f(585.0f, 985.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 200.0f), sf::Vector2f(496.0f, 1000.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(542.0f, 910.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(60.0f, 45.0f), sf::Vector2f(625.0f, 1145.0f)));
	*/
	//bg2
	//bg3
	/*
	platfroms.push_back(Platform(nullptr, sf::Vector2f(130.0f, 130.0f), sf::Vector2f(60.0f, 1300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(172.0f, 1340.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(130.0f, 5.0f), sf::Vector2f(283.0f, 1355.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(240.0f, 30.0f), sf::Vector2f(471.0f, 1340.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 5.0f), sf::Vector2f(665.0f, 1355.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(280.0f, 30.0f), sf::Vector2f(855.0f, 1340.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(220.0f, 5.0f), sf::Vector2f(1100.0f, 1355.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(600.0f, 30.0f), sf::Vector2f(1520.0f, 1340.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(75.0f, 230.0f), sf::Vector2f(466.0f, 1230.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(255.0f, 5.0f), sf::Vector2f(460.0f, 1120.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 35.0f), sf::Vector2f(260.0f, 1100.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 35.0f), sf::Vector2f(664.0f, 1110.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(350.0f, 35.0f), sf::Vector2f(850.0f, 1060.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 170.0f), sf::Vector2f(1010.0f, 1130.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(180.0f, 5.0f), sf::Vector2f(1100.0f, 1170.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1040.0f, 1155.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 30.0f), sf::Vector2f(1220.0f, 1155.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 100.0f), sf::Vector2f(1390.0f, 1275.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 230.0f), sf::Vector2f(1435.0f, 1150.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(290.0f, 30.0f), sf::Vector2f(1270.0f, 1015.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 60.0f), sf::Vector2f(1470.0f, 916.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 70.0f), sf::Vector2f(1415.0f, 976.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 400.0f), sf::Vector2f(1528.0f, 785.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(605.0f, 35.0f), sf::Vector2f(1010.0f, 775.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 35.0f), sf::Vector2f(835.0f,740.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(585.0f, 35.0f), sf::Vector2f(1230.0f, 580.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(60.0f, 60.0f), sf::Vector2f(809.0f, 695.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 35.0f), sf::Vector2f(390.0f, 870.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 35.0f), sf::Vector2f(780.0f, 825.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 35.0f), sf::Vector2f(446.0f, 585.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(170.0f, 130.0f), sf::Vector2f(89.0f, 825.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(80.0f, 140.0f), sf::Vector2f(417.0f, 500.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(270.0f, 35.0f), sf::Vector2f(180.0f, 305.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 225.0f), sf::Vector2f(444.0f, 400.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(705.0f, 5.0f), sf::Vector2f(780.0f, 320.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 35.0f), sf::Vector2f(1170.0f, 310.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 35.0f), sf::Vector2f(480.0f, 310.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 35.0f), sf::Vector2f(720.0f, 300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 35.0f), sf::Vector2f(930.0f, 300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 270.0f), sf::Vector2f(1195.0f, 420.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(85.0f, 150.0f), sf::Vector2f(1265.0f, 505.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1350.0f), sf::Vector2f(1810.0f, 680.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1280.0f), sf::Vector2f(20.0f, 630.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(1730.0f, 1080.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 35.0f), sf::Vector2f(1555.0f, 730.0f)));

	*/


	//bg01
	sf::Texture bg01;
	bg01.loadFromFile("charecter/back01.png");
	sf::RectangleShape back01(sf::Vector2f(1830.5f, 1358.5f));
	back01.setPosition(0.0f, 0.0f);
	back01.setTexture(&bg01);
	//bg02
	sf::Texture bg02;
	bg02.loadFromFile("charecter/back02.png");
	sf::RectangleShape back02(sf::Vector2f(1830.5f, 1358.5f));
	back02.setPosition(0.0f, 0.0f);
	back02.setTexture(&bg02);
	//bg03
	sf::Texture bg03;
	bg03.loadFromFile("charecter/back03.png");
	sf::RectangleShape back03(sf::Vector2f(1830.5f, 1358.5f));
	back03.setPosition(0.0f, 0.0f);
	back03.setTexture(&bg03);

	

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
		//window.draw(back02);
		//window.draw(back03);
		window.setView(view);
		
		for (Platform& platfrom : platfroms)
			platfrom.Draw(window);
		//window.draw(back01);
		//window.draw(back02);

		player.Draw(window);
		heartt.setPosition(player.GetPosition().x-80, player.GetPosition().y-60);
		window.draw(heartt);


		window.display();
	}
}
