# star-centroiding

![build status](https://img.shields.io/badge/build-passing-66c2a5.svg)
[![OpenCV version](https://img.shields.io/badge/OpenCV-3.4.3-fc8d62.svg)](https://opencv.org)
[![Homebrew version](https://img.shields.io/badge/Homebrew-1.8.1-8da0cb.svg)](https://brew.sh)
[![MIT license](https://img.shields.io/badge/license-MIT-e78ac3.svg)](https://mit-license.org)

Preprocess star image, extract centroids and brightness of stars and plot them with __C++__

## Prerequisites (macOS)

* Install [![Homebrew version](https://img.shields.io/badge/Homebrew-1.8.1-8da0cb.svg)](https://brew.sh)

```commandline
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

* Install [![OpenCV version](https://img.shields.io/badge/OpenCV-3.4.3-fc8d62.svg)](https://opencv.org)

```commandline
brew install opencv
```

## Usage (CLion)

* Load `CMakeLists.txt`
* Run

## Functions

See `main.cpp` for usage.

### Read Image

`Mat read_img(const string &filename)` reads source image.

### Grey Image

`Mat grey_img(Mat &img)` turns source image into grey image.

### Preprocess Image

`Mat preprocess_img(Mat &greyimg, const string &filter)` filters out unwanted areas by setting values to 0 in these areas.
There are 3 choices of standard to find these areas, which is set by the value of `filter`:

* `"mean"` The image is divided into small blocks. If the mean value of a block is greater than a given threshold, set the whole block to 0. 
This performs great on images with large blocks of bright area.
* `"threshold"` Compute the global threshold of the image with its mean and standard deviation. If a pixel is lower than the threshold, set the pixel 0.
This performs well on general images.
* `"gradient"` Compute the gradient of the image. If the gradient of a pixel is lower than a given threshold, set the pixel 0.
This intends to work on images with large blocks of bright area, but it does not work well.

### Centroiding

* `vector<pair<pair<double, double>, double>> get_centroids(Mat &img)` gets the centroids and brightness of stars in an image.
* You can print out the centroids and brightness with `void print_vector(vector<pair<pair<double, double>, double>> &v)`

### Plot Centroids

* `Mat plot_centroids(Mat plotimg, vector<pair<pair<double, double>, double>> &centroids, const uchar color[])` 
plots the centroids with green `+` symbol on source image 
* `Mat plot_centroids_white_background(Mat &img, vector<pair<pair<double, double>, double>> &centroids, const uchar color[])` 
plots the centroids with green `+` symbol 
on a white image with the same size as source image

## Links

* [Heavens-Above](https://www.heavens-above.com)

## Author

Zhongyu Chen
