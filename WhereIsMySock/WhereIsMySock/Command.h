#pragma once

class Command {
public:
	void execute();
	void cancel();
	const char* getName();

private:
	const char* name;
};