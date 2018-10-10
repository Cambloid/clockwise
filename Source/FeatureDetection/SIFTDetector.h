#ifndef SIFTDETECTOR_H
#define SIFTDETECTOR_H

#include "Image/ImageContainer.h"
#include <opencv2/xfeatures2d.hpp>

class SIFTDetector
{
public:
    SIFTDetector();
    ~SIFTDetector();
    ImageContainer StartDetection(ImageContainer &imageContainer);

};

#endif // SIFTDETECTOR_H
