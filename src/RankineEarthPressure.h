#ifndef RANKINEEP_H
#define RANKINEEP_H

#include "LateralEarthPressure.h"

class RankineEarthPressure : public LateralEarthPressure
{
public:
    RankineEarthPressure();
    RankineEarthPressure(double unitWeight, double bottomDepth,
                         double phiAngle, double betaAngle);
    ~RankineEarthPressure();
    double lateralEarthPressure();
    double lateralEarthPressure(double depth);
    double passiveLateralCoefficient();
    double activeLateralCoefficient();

private:

};

#endif // RANKINEEP_H
