#pragma once
#include <ECS.h>

class postioncomponent : public Component
{
private:
	int xpos;
	int	ypos;

public:
	int getX() { return xpos; }
	int getY() { return ypos; }

	void init() override
	{
		xpos = 0;
		ypos = 0;
	}

	void update() override
	{
		xpos++;
		ypos++;
	}

	void setpos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};
