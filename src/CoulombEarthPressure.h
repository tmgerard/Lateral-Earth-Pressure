#ifndef COULOMBEARTHPRESSURE_H
#define COULOMBEARTHPRESSURE_H

#include "LateralEarthPressure.h"


class CoulombEarthPressure : public LateralEarthPressure
{
public:
    CoulombEarthPressure();
    CoulombEarthPressure(double unitWeight, double bottomDepth,
                         double phiAngle, double betaAngle,
                         double deltaAngle, double thetaAngle);
    ~CoulombEarthPressure();
    // getters
    double getDeltaAngle();
    double getThetaAngle();
    // setters
    void setDeltaAngle(double angle);
    void setThetaAngle(double angle);
    double lateralEarthPressure();
    double lateralEarthPressure(double depth);
    double passiveLateralCoefficient();
    double activeLateralCoefficient();

private:
    double mDeltaAngle;  // friction angle between fill and wall
                         // as specified in Table 3.11.5.3-1
    double mThetaAngle;  // angle of back face of wall to the horizontal
                         // as shown in figure 3.11.5.3-1
    double activeGamma();
    double passiveGamma();
};

#endif // COULOMBEARTHPRESSURE_H
