///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// IMAGE HISTOGRAM /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


//Mat equalizeHistogram(Mat grayScaleFrame)
//{
//	Mat equalizeFrame;
//	return equalizeFrame;
//}
//
//void imhist(Mat image, int histogram[])
//{
//
//    // initialize all intensity values to 0
//    for(int i = 0; i < 256; i++)
//    {
//        histogram[i] = 0;
//    }
//
//    // calculate the no of pixels for each intensity values
//    for(int y = 0; y < image.rows; y++)
//        for(int x = 0; x < image.cols; x++)
//            histogram[(int)image.at<uchar>(y,x)]++;
//
//}
//
//void cumhist(int histogram[], int cumhistogram[])
//{
//    cumhistogram[0] = histogram[0];
//
//    for(int i = 1; i < 256; i++)
//    {
//        cumhistogram[i] = histogram[i] + cumhistogram[i-1];
//    }
//}
//
//void histDisplay(int histogram[], const char* name)
//{
//    int hist[256];
//    for(int i = 0; i < 256; i++)
//    {
//        hist[i]=histogram[i];
//    }
//    // draw the histograms
//    int hist_w = 512; int hist_h = 400;
//    int bin_w = cvRound((double) hist_w/256);
//
//    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));
//
//    // find the maximum intensity element from histogram
//    int max = hist[0];
//    for(int i = 1; i < 256; i++){
//        if(max < hist[i]){
//            max = hist[i];
//        }
//    }
//
//    // normalize the histogram between 0 and histImage.rows
//
//    for(int i = 0; i < 256; i++){
//        hist[i] = ((double)hist[i]/max)*histImage.rows;
//    }
//
//
//    // draw the intensity line for histogram
//    for(int i = 0; i < 256; i++)
//    {
//        line(histImage, Point(bin_w*(i), hist_h),
//                              Point(bin_w*(i), hist_h - hist[i]),
//             Scalar(0,0,0), 1, 8, 0);
//    }
//
//    // display histogram
//    namedWindow(name, CV_WINDOW_AUTOSIZE);
//    imshow(name, histImage);
//}
//
//
//int getHisto()
//{
//    // Load the image
//    Mat image = imread("C:/Users/Desktop/Research/Research/1.jpg", CV_LOAD_IMAGE_GRAYSCALE);
//
//    // Generate the histogram
//    int histogram[256];
//
//    imhist(image, histogram);
//
//    // Display the original Image
//    namedWindow("Original Image");
//    imshow("Original Image", image);
//
//    // Display the original Histogram
//    histDisplay(histogram, "Original Histogram");
//
//
//    // Caluculate the size of image
//    int size = image.rows * image.cols;
//
//    // Generate cumulative frequency histogram
//    int cumhistogram[256];
//    cumhist(histogram,cumhistogram );
//
//    int CDFMin =256;
//    for(int i =0;i<256;i++)
//        if(cumhistogram[i] != 0 && cumhistogram[i] < CDFMin)
//            CDFMin = cumhistogram[i];
//
//      //histogram equalization 
//    float z;
//    int ScaledCDF[256];
//    for(int i =0;i<256;i++)
//    {
//
//            z=(float)(cumhistogram[i]-CDFMin)/(size-CDFMin);
//            ScaledCDF[i]= z*255;
//
//    }
//
//
//
//    // Generate the equlized image
//    Mat new_image = image.clone();
//
//    for(int y = 0; y < image.rows; y++)
//        for(int x = 0; x < image.cols; x++)
//
//            new_image.at<uchar>(y,x) = saturate_cast<uchar>(ScaledCDF[image.at<uchar>(y,x)]);
//
//
//    imwrite("C:/Users/Desktop/Research/Research/All.jpg", new_image );
//
//
//
//
//    // Load the image
//    Mat ResultImage = imread("C:/Users/Desktop/Research/Research/All.jpg", CV_LOAD_IMAGE_GRAYSCALE);
//    imshow("Equilized Image",ResultImage);
//    // Generate the histogram
//
//    int NewHistogram[256];
//    // calculate the no of pixels for each intensity values
//    imhist(ResultImage, NewHistogram);
//
//
//
//    // Display the equilzed histogram
//    histDisplay(NewHistogram, "Equilized Histogram");
//
//
//    waitKey();
//    return 0;
//}






 //// OpenCV Sample Application: blink_detction.cpp  
 //// Include header files  
 //#include "cv.h"  
 //#include "highgui.h"  
 //#include <stdio.h>  
 //#include <stdlib.h>  
 //#include <string.h>  
 //#include <assert.h>  
 //#include <math.h>  
 //#include <float.h>  
 //#include <limits.h>  
 //#include <time.h>  
 //#include <ctype.h>  
 //#include <iostream>  
 //#include "opencv2/objdetect/objdetect.hpp"  
 //#include "opencv2/highgui/highgui.hpp"  
 //#include "opencv2/imgproc/imgproc.hpp"  
 //// Create memory for calculations  
 //static CvMemStorage* storage = 0;  
 //// Create a new Haar classifier  
 //static CvHaarClassifierCascade* cascade = 0;  
 //// Function prototype for detecting and drawing an object from an image  
 //bool detect_and_draw( IplImage* image ,CvHaarClassifierCascade* cascade);  
 //// Create a string that contains the cascade name  
 ///*  "eyes.xml*/  
 //const char *cascade_name[1]={"eyes.xml"};  
 //cv::Mat roiImg;  
 //int threshold_value = 200;  
 //int threshold_type = 3;;  
 //int const max_value = 255;  
 //int const max_type = 4;  
 //int const max_BINARY_value = 255;  
 //int hough_thr = 35;  
 //cv::Mat src_gray, dst;  
 //using namespace cv;  
 //Mat img1; Mat img2; Mat templ; Mat result;  
 //const char* image_window = "Source Image";  
 //const char* result_window = "Result window";  
 //int match_method=0;  
 //int max_Trackbar = 5;  
 //int eye_open=0;  
 //int eye_close=0;  
 ///*  
 //**  
 // * @function MatchingMethod  
 // * @brief Trackbar callback  
 //*/  
 ////Matching with 2 images ,eye closed or open  
 //void MatchingMethod(cv::Mat templ,int id )  
 //{  
 // /// Source image to display  
 // cv::Mat img_display;  
 // roiImg.copyTo( img_display );  
 // /// Create the result matrix  
 // int result_cols = roiImg.cols - templ.cols + 1;  
 // int result_rows = roiImg.rows - templ.rows + 1;  
 // result.create( result_cols, result_rows, CV_32FC1 );  
 // /// Do the Matching and Normalize  
 // cv::matchTemplate( roiImg, templ, result, match_method );  
 // cv::normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );  
 // /// Localizing the best match with minMaxLoc  
 // double minVal; double maxVal; Point minLoc; Point maxLoc;  
 // cv::Point matchLoc;  
 // cv::minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );  
 // ///Justing checkin the match template value reaching the threashold  
 // if(id == 0 && (minVal < 0))  
 //     {  
 //     eye_open=eye_open+1;  
 //     if(eye_open == 10)  
 //          {  
 //          std::cout<<"Eye Open"<<std::endl;  
 //          eye_open=0;  
 //          eye_close=0;  
 //          }  
 //     }  
 //  else if(id == 1 && (minVal < 0))  
 //     eye_close=eye_close+1;  
 //     if(eye_close == 10)  
 //          {  
 //          std::cout<<"Eye Closed"<<std::endl;  
 //          eye_close=0;  
 //          system("python send_arduino.py");  
 //          }  
 // /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better  
 // if( match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )  
 //  { matchLoc = minLoc; }  
 // else  
 //  { matchLoc = maxLoc; }  
 // /// Show me what you got  
 // cv::rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );  
 // cv::rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );  
 // cv::imshow( image_window, img_display );  
 // cv::imshow( result_window, result );  
 // return;  
 //}  
 //void detect_blink(cv::Mat roi)  
 //{  
 //     try  
 //     {        
 //     MatchingMethod(img1,0);  
 //      MatchingMethod(img2,1);  
 //     }  
 //     catch( cv::Exception& e )  
 //     {  
	//	  std::cout<<"An exception occued: " << e.what() <<std::endl;  
 //     }  
 //}  
 //// Main function, defines the entry point for the program.  
 //int main( int argc, char** argv )  
 //{  
 //  if(argc <= 1)  
 //     {  
 //     std::cout<<"\n Help "<<std::endl;  
 //     std::cout<<"\n ------------------------------------\n"<<std::endl;  
 //     std::cout<<"./blink_detect open_eye.jpg close_eye.jpg\n"<<std::endl;  
 //    std::cout<<"Eg :: ./blink_detect 2.jpg 3.jpg\n"<<std::endl;  
 //     std::cout<<"\n ------------------------------------\n"<<std::endl;  
 //     exit(0);  
 //     }  
 //  // Structure for getting video from camera or avi  
 //  CvCapture* capture = 0;  
 //  // Images to capture the frame from video or camera or from file  
 //  IplImage *frame, *frame_copy = 0;  
 //  // Used for calculations  
 //  int optlen = strlen("--cascade=");  
 //  // Input file name for avi or image file.  
 //  //const char* input_name;  
 //   img1 = imread( argv[1], 1 );  
 //   img2 = imread( argv[2], 1 );  
 //  // Load the HaarClassifierCascade  
 //   /// Create windows  
 //   cv::namedWindow( image_window, CV_WINDOW_AUTOSIZE );  
 //   cv::namedWindow( result_window, CV_WINDOW_AUTOSIZE );  
 //  // Allocate the memory storage  
 //  storage = cvCreateMemStorage(0);  
 //  capture = cvCaptureFromCAM( 0);  
 //  // Create a new named window with title: result  
 //  cvNamedWindow( "original_frame", 1 );  
 //  // If loaded succesfully, then:  
 //  if( capture )  
 //  {  
 //    // Capture from the camera.  
 //    for(;;)  
 //    {  
 //      // Capture the frame and load it in IplImage  
 //      if( !cvGrabFrame( capture ))  
 //        break;  
 //      frame = cvRetrieveFrame( capture );  
 //      // If the frame does not exist, quit the loop  
 //      if( !frame )  
 //        break;  
 //      // Allocate framecopy as the same size of the frame  
 //      if( !frame_copy )  
 //        frame_copy = cvCreateImage( cvSize(frame->width,frame->height),  
 //                      IPL_DEPTH_8U, frame->nChannels );  
 //      // Check the origin of image. If top left, copy the image frame to frame_copy.   
 //      if( frame->origin == IPL_ORIGIN_TL )  
 //        cvCopy( frame, frame_copy, 0 );  
 //      // Else flip and copy the image  
 //          for(int i=0;i<1;i++)  
 //          {  
 //       cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name[i], 0, 0, 0 );  
 //       // Check whether the cascade has loaded successfully. Else report and error and quit  
 //       if( !cascade )  
 //            {  
 //               fprintf( stderr, "ERROR: Could not load classifier cascade\n" );  
 //               return -1;  
 //            }  
 //      // Call the function to detect and draw the face  
 //           if(detect_and_draw(frame_copy,cascade))  
 //          {  
 //               std::cout<<"Detected"<<std::endl;  
 //          }                                
 //          }  
 //      // Wait for a while before proceeding to the next frame  
 //      if( cvWaitKey( 1 ) >= 0 )  
 //       break;  
 //   }  
 //    // Release the images, and capture memory  
 //    cvReleaseHaarClassifierCascade(&cascade);  
 //    cvReleaseImage( &frame_copy );  
 //    cvReleaseCapture( &capture );  
 //    cvReleaseMemStorage(&storage);  
 //  }  
 // return 0;  
 //}  
 //// Function to detect and draw any faces that is present in an image  
 //bool detect_and_draw( IplImage* img,CvHaarClassifierCascade* cascade )  
 //{  
 //  int scale = 1;  
 //  // Create a new image based on the input image  
 //  IplImage* temp = cvCreateImage( cvSize(img->width/scale,img->height/scale), 8, 3 );  
 //  // Create two points to represent the face locations  
 //  CvPoint pt1, pt2;  
 //  int i;  
 //  // Clear the memory storage which was used before  
 //  cvClearMemStorage( storage );  
 //  // Find whether the cascade is loaded, to find the faces. If yes, then:  
 //  if( cascade )  
 //  {  
 //    // There can be more than one face in an image. So create a growable sequence of faces.  
 //    // Detect the objects and store them in the sequence  
 //    CvSeq* faces = cvHaarDetectObjects( img, cascade, storage,  
 //                      1.1, 8, CV_HAAR_DO_CANNY_PRUNING,  
 //                      cvSize(40, 40) );  
 //    // Loop the number of faces found.  
 //    for( i = 0; i < (faces ? faces->total : 0); i++ )  
 //    {  
 //      // Create a new rectangle for drawing the face  
 //      CvRect* r = (CvRect*)cvGetSeqElem( faces, i );  
 //      // Find the dimensions of the face,and scale it if necessary  
 //      pt1.x = r->x*scale;  
 //      pt2.x = (r->x+r->width)*scale;  
 //      pt1.y = r->y*scale;  
 //      pt2.y = (r->y+r->height)*scale;  
 //      // Draw the rectangle in the input image  
 //      cvRectangle( img, pt1, pt2, CV_RGB(255,0,0), 3, 8, 0 );  
 //      cv::Mat image(img);  
 //      cv::Rect rect;  
 //      rect = cv::Rect(pt1.x,pt1.y,(pt2.x-pt1.x),(pt2.y-pt1.y));  
 //      roiImg = image(rect);  
 //        cv::imshow("roi",roiImg);       
 /////Send to arduino  
 //      detect_blink(roiImg);  
 //    }  
 //  }  
 //  // Show the image in the window named "result"  
 //  cvShowImage( "original_frame", img );  
 //  if(i > 0)  
 //          return 1;  
 //     else  
 //          return 0;  
 //  // Release the temp image created.  
 //  cvReleaseImage( &temp );  
 //}




//
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// PROCESS METHODS /////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//Mat grayscaleFrame(Mat colourFrame)
//{
//	Mat grayScaleFrame;
//	return grayScaleFrame;
//}
//
//int processImage(Mat procImg)
//{
//	//This method will process the image by removing the colour and returning the grayscale image.
//
//	return 0;
//}
//
//int getCurrentImageHistogram(Mat procImg)
//{
//	// here the image histogram will be reteived
//
//	return 0;
//}
//
//int compareHistogram(int arry1[], int arry2[])
//{
//	// Here the current histogram will be compare against the previous image histogram.
//
//	return 0;
//}
//
//
//int checkROI()
//{
//	// this where the region of interest will checked (eyes, mouth, etc)
//
//	return 0;
//}


//
//int loadCascades(CascadeClassifier face_cascade, CascadeClassifier eye_cascade)
//{
//int ret_val = 0;
//	
//if (!face_cascade.load("haarcascade_frontalface_alt.xml"))										//use the haarcascade_frontalface_alt.xml library
//{
//	printMsg("failed to load the haarcascade xml file... exiting program!!!");
//	ret_val = -1;
//}
//else
//{
//	cout << "loading haarcascade xml file." << endl;
//}
//
//if (!eye_cascade.load("haarcascade_eye.xml"))										//use the haarcascade_frontalface_alt.xml library
//{
//	cout << "failed to load the haarcascade_eye.xml file... exiting program!!!" << endl;
//	ret_val = -1;
//}
//else
//{
//	cout << "loading haarcascade xml file." << endl;
//}
//
//return ret_val;
//}