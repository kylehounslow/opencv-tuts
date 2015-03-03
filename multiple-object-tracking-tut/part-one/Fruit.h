#pragma once
#include <string>
using namespace std;

class Fruit
{
public:
	Fruit(void);
	~Fruit(void);

	int getXPos();
	void setXPos(int x);

	int getYPos();
	void setYPos(int y);

private:

	int xPos, yPos;
	string type;
	
};

