#pragma once
#include "raylib.h"
#include <string>

class Button
{
public:
	Rectangle buttonRectangle;
	bool isClicked = false;
	Color buttonColour = GRAY;
	std::string buttonText;

	Button();
	Button(std::string text, Rectangle rectangle);
	~Button();

	bool IsOver();
	bool IsClicked();
	bool OnClick();
	void Draw();
};

