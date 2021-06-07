#pragma once
#include <Image.h>
#include <Event.h>

class L_Mouse_Button
{
public:
	L_Mouse_Button();

	void setposition(int x, int y);

	void handleevent(SDL_Event* e);

	void render(Ltexure To_Render, SDL_Renderer* renderer);

	SDL_Point getposition();
	Lbuttonsprite mCurrentSprite;

private:
	SDL_Point mPosition;

};

