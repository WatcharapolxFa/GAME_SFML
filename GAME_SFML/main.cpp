#pragma warning(disable : 26812)
#include <SFML/Graphics.hpp>
#include<iostream>
#include<stdio.h>
#include<vector>
#include"Player.h"
#include"Platform.h"
#include"Bullet.h"
#include"HitboxComponent.h"
#include<SFML/Audio.hpp>
#include<sstream>
#include"friebg.h"
#include<SFML/System.hpp>
#include<cstdlib>
using namespace std;


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
	sf::Texture mana;
	sf::IntRect datamana;
	sf::Texture thunderbolt;
	sf::Texture waterbg;
	sf::Music music;
	sf::Texture firebgg;

	//Load File
	princess.loadFromFile("charecter/princess.png");
	prince.loadFromFile("charecter/prince.png");
	firee.loadFromFile("charecter/frie.png");
	heart.loadFromFile("charecter/heart.png");
	mana.loadFromFile("charecter/mana.png");
	thunderbolt.loadFromFile("charecter/thunderbolt.png");
	firebgg.loadFromFile("charecter/friebg.png");
	waterbg.loadFromFile("charecter/waterbg.png");

	//Music
	/*if (!music.openFromFile("C:/Users/007xfa/source/repos/WatcharapolxFa/GAME_SFML/GAME_SFML/charecter/music.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}
	music.play();
	*/



	friebg friebggg(&firebgg, sf::Vector2u(2,1), 0.5f);
	

	Player player(&prince, sf::Vector2u(5, 8), 0.5f, 300.0f, 300);



	//heart
	sf::RectangleShape heartt(sf::Vector2f(120.0f, 40.0f));
	data.top = 300;
	data.left = 0;
	data.width = 900;
	data.height = 300; 

	heartt.setTextureRect(data);
	heartt.setTexture(&heart);
	//mana
	sf::RectangleShape manaa(sf::Vector2f(120.0f, 40.0f));
	datamana.top = 0;
	datamana.left = 0;
	datamana.width = 900;
	datamana.height = 300;
	
	manaa.setTextureRect(datamana);
	manaa.setTexture(&mana);
	
	sf::Vector2f pos ;
	//Bullet
	Bullet bullet1(&firee, sf::Vector2u(5, 1), 0.1f, 1000.0f, pos, sf::Vector2f(70.0f, 70.0f), 5.0f);
	Bullet bullet2(&thunderbolt, sf::Vector2u(5, 1), 0.1f, 1000.0f, pos, sf::Vector2f(70.0f, 70.0f), 10.0f);

	int Bul = 0;
	int Bul2 = 0;

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080, 720));

	//hitbox
	HitboxComponent hitboxPlayer(0, 0, sf::Vector2f(30.0f, 52.0f), player.GetPosition());
	


	std::vector<Platform> platfroms;
	// Warp
	sf::RectangleShape waroPoint(sf::Vector2f(20, 40));
	waroPoint.setPosition(sf::Vector2f(75, 204));

	//Warp2
	sf::RectangleShape waroPoint2(sf::Vector2f(20, 40));
	waroPoint2.setPosition(sf::Vector2f(180, 3284));

	
	//cob01
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

	
	//cob02
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(-50.0f, 2679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(1880.5f, 2679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 33.5f), sf::Vector2f(915.25f, 3350.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 1950.0f)));
	//bg02
	/*
	platfroms.push_back(Platform(nullptr, sf::Vector2f(220.0f, 278.0f), sf::Vector2f(118.0f, 3225.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 30.0f), sf::Vector2f(600.0f, 3330.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(915.0f, 3290.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(1000.0f, 3230.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 150.0f), sf::Vector2f(1150.0f, 3205.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 150.0f), sf::Vector2f(1430.0f, 3185.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 150.0f), sf::Vector2f(1430.0f, 3300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 150.0f), sf::Vector2f(1730.0f, 3325.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1613.0f, 3233.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(95.0f, 30.0f), sf::Vector2f(1549.0f, 3100.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(95.0f, 45.0f), sf::Vector2f(1183.0f, 3105.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(95.0f, 45.0f), sf::Vector2f(1220.0f, 3133.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(40.0f, 30.0f), sf::Vector2f(1770.0f, 3233.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1400.0f), sf::Vector2f(1812.0f, 2600.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1500.0f), sf::Vector2f(20.0f, 2800.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(620.0f, 30.0f), sf::Vector2f(1485.0f, 2863.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(145.0f, 30.0f), sf::Vector2f(1585.0f,2675.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(325.0f, 30.0f), sf::Vector2f(1300.0f, 2528.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(370.0f, 5.0f), sf::Vector2f(1630.0f, 2545.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 30.0f), sf::Vector2f(1740.0f, 2532.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 120.0f), sf::Vector2f(1150.0f, 2584.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(390.0f, 5.0f), sf::Vector2f(1381.0f, 2304.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 30.0f), sf::Vector2f(1620.0f, 2298.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(440.0f, 30.0f), sf::Vector2f(965.0f, 2296.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(450.0f, 5.0f), sf::Vector2f(520.0f, 2304.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(240.0f, 30.0f), sf::Vector2f(257.0f, 2296.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(250.0f, 5.0f), sf::Vector2f(160.0f, 2545.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(55.0f, 2530.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(45.0f, 80.0f), sf::Vector2f(310.0f, 2560.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(130.0f, 45.0f), sf::Vector2f(350.0f, 2580.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 420.0f), sf::Vector2f(400.0f, 2810.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 30.0f), sf::Vector2f(313.0f, 2955.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 550.0f), sf::Vector2f(963.0f, 2555.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(250.0f, 30.0f), sf::Vector2f(835.0f, 2720.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(220.0f, 40.0f), sf::Vector2f(680.0f, 2625.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(750.0f, 2680.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(135.0f, 120.0f), sf::Vector2f(445.0f, 2955.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 330.0f), sf::Vector2f(585.0f, 2985.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 200.0f), sf::Vector2f(496.0f, 3000.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(542.0f, 2910.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(60.0f, 45.0f), sf::Vector2f(625.0f, 3145.0f)));
	*/
	//bg2
	//cob03
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(-50.0f, 6679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(1880.5f, 6679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 61408.5f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 5950.0f)));
	//bg3
	
	platfroms.push_back(Platform(nullptr, sf::Vector2f(130.0f, 130.0f), sf::Vector2f(60.0f, 5300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 30.0f), sf::Vector2f(172.0f, 5340.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(130.0f, 5.0f), sf::Vector2f(283.0f, 5355.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(240.0f, 30.0f), sf::Vector2f(471.0f, 5340.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 5.0f), sf::Vector2f(665.0f, 5355.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(280.0f, 30.0f), sf::Vector2f(855.0f, 5340.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(220.0f, 5.0f), sf::Vector2f(1100.0f, 5355.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(600.0f, 30.0f), sf::Vector2f(1520.0f, 5340.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(75.0f, 230.0f), sf::Vector2f(466.0f, 5230.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(255.0f, 5.0f), sf::Vector2f(460.0f, 5120.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 35.0f), sf::Vector2f(260.0f, 5100.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 35.0f), sf::Vector2f(664.0f, 5110.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(350.0f, 35.0f), sf::Vector2f(850.0f, 5060.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 170.0f), sf::Vector2f(1010.0f, 5130.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(180.0f, 5.0f), sf::Vector2f(1100.0f, 5170.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 30.0f), sf::Vector2f(1040.0f, 5155.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 30.0f), sf::Vector2f(1220.0f, 5155.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(140.0f, 100.0f), sf::Vector2f(1390.0f, 5275.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(30.0f, 230.0f), sf::Vector2f(1435.0f, 5150.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(290.0f, 30.0f), sf::Vector2f(1270.0f, 5015.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 60.0f), sf::Vector2f(1470.0f, 4916.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 70.0f), sf::Vector2f(1415.0f,4976.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 400.0f), sf::Vector2f(1528.0f, 4785.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(605.0f, 35.0f), sf::Vector2f(1010.0f, 4775.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 35.0f), sf::Vector2f(835.0f,4740.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(585.0f, 35.0f), sf::Vector2f(1230.0f, 4580.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(60.0f, 60.0f), sf::Vector2f(809.0f, 4695.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 35.0f), sf::Vector2f(390.0f, 4870.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(330.0f, 35.0f), sf::Vector2f(780.0f, 4825.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 35.0f), sf::Vector2f(446.0f, 4585.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(170.0f, 130.0f), sf::Vector2f(89.0f, 4825.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(80.0f, 140.0f), sf::Vector2f(417.0f, 4500.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(270.0f, 35.0f), sf::Vector2f(180.0f, 4305.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 225.0f), sf::Vector2f(444.0f, 4400.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(705.0f, 5.0f), sf::Vector2f(780.0f, 4320.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(70.0f, 35.0f), sf::Vector2f(1170.0f, 4310.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 35.0f), sf::Vector2f(480.0f, 4310.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 35.0f), sf::Vector2f(720.0f, 4300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 35.0f), sf::Vector2f(930.0f, 4300.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 270.0f), sf::Vector2f(1195.0f, 4420.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(85.0f, 150.0f), sf::Vector2f(1265.0f, 4505.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1350.0f), sf::Vector2f(1810.0f, 4680.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1280.0f), sf::Vector2f(20.0f, 4630.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(1730.0f, 41080.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 35.0f), sf::Vector2f(1555.0f, 4730.0f)));

	


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
	back02.setPosition(0.0f, 2000.0f);
	back02.setTexture(&bg02);
	//bg03
	sf::Texture bg03;
	bg03.loadFromFile("charecter/back03.png");
	sf::RectangleShape back03(sf::Vector2f(1830.5f, 1358.5f));
	back03.setPosition(0.0f, 4000.0f);
	back03.setTexture(&bg03);

	//==================================================================
	bool faceright;
	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Clock clocks;
	sf::Time time;
	faceright = true;

	std::ostringstream showtime;
	sf::Font font;
	font.loadFromFile("charecter/FC.ttf");
	sf::Text lbltime;
	lbltime.setString(showtime.str());
	lbltime.setCharacterSize(45);
	lbltime.setFont(font);
	//==================================================================



	int u=0;

	//OPEN WINDOW
	while (window.isOpen())
	{
		
		pos = player.GetPosition();
		time = clocks.getElapsedTime();
		showtime << time.asSeconds();
		

	

		std::cout << "x = " << player.GetPosition().x << " y = " << player.GetPosition().y << std::endl;
		//std::cout << Bul << std::endl;
		//std::cout << bullet1.cooldown(deltaTime, Bul) << "   ";
		//std::cout << bullet2.cooldown(deltaTime, Bul2) << std::endl;
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
		friebggg.Update(deltaTime, direction);
		
		
		player.Update(deltaTime,direction);
		//hitbox
		hitboxPlayer.Update(player.GetPosition(), -12.5f, -3.0f);

		


		
		

		for (Platform& platfrom : platfroms)
			if (platfrom.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);

		//set Viw

		view.setCenter(sf::Vector2f(player.GetPosition()));
			if (view.getCenter().x - 540.0f <= 0.0f)//เช็คค่า x มุมซ้ายสุด ขนาดครึ่งจอ 0.0 ขนาดของรูป ซ้าย
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
			if (view.getCenter().x + 540.0f >= 1830.5f)//เช็คค่า x 1830.5 ขนาดเต็มของรูปเรา ขวา
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
			if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 1830.5f)//เช็คค่า x ด้านล่าง
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				faceright = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				faceright = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && Bul == 0 && bullet1.cooldown(deltaTime, Bul) >= 5.0f)
			{
				if (faceright == true)
				{
					Bul = 1;
					bullet1.attackR(pos);
				}
				if (faceright == false)
				{
					Bul = -1;
					bullet1.attackL(pos);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Bul2 == 0 && bullet2.cooldown(deltaTime, Bul2) >= 10.0f)
			{
				if (faceright == true)
				{
					Bul2 = 1;
					bullet2.attackR(pos);
				}
				if (faceright == false)
				{
					Bul2 = -1;
					bullet2.attackL(pos);
				}
			}
		

		///// viw 02
		if (player.GetPosition().y <=1600&& player.GetPosition().y<= 4000)
		{
			u = 1;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				faceright = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				faceright = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && Bul == 0 && bullet1.cooldown(deltaTime, Bul) >= 5.0f)
			{
				if (faceright == true)
				{
					Bul = 1;
					bullet1.attackR(pos);
				}
				if (faceright == false)
				{
					Bul = -1;
					bullet1.attackL(pos);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Bul2 == 0 && bullet2.cooldown(deltaTime, Bul2) >= 10.0f)
			{
				if (faceright == true)
				{
					Bul2 = 1;
					bullet2.attackR(pos);
				}
				if (faceright == false)
				{
					Bul2 = -1;
					bullet2.attackL(pos);
				}
			}
		}if (u == 1)
		{
			view.setCenter(sf::Vector2f(player.GetPosition()));
			if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
			{
				if (view.getCenter().y - 360.0f <= 0.0f)
				{
					view.setCenter(540.0f, 360.0f);//window
				}
				if (view.getCenter().y + 360.0f >= 3358.5f)
				{
					view.setCenter(540.0f, 2998.5f);//window
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 3358.5f)
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
				if (view.getCenter().y + 360.0f >= 3358.5f)
				{
					view.setCenter(1290.5f, 2998.5f);//window 1248-540
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 3358.5f)
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
				if (view.getCenter().y + 360.0f >= 3358.5f)
				{
					view.setCenter(player.GetPosition().x,2998.5f);
				}
			}
		}
		// viw 03 
		if (player.GetPosition().y > 4000)
		{
			u = 2;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				faceright = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				faceright = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && Bul == 0 && bullet1.cooldown(deltaTime, Bul) >= 5.0f)
			{
				if (faceright == true)
				{
					Bul = 1;
					bullet1.attackR(pos);
				}
				if (faceright == false)
				{
					Bul = -1;
					bullet1.attackL(pos);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Bul2 == 0 && bullet2.cooldown(deltaTime, Bul2) >= 10.0f)
			{
				if (faceright == true)
				{
					Bul2 = 1;
					bullet2.attackR(pos);
				}
				if (faceright == false)
				{
					Bul2 = -1;
					bullet2.attackL(pos);
				}
			}
		}if (u==2)
		{
			view.setCenter(sf::Vector2f(player.GetPosition()));
			if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
			{
				if (view.getCenter().y - 360.0f <= 0.0f)
				{
					view.setCenter(540.0f, 360.0f);//window
				}
				if (view.getCenter().y + 360.0f >= 5358.5f)
				{
					view.setCenter(540.0f, 4998.5f);//window
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 5358.5f)
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
				if (view.getCenter().y + 360.0f >= 5358.5f)
				{
					view.setCenter(1290.5f, 4998.5f);//window 1248-540
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 5358.5f)
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
				if (view.getCenter().y + 360.0f >= 5358.5f)
				{
					view.setCenter(player.GetPosition().x, 4998.5f);
				}
			}
		}
		
		// Time

		lbltime.setString(showtime.str());
		
		showtime.str(" ");
		showtime << "Time : ";
		lbltime.setPosition(view.getCenter().x + 250, view.getCenter().y - 360);

		
		
		
		
		window.clear();
		window.draw(back01);
		window.draw(back02);
		window.draw(back03);
		window.setView(view);
		
		for (Platform& platfrom : platfroms)
			platfrom.Draw(window);

		//window.draw(back01); 
		//window.draw(back02);
		//window.draw(back03);


		//wrab
		if (player.GetCollider().CheckCollision(Collider(waroPoint), direction, 1.0f))
		{
			player.Warped(window);
		}
		window.draw(waroPoint);

		//warp2
		if (player.GetCollider().CheckCollision(Collider(waroPoint2), direction, 1.0f))
		{
			player.Warped2(window);

		}window.draw(waroPoint2);



		//player
		player.Draw(window);

		//heartt
		heartt.setPosition(player.GetPosition().x-50, player.GetPosition().y-60);
		//window.draw(heartt);

		//manaa
		manaa.setPosition(player.GetPosition().x - 50, player.GetPosition().y + 40);
		//window.draw(manaa);

		//hitbox
		hitboxPlayer.Draw(window);

		//time
		window.draw(lbltime);

		friebggg.draw(window);

		//Draw bullet
		if (Bul == 1)
		{
			bullet1.updateR(deltaTime);
			bullet1.draw(window);
		}
		if (Bul == -1)
		{
			bullet1.updateL(deltaTime);
			bullet1.draw(window);
		}
		if (abs(bullet1.GetPosition().x - player.GetPosition().x) >= 1000.0f)
		{
			Bul = 0;
			bullet1.isAvaliable();
			bullet1.SetPosition(pos);
		}

		if (Bul2 == 1)
		{
			bullet2.updateR(deltaTime);
			bullet2.draw(window);
		}
		if (Bul2 == -1)
		{
			bullet2.updateL(deltaTime);
			bullet2.draw(window);
		}
		if (abs(bullet2.GetPosition().x - player.GetPosition().x) >= 1000.0f)
		{
			Bul2 = 0;
			bullet2.isAvaliable();
			bullet2.SetPosition(pos);
		}
		
	
		window.display();
	}
}
