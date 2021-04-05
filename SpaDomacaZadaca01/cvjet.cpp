#include "cvjet.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>






Cvjet::Cvjet(sf::RenderWindow  &window)
{
	
	color.r = 255;
	color.b = 0;
	color.g = 0;
	
	if (i > 10 || i < 0)
	{
		i = 0;
	}
	std::cout << "i:"<<i << std::endl;
	 stabljika.setSize(sf::Vector2f(120.f, 5.f));
	 tucak.setRadius(30.f);
	 list.setPointCount(4);
	 list.setRadius(80.f);
		latice.resize(5, sf::CircleShape(25));
		for (int i = 0;i < 5;i++)
		{
			latice.at(i).setOrigin(10, 10);

			latice.at(i).setFillColor(sf::Color::Red);
		}
		latice.at(0).setPosition(385, 420);
		latice.at(1).setPosition(415, 400);
		latice.at(2).setPosition(405, 370);
		latice.at(3).setPosition(370, 370);
		latice.at(4).setPosition(360, 400);

		;


		stabljika.setFillColor(sf::Color::Green);
		stabljika.setPosition(400, 450);
		stabljika.setRotation(90);

		list.setFillColor(sf::Color::Green);
		list.setScale(sf::Vector2f(0.2, 0.8));
		list.setPosition(405.f, 525);
		list.setRotation(-120);

		tucak.setFillColor(sf::Color::Yellow);
		tucak.setOrigin(15, 15);
		tucak.setPosition(385, 390);

	

}



void Cvjet::anim(sf::Clock &clock)
{
	std::cout << clock.getElapsedTime().asSeconds() << std::endl;
	
	
	
		if (i == 0)
		{
			srand(time(nullptr));
			color.r = rand() % 255;
			color.b = rand() % 255;
			color.g = rand() % 255;
		}
		
		
			if (clock.getElapsedTime().asSeconds() >= 5)
			{
				ran = !ran;
				clock.restart();
				std::cout << "5s \n";
				

			}
		
		

			if (!ran)
			{
				if (i < 5)
				{

					if (clock.getElapsedTime().asSeconds() >= 0.75f)
					{
						std::cout << "kita";
						latice.at(i).setFillColor(color);
						clock.restart();
						i++;

					}
				}

			}


		
		



		

		if (i == 5)
		{
			i = 0;

			clock.restart();
			ran = true;

		}

	}
	
		

	
	



sf::CircleShape Cvjet::get_tucak() const
{
	return tucak;
}

sf::RectangleShape Cvjet::get_stabljika() const
{
	return stabljika;
}

std::vector<sf::CircleShape> Cvjet::get_latice() const
{
	return latice;
}

sf::CircleShape Cvjet::get_list() const
{
	return list;
}



void Cvjet::set_tucak(sf::CircleShape tucak)
{
	this->tucak = tucak;
}

void Cvjet::set_stabljuka(sf::RectangleShape stabljika)
{
	this->stabljika = stabljika;
}

void Cvjet::set_list(sf::CircleShape list)
{
	this->list = list;
}

void Cvjet::set_latica(sf::CircleShape latica, int i)
{
	this->latice.at(i) = latica;
}

bool Cvjet::get_ran() const
{
	return ran;
}



void Cvjet::set_ran(const bool ran)
{
	this->ran = ran;
}







