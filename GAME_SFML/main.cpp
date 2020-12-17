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
#include"waterbg.h"
#include"dimon.h"
#include"dimonfah.h"
#include"dimongreen.h"
#include<time.h> 
#include <stdlib.h>
#include"Menu.h"
#include"stop.h"
#include"box.h"
#include"button.h"
#include"item.h"
#include"boxsx.h"
#include"Barrier.h"
#include"Barrierred.h"
#include"buttonred.h"
#include"platfrom2.h"
#include"fstream"
#include"Enemy.h"
#include "enemys.h"
#include"enemys.h"
#include"Boss.h"
#include"princess.h"
using namespace std;


int main()
{
	//Set screen and Set title name. ========================================================================================================================
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Watcharapol Yotade 63010870", sf::Style::Close | sf::Style::Resize);//Resize Size as you like.
	//Declare variablees.
	sf::Texture princessx;
	sf::Texture prince;
	sf::Texture firee; 
	sf::Texture heart;
	sf::IntRect data;
	sf::Texture mana;
	sf::IntRect datamana;
	sf::Texture thunderbolt;
	sf::Music music;
	sf::Texture firebgg;
	sf::Texture waterbgg;
	sf::Texture daimonn;
	sf::Texture daimonfah;
	sf::Texture daimongreen;
	sf::Texture menustr;
	sf::Texture boxx;
	sf::Texture buttonn;
	sf::Texture boxs;
	sf::Texture boxsxs;
	sf::Texture barrierr;
	sf::Texture barrierreds;
	sf::Texture buttonredd;
	sf::Texture penois;
	sf::Texture cobe;
	sf::Texture bulletboss1;
	sf::Texture bo;
	float cooldown = 0;

	//Load File
	princessx.loadFromFile("charecter/princess.png");
	prince.loadFromFile("charecter/prince.png");
	firee.loadFromFile("charecter/frie.png");
	heart.loadFromFile("charecter/heart.png");
	mana.loadFromFile("charecter/mana.png");
	thunderbolt.loadFromFile("charecter/thunderbolt.png");
	firebgg.loadFromFile("charecter/friebg.png");
	waterbgg.loadFromFile("charecter/waterbg.png");
	daimonn.loadFromFile("charecter/dimon.png");
	daimonfah.loadFromFile("charecter/dimonfah.png");
	daimongreen.loadFromFile("charecter/dimongr.png");
	boxx.loadFromFile("charecter/box.png");
	menustr.loadFromFile("charecter/menu.png");
	buttonn.loadFromFile("charecter/button.png");
	boxs.loadFromFile("charecter/boxs.png");
	boxsxs.loadFromFile("charecter/boxsx.png");
	barrierr.loadFromFile("charecter/Barrier.png");
	barrierreds.loadFromFile("charecter/Barrierred.png");
	buttonredd.loadFromFile("charecter/buttonred.png");
	penois.loadFromFile("charecter/penoi.png");
	cobe.loadFromFile("charecter/cobe.png");
	bulletboss1.loadFromFile("charecter/pebos.png");
	bo.loadFromFile("charecter/boss.png");

	sf::Sprite background;
	background.setTexture(menustr);
	//=========================================================================================================================================================
	//Music
	if (!music.openFromFile("C:/Users/007xfa/source/repos/WatcharapolxFa/GAME_SFML/GAME_SFML/charecter/bleach.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}
	music.setVolume(50.0f);
	music.setLoop(true);
	music.play();
	//=========================================================================================================================================================

	sf::SoundBuffer coins;
	coins.loadFromFile("charecter/coin.wav");
	sf::Sound coinss;
	coinss.setVolume(60);
	coinss.setBuffer(coins);

	sf::SoundBuffer tunders;
	tunders.loadFromFile("charecter/spark.wav");
	sf::Sound tunderse;
	tunderse.setVolume(60);
	tunderse.setBuffer(tunders);

	sf::SoundBuffer sounfire;
	sounfire.loadFromFile("charecter/firebu.wav");
	sf::Sound sounfires;
	sounfires.setVolume(60);
	sounfires.setBuffer(sounfire);

	sf::SoundBuffer worldclear;
	worldclear.loadFromFile("charecter/worldclear.ogg");
	sf::Sound worldclears;
	worldclears.setVolume(60);
	worldclears.setBuffer(worldclear);

	sf::SoundBuffer gameover;
	gameover.loadFromFile("charecter/gameover.ogg");
	sf::Sound gameovers;
	gameovers.setVolume(60);
	gameovers.setBuffer(gameover);
	//?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
	//check 
	srand(time(NULL));
	int cheeck = rand() % 6;
	float positionrand_x[3]{}, positionrand_y[3]{};

	if (cheeck == 0)
	{
		positionrand_x[0] = 943.0f;
		positionrand_y[0] = 65.0f;

		positionrand_x[1] = 1270.0f;
		positionrand_y[1] = 1050.0f;

		positionrand_x[2] = 1273.0f;
		positionrand_y[2] = 415.0f;

	}
	else if (cheeck == 1)
	{
		positionrand_x[0] = 943.0f;
		positionrand_y[0] = 65.0f;

		positionrand_x[2] = 1270.0f;
		positionrand_y[2] = 1050.0f;

		positionrand_x[1] = 1273.0f;
		positionrand_y[1] = 415.0f;
	}
	else if (cheeck == 2)
	{
		positionrand_x[2] = 943.0f;
		positionrand_y[2] = 65.0f;

		positionrand_x[1] = 1270.0f;
		positionrand_y[1] = 1050.0f;

		positionrand_x[0] = 1273.0f;
		positionrand_y[0] = 415.0f;
	}
	else if (cheeck == 3)
	{
		positionrand_x[1] = 943.0f;
		positionrand_y[1] = 65.0f;

		positionrand_x[0] = 1270.0f;
		positionrand_y[0] = 1050.0f;

		positionrand_x[2] = 1273.0f;
		positionrand_y[2] = 415.0f;
	}
	else if (cheeck == 4)
	{
		positionrand_x[1] = 943.0f;
		positionrand_y[1] = 65.0f;

		positionrand_x[2] = 1270.0f;
		positionrand_y[2] = 1050.0f;

		positionrand_x[0] = 1273.0f;
		positionrand_y[0] = 415.0f;
	}
	else if (cheeck == 5)
	{
		positionrand_x[2] = 943.0f;
		positionrand_y[2] = 65.0f;

		positionrand_x[0] = 1270.0f;
		positionrand_y[0] = 1050.0f;

		positionrand_x[2] = 1273.0f;
		positionrand_y[2] = 415.0f;
	}
	//???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
	int cheeck2 = rand() % 6;
	float positionrand_x2[3]{}, positionrand_y2[3]{};

	if (cheeck2 == 0)
	{
		positionrand_x2[0] = 438.0f;
		positionrand_y2[0] = 2600.0f;

		positionrand_x2[1] = 60.5f;
		positionrand_y2[1] = 2280.0f;

		positionrand_x2[2] = 1585.0f;
		positionrand_y2[2] = 2585.0f;

	}
	else if (cheeck2 == 1)
	{
		positionrand_x2[0] = 438.0f;
		positionrand_y2[0] = 2600.0f;

		positionrand_x2[2] = 60.5f;
		positionrand_y2[2] = 2280.0f;

		positionrand_x2[1] = 1585.0f;
		positionrand_y2[1] = 2585.0f;
	}
	else if (cheeck2 == 2)
	{
		positionrand_x2[2] = 438.0f;
		positionrand_y2[2] = 2600.0f;

		positionrand_x2[1] = 60.5f;
		positionrand_y2[1] = 2280.0f;

		positionrand_x2[0] = 1585.0f;
		positionrand_y2[0] = 2585.0f;
	}
	else if (cheeck2 == 3)
	{
		positionrand_x2[1] = 438.0f;
		positionrand_y2[1] = 2600.0f;

		positionrand_x2[0] = 60.5f;
		positionrand_y2[0] = 2280.0f;

		positionrand_x2[2] = 1585.0f;
		positionrand_y2[2] = 2585.0f;

	}
	else if (cheeck2 == 4)
	{
		positionrand_x2[1] = 438.0f;
		positionrand_y2[1] = 2600.0f;


		positionrand_x2[2] = 60.5f;
		positionrand_y2[2] = 2280.0f;

		positionrand_x2[0] = 1585.0f;
		positionrand_y2[0] = 2585.0f;
	}
	else if (cheeck2 == 5)
	{
		positionrand_x2[2] = 438.0f;
		positionrand_y2[2] = 2600.0f;

		positionrand_x2[0] = 60.5f;
		positionrand_y2[0] = 2280.0f;


		positionrand_x2[2] = 1585.0f;
		positionrand_y2[2] = 2585.0f;
	}

	//*********************************************************


	int cheeck3 = rand() % 6;
	float positionrand_x3[3]{}, positionrand_y3[3]{};

	if (cheeck3 == 0)
	{
		positionrand_x3[0] = 659.0f;
		positionrand_y3[0] = 5270.0f;

		positionrand_x3[1] = 819.0f;
		positionrand_y3[1] = 4250.0f;

		positionrand_x3[2] = 1770.0f;
		positionrand_y3[2] = 4686.0f;

	}
	else if (cheeck3 == 1)
	{
		positionrand_x3[0] = 659.0f;
		positionrand_y3[0] = 5270.0f;

		positionrand_x3[2] = 819.0f;
		positionrand_y3[2] = 4250.0f;

		positionrand_x3[1] = 1770.0f;
		positionrand_y3[1] = 4686.0f;
	}
	else if (cheeck3 == 2)
	{
		positionrand_x3[2] = 659.0f;
		positionrand_y3[2] = 5270.0f;

		positionrand_x3[1] = 819.0f;
		positionrand_y3[1] = 4250.0f;

		positionrand_x3[0] = 1770.0f;
		positionrand_y3[0] = 4686.0f;
	}
	else if (cheeck3 == 3)
	{
		positionrand_x3[1] = 659.0f;
		positionrand_y3[1] = 5270.0f;

		positionrand_x3[0] = 819.0f;
		positionrand_y3[0] = 4250.0f;


		positionrand_x3[2] = 1770.0f;
		positionrand_y3[2] = 4686.0f;

	}
	else if (cheeck3 == 4)
	{
		positionrand_x3[1] = 659.0f;
		positionrand_y3[1] = 5270.0f;


		positionrand_x3[2] = 819.0f;
		positionrand_y3[2] = 4250.0f;

		positionrand_x3[0] = 1770.0f;
		positionrand_y3[0] = 4686.0f;
	}
	else if (cheeck3 == 5)
	{
		positionrand_x3[2] = 659.0f;
		positionrand_y3[2] = 5270.0f;

		positionrand_x3[0] = 819.0f;
		positionrand_y3[0] = 4250.0f;


		positionrand_x3[2] = 1770.0f;
		positionrand_y3[2] = 4686.0f;
	}


	//Vector ?? ===============================================================================================================================================
	std::vector<friebg>FireVector;
	FireVector.push_back(friebg(&firebgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(400.f, 150.0f), sf::Vector2f(495.0f, 1330.0f)));
	FireVector.push_back(friebg(&firebgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(400.f, 150.0f), sf::Vector2f(1245.0f, 1330.0f)));
	FireVector.push_back(friebg(&firebgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(400.f, 150.0f), sf::Vector2f(583.0f, 720.0f)));
	FireVector.push_back(friebg(&firebgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(330.f, 170.0f), sf::Vector2f(560.0f, 2280.0f)));
	FireVector.push_back(friebg(&firebgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(330.f, 170.0f), sf::Vector2f(1362.0f, 2280.0f)));
	FireVector.push_back(friebg(&firebgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(280.f, 170.0f), sf::Vector2f(466.0f, 5085.0f)));
	FireVector.push_back(friebg(&firebgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(220.f, 170.0f), sf::Vector2f(578.0f, 4286.0f)));
	FireVector.push_back(friebg(&firebgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(220.f, 170.0f), sf::Vector2f(1061.0f, 4286.0f)));
	//=========================================================================================================================================================

	//Vector ??? ===============================================================================================================================================
	std::vector<waterbg>WaterVector;
	WaterVector.push_back(waterbg(&waterbgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(320.f, 140.0f), sf::Vector2f(1250.0f, 723.0f)));
	WaterVector.push_back(waterbg(&waterbgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(200.f, 150.0f), sf::Vector2f(155.0f, 2515.0f)));
	WaterVector.push_back(waterbg(&waterbgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(200.f, 150.0f), sf::Vector2f(1577.3f, 2520.0f)));
	WaterVector.push_back(waterbg(&waterbgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(239.f, 150.0f), sf::Vector2f(1365.3f, 3080.0f)));
	WaterVector.push_back(waterbg(&waterbgg, sf::Vector2u(2, 1), 0.5f, sf::Vector2f(130.f, 150.0f), sf::Vector2f(1136.3f, 5138.0f)));
	//=========================================================================================================================================================

	//Vector ??????? ===============================================================================================================================================
	std::vector<dimon>DimonVector;
	DimonVector.push_back(dimon(&daimonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x[0], positionrand_y[0])));
	DimonVector.push_back(dimon(&daimonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x2[0], positionrand_y2[0])));
	DimonVector.push_back(dimon(&daimonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x3[0], positionrand_y3[0])));
	//DimonVector.push_back(dimon(&daimonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x[0] , positionrand_y[0])));
	//DimonVector.push_back(dimon(&daimonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x2[0], positionrand_y2[0]))); 
	//DimonVector.push_back(dimon(&daimonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x3[0], positionrand_y3[0])));
	//monVector.push_back(dimon(&daimonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x2[2], positionrand_y[2])));
	//===========================================================================================================================================================

	//Vector ??????? ===============================================================================================================================================
	std::vector<dimonfah>DimonfahVector;
	DimonfahVector.push_back(dimonfah(&daimonfah, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x[1], positionrand_y[1])));
	DimonfahVector.push_back(dimonfah(&daimonfah, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x2[1], positionrand_y2[1])));
	DimonfahVector.push_back(dimonfah(&daimonfah, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x3[1], positionrand_y3[1])));
	//=============================================================================================================================================================

	//Vector ????????? ===============================================================================================================================================
	std::vector<dimongreen>DimongreenVector;
	DimongreenVector.push_back(dimongreen(&daimongreen, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x[2], positionrand_y[2])));
	DimongreenVector.push_back(dimongreen(&daimongreen, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x2[2], positionrand_y2[2])));
	DimongreenVector.push_back(dimongreen(&daimongreen, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(100.f, 100.0f), sf::Vector2f(positionrand_x3[2], positionrand_y3[2])));
	//=============================================================================================================================================================

	// Vector ????? ============================================================================================================================================== =
	std::vector<box>boxVector;
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(500.0f, 1285.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(1220.0f, 1285.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(947.0f, 628.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(963.0f, 2254.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(1462, 2800.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(575, 690.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(360.0f, 3263.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(305.0f, 2480.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(525.0f, 2200.0f)));
	boxVector.push_back(box(&boxx, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(480.0f, 5056.0f)));
	//=============================================================================================================================================================
	// Vector ???? ============================================================================================================================================== =
	std::vector<button>buttonVector;
	buttonVector.push_back(button(&buttonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(1516.0f, 910.0f)));
	//buttonVector.push_back(button(&buttonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(1277.0f,203.0f)));
	buttonVector.push_back(button(&buttonn, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(453.0f, 3263.0f)));
	//=============================================================================================================================================================

		// Vector ????????? ============================================================================================================================================== =
	std::vector<buttonred>buttonredVector;
	buttonredVector.push_back(buttonred(&buttonredd, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(1277.0f, 203.0f)));

	//=============================================================================================================================================================



	// Vector ??????????? =============================================================================================================================================
	std::vector<item>itemVector;
	itemVector.push_back(item(&boxs, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(75.0f, 1285.0f)));
	itemVector.push_back(item(&boxs, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(1760.5f, 360.0f)));
	itemVector.push_back(item(&boxs, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(1765.0f, 2800.0f)));
	//=============================================================================================================================================================

	// Vector ??????? ===============================================================================================================================================
	std::vector<boxsx>boxitemVector;
	boxitemVector.push_back(boxsx(&boxsxs, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(75.0f, 755.0f)));
	boxitemVector.push_back(boxsx(&boxsxs, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(75.0f, 3030.0f)));
	boxitemVector.push_back(boxsx(&boxsxs, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.0f), sf::Vector2f(910.0f, 2640.0f)));

	//=============================================================================================================================================================

	//Vector ??????? ??? ==============================================================================================================================================
	std::vector<Barrier>barrierVector;
	barrierVector.push_back(Barrier(&barrierr, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(90.f, 100.f), sf::Vector2f(1300.0f, 903.0f)));
	//=============================================================================================================================================================


	//Vector ??????? ?????? ===========================================================================================================================================
	std::vector<Barrierred>barrieredVector;
	barrieredVector.push_back(Barrierred(&barrierreds, sf::Vector2u(4, 1), 1.0f, sf::Vector2f(200.0f, 50.f), sf::Vector2f(775.0f, 226.0f)));
	//=============================================================================================================================================================

//Player **************************************************************************************************************************************************
	Player player(&prince, sf::Vector2u(5, 8), 0.5f, 180.0f, 350, &firee,&thunderbolt);
	//*********************************************************************************************************************************************************


	//mon1
	std::vector<Enemy>enemyes;
	enemyes.push_back(Enemy(sf::Vector2f(800.0f, 3250.0f),&penois));
	enemyes.push_back(Enemy(sf::Vector2f(870.0f, 2500.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(940.0f, 2200.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(1500.0f, 2730.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(1100.0f, 4600.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(950.0f, 4600.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(820.0f, 4600.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(9000.0f, 4600.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(840.0f, 4200.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(820.0f, 4160.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(1150.0f, 4200.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(1120.0f, 4120.0f), &penois));
	//ถึงตรงนี้
	enemyes.push_back(Enemy(sf::Vector2f(500.0f, 7230.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(800.0f, 7200.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(1000.0f, 7230.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(1200.0f, 7200.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(944.0f, 900.0f), &penois));
	enemyes.push_back(Enemy(sf::Vector2f(1200.0f, 850.0f), &penois));


	//mon2
	std::vector<enemys>Enemyss;
	Enemyss.push_back(enemys(sf::Vector2f(970.0f, 1218.0f), &penois));
	Enemyss.push_back(enemys(sf::Vector2f(500.0f, 659.0f), &penois));
	Enemyss.push_back(enemys(sf::Vector2f(950.0f, 200.0f), &penois));
	Enemyss.push_back(enemys(sf::Vector2f(740.0f, 2770.0f), &penois));
	Enemyss.push_back(enemys(sf::Vector2f(1600.0f, 2450.0f), &penois));
	Enemyss.push_back(enemys(sf::Vector2f(870.0f, 5250.0f), &penois));
	Enemyss.push_back(enemys(sf::Vector2f(400.0f, 4230.0f), &penois));
	Enemyss.push_back(enemys(sf::Vector2f(1120.0f, 4160.0f), &penois));
	Enemyss.push_back(enemys(sf::Vector2f(820.0f, 4120.0f), &penois));


	/*
	std::vector<princess>princesox;
	princesox.push_back(princess(sf::Vector2f(1800.0f, 7200.0f),&princessx));
	*/

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//heart
	sf::RectangleShape heartt(sf::Vector2f(120.0f, 40.0f));
	data.top = 300;
	data.left = 0;
	data.width = 900;
	data.height = 300;
	heartt.setTextureRect(data);
	heartt.setTexture(&heart);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//mana
	sf::RectangleShape manaa(sf::Vector2f(120.0f, 40.0f));
	datamana.top = 0;
	datamana.left = 0;
	datamana.width = 900;
	datamana.height = 300;
	manaa.setTextureRect(datamana);
	manaa.setTexture(&mana);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	// ??????? ???????
	sf::Vector2f pos;

	// Menu
	Menu menu(window.getSize().x, window.getSize().y);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Stop
	stop Stop(window.getSize().x, window.getSize().y);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Bullet

	Bullet bullet1(&firee, sf::Vector2u(5, 1), 0.1f, 800.0f, pos, sf::Vector2f(60.0f, 60.0f), 5.0f);
	Bullet bullet2(&thunderbolt, sf::Vector2u(5, 1), 0.1f, 800.0f, pos, sf::Vector2f(70.0f, 70.0f), 10.0f);
	Bullet bulletboss(&bulletboss1, sf::Vector2u(4, 1), 0.1f, 800.0f, pos, sf::Vector2f(80.0f, 80.0f), 2.0f);

	int Bul = 0;
	int Bul2 = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080, 720));


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//hitbox
	/*HitboxComponent hitboxPlayer(0, 0, sf::Vector2f(30.0f, 52.0f), player.GetPosition());*/
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Warp
	sf::RectangleShape waroPoint(sf::Vector2f(20, 40));
	waroPoint.setPosition(sf::Vector2f(130, 204));

	//Warp2
	sf::RectangleShape waroPoint2(sf::Vector2f(20, 40));
	waroPoint2.setPosition(sf::Vector2f(1693, 3201));

	//Warp3
	sf::RectangleShape waroPoint3(sf::Vector2f(20, 40));
	waroPoint3.setPosition(sf::Vector2f(1730.0f, 5280.0f));


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//cob01
	std::vector<Platform> platfroms;
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
	platfroms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 60.0f), sf::Vector2f(330.0f, 20.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 60.0f), sf::Vector2f(1480.0f, 20.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 1500.0f), sf::Vector2f(23.0f, 600.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(45.0f, 1500.0f), sf::Vector2f(1820.0f, 600.0f)));

	//bg01
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//-------------------------------------------------------------------------------------------------------------------------------------------------------//
	//cob02
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(-50.0f, 2679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(1880.5f, 2679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 33.5f), sf::Vector2f(915.25f, 3365.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 1950.0f)));

	//bg02

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
	platfroms.push_back(Platform(nullptr, sf::Vector2f(145.0f, 30.0f), sf::Vector2f(1585.0f, 2675.0f)));
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
	platfroms.push_back(Platform(nullptr, sf::Vector2f(45.0f, 30.0f), sf::Vector2f(767.0f, 2970.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(15.0f, 10.0f), sf::Vector2f(430.0f, 2700.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(15.0f, 10.0f), sf::Vector2f(52.5f, 2350.0f)));

	//bg2
	//-------------------------------------------------------------------------------------------------------------------------------------------------------//

	//-------------------------------------------------------------------------------------------------------------------------------------------------------//
	//cob03
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(-50.0f, 6679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(1880.5f, 6679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 3980.5f)));
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
	platfroms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 70.0f), sf::Vector2f(1415.0f, 4976.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(35.0f, 400.0f), sf::Vector2f(1528.0f, 4785.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(605.0f, 35.0f), sf::Vector2f(1010.0f, 4775.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 35.0f), sf::Vector2f(835.0f, 4740.0f)));
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

	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 35.0f), sf::Vector2f(1748.0f, 5112.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 35.0f), sf::Vector2f(1755.0f, 5150.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 35.0f), sf::Vector2f(1780.0f, 5180.0f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(150.0f, 35.0f), sf::Vector2f(100, 4734.0f)));
	//-------------------------------------------------------------------------------------------------------------------------------------------------------//

	//cob04
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(30.0f, 7679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 1358.5f), sf::Vector2f(1880.5f, 7679.25f)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 6300)));
	platfroms.push_back(Platform(nullptr, sf::Vector2f(1830.5f, 100.0f), sf::Vector2f(915.25f, 7335.0f)));






	//-------------------------------------------------------------------------------------------------------------------------------------------------------//
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

	sf::Texture bg04;
	bg04.loadFromFile("charecter/black04.png");
	sf::RectangleShape back04(sf::Vector2f(1830.5f, 1358.5f));
	back04.setPosition(0.0f, 6000.0f);
	back04.setTexture(&bg04);


	sf::RectangleShape pauses(sf::Vector2f(1080.0f, 720.0f));
	sf::Texture pau;
	pau.loadFromFile("charecter/stop.png");
	pauses.setTexture(&pau);
	//-------------------------------------------------------------------------------------------------------------------------------------------------------//

	//==================================================================//

	bool faceright;
	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Clock clocks;
	sf::Time time;
	faceright = true;

	std::ostringstream showtime;
	sf::Font font;
	font.loadFromFile("charecter/ka.ttf");
	sf::Text lbltime;
	lbltime.setString(showtime.str());
	lbltime.setCharacterSize(40);
	lbltime.setFont(font);
	lbltime.setFillColor(sf::Color::Yellow);
	lbltime.setString(showtime.str());

	showtime.str(" ");
	showtime << "Time : ";
	lbltime.setPosition(view.getCenter().x + 240, view.getCenter().y - 360);

	//==================================================================//
	int score = 0;
	sf::Text showScore("Score", font, 20);
	showScore.setFillColor(sf::Color::Green);

	sf::Texture endgame;
	endgame.loadFromFile("charecter/End.png");
	sf::RectangleShape endgames;
	endgames.setSize(sf::Vector2f(1080.0f, 720.0f));
	endgames.setOrigin(endgames.getSize()/2.0f);
	endgames.setTexture(&endgame);
	//=====================================================================//
	Boss boss(&bo, sf::Vector2u(4, 1), 0.1f);
	float bos = 0.0f;
	bool pause = false;
	int pselect = 0;
	bool dead = false;
	bool checksound = false;
	bool checksound1 = false;
	int dselect = 0;
	bool menup = true;
	int mselect = 0;
	bool sav;
	int u = 0;
	int cheeckongame = 0;
	bool end = false;
	std::ostringstream savetime;
	//OPEN WINDOW
	while (window.isOpen())
	{
		while (menup == true)
		{
			ifstream hs1;
			ifstream hs2;
			ifstream hs3;
			ifstream hs4;
			ifstream hs5;
			hs1.open("score1.txt");
			hs2.open("score2.txt");
			hs3.open("score3.txt");
			hs4.open("score4.txt");
			hs5.open("score5.txt");
			string h1;
			string h2;
			string h3;
			string h4;
			string h5;
			hs1 >> h1;
			hs2 >> h2;
			hs3 >> h3;
			hs4 >> h4;
			hs5 >> h5;

			sf::Text play("Play", font, 30);
			sf::Text exit("Exit", font, 30);
			sf::Text guide("Press 'Enter' to select.", font, 30);
			sf::Text name(" Watcharapol Yotadee", font, 30);
			sf::Text leader("Leaderboard", font, 30);
			sf::Text gamename("THE FORGOTTEN \n\tPRINCE", font, 40);
			sf::Text score1("1. " + h1, font, 20);
			sf::Text score2("2. " + h2, font, 20);
			sf::Text score3("3. " + h3, font, 20);
			sf::Text score4("4. " + h4, font, 20);
			sf::Text score5("5. " + h5, font, 20);
			window.clear();
			window.setView(view);

			view.setCenter(sf::Vector2f(-1000.0f, 1800.0f));
			background.setOrigin(pauses.getSize() / 2.0f);
			background.setPosition(view.getCenter());
			leader.setPosition(view.getCenter().x - 450, view.getCenter().y - 190.0f);
			score1.setPosition(view.getCenter().x - 350, view.getCenter().y - 125.0f);
			score2.setPosition(view.getCenter().x - 350, view.getCenter().y - 75.0f);
			score3.setPosition(view.getCenter().x - 350, view.getCenter().y - 25.0f);
			score4.setPosition(view.getCenter().x - 350, view.getCenter().y + 25.0f);
			score5.setPosition(view.getCenter().x - 350, view.getCenter().y + 75.0f);
			play.setPosition(view.getCenter().x - 35, view.getCenter().y + 70.0f);
			exit.setPosition(view.getCenter().x - 35, view.getCenter().y + 195.0f);
			//guide.setPosition(view.getCenter().x - 540, view.getCenter().y + 260.0f);
			//name.setPosition(view.getCenter().x +55, view.getCenter().y + 320.0f);
			//gamename.setPosition(view.getCenter().x - 400, view.getCenter().y - 360.0f);
			if (mselect == 0)
			{
				play.setFillColor(sf::Color::Black);
				exit.setFillColor(sf::Color::White);
			}
			if (mselect == 1)
			{
				exit.setFillColor(sf::Color::Black);
				play.setFillColor(sf::Color::White);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{			
				mselect = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				mselect = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && mselect == 0)
			{
				pause = false;
				menup = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && mselect == 1)
			{
				window.close();
				return 0;
			}
			window.draw(background);
			window.draw(leader);
			window.draw(name);
			window.draw(score1);
			window.draw(score2);
			window.draw(score3);
			window.draw(score4);
			window.draw(score5);
			window.draw(play);
			window.draw(exit);
			window.draw(guide);
			window.draw(gamename);
			window.display();
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					std::cout << "Width: " << evnt.size.width << "Height: " << evnt.size.height << std::endl;
					break;
				}
			}
		}
		while (pause == false && dead == false && menup == false && end == false)																																																																	
		{
			//time
			pos = player.GetPosition();
			if (cheeckongame == 1) {
				time = clocks.getElapsedTime();
				//time = sf::seconds((int)time.asSeconds() % 60);
				showtime << (int)time.asSeconds() / 60 << " : " << (int)time.asSeconds() % 60;
			}


			std::cout << "x = " << player.GetPosition().x << " y = " << player.GetPosition().y << std::endl;
			//std::cout << Bul << std::endl;
			//bullet1.cooldown(deltaTime, Bul);
			sf::RectangleShape cooldownfire;
			cooldownfire.setSize(sf::Vector2f(bullet1.cooldown(deltaTime, Bul)*40, 35.0f));
			cooldownfire.setPosition(sf::Vector2f(view.getCenter().x - 345, view.getCenter().y - 250));
			cooldownfire.setFillColor(sf::Color::Red);
			//bullet2.cooldown(deltaTime, Bul2);
			sf::RectangleShape cooldownspark;
			cooldownspark.setSize(sf::Vector2f(bullet2.cooldown(deltaTime, Bul2)*20, 35.0f));
			cooldownspark.setPosition(sf::Vector2f(view.getCenter().x - 345, view.getCenter().y - 200));
			cooldownspark.setFillColor(sf::Color::Magenta);
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
				case sf::Event::KeyReleased:
					switch (evnt.key.code) {
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;
					case sf::Keyboard::Down:
						menu.MoveDown();
						break;
					case sf::Keyboard::Return:
						switch (menu.GetPressedItem())
						{
						case 0:
							cheeckongame = 1;
							clocks = sf::Clock();
							break;
						case 1:
							std::cout << "2" << std::endl;
							break;
						case 2:
							window.close();
							break;
						}


					}


					break;
				case sf::Event::Closed: // When you press close.
					window.close();
					break;



				case sf::Event::TextEntered:
					if (evnt.text.unicode < 128)
					{
						char show = evnt.text.unicode;
						//std::cout << show << std::endl;  // Show input Keyboards
					}
				}
			}
			sf::Vector2f direction;
			
			Platform2 coolspeed(nullptr , sf::Vector2f(200.0 - cooldown, 35.0f), sf::Vector2f(view.getCenter().x - 345, view.getCenter().y - 300));
			coolspeed.col();
			sf::RectangleShape bar(sf::Vector2f(300.0f,150.0f));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				if (cooldown <= 200)
				{
					cooldown += 1.5;
				}
			}
			else
			{
				if (cooldown >= 0)
				{
					cooldown -= 0.2;
				}

			}

			player.Update(deltaTime, direction, cooldown);

			if (player.GetPosition().y > 6500)
			{
				if (boss.GetHp() > 0)
				{
					boss.Update(deltaTime,player.GetPosition().x);
					bos += deltaTime;
					if (bos > 9 && bos < 9.1)
					{						
						bulletboss.attackR(sf::Vector2f(boss.GetPosition().x, boss.GetPosition().y + 120));
					}
					if (bos > 9 && bos <= 12)
					{
						bulletboss.updateR(deltaTime);
					}
					if (bos > 12 && bos < 12.1)
					{
						bulletboss.attackL(sf::Vector2f(boss.GetPosition().x, boss.GetPosition().y + 120));
					}
					if (bos > 12 && bos <= 15) 
					{
						bulletboss.updateL(deltaTime);
					}
					if (boss.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
					{
						sav = true;
						dead = true;
					}
					if (boss.GetCollider().CheckCollision(bullet1.GetCollider(), direction, 1.0f))
					{
						bullet1.SetPosition();
						boss.damaged(1);
						Bul = 0;
					}
					if (boss.GetCollider().CheckCollision(bullet2.GetCollider(), direction, 1.0f))
					{
						bullet2.SetPosition();
						boss.damaged(2);
						Bul2 = 0;
					}
				}
				if (abs(bulletboss.GetPosition().x - boss.GetPosition().x) >= 1400.0f)
				{
					bulletboss.SetPosition();
					bulletboss.isAvaliable();
				}
				if (bos > 15.0f)
				{
					bos = 0.0f;
				}
				if (boss.GetHp() == 0)
				{
					bos = 0.0f;
					boss.dead();
					score += 500;
					sav = true;
					end = true;
				}
			}
			if (bulletboss.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				sav = true;
				dead = true;
			}
			for (Platform& platfrom : platfroms)
				if (platfrom.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
					player.OnCollision(direction);

			for (box& bx : boxVector) {

				if (bx.GetCollider().CheckCollision(player.GetCollider(), direction, 0.0f)) {
					bx.OnCollision(direction);
					player.OnCollision(direction);
				}
				else
					bx.OnCollision({ 0,0 });

				for (Platform& platform : platfroms)
					if (platform.GetCollider().CheckCollision(bx.GetCollider(), direction, 1.0f))
						bx.OnCollision2(direction);

			}
			for (dimon& d : DimonVector) {
				if (d.GetCollider().CheckCollisionItem(player.GetCollider(), direction)) {
					d.pickup();
					score += 5;
					printf("%d", score);
					coinss.play();


				}
			}

			for (dimonfah& df : DimonfahVector) {
				if (df.GetCollider().CheckCollisionItem(player.GetCollider(), direction)) {
					df.pickup();
					score += 10;
					printf("%d", score);
					coinss.play();

				}
			}
			for (dimongreen& dg : DimongreenVector) {
				if (dg.GetCollider().CheckCollisionItem(player.GetCollider(), direction)) {
					dg.pickup();
					score += 20;
					printf("%d", score);
					coinss.play();

				}

			}

			for (friebg& fires : FireVector) {
				if (fires.GetCollider().CheckCollisionItem(player.GetCollider(), direction)) {
					sav = true;
					dead = true;
				}

			}
			for (waterbg& water : WaterVector) {
				if (water.GetCollider().CheckCollisionItem(player.GetCollider(), direction)) {
					sav = true;
					dead = true;
				}

			}

			for (Enemy& enemy : enemyes) {
				if (enemy.GetCollider().CheckCollisionItem(player.GetCollider(), direction)) {
					sav = true;
					dead = true;
				}

			}

			for (enemys& enemyxr : Enemyss) {
				if (enemyxr.GetCollider().CheckCollisionItem(player.GetCollider(), direction)) {
					sav = true;
					dead = true;
				}

			}



			



			// Update ?????? //==================================================================//
			for (int i = 0; i < FireVector.size(); i++)
			{
				FireVector[i].Update(deltaTime, player);
			}
			//==================================================================//

			// Update ??????? //==================================================================//
			for (int i = 0; i < WaterVector.size(); i++)
			{
				WaterVector[i].Update(deltaTime, player);
			}
			//==================================================================//
			// Update ???? //==================================================================//
			for (int i = 0; i < DimonVector.size(); i++)
			{
				DimonVector[i].Update(deltaTime, player);
			}
			//==================================================================//

			// Update ??????? //==================================================================//
			for (int i = 0; i < DimonfahVector.size(); i++)
			{
				DimonfahVector[i].Update(deltaTime, player);
			}
			//==================================================================//

			// Update ????????? //==================================================================//
			for (int i = 0; i < DimongreenVector.size(); i++)
			{
				DimongreenVector[i].Update(deltaTime, player);
			}
			//==================================================================//
			//?????
			for (int i = 0; i < boxVector.size(); i++)
			{
				boxVector[i].Update(deltaTime, player);
			}
			//==================================================================//

			//????
			for (int i = 0; i < buttonVector.size(); i++)
			{
				buttonVector[i].Update(deltaTime, player);
			}
			//==================================================================//

			//???????
			for (int i = 0; i < buttonredVector.size(); i++)
			{
				buttonredVector[i].Update(deltaTime, player);
			}
			//==================================================================//

			//???????????
			for (int i = 0; i < itemVector.size(); i++)
			{
				itemVector[i].Update(deltaTime, player);
			}
			//==================================================================//


			//???????
			for (int i = 0; i < boxitemVector.size(); i++)
			{
				boxitemVector[i].Update(deltaTime, player);
			}
			//==================================================================//

			//???????
			for (int i = 0; i < barrierVector.size(); i++)
			{
				barrierVector[i].Update(deltaTime, player);
			}
			//==================================================================//

			//??????? ???
			for (int i = 0; i < barrieredVector.size(); i++)
			{
				barrieredVector[i].Update(deltaTime, player);
			}
			//==================================================================//





			//==================================================================//
			//hitbox
			/*hitboxPlayer.Update(player.GetPosition(), -12.5f, -3.0f);*/
			//==================================================================//



			
			for (Enemy& enemy : enemyes)
			{
				enemy.update(deltaTime);
				if (bullet1.GetCollider().CheckCollisionItem(enemy.GetCollider(), direction))
				{
					enemy.dead();
					score += 20;
					Bul = 0;
					bullet1.SetPosition();
					bullet1.isAvaliable();
				}
				if (bullet2.GetCollider().CheckCollisionItem(enemy.GetCollider(), direction))
				{
					enemy.dead();
					score += 20;
					Bul2 = 0;
					bullet2.SetPosition();
					bullet2.isAvaliable();
				}
			}
			for (enemys& enemyxr : Enemyss)
			{
				enemyxr.update(deltaTime);
				if (bullet1.GetCollider().CheckCollisionItem(enemyxr.GetCollider(), direction))
				{
					enemyxr.dead();
					score += 20;
					Bul = 0;
					bullet1.SetPosition();
					bullet1.isAvaliable();
				}
				if (bullet2.GetCollider().CheckCollisionItem(enemyxr.GetCollider(), direction))
				{
					enemyxr.dead();
					score += 20;
					Bul2 = 0;
					bullet2.SetPosition();
					bullet2.isAvaliable();
				}
			}
			


			//std::cout << "dir x = " << direction.x << " dir y = " << direction.y << endl;
			//delete this debug view warp cheat button
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
				player.Warped(window);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
				player.Warped2(window);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) {
				player.Warped3(window);
			}

			//set Viw
			if (player.GetPosition().y <= 2000) {
				u = 0;
				view.setCenter(sf::Vector2f(player.GetPosition()));
				if (view.getCenter().x - 540.0f <= 0.0f)//??????? x ?????????? ??????????? 0.0 ?????????? ????
				{
					//view.setCenter(540.f, view.getCenter().y);

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
				if (view.getCenter().x + 540.0f >= 1830.5f)//??????? x 1830.5 ????????????????? ???
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
				if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 1830.5f)//??????? x ????????
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
					sounfires.play();
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
					tunderse.play();
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

			}





			///// viw 02
			if (player.GetPosition().y >= 2005 && player.GetPosition().y < 4000)
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
					sounfires.play();
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
					tunderse.play();
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
					if (view.getCenter().y - 360.0f <= 2015.f + 0.0f)
					{
						view.setCenter(540.0f, 2015.f + 360.0f);//window
					}
					if (view.getCenter().y + 360.0f >= 3358.5f)
					{
						view.setCenter(540.0f, 2998.5f);//window
					}
					if (view.getCenter().y - 360.0f > 2015.f && view.getCenter().y + 360.0f < 3358.5f)
					{
						view.setCenter(540.0f, player.GetPosition().y);
					}

				}
				if (view.getCenter().x + 540.0f >= 1830.5f)
				{
					if (view.getCenter().y - 360.0f <= 2015.f + 0.0f)
					{
						view.setCenter(1290.5f, 2015.f + 360.0f);//window 1248-540 collision right 
					}
					if (view.getCenter().y + 360.0f >= 3358.5f)
					{
						view.setCenter(1290.5f, 2998.5f);//window 1248-540
					}
					if (view.getCenter().y - 360.0f > 2015.0f && view.getCenter().y + 360.0f < 3358.5f)
					{
						view.setCenter(1290.5f, player.GetPosition().y);
					}
				}
				if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 1830.5f)
				{
					if (view.getCenter().y - 360.0f <= 2015.f + 0.0f)
					{
						view.setCenter(player.GetPosition().x, 2015.f + 360.0f);
					}
					if (view.getCenter().y + 360.0f >= 3358.5f)
					{
						view.setCenter(player.GetPosition().x, 2998.5f);
					}
				}
			}





			// viw 03 
			if (player.GetPosition().y >= 4005 && player.GetPosition().y < 6000)
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
					sounfires.play();
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
					tunderse.play();
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
			}
			if (u == 2)
			{
				view.setCenter(sf::Vector2f(player.GetPosition()));
				if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
				{
					if (view.getCenter().y - 360.0f <= 3980.0f)
					{
						view.setCenter(540.0f, 3980.0f + 360.0f);//window
					}
					else if (view.getCenter().y + 360.0f >= 5358.5f)
					{
						view.setCenter(540.0f, 4998.5f);//window
					}
					else if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 5358.5f)
					{
						view.setCenter(540.0f, player.GetPosition().y);
					}

				}
				else if (view.getCenter().x + 540.0f >= 1830.5f)
				{
					if (view.getCenter().y - 360.0f <= 3980.0f)
					{
						view.setCenter(1290.5f, 3980.0f + 360.0f);//window 1248-540 collision right 
					}
					else if (view.getCenter().y + 360.0f >= 5358.5f)
					{
						view.setCenter(1290.5f, 4998.5f);//window 1248-540
					}
					else if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 5358.5f)
					{
						view.setCenter(1290.5f, player.GetPosition().y);
					}
				}
				else if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 1830.5f)
				{
					if (view.getCenter().y - 360.0f <= 3980.0f)
					{
						view.setCenter(player.GetPosition().x, 3980.0f + 360.0f);
					}
					else if (view.getCenter().y + 360.0f >= 5358.5f)
					{
						view.setCenter(player.GetPosition().x, 4998.5f);
					}
				}
			}



			
			// viw 04 
			if (player.GetPosition().y > 6005)
			{
				u = 3;

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
					sounfires.play();
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
					tunderse.play();
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
			}
			if (u == 3)
			{
				view.setCenter(sf::Vector2f(player.GetPosition()));
				if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
				{
					if (view.getCenter().y - 360.0f <= 5945.0f)
					{
						view.setCenter(540.0f, 5945.0f + 360.0f);//window
					}
					else if (view.getCenter().y + 360.0f >= 7358.5f)
					{
						view.setCenter(540.0f, 6998.5f);//window
					}
					else if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 7358.5f)
					{
						view.setCenter(540.0f, player.GetPosition().y);
					}

				}
				else if (view.getCenter().x + 540.0f >= 1830.5f)
				{
					if (view.getCenter().y - 360.0f <= 5945.0f)
					{
						view.setCenter(1290.5f, 5945.0f + 360.0f);//window 1248-540 collision right 
					}
					else if (view.getCenter().y + 360.0f >= 7358.5f)
					{
						view.setCenter(1290.5f, 6998.5f);//window 1248-540
					}
					else if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 7358.5f)
					{
						view.setCenter(1290.5f, player.GetPosition().y);
					}
				}
				else if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 1830.5f)
				{
					if (view.getCenter().y - 360.0f <= 5945.0f)
					{
						view.setCenter(player.GetPosition().x, 5945.0f + 360.0f);
					}
					else if (view.getCenter().y + 360.0f >= 7358.5f)
					{
						view.setCenter(player.GetPosition().x, 6998.5f);
					}
				}
			}





			// Time //==================================================================//

			lbltime.setString(showtime.str());

			showtime.str(" ");
			showtime << " Time  :  ";
			lbltime.setPosition(view.getCenter().x + 200, view.getCenter().y - 360);

			//==================================================================//


			window.clear();

			if (cheeckongame == 0)
			{
				// Menu		
				window.draw(background);
				view.setCenter(background.getPosition());
				menu.draw(window);
				//Stop.draw(window);

			}
			if (cheeckongame == 1)
			{				
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

				//warp3
				if (player.GetCollider().CheckCollision(Collider(waroPoint3), direction, 1.0f))
				{
					player.Warped3(window);

				}window.draw(waroPoint3);

				//window.draw(back01);
				//window.draw(back02);
				//window.draw(back03);
				//window.draw(back04);
				window.setView(view);

				for (Platform& platfrom : platfroms)
					platfrom.Draw(window);


				window.draw(back01);
				window.draw(back02);
				window.draw(back03);
				window.draw(back04);

				
				
				//??????
				for (int i = 0; i < FireVector.size(); i++)
				{
					FireVector[i].draw(window);
				}
				//???????
				for (int i = 0; i < WaterVector.size(); i++)
				{
					WaterVector[i].draw(window);
				}
				//????
				for (int i = 0; i < DimonVector.size(); i++)
				{
					DimonVector[i].draw(window);
				}

				//???????
				for (int i = 0; i < DimonfahVector.size(); i++)
				{
					DimonfahVector[i].draw(window);
				}

				//?????????
				for (int i = 0; i < DimongreenVector.size(); i++)
				{
					DimongreenVector[i].draw(window);
				}
				for (int i = 0; i < boxVector.size(); i++)
				{
					boxVector[i].draw(window);
				}

				//?????
				
				/*
				//????
				for (int i = 0; i < buttonVector.size(); i++)
				{
					buttonVector[i].draw(window);
				}
				
				//???????
				for (int i = 0; i < buttonredVector.size(); i++)
				{
					buttonredVector[i].draw(window);
				}/*
				// ??????????
				/*for (int i = 0; i < itemVector.size(); i++)
				{
					itemVector[i].draw(window);
				}

				// ??????? barrierVector
				for (int i = 0; i < boxitemVector.size(); i++)
				{
					boxitemVector[i].draw(window);
				}
				
				// ??????? 
				for (int i = 0; i < barrierVector.size(); i++)
				{
					barrierVector[i].draw(window);
				}

				// ??????????
				for (int i = 0; i < barrieredVector.size(); i++)
				{
					barrieredVector[i].draw(window);
				}
				*/

				//==================================================================//





				//==================================================================//
				//player.backe
				bar.setPosition(sf::Vector2f(view.getCenter().x - 430, view.getCenter().y - 380));
				bar.setTexture(&cobe);
				
				window.draw(bar);
				coolspeed.Draw(window);
				window.draw(cooldownfire);
				window.draw(cooldownspark);
				player.backe(window, sf::Vector2f(view.getCenter().x - 375, view.getCenter().y - 300));
				//printf("%.2f", cooldown);
				//player
				player.Draw(window);
				for (Enemy& enemy : enemyes)
				{
					enemy.draw(window);
				}
				for (enemys& enemyxr : Enemyss)
				{
					enemyxr.draw(window);
				}
				//heartt
				heartt.setPosition(player.GetPosition().x - 50, player.GetPosition().y - 60);
				//window.draw(heartt);

				//manaa
				manaa.setPosition(player.GetPosition().x - 50, player.GetPosition().y + 40);
				//window.draw(manaa);

				boss.draw(window);
				bulletboss.draw(window);
				//time
				showScore.setString("score : " + std::to_string(score));
				showScore.setPosition(view.getCenter().x + 300, view.getCenter().y - 300);
				
				window.draw(lbltime);
				window.draw(showScore);

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
					bullet1.SetPosition();
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
					bullet2.SetPosition();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				{
					sav = true;
					pause = true;
				}
			}

			window.display();
		}
		while (pause == true && dead == false)
		{
			
			sf::Text paused("Paused", font, 30);
			sf::Text resume("Resume", font, 30);
			sf::Text exit("Exit", font, 30);			

			window.clear();
			window.setView(view);

			view.setCenter(sf::Vector2f(-1000.0f, 1800.0f));
			pauses.setOrigin(pauses.getSize() / 2.0f);
			pauses.setPosition(view.getCenter());
			paused.setPosition(view.getCenter().x - 380, view.getCenter().y - 200.0f);
			resume.setPosition(view.getCenter().x - 380, view.getCenter().y + 10.0f);
			exit.setPosition(view.getCenter().x - 380, view.getCenter().y +100.0f);

			if (pselect == 0)
			{
				resume.setFillColor(sf::Color::Red);
				exit.setFillColor(sf::Color::White);
			}
			if (pselect == 1)
			{
				exit.setFillColor(sf::Color::Red);
				resume.setFillColor(sf::Color::White);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				pselect = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				pselect = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && pselect == 0)
			{
				pause = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && pselect == 1)
			{				
				int x1, x2, x3, x4, x5;
				//---------1------------
				ifstream i1;
				i1.open("score1.txt");
				i1 >> x1;
				//---------2------------
				ifstream i2;
				i2.open("score2.txt");
				i2 >> x2;
				//---------3------------
				ifstream i3;
				i3.open("score3.txt");
				i3 >> x3;
				//---------4------------
				ifstream i4;
				i4.open("score4.txt");
				i4 >> x4;
				//---------5------------
				ifstream i5;
				i5.open("score5.txt");
				i5 >> x5;

				if (sav == true)
				{
					if (score > x1)
					{
						//---------5--------------
						ofstream s5;
						s5.open("score5.txt");
						s5 << x4 << endl;
						s5.close();
						//---------4--------------
						ofstream s4;
						s4.open("score4.txt");
						s4 << x3 << endl;
						s4.close();
						//---------3--------------
						ofstream s3;
						s3.open("score3.txt");
						s3 << x2 << endl;
						s3.close();
						//---------2--------------
						ofstream s2;
						s2.open("score2.txt");
						s2 << x1 << endl;
						s2.close();
						//---------1--------------
						ofstream s1;
						s1.open("score1.txt");
						s1 << score << endl;
						s1.close();
						goto SAVED2;
					}
					if (score > x2 && score <= x1)
					{
						//---------5--------------
						ofstream s5;
						s5.open("score5.txt");
						s5 << x4 << endl;
						s5.close();
						//---------4--------------
						ofstream s4;
						s4.open("score4.txt");
						s4 << x3 << endl;
						s4.close();
						//---------3--------------
						ofstream s3;
						s3.open("score3.txt");
						s3 << x2 << endl;
						s3.close();
						//---------2--------------
						ofstream s2;
						s2.open("score2.txt");
						s2 << score << endl;
						s2.close();
						goto SAVED2;
					}
					if (score > x3 && score <= x2)
					{
						//---------5-------------- 
						ofstream s5;
						s5.open("score5.txt");
						s5 << x4 << endl;
						s5.close();
						//---------4--------------
						ofstream s4;
						s4.open("score4.txt");
						s4 << x3 << endl;
						s4.close();
						//---------3--------------
						ofstream s3;
						s3.open("score3.txt");
						s3 << score << endl;
						s3.close();
						goto SAVED2;
					}
					if (score > x4 && score <= x3)
					{
						//---------5--------------
						ofstream s5;
						s5.open("score5.txt");
						s5 << x4 << endl;
						s5.close();
						//---------4--------------
						ofstream s4;
						s4.open("score4.txt");
						s4 << score << endl;
						s4.close();
						goto SAVED2;
					}
					if (score > x5 && score <= x4)
					{
						//---------5--------------
						ofstream s5;
						s5.open("score5.txt");
						s5 << score << endl;
						s5.close();
						goto SAVED2;
					}
				}
			SAVED2:
				sav = false;
				std::cout << score << " " << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << std::endl;
				score = 0;
				boss.re();
				bos = 0.0f;
				bulletboss.SetPosition();
				for (Enemy& enemy : enemyes)
				{
					enemy.re();
				}
					for (enemys& enemyxr : Enemyss)
					{
						enemyxr.re();
					}
				for (box& bx : boxVector) {
					bx.re();
				}
				for (dimon& d : DimonVector) {
					d.re();
				}
				for (dimonfah& df : DimonfahVector) {
					df.re();
				}
				for (dimongreen& dg : DimongreenVector) {
					dg.re();
				}
				bullet1.SetPosition();
				bullet2.SetPosition();
				Bul = 0;
				Bul2 = 0;
				player.setPosition(91.0f, 1218.0f);
				cheeckongame = 0;
				pause = false;
				menup = true;
			}
			window.draw(pauses);
			window.draw(resume);
			window.draw(exit);
			window.draw(paused);
			window.display();
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					std::cout << "Width: " << evnt.size.width << "Height: " << evnt.size.height << std::endl;
					break;
				}
			}
		}
		while (dead == true)
		{
			if (checksound == false)
			{
				gameovers.play();
				checksound = true;
			}
			sf::Text paused("You Dead", font, 30);
			sf::Text resume("Continue", font, 30);
			sf::Text exit("Exit", font, 30);

			window.clear();
			window.setView(view);
			
			view.setCenter(sf::Vector2f(-1000.0f, 1800.0f));
			pauses.setOrigin(pauses.getSize() / 2.0f);
			pauses.setPosition(view.getCenter());
			paused.setPosition(view.getCenter().x - 380, view.getCenter().y - 200.0f);
			resume.setPosition(view.getCenter().x - 380, view.getCenter().y + 10.0f);
			exit.setPosition(view.getCenter().x - 380, view.getCenter().y + 100.0f);

			int x1, x2, x3, x4, x5;
			//---------1------------
			ifstream i1;
			i1.open("score1.txt");
			i1 >> x1;
			//---------2------------
			ifstream i2;
			i2.open("score2.txt");
			i2 >> x2;
			//---------3------------
			ifstream i3;
			i3.open("score3.txt");
			i3 >> x3;
			//---------4------------
			ifstream i4;
			i4.open("score4.txt");
			i4 >> x4;
			//---------5------------
			ifstream i5;
			i5.open("score5.txt");
			i5 >> x5;

			if (sav == true)
			{
				if (score > x1)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << x4 << endl;
					s5.close();
					//---------4--------------
					ofstream s4;
					s4.open("score4.txt");
					s4 << x3 << endl;
					s4.close();
					//---------3--------------
					ofstream s3;
					s3.open("score3.txt");
					s3 << x2 << endl;
					s3.close();
					//---------2--------------
					ofstream s2;
					s2.open("score2.txt");
					s2 << x1 << endl;
					s2.close();
					//---------1--------------
					ofstream s1;
					s1.open("score1.txt");
					s1 << score << endl;
					s1.close();
					goto SAVED;
				}
				if (score > x2 && score <= x1)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << x4 << endl;
					s5.close();
					//---------4--------------
					ofstream s4;
					s4.open("score4.txt");
					s4 << x3 << endl;
					s4.close();
					//---------3--------------
					ofstream s3;
					s3.open("score3.txt");
					s3 << x2 << endl;
					s3.close();
					//---------2--------------
					ofstream s2;
					s2.open("score2.txt");
					s2 << score << endl;
					s2.close();
					goto SAVED;
				}
				if (score > x3 && score <= x2)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << x4 << endl;
					s5.close();
					//---------4--------------
					ofstream s4;
					s4.open("score4.txt");
					s4 << x3 << endl;
					s4.close();
					//---------3--------------
					ofstream s3;
					s3.open("score3.txt");
					s3 << score << endl;
					s3.close();
					goto SAVED;
				}
				if (score > x4 && score <= x3)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << x4 << endl;
					s5.close();
					//---------4--------------
					ofstream s4;
					s4.open("score4.txt");
					s4 << score << endl;
					s4.close();
					goto SAVED;
				}
				if (score > x5 && score <= x4)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << score << endl;
					s5.close();
					goto SAVED;
				}
			}
		SAVED:
			sav = false;
			std::cout << score << " " << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << std::endl;
			player.setPosition(91.0f, 1218.0f);
			if (dselect == 0)
			{
				resume.setFillColor(sf::Color::Red);
				exit.setFillColor(sf::Color::White);
			}
			if (dselect == 1)
			{
				exit.setFillColor(sf::Color::Red);
				resume.setFillColor(sf::Color::White);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				dselect = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				dselect = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && dselect == 0)
			{
				pause = false;
				dead = false;
				menup = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && dselect == 1)
			{
				pause = false;				
				dead = false;
				menup = true;
			}
			score = 0;
			boss.re();
			bos = 0.0f;
			bulletboss.SetPosition();
			for (enemys& enemyxr : Enemyss)
			{
				enemyxr.re();
			}

			for (Enemy& enemy : enemyes)
			{
				enemy.re();
			}
			for (box& bx : boxVector) {
				bx.re();
			}
			for (dimon& d : DimonVector) {
				d.re();
			}
			for (dimonfah& df : DimonfahVector) {
				df.re();
			}
			for (dimongreen& dg : DimongreenVector) {
				dg.re();
			}
			bullet1.SetPosition();
			bullet2.SetPosition();
			Bul = 0;
			Bul2 = 0;

			window.draw(pauses);
			window.draw(resume);
			window.draw(exit);
			window.draw(paused);
		
			window.display();
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					std::cout << "Width: " << evnt.size.width << "Height: " << evnt.size.height << std::endl;
					break;
				}
			}
		}
		while (end == true)
		{
			if (checksound1 == false)
			{
				worldclears.play();
				checksound1 = true;
			}
			
			sf::Text paused("", font, 30);
			sf::Text resume("", font, 30);

			window.clear();
			window.setView(view);
			
			view.setCenter(sf::Vector2f(-1000.0f, 1800.0f));
			endgames.setPosition(view.getCenter());
			paused.setPosition(view.getCenter().x - 50, view.getCenter().y - 300.0f);
			resume.setPosition(view.getCenter().x - 50, view.getCenter().y + 200.0f);

			int x1, x2, x3, x4, x5;
			//---------1------------
			ifstream i1;
			i1.open("score1.txt");
			i1 >> x1;
			//---------2------------
			ifstream i2;
			i2.open("score2.txt");
			i2 >> x2;
			//---------3------------
			ifstream i3;
			i3.open("score3.txt");
			i3 >> x3;
			//---------4------------
			ifstream i4;
			i4.open("score4.txt");
			i4 >> x4;
			//---------5------------
			ifstream i5;
			i5.open("score5.txt");
			i5 >> x5;

			if (sav == true)
			{
				if (score > x1)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << x4 << endl;
					s5.close();
					//---------4--------------
					ofstream s4;
					s4.open("score4.txt");
					s4 << x3 << endl;
					s4.close();
					//---------3--------------
					ofstream s3;
					s3.open("score3.txt");
					s3 << x2 << endl;
					s3.close();
					//---------2--------------
					ofstream s2;
					s2.open("score2.txt");
					s2 << x1 << endl;
					s2.close();
					//---------1--------------
					ofstream s1;
					s1.open("score1.txt");
					s1 << score << endl;
					s1.close();
					goto SAVED1;
				}
				if (score > x2 && score <= x1)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << x4 << endl;
					s5.close();
					//---------4--------------
					ofstream s4;
					s4.open("score4.txt");
					s4 << x3 << endl;
					s4.close();
					//---------3--------------
					ofstream s3;
					s3.open("score3.txt");
					s3 << x2 << endl;
					s3.close();
					//---------2--------------
					ofstream s2;
					s2.open("score2.txt");
					s2 << score << endl;
					s2.close();
					goto SAVED1;
				}
				if (score > x3 && score <= x2)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << x4 << endl;
					s5.close();
					//---------4--------------
					ofstream s4;
					s4.open("score4.txt");
					s4 << x3 << endl;
					s4.close();
					//---------3--------------
					ofstream s3;
					s3.open("score3.txt");
					s3 << score << endl;
					s3.close();
					goto SAVED1;
				}
				if (score > x4 && score <= x3)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << x4 << endl;
					s5.close();
					//---------4--------------
					ofstream s4;
					s4.open("score4.txt");
					s4 << score << endl;
					s4.close();
					goto SAVED1;
				}
				if (score > x5 && score <= x4)
				{
					//---------5--------------
					ofstream s5;
					s5.open("score5.txt");
					s5 << score << endl;
					s5.close();
					goto SAVED1;
				}
			}
		SAVED1:
			sav = false;
			std::cout << score << " " << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << std::endl;
			player.setPosition(91.0f, 1218.0f);
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				pause = false;
				dead = false;
				end = false;
				menup = true;
			}
			score = 0;
			boss.re();
			bos = 0.0f;
			bulletboss.SetPosition();
			for (enemys& enemyxr : Enemyss)
			{
				enemyxr.re();
			}

			for (Enemy& enemy : enemyes)
			{
				enemy.re();
			}
			for (box& bx : boxVector) {
				bx.re();
			}
			for (dimon& d : DimonVector) {
				d.re();
			}
			for (dimonfah& df : DimonfahVector) {
				df.re();
			}
			for (dimongreen& dg : DimongreenVector) {
				dg.re();
			}
			bullet1.SetPosition();
			bullet2.SetPosition();
			Bul = 0;
			Bul2 = 0;

			window.draw(endgames);
			window.draw(resume);
			window.draw(paused);

			window.display();
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					std::cout << "Width: " << evnt.size.width << "Height: " << evnt.size.height << std::endl;
					break;
				}
			}
		}
		std::cout << score << std::endl;
	}
}
