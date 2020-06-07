#pragma once
#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <SFML\Graphics.hpp>
#include "ConsoleLogger.h"

extern int arraySize;
extern int arrayWrites;
extern int comparisons;
extern int delay;

class Visualiser
{
public:
	std::array<int, 100> mainArray;
	sf::RectangleShape visRect[100];

	Visualiser() {
		for (int i = 0;i < 100;i++) {
			mainArray[i] = i;
			visRect[i].setFillColor(sf::Color(100, 100, 255));
		}

		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

		shuffle(mainArray.begin(), mainArray.end(), std::default_random_engine(seed));

		for (int i = 0;i < 100;i++) {
			ConsoleLogger::log("mainArray["+std::to_string(i)+"] = "+std::to_string(mainArray[i]),0);
		}

		arraySize = mainArray.size();
		arrayWrites = 0;
		comparisons = 0;
	}


	void draw(sf::RenderWindow* window) {
		for (int i = 0;i < 100;i++) {
			visRect[i].setSize(sf::Vector2f(9, 7.25*mainArray[i]));
			visRect[i].setPosition(10.25 * i, 720);
			visRect[i].setOrigin(0, 7.25*mainArray[i]);
			window->draw(visRect[i]);
		}
	}
};

