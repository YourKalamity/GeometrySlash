#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <raylib.h>
#include <string>

#include "globals.h"
#include "gamestate.h"
#include "button.h"

class Leaderboard: public GameState
{
private:
	std::string csv;

	//IMGUI Variables

	Button* MainMenuButton;
	Button* PlayAgainButton;
	Button* BackButton;
	Button* PrevPageButton;
	Button* NextPageButton;
	Rectangle Backboard;
	Rectangle PlayerBackboard;
	Rectangle Vline1;
	Rectangle Vline2;

public:
	void logic(void) final override;
	void render(void) final override;
	Leaderboard(void);
	~Leaderboard(void);
};

#endif
