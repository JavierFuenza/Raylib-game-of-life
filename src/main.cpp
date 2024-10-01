#include <iostream>
#include "raylib.h"
#include "simulation.hpp"

int main ()
{
	const int WINDOW_WIDTH = 750;
	const int WINDOW_HEIGHT = 750;
	const int CELL_SIZE = 25;
	int FPS = 12;
	Color GRIS = {29,29,29,255};

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game Of Life");
	SetTargetFPS(FPS);
	Simulation simulation{WINDOW_WIDTH,WINDOW_HEIGHT,CELL_SIZE};
	

	//Simulation loop
	while(WindowShouldClose() == false){
		//Event Handling
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			Vector2 mousePosition = GetMousePosition();
			int row = mousePosition.y/CELL_SIZE;
			int column = mousePosition.x/CELL_SIZE;
			simulation.ToggleCell(row,column);
		}
		
		if (IsKeyPressed(KEY_SPACE)&&simulation.IsRunning()==false)
		{
			simulation.Start();
			SetWindowTitle("Game of Life is running...");
		}
		else if (IsKeyPressed(KEY_SPACE)&&simulation.IsRunning())
		{
			simulation.Stop();
			SetWindowTitle("Game of Life has stopped.");
		}
		else if (IsKeyPressed(KEY_F))
		{
			FPS += 2;
			SetTargetFPS(FPS);
		}
		else if (IsKeyPressed(KEY_S) && FPS > 5)
		{
			FPS -= 2;
			SetTargetFPS(FPS);
		}
		else if (IsKeyPressed(KEY_R))
		{
			simulation.CreateRandomState();
		}
		else if (IsKeyPressed(KEY_C))
		{
			simulation.ClearGrid();
		}
		
		
		
		
		
		//Update State
		simulation.Update();
		//Drawing
		BeginDrawing();
		ClearBackground(GRIS);
		simulation.Draw();
		EndDrawing();
	}

	CloseWindow();
}