#include "SerialPrint.h"

using namespace std;

void SerialPrint::serialPrint(const string& msg, int delay) {
	for (const char& c : msg) {
		cout << c;
		if (c == ',' ||
			c == '.' ||
			c == '\n' ||
			c == '?' ||
			c == '!')
			sleep(delay * 10);
		else sleep(delay);
	}
}

void SerialPrint::serialPrint(const char* msg, int delay) {
	for (size_t i = 0; i < strlen(msg); ++i) {
		cout << msg[i];
		if (msg[i] == ',' ||
			msg[i] == '.' ||
			msg[i] == '\n' ||
			msg[i] == '?' ||
			msg[i] == '!')
			sleep(delay * 10);
		else sleep(delay);
	}
}

void SerialPrint::serialPrintln(const string& msg, int delay) {
	serialPrint(msg, delay);
	cout << endl;
}

void SerialPrint::serialPrintln(const char* msg, int delay) {
	serialPrint(msg, delay);
	cout << endl;
}

void SerialPrint::setColor(const string& color) { cout << color; }

void SerialPrint::resetColor() { cout << "\033[0m"; }