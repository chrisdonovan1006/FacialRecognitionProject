///////////////////////////////////////////////////////////////////////////////////////////////////
// This is the main .cpp file of the facial recogntion system.
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
 
#include <iostream>
#include <stdio.h>

 
using namespace std;
using namespace cv;
 
Mat grayscaleFrame(Mat colourFrame)
{
	Mat grayScaleFrame;
	return grayScaleFrame;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// PROCESS METHODS /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


int processImage(Mat procImg)
{
	//This method will process the image by removing the colour and returning the grayscale image.

	return 0;
}

int getCurrentImageHistogram(Mat procImg)
{
	// here the image histogram will be reteived

	return 0;
}

int compareHistogram(int arry1[], int arry2[])
{
	// Here the current histogram will be compare against the previous image histogram.

	return 0;
}


int checkROI()
{
	// this where the region of interest will checked (eyes, mouth, etc)

	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// MAIN METHOD /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, const char** argv)
{
    cout << "facial recognition system for driver fatgure" << endl;	   
    CascadeClassifier face_cascade;																	//create the cascade classifier object used for the face detection
	CascadeClassifier eyes_cacscade;
    
	
	if (face_cascade.load("haarcascade_frontalface_alt.xml") == -1)									//use the haarcascade_frontalface_alt.xml library
	{
		cout << "failed to load the haarcascade xml file... exiting program!!!" << endl;
		return -1;
	}
	else
		cout << "loading haarcascade xml file." << endl;
    
    VideoCapture capture_device;																	//setup video capture device and link it to the first capture device
    capture_device.open(0);
    
    Mat capture_frame;																				//setup image files used in the capture process
    Mat grayscale_frame;
 
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
 
            rectangle(capture_frame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
        }
 
        imshow("LiveWebcamFeed", capture_frame);													//print the output
 
        if (waitKey(10) == 27)																		//pause for 10 milliseconds
		{
			cout << "user pressed 'Esc', exiting program!" << endl;
			break;
		}
    }
 
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////