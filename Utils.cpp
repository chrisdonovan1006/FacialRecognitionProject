#undef MODULE_NAME
#define MODULE_NAME "Utils"

#include <iostream>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Utils.h"

using namespace std;
using namespace cv;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ********************* GTP TCP CONNECTION *************************************
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Utils::Utils()
{
	
}

int Utils::activate()
{
	
	return 0;
}

void printMsg(const char* msg)
{
	cout << msg << endl;
}
