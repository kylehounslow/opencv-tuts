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
	bool recording = false;
	bool startNewRecording = false;
	int inc=0;
	bool firstRun = true;

	VideoCapture cap(0); // open the video camera no. 0
	VideoWriter oVideoWriter;//create videoWriter object, not initialized yet

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "ERROR: Cannot open the video file" << endl;
		return -1;
	}

	namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame Size = " << dWidth << "x" << dHeight << endl;

	//set framesize for use with videoWriter
	Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));


	while (1) {

		if(startNewRecording==true){

			
			oVideoWriter  = VideoWriter("D:/MyVideo"+intToString(inc)+".avi", CV_FOURCC('D', 'I', 'V', '3'), 20, frameSize, true); //initialize the VideoWriter object 
			//oVideoWriter  = VideoWriter("D:/MyVideo"+intToString(inc)+".avi", (int)cap.get(CV_CAP_PROP_FOURCC), 20, frameSize, true); //initialize the VideoWriter object 

			recording = true;
			startNewRecording = false;
			cout<<"New video file created D:/MyVideo"+intToString(inc)+".avi "<<endl;


			if ( !oVideoWriter.isOpened() ) //if not initialize the VideoWriter successfully, exit the program
			{
				cout << "ERROR: Failed to initialize video writing" << endl;
				getchar();
				return -1;
			}

		}


		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "ERROR: Cannot read a frame from video file" << endl;
			break;
		}

		//if we're in recording mode, write to file
		if(recording){

			oVideoWriter.write(frame);
			//show "REC" in top left corner in red
			//be sure to do this AFTER you write to the file so that "REC" doesn't show up
			//on the recorded video.
			putText(frame,"REC",Point(0,60),2,2,Scalar(0,0,255),2);


		}
		imshow("MyVideo", frame); //show the frame in "MyVideo" window


		switch(waitKey(10)){

		case 114:
			//'r' has been pressed.
			//toggle recording mode
			recording =!recording;

			if(firstRun == true){

				cout << "New Recording Started" << endl;
				oVideoWriter  = VideoWriter("D:/MyVideo0.avi", CV_FOURCC('D', 'I', 'V', '3'), 20, frameSize, true);

				if ( !oVideoWriter.isOpened() ) 
			{
				cout << "ERROR: Failed to initialize video writing" << endl;
				getchar();
				return -1;
			}
				firstRun = false;


			}
			else {if (!recording)cout << "Recording Stopped" << endl;

			else cout << "Recording Started" << endl;
			}
			break;

		case 110:
			//'n' has been pressed
			//start new video file
			startNewRecording = true;
			cout << "New Recording Started" << endl;
			//increment video file name
			inc+=1;
			break; 
		case 27:
			//'esc' has been pressed
			//exit program.
			cout << "Exit Program" << endl;
			return 0;



		}


	}

	return 0;

}
////////////////////////////////////////////////////////////////////////////////////////////