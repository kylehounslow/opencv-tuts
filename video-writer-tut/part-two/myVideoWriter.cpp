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

	cv::VideoWriter writer;


	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "ERROR INITIALIZING VIDEO CAPTURE" << endl;
		return -1;
	}


	char* windowName = "Webcam Feed";
	namedWindow(windowName,CV_WINDOW_AUTOSIZE); //create a window to display our webcam feed

	//filename string

	string filename = "D:\myVideo.avi";

	//fourcc integer
	
	int fcc = CV_FOURCC('D','I','V','3');

	//frames per sec integer

	int fps = 10;

	//frame size

	cv::Size frameSize(cap.get(CV_CAP_PROP_FRAME_WIDTH),cap.get(CV_CAP_PROP_FRAME_HEIGHT));


	writer = VideoWriter(filename,fcc,fps,frameSize);

	if(!writer.isOpened()){

		cout<<"ERROR OPENING FILE FOR WRITE"<<endl;
		getchar();

		return -1;
	}

	Mat frame;

	while (1) {

		

		bool bSuccess = cap.read(frame); // read a new frame from camera feed

		if (!bSuccess) //test if frame successfully read
		{
			cout << "ERROR READING FRAME FROM CAMERA FEED" << endl;
			break;
		}

		writer.write(frame);
		
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