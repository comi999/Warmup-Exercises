#include "Button.h"
#include <functional>

Button::Button()
{

}

Button::Button(std::string text, Rectangle rectangle)
{
	buttonText = text;
	buttonRectangle = rectangle;
}

Button::~Button()
{

}

bool Button::IsOver()
{
	Vector2 mousePos = GetMousePosition();
	return (buttonRectangle.x <= mousePos.x && buttonRectangle.width + buttonRectangle.x > mousePos.x) && 
		(buttonRectangle.y <= mousePos.y && buttonRectangle.height + buttonRectangle.y > mousePos.y);
}

bool Button::IsClicked()
{
	return IsOver() && IsMouseButtonDown(0);
}

bool Button::OnClick()
{

}

void Button::Draw()
{
	Color colour = IsClicked() ? RED : GREEN;
	DrawRectangle(buttonRectangle.x, buttonRectangle.y, buttonRectangle.width, buttonRectangle.height, colour);
	DrawText(buttonText.c_str(), buttonRectangle.x + 0.5f * buttonRectangle.width, buttonRectangle.y + 0.5f * buttonRectangle.height, 10, GRAY);
}