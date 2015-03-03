#pragma once
#include <string>
#include <opencv\cv.h>
#include <opencv\highgui.h>
using namespace std;
using namespace cv;

class Fruit
{
public:
	Fruit();
	~Fruit(void);

	Fruit(string name);

	int getXPos();
	void setXPos(int x);

	int getYPos();
	void setYPos(int y);

	Scalar getHSVmin();
	Scalar getHSVmax();

	void setHSVmin(Scalar min);
	void setHSVmax(Scalar max);

	string getType(){return type;}
	void setType(string t){type = t;}

	Scalar getColour(){
		return Colour;
	}
	void setColour(Scalar c){

		Colour = c;
	}

private:

	int xPos, yPos;
	string type;
	Scalar HSVmin, HSVmax;
	Scalar Colour;
};