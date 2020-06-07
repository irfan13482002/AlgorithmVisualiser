#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

extern bool bLog;
static HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

class ConsoleLogger
{
private:
	ConsoleLogger() {
	}

public:
	static void log(std::string message, int logLevel) {
		if (bLog == true) {
			switch (logLevel) {
			case 0:
				SetConsoleTextAttribute(out, 0x8 | 0x0);
				std::cout << "[MESSAGE]: " << message << std::endl;
				break;
			case 1:
				SetConsoleTextAttribute(out, 0x6 | 0x6);
				std::cout << "[WARNING]: " << message << std::endl;
				break;
			case 2:
				SetConsoleTextAttribute(out, 0x4 | 0x4);
				std::cout << "[ERROR]: " << message << std::endl;
				break;
			}
		}
	}

	static void log() {
		std::cout<<std::endl;
	}
};
