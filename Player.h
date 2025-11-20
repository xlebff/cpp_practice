#pragma once

class Player {
public:
	static Player* getInstance();
	void completeGame();

private:
	static Player* instance;
	Player();
};
