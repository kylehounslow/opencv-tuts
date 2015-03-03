#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <iostream>

using namespace cv;
using namespace std;

string intToString(int number){


	std::stringstream ss;
	ss << number;
	return ss.str();
}

int main(int argc, char* argv[])
{

	VideoCapture cap(0); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "ERROR INITIALIZING VIDEO CAPTURE" << endl;
		return -1;
	}

	char* windowName = "Webcam Feed";
	namedWindow(windowName,CV_WINDOW_AUTOSIZE); //create a window to display our webcam feed


	while (1) {

		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from camera feed

		if (!bSuccess) //test if frame successfully read
		{
			cout << "ERROR READING FRAME FROM CAMERA FEED" << endl;
			break;
		}

		
		imshow(windowName, frame); //show the frame in "MyVideo" window

		//listen for 10ms for a key to be pressed
		switch(waitKey(10)){

		case 27:
			//'esc' has been pressed (ASCII value for 'esc' is 27)
			//exit program.
			return 0;

		}


	}

	return 0;

}
////////////////////////////////////////////////////////////////////////////////////////////