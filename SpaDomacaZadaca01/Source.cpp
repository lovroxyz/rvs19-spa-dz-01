#include <SFML/Graphics.hpp>
#include "cvjet.h"
#include <vector>
#include <iostream>


int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvjet cvijet(window);
	cvijet.set_ran(false);
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		
		
		cvijet.anim(clock);
		std::cout << clock.getElapsedTime().asSeconds() <<"||"<<"\n";
		
	
		window.clear();
	
		
		
		
			
		
		window.draw(cvijet.get_stabljika());
		for (int i = 0;i < 5;i++)
		{
			window.draw(cvijet.get_latice().at(i));
		}
		window.draw(cvijet.get_list());
		window.draw(cvijet.get_tucak());
	
		window.display();
	}

	return 0;
}
