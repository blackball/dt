#include "dt.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>

static void 
test_binary(const char *iname) {
        IplImage *gray = cvLoadImage(iname, 0);
        IplImage *binary = NULL;
        
        if (!gray) {
                return ;
        }
        
        binary = cvCreateImage(cvGetSize(gray), 8, 1);
        
        cvThreshold(gray, binary, 50, 255, CV_THRESH_BINARY);

        dt_binary((unsigned char*)binary->imageData, binary->height, binary->width, binary->widthStep);
        
        cvSaveImage("result-binary.jpg", binary, 0);
        cvNamedWindow("result", 1);
        cvShowImage("result", binary);
        cvWaitKey(0);
        cvDestroyWindow("result");
        cvReleaseImage(&gray);
        cvReleaseImage(&binary);
}

static void 
test_gray(const char *iname) {
        IplImage *gray = cvLoadImage(iname, 0);
        
        if (!gray) {
                return ;
        }
        
        dt_gray((unsigned char*)gray->imageData, gray->height, gray->width, gray->widthStep);
        
        cvSaveImage("result-gray.jpg", gray, 0);
        cvNamedWindow("result", 1);
        cvShowImage("result", gray);
        cvWaitKey(0);
        cvDestroyWindow("result");
        cvReleaseImage(&gray);
}

int 
main(int argc, char **argv) {
        if (argc != 3) {
                return 0;
        }

        if (strcmp(argv[2], "b") == 0) {
                test_binary(argv[1]);
        }
        else if (strcmp(argv[2], "g") == 0) {
                test_gray(argv[1]);
        }
        
        return 0;
}
