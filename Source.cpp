#include <iostream>
#include <SFML\Graphics.hpp>
#include "sidebar.h"
#include "ConsoleLogger.h"
#include "Visualiser.h"
#include "Algorithms.h"

bool bLog = true;
bool sorting = false;
int arraySize;
int arrayWrites;
int comparisons;
int delay;

int main() {

	delay = 0;
	sorting = false;

	//console test
	SetConsoleTitle("Debug Console");
	if (bLog) {
		std::cout << "----------Test----------" << std::endl;
		ConsoleLogger::log("Message Test", 0);
		ConsoleLogger::log("Warning Test", 1);
		ConsoleLogger::log("Error Test", 2);
		std::cout << "------------------------" << std::endl;
		ConsoleLogger::log();
	}
	//class instances
	sf::RenderWindow window(sf::VideoMode(1280,720),"Algorithm Visualiser");
	sf::RectangleShape background;
	sf::RectangleShape whiteBackground;
	sidebar bar;
	Visualiser vis;

	background.setFillColor(sf::Color(50,50,50));
	whiteBackground.setFillColor(sf::Color(200,200,200));

	ConsoleLogger::log("Window Initialised",0);

	//main loop
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {

			//events
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				window.setSize(sf::Vector2u(1280, 720));
				break;

			case sf::Event::MouseButtonPressed:
				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				if ((bar.buttonLeft.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					ConsoleLogger::log("'buttonLeft' Clicked", 0);
					bar.leftButton();
				}
				else if ((bar.buttonRight.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					ConsoleLogger::log("'buttonRight' Clicked", 0);
					bar.rightButton();
				}
				else if ((bar.restartButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					ConsoleLogger::log("'Reinit' Clicked",0);
					window.close();
					main();
				}
				else if ((bar.visButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					ConsoleLogger::log("'Visualised' Clicked", 0);
					if (!sorting) {
						switch (bar.selected)
						{
						case 0:
							bubblesort(vis.mainArray,&vis,&window,&background,&whiteBackground,&bar);
							break;
						case 1:
							mergesort();
							break;
						case 2:
							quicksort();
							break;
						}
					}
				}
				else if ((bar.buttonRightDelay.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					ConsoleLogger::log("'buttonRightDelay' Clicked", 0);
					delay++;
					ConsoleLogger::log("delay = " + std::to_string(delay), 0);
				}
				else if ((bar.buttonLeftDelay.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					ConsoleLogger::log("'buttonLeftDelay' Clicked", 0);
					if (delay>0) {
						delay--;
						ConsoleLogger::log("delay = " + std::to_string(delay), 0);
					}
					else {
						ConsoleLogger::log("delay cannot be less than 0!!", 1);
					}
				}
				break;
			}
		}

		//background colors
		background.setSize(sf::Vector2f(window.getSize().x*2, window.getSize().y*2));
		whiteBackground.setSize(sf::Vector2f(window.getSize().x*.8, window.getSize().y));


		//rendering
		window.clear();

		window.draw(background);
		window.draw(whiteBackground);
		bar.draw(&window);
		vis.draw(&window);

		window.display();
	}
}