#undef MODULE_NAME
#define MODULE_NAME "ZOOM_PROCESS"

#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ZoomProcess.h"

using namespace std;
using namespace cv;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ********************* GTP TCP CONNECTION *************************************
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ZoomProcess::ZoomProcess()
{
	m_zoom_image = NULL;
}

int ZoomProcess::activate()
{
	
	return 0;
}

Mat cropImage(Mat imageIn)
{
	Mat imageOut;

	return imageOut;
}

