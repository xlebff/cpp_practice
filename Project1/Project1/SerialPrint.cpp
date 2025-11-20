#include "SerialPrint.h"

using namespace std;

void SerialPrint::serialPrint(const string& msg, int delay) {
	for (const char& c : msg) {
		cout << c;
		sleep(delay);
	}
}

void SerialPrint::serialPrint(const char* msg, int delay) {
	for (size_t i = 0; i < strlen(msg); ++i) {
		cout << msg[i];
		sleep(delay);
	}
}

void SerialPrint::serialPrintln(const string& msg, int delay) {
	for (const char& c : msg) {
		cout << c;
		sleep(delay);
	}

	cout << endl;
}

void SerialPrint::serialPrintln(const char* msg, int delay) {
	for (size_t i = 0; i < strlen(msg); ++i) {
		cout << msg[i];
		sleep(delay);
	}

	cout << endl;
}