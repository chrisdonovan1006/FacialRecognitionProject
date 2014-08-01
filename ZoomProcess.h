#ifndef _ZoomProcess
#define _ZoomProcess

// #include <include externak libs here>

using namespace std;
using namespace cv;

// ***************************** _ZoomProcess *************************
class ZoomProcess
{
public:
	ZoomProcess();
	
	int activate();

	Mat cropImage(Mat image);
	
private:	
	Mat m_zoom_image;
};

#endif //  _GTP_FILE_TRANSFER_TCP_
