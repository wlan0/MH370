#include <opencv/cv.h>
#include <opencv/highgui.h>
#include<iostream>
using namespace std;
#include<stdio.h>

bool look4Parts(char *img_file);

int main(int argc, char **argv) {
    char file_name[50];
    for(int i=412 ; i<601;i++) {
        sprintf(file_name, "test125%d.jpg",i);
        if(look4Parts(file_name)) {
            cout << i << " " << "has parts in it!\n";
        }
    }
}

bool look4Parts(char *img_file)
{
	IplImage* img = cvLoadImage( img_file, 0);

    // Make sure image is divisible by 2
    assert( img->width%2 == 0 && img->height%2 == 0);
	
    // Create an image for the output
    IplImage* out = cvCreateImage( cvSize(img->width/2,img->height/2), img->depth, img->nChannels );
	
    // Reduce the image by 2
    cvPyrDown( img, out );
	
    // Perform canny edge detection
    cvCanny( out, out, 12, 120, 3 );

    if( cvCountNonZero(out) > 0)
    {
//        cout << "found some part!";
        return true;
    }
    else {
  //      cout << "no parts here";
    }
	
    return false;
	
}