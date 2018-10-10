#ifndef ORBDETECTOR_H
#define ORBDETECTOR_H

#include "Image/ImageContainer.h"

#include <opencv2/features2d.hpp>

class ORBDetector
{
private:
    int numFeatures = 10000;

public:
    ORBDetector();
    ~ORBDetector();
    ImageContainer StartDetection(ImageContainer &imageContainer);


    int getNumFeatures() const;
    void setNumFeatures(int value);
};

#endif // ORBDETECTOR_H
