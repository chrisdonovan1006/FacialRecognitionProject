///////////////////////////////////////////////////////////////////////////////////////////////////
// This is the main .cpp file of the facial recogntion system.
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
 
#include <iostream>
#include <stdio.h>

//#include "Utils.h"
//#include "ZoomProcess.h"

using namespace std;
using namespace cv;

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// MAIN METHOD /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int printMsg(string msg)
{
	cout << msg << endl;
	return 0;
}


int main(int argc, const char** argv)
{
    cout << "facial recognition system for driver fatgure" << endl;	   
    CascadeClassifier face_cascade;																	//create the cascade classifier object used for the face detection
	CascadeClassifier eye_cascade;
    
	if (!face_cascade.load("haarcascade_frontalface_alt.xml"))										//use the haarcascade_frontalface_alt.xml library
	{
		printMsg("failed to load the haarcascade_frontalface_alt.xml file... exiting program!!!");
		return -1;
	}
	else
	{
		printMsg("loading haarcascade_frontalface_alt.xml file.");
	}

	if (!eye_cascade.load("haarcascade_eye.xml"))										//use the haarcascade_frontalface_alt.xml library
	{
		printMsg("failed to load the haarcascade_eye.xml file... exiting program!!!");
		return -1;
	}
	else
	{
		printMsg("loading haarcascade_eye.xml file.");
	}
	
    VideoCapture capture_device;																	//setup video capture device and link it to the first capture device
    capture_device.open(0);
    
    Mat capture_frame;																				//setup image files used in the capture process
    Mat grayscale_frame;
	Mat cropped_image;
 
    namedWindow("LiveWebcamFeed", WINDOW_AUTOSIZE);													//create a window to present the results
	cout << "created the display window objects!" << endl;
    
    while(true)																						//create a loop to capture and find faces
    {       
        capture_device>>capture_frame;																//capture a new image frame
       
        cvtColor(capture_frame, grayscale_frame, CV_BGR2GRAY);										 //convert captured image to gray scale and equalize
        equalizeHist(grayscale_frame, grayscale_frame);
       
        std::vector<Rect> faces;																	 //create a vector array to store the face found
        
        face_cascade.detectMultiScale(grayscale_frame, faces, 1.1, 3, 
			CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_SCALE_IMAGE, Size(30,30));							//find faces and store them in the vector array
        
        for(int i = 0; i < faces.size(); i++)														//draw a rectangle for all found faces in the vector array on the original image
        {
            Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
            Point pt2(faces[i].x, faces[i].y);
			
			Rect crop_rect(pt1, pt2);
            rectangle(capture_frame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);

			cropped_image = capture_frame(crop_rect);
        }
		
        imshow("LiveWebcamFeed", capture_frame);													//print the output
		if (cropped_image.cols != 0 && cropped_image.rows != 0)
		{
			imshow("CroppedImage", cropped_image);
		}
															//print the output
 
        if (waitKey(10) == 27)																		//pause for 10 milliseconds
		{
			cout << "user pressed 'Esc', exiting program!" << endl;
			break;
		}
    }
 
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

