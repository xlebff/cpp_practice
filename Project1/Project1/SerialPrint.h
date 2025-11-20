#pragma once
#include <iostream>
#include <cstring>

/* #define LINUX */

#ifndef WINDOWS || LINUX
#define WINDOWS
#endif

#ifdef WINDOWS
	#include <windows.h>
	#define sleep(seconds) Sleep((seconds))
#else
	#include <unistd.h>
	#define sleep(seconds) Sleep((seconds) / 1000)
#endif

namespace SerialPrint {
	void serialPrint(const std::string& msg, int delay = 25);
	void serialPrint(const char* msg, int delay = 25);

	void serialPrintln(const std::string& msg, int delay = 25);
	void serialPrintln(const char* msg, int delay = 25);
}
