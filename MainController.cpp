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

int printMsg(string msg, int code)
{
	if (code == 0)
		cout << msg << endl;
	else
		cout << msg << code << endl;
	return 0;
}

int display_histo(Mat src_image, const char* roi_name)
{
    Mat hist;
	int histSize = 64;

    calcHist(&src_image, 1, 0, Mat(), hist, 1, &histSize, 0);


    Mat histImage = Mat::ones(200, 320, CV_8U)*255;

    normalize(hist, hist, 0, histImage.rows, CV_MINMAX, CV_32F);

    histImage = Scalar::all(255);
    int binW = cvRound((double)histImage.cols/histSize);

    for( int i = 0; i < histSize; i++ )
        rectangle( histImage, Point(i*binW, histImage.rows),
                   Point((i+1)*binW, histImage.rows - cvRound(hist.at<float>(i))),
                   Scalar::all(0), -1, 8, 0 );
    imshow(roi_name, histImage);

	return 0;
}

int main(int argc, const char** argv)
{
    printMsg("facial recognition system for driver fatgure", 0);
	//create the cascade classifier objects used for the face and eye detection
    CascadeClassifier face_cascade;																	
	CascadeClassifier eye_cascade;
    
	// load the pre-built classifier objects
	if (!face_cascade.load("haarcascade_frontalface_alt.xml"))
	{
		printMsg("failed to load the haarcascade_frontalface_alt.xml file... exiting program!!!", 0);
		return -1;
	}
	else
	{
		printMsg("loading haarcascade_frontalface_alt.xml file.", 0);
	}

	if (!eye_cascade.load("haarcascade_eye_tree_eyeglasses.xml"))
	{
		printMsg("failed to load the haarcascade_eye_tree_eyeglasses.xml file... exiting program!!!", 0);
		return -1;
	}
	else
	{
		printMsg("loading haarcascade_eye.xml file.", 0);
	}
	
    //setup video capture device and link it to the first capture device
	VideoCapture capture_device;																	
    capture_device.open(0);
    
	//setup image files used in the capture process
    Mat capture_frame;																				
    Mat grayscale_frame;
	Mat cropped_frame;
	Mat roi_eyes;
	
	//create a window to present the results
    namedWindow("LiveWebcamFeed", WINDOW_AUTOSIZE);													
	printMsg("created the display window objects!", 0);
    
    while(true)
    {       
        //capture a new image frame
		capture_device >> capture_frame; 
       
        //convert captured image to gray scale and equalize
		cvtColor(capture_frame, grayscale_frame, CV_BGR2GRAY);										 
        equalizeHist(grayscale_frame, grayscale_frame);
       
        //create a vector array to store any found faces
		vector<Rect> faces;																			
        
		//find faces and store them in the vector array
        face_cascade.detectMultiScale(grayscale_frame, faces, 1.1, 3, 
			CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_SCALE_IMAGE, Size(30,30));							
		// printMsg("no. of faces: ", faces.size());
		
        for(int i = 0; i < faces.size(); i++)														
        {
            //draw a rectangle for all found faces in the vector array on the original image
			Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
            Point pt2(faces[i].x, faces[i].y);

            rectangle(capture_frame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
			
			// extract the face from the image
			cropped_frame = capture_frame(faces[i]);
			
			// create a veactor array to store the eyes
			vector<Rect> eyes;
			//find eyes and store them in the vector array
			eye_cascade.detectMultiScale(cropped_frame, eyes, 1.1, 3, 
			0|CV_HAAR_SCALE_IMAGE, Size(30,30));

			for (int j = 0; j < eyes.size(); j++)
			{
				Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, 
						faces[i].y + eyes[j].y + eyes[j].height*0.5 );
				int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
				circle( capture_frame, center, radius, Scalar( 255, 0, 0 ), 1, 8, 0 );
				roi_eyes = capture_frame(eyes[j]);
			}

			display_histo(grayscale_frame, "main_image");
			/*if (roi_eyes.cols != 0 && roi_eyes.rows != 0)
			{
				display_histo(roi_eyes, "roi_eyes");
			}*/
		}

        
		imshow("LiveWebcamFeed", capture_frame);													//print the output
		if (cropped_frame.cols != 0 && cropped_frame.rows != 0)
		{
			imshow("CroppedImage", cropped_frame);													//print the output
		}
															
        if (waitKey(33) == 27)																		//pause for 10 milliseconds
		{
			cout << "user pressed 'Esc', exiting program!" << endl;
			break;
		}
    }
 
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////

