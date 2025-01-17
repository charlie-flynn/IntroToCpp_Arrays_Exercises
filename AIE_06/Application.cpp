#include "Application.h"
#include "raylib.h"
#include <stdlib.h>
#include <chrono>


Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Simple Tilemap");
	SetTargetFPS(60);
	srand(time(0));
	Load();


	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}

void Application::Load()
{
	// Task1:
	// Initialise all values in m_tiles array to a random
	// value between 0 and 5 exclusive;
	// -----------------------------------------------------
	
	// write your code here
	for (int i = 0; i < ROWS * COLS; i++)
	{
		m_tiles[i] = rand() % 5;
	}

	// -----------------------------------------------------
}

void Application::Unload()
{

}

void Application::Update(float deltaTime)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		int rowIndex = mousePos.y / m_tileWidth; 
		int colIndex = mousePos.x / m_tileHeight;

		// TODO: calculate the index of the tile clicked on based on the row/col index
		int tileIndex = colIndex + (rowIndex * COLS);

		m_tiles[tileIndex] += 1;
		if (m_tiles[tileIndex] >= 5)
			m_tiles[tileIndex] = 0;
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Task2:
	// use a nested loop to iterate over rows and columns
	// Use raylib's DrawRect method to draw each tile in the array.
	// 	   use the row and col index multipled by m_tileHeight/m_tileWidth
	// 	   to calculate the x and y position for each rectangle.
	// 
	// change the color of the rect drawn based on the value of the tile.
	// 	   We have created a helper function you can use "GetTileColor"
	// --------------------------------------------------------------------
	// write your code here
	for (int colIndex = 0; colIndex < ROWS; colIndex++)
	{
		for (int rowIndex = 0; rowIndex < COLS; rowIndex++)
		{
			float xPos = m_tileWidth * colIndex;
			float yPos = m_tileHeight * rowIndex;
			int index = colIndex + (rowIndex * COLS);
			Color color = GetTileColor(m_tiles[index]); // pass in the tilevalue

			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}

	}




	// --------------------------------------------------------------------

	EndDrawing();
}

Color Application::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0: return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return BLUE;
	case 4: return YELLOW;
	}
	
	return BLACK;
}