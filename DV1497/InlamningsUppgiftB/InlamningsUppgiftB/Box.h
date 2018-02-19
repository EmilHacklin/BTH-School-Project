#pragma once

class Box
{
private:
	int width;
	int height;
public:
	Box(const int width = 0, const int height = 0);
	Box(const Box &otherBox);
	Box& operator=(const Box &otherBox);
	int getWidth() const;
	int getHeight() const;
	~Box();
};

