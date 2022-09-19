#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include "code/extraction.h"
#include <ctime>

// input path
#define INPUT_IMG "../data/images/stars1.jpg"

// result path
#define SEG_IMG "../results/stars1-segimg.jpg"
#define PLOT_IMG "../results/stars1-plotimg.jpg"
#define WHITE_IMG "../results/stars1-whiteimg.jpg"

using namespace std;
using namespace cv;

int main()
{
    // OpenCV version
    cout << "OpenCV version: " << CV_VERSION << endl;

    // variables
    Mat srcimg, greyimg, segimg, filimg, plotimg, whiteimg;
    vector<pair<pair<double, double>, double>> centroids;
    uchar markcolor[3] = {0, 255, 0};
    time_t start, end;

    // read srcimg
    cout << "Reading image..." << endl;
    srcimg = read_img(INPUT_IMG);

    // grey img
    cout << "Get grey image..." << endl;
    greyimg = grey_img(srcimg);

    // preprocess img
    cout << "Preprocessing image..." << endl;
    // choices: "mean" / "threshold" / "gradient" / "none"
    // default: "none"
    segimg = preprocess_img(greyimg, "mean");
    imwrite(SEG_IMG, segimg);

    // centroids
    cout << "Get centroids of stars..." << endl;
    start = clock();
    centroids = get_centroids(segimg);
    print_vector(centroids);
    end = clock();
    cout << "Time used: " << end - start << endl;

    // plot centroids
    cout << "Plotting stars on src image..." << endl;
    plotimg = plot_centroids(srcimg, centroids, markcolor);
    imwrite(PLOT_IMG, plotimg);

    // plot centroids on white img
    cout << "Plotting stars on plain image..." << endl;
    whiteimg = plot_centroids_white_background(srcimg, centroids, markcolor);
    imwrite(WHITE_IMG, whiteimg);

    return 0;
}