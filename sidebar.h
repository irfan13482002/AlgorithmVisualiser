#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "ConsoleLogger.h"

extern int arraySize;
extern int arrayWrites;
extern int comparisons;
extern bool sorting;
extern int delay;

class sidebar
{
public:
	int selected;

	sf::Text selectedName;
	sf::Text rightIcon;
	sf::Text leftIcon;
	sf::Text rightIconD;
	sf::Text leftIconD;
	sf::Text visText;
	sf::Text RestartText;
	sf::Text delayText;
	sf::Text delayTimeText;
	sf::Text stats[4];

	sf::Font font;

	sf::RectangleShape restartButton;
	sf::RectangleShape visButton;
	sf::RectangleShape blackBack;
	sf::RectangleShape blackBackD;

	sf::RectangleShape buttonRight;
	sf::RectangleShape buttonLeft;

	sf::RectangleShape buttonRightDelay;
	sf::RectangleShape buttonLeftDelay;

	enum algorithms {
		bubble,merge,quick
	};

public:

	sidebar() {
		//text init
		if (font.loadFromFile("msyi.ttf")) {
			ConsoleLogger::log("Successfully loaded 'msyi.ttf'",0);
		}
		else
		{
			ConsoleLogger::log("Failed to Load 'msyi.ttf'", 2);
		}

		for (int i=0;i<4;i++)
		{
			stats[i].setFont(font);
			stats[i].setPosition(1060, 350+(40*i));
		}
		stats[0].setCharacterSize(18);
		stats[0].setPosition(1130, 360);

		rightIcon.setString("->");
		rightIcon.setFont(font);
		rightIcon.setCharacterSize(12);
		rightIcon.setPosition(1260, 42);

		leftIcon.setString("<-");
		leftIcon.setFont(font);
		leftIcon.setCharacterSize(12);
		leftIcon.setPosition(1050, 42);

		rightIconD.setString("->");
		rightIconD.setFont(font);
		rightIconD.setCharacterSize(12);
		rightIconD.setPosition(1260, 106);

		leftIconD.setString("<-");
		leftIconD.setFont(font);
		leftIconD.setCharacterSize(12);
		leftIconD.setPosition(1160, 106);

		visText.setString("Run");
		visText.setFont(font);
		visText.setPosition(1135,640);

		RestartText.setString("Reinit");
		RestartText.setFont(font);
		RestartText.setPosition(1130,550);

		delayText.setString("Delay(ms):");
		delayText.setFont(font);
		delayText.setPosition(1050, 100);
		delayText.setCharacterSize(20);

		selectedName.setFont(font);
		selectedName.setCharacterSize(18);
		selectedName.setPosition(1120, 36);

		delayTimeText.setFont(font);
		delayTimeText.setCharacterSize(18);
		delayTimeText.setPosition(1210, 100);

		//other init
		selected = 0;

		visButton.setSize(sf::Vector2f(192,64));
		visButton.setFillColor(sf::Color(100, 100, 100));
		visButton.setPosition(1060,630);

		restartButton.setSize(sf::Vector2f(192, 64));
		restartButton.setFillColor(sf::Color(100, 100, 100));
		restartButton.setPosition(1060, 540);

		blackBack.setSize(sf::Vector2f(192, 32));
		blackBack.setFillColor(sf::Color(20,20,20));
		blackBack.setPosition(1060, 36);

		blackBackD.setSize(sf::Vector2f(70, 32));
		blackBackD.setFillColor(sf::Color(20, 20, 20));
		blackBackD.setPosition(1180, 100);

		buttonLeft.setSize(sf::Vector2f(32,32));
		buttonRight.setSize(sf::Vector2f(32, 32));
		buttonLeft.setFillColor(sf::Color(100, 100, 100));
		buttonRight.setFillColor(sf::Color(100, 100, 100));

		buttonLeft.setPosition(1040,36);
		buttonRight.setPosition(1250, 36);

		buttonLeftDelay.setSize(sf::Vector2f(32, 32));
		buttonRightDelay.setSize(sf::Vector2f(32, 32));
		buttonLeftDelay.setFillColor(sf::Color(100, 100, 100));
		buttonRightDelay.setFillColor(sf::Color(100, 100, 100));

		buttonLeftDelay.setPosition(1150, 100);
		buttonRightDelay.setPosition(1250, 100);
	}

	void rightButton() {
		if (!sorting) {
			if (selected < 2) {
				selected++;
				getSelectedName();
				ConsoleLogger::log("selected = " + std::to_string(selected) + "[" + selectedName.getString() + "]", 0);
			}
		}
	}

	void leftButton() {
		if (!sorting) {
			if (selected > 0) {
				selected--;
				getSelectedName();
				ConsoleLogger::log("selected = " + std::to_string(selected) + "[" + selectedName.getString() + "]", 0);
			}
		}
	}

	void getSelectedName() {
		switch (selected) {
		case 0:
			selectedName.setString("Bubble Sort");
			break;
		case 1:
			selectedName.setString("Merge Sort");
			break;
		case 2:
			selectedName.setString("Quick Sort");
			break;
		}
		delayTimeText.setString(std::to_string(delay));
		stats[0].setString("Statistics:");
		stats[1].setString("Array Size: " + std::to_string(arraySize));
		stats[2].setString("Array Writes: " + std::to_string(arrayWrites));
		stats[3].setString("Comparisons: " + std::to_string(comparisons));
	}

	void draw(sf::RenderWindow* window) {
		getSelectedName();
		window->draw(blackBackD);
		window->draw(blackBack);
		window->draw(selectedName);
		window->draw(restartButton);
		window->draw(visButton);
		window->draw(buttonLeft);
		window->draw(buttonRight);
		window->draw(buttonRightDelay);
		window->draw(buttonLeftDelay);
		window->draw(rightIcon);
		window->draw(leftIcon);
		window->draw(rightIconD);
		window->draw(leftIconD);
		window->draw(visText);
		window->draw(RestartText);
		window->draw(delayText);
		window->draw(delayTimeText);
		for (int i = 0;i < 4;i++) {
			window->draw(stats[i]);
		}
	}
};

