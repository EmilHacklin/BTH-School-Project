#pragma once

class Coord
{
private:
	int xPos;
	int yPos;
public:
	Coord(const int xPos = 0, const int yPos = 0);
	int getXPos() const;
	int getYPos() const;
	void changeXPos(const int change);
	void changeYPos(const int change);
	~Coord();
};

