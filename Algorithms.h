#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include "Visualiser.h"
#include "sidebar.h"

extern bool sorting;
extern int arraySize;
extern int arrayWrites;
extern int comparisons;
extern int delay;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void drawVis(Visualiser* visPtr,sf::RenderWindow* window, sf::RectangleShape* background, sf::RectangleShape* whiteBackground,sidebar* bar) {
	window->clear();

	window->draw(*background);
	window->draw(*whiteBackground);
	bar->draw(window);
	visPtr->draw(window);

	window->display();
}


void bubblesort(std::array<int, 100>& arr, Visualiser* visPtr, sf::RenderWindow* window,
	sf::RectangleShape* background, sf::RectangleShape* whiteBackground, sidebar* bar) {

	ConsoleLogger::log("Status: Sorting with delay "+std::to_string(delay)+"ms....", 0);
	static sf::Clock clock;
	sorting = true;

	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				arrayWrites++;
				drawVis(visPtr, window, background, whiteBackground, bar);
				while (clock.getElapsedTime().asMilliseconds()<delay) {
					continue;
				}
				clock.restart();
				swap(&arr[j], &arr[j + 1]);
			}
			comparisons++;
		}
	}
	ConsoleLogger::log("Status: Sorted.",0);
	sorting = false;
}

void mergesort() {
	static sf::Clock clock;
	ConsoleLogger::log("'mergesort' not yet implemented",2);
}

void quicksort() {
	static sf::Clock clock;
	ConsoleLogger::log("'quicksort' not yet implemented", 2);
}