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