#include "ingame.h"
#include "globals.h"

void InGame::logic(void)
{
}

void InGame::render(void)
{
	DrawBoard();
}




void InGame::DrawBoard(void)
{
	constexpr int gridHeight = 48*7 + 6*8;
	constexpr int gridWidth = 48*7 + 6*8;
	int gridOffsetX = GetScreenWidth()/2 - gridWidth/2;
	int gridOffsetY = GetScreenHeight()/2 - gridHeight/2;
	board.bounds.x = gridOffsetX;
	board.bounds.y = gridOffsetY;
	board.bounds.height = gridHeight;
	board.bounds.width = gridWidth;
	DrawRectangleLinesEx(board.bounds, 4.0f, BLACK);
	Rectangle TextureBounds;
	TextureBounds.height = 32;
	TextureBounds.width = 32;
	Rectangle TileDest;
	TileDest.width = 48;
	TileDest.height = 48;

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			TextureBounds.x = 32 * static_cast<int>(board.cells[i][j].color);
			TextureBounds.y = 32 * static_cast<int>(board.cells[i][j].shape);
			TileDest.x = gridOffsetX + 6*(i+1) + 48*i;
			TileDest.y = gridOffsetY + 6*(j+1) + 48*j;
			DrawTexturePro(tiles, TextureBounds, TileDest, Vector2{0,0}, 0.0f, WHITE);
		}
	}
}

InGame::InGame(void)
{
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			board.cells[i][j].color = static_cast<Colors>(GetRandomValue(0, 4));
			board.cells[i][j].shape = static_cast<Shapes>(GetRandomValue(0, 4));
		}
	}
}