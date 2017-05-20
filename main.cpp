#include <opencv2/opencv.hpp>
#include <math.h>


using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  //checking if all parameters are present
  if(argc != 5)
  {
    cout << "Error: There should be 4 parameters!\n";
    return -1; 
  }
  
  //defying variables
  Mat inputImg1, inputImg2, outputImg;
  double alpha;
  stringstream s;
  
  //loading input data
  s << argv[4];
  s >> alpha;
  inputImg1 = imread(argv[1], CV_LOAD_IMAGE_COLOR);
  inputImg2 = imread(argv[2], CV_LOAD_IMAGE_COLOR);
  if(!inputImg1.data || !inputImg2.data)
  {
    cout << "Error: input file opening failure!\n";
  }
  if(!(alpha >= 0.0 && alpha <= 1.0))
  {
    cout << "Error: Alpha should be between 0.0 and 1.0\n";
  }
  
  //transforming image
  addWeighted(inputImg1, alpha, inputImg2, 1.0 - alpha, 0.0, outputImg);
  
  //saving output
  imwrite(argv[3], outputImg);
  
  //displaying output image
  namedWindow("Output Image", CV_WINDOW_AUTOSIZE);
  imshow("Output Image", outputImg);
  
  //waiting for signal to close app
  waitKey(0);
  return 0;
}