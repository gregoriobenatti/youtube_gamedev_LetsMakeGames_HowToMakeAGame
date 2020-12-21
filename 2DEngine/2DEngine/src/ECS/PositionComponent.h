#pragma once

#include "Components.h"


class PositionComponent : public Component
{
private:
	int xPosition;
	int yPosition;

public:
	PositionComponent()
	{
		xPosition = 0;
		yPosition = 0;
	}

	PositionComponent(int x, int y)
	{
		xPosition = x;
		yPosition = y;
	}

	void update() override
	{
		xPosition++;
		yPosition++;
	}

	int x() { return xPosition; }
	void x(int x) { xPosition = x; }
	int y() { return yPosition; }
	void y(int y) { xPosition = y; }

	void setPosition(int x, int y)
	{
		xPosition = x;
		yPosition = y;
	}
};