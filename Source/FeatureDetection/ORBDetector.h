#ifndef SIFTDETECTOR_H
#define SIFTDETECTOR_H

#include "Image/ImageContainer.h"

#include <opencv2/features2d.hpp>

class ORBDetector
{
public:
    ORBDetector();
    ~ORBDetector();
    ImageContainer StartDetecion(ImageContainer &imageContainer);
};

#endif // SIFTDETECTOR_H
