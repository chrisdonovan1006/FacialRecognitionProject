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

Mat equalizeHistogram(Mat grayScaleFrame)
{
	Mat equalizeFrame;
	return equalizeFrame;
}

int main(int argc, const char** argv)
{
    cout << "this is the main class in the facial recognition system!" << endl;	   
    CascadeClassifier face_cascade;																	//create the cascade classifier object used for the face detection
    face_cascade.load("haarcascade_frontalface_alt.xml");											//use the haarcascade_frontalface_alt.xml library
	cout << "loading haarcascade xml file." << endl;
    
    VideoCapture captureDevice;																		//setup video capture device and link it to the first capture device
    captureDevice.open(0);
    
    Mat captureFrame;																				//setup image files used in the capture process
    Mat grayscaleFrame;
 
    namedWindow("LiveWebcamFeed", 1);																//create a window to present the results
	namedWindow("LiveWebcamFeed - Grayscale image", 1);
	cout << "created the display window objects!" << endl;
    
    while(true)																						//create a loop to capture and find faces
    {       
        captureDevice>>captureFrame;																//capture a new image frame
       
        cvtColor(captureFrame, grayscaleFrame, CV_BGR2GRAY);										 //convert captured image to gray scale and equalize
        equalizeHist(grayscaleFrame, grayscaleFrame);
       
        std::vector<Rect> faces;																	 //create a vector array to store the face found
        
        face_cascade.detectMultiScale(grayscaleFrame, faces, 1.1, 3, 
			CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_SCALE_IMAGE, Size(30,30));							//find faces and store them in the vector array
        
        for(int i = 0; i < faces.size(); i++)														//draw a rectangle for all found faces in the vector array on the original image
        {
            Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
            Point pt2(faces[i].x, faces[i].y);
 
            rectangle(captureFrame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
        }
 
        imshow("LiveWebcamFeed", captureFrame);														//print the output
		imshow("LiveWebcamFeed - Grayscale image", grayscaleFrame);
 
        if (waitKey(33) == 27)																		//pause for 33ms
		{
			cout << "user pressed 'Esc', exiting program!" << endl;
			break;
		}
    }
 
    return 0;
}


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

int compareHistogram()
{
	// Here the current histogram will be compare against the previous image histogram.

	return 0;
}


int checkROI()
{
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////