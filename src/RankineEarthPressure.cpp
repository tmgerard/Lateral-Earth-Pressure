#include <math.h>
#include "RankineEarthPressure.h"
#include "LateralEarthPressure.h"

RankineEarthPressure::RankineEarthPressure() : LateralEarthPressure()
{

}

RankineEarthPressure::RankineEarthPressure(double unitWeight, double bottomDepth,
                         double phiAngle, double betaAngle)
{
    mSoilUnitWeight = unitWeight;
    mBottomDepth = bottomDepth;
    mPhiAngle = phiAngle;
    mBetaAngle = betaAngle;
    mOCR = 1.0;
    mState = PressureState::AtRest;
}

RankineEarthPressure::~RankineEarthPressure()
{

}

// Calculate the lateral earth pressure at the bottom of wall using
// EQ. 3.11.5.1-1 in the AASHTO LRFD Bridge Design Specifications,
// 7th Edition, with 2016 Interim Revisions. [pg. 3-104].
double RankineEarthPressure::lateralEarthPressure()
{
    double k; // lateral earth pressure coefficient

    switch(mState)
    {
    case PressureState::Active:
        k = activeLateralCoefficient();
        break;
    case PressureState::Passive:
        k = passiveLateralCoefficient();
        break;
    default: // default to at-rest condition
        k = atRestLateralCoeficient();
        break;
    }
    return k * mSoilUnitWeight * mBottomDepth;
}

// Calculate the lateral earth pressure at a given depth using
// EQ. 3.11.5.1-1 in the AASHTO LRFD Bridge Design Specifications,
// 7th Edition, with 2016 Interim Revisions. [pg. 3-104].
double RankineEarthPressure::lateralEarthPressure(double depth)
{
    double k; // lateral earth pressure coefficient

    switch(mState)
    {
    case PressureState::Active:
        k = activeLateralCoefficient();
        break;
    case PressureState::Passive:
        k = passiveLateralCoefficient();
        break;
    default: // default to at-rest condition
        k = atRestLateralCoeficient();
        break;
    }
    return k * mSoilUnitWeight * depth;
}

// Calculation of the passive lateral earth pressure coefficient using
// EQ. 37.15 in the Civil Engineering Reference Manual, 9th Edition
// [pg. 37-4]
double RankineEarthPressure::passiveLateralCoefficient()
{
    double numerator;
    numerator = cos(mBetaAngle) + sqrt(pow(cos(mBetaAngle), 2.0)
                                       - pow(cos(mPhiAngle), 2.0));
    double denominator;
    denominator = cos(mBetaAngle) - sqrt(pow(cos(mBetaAngle), 2.0)
                                       - pow(cos(mPhiAngle), 2.0));

    return cos(mBetaAngle) * (numerator / denominator);
}

// Calculation of the active lateral earth pressure coefficient using
// EQ. 37.6 in the Civil Engineering Reference Manual, 9th Edition
// [pg. 37-4]
double RankineEarthPressure::activeLateralCoefficient()
{
    double numerator;
    numerator = cos(mBetaAngle) - sqrt(pow(cos(mBetaAngle), 2.0)
                                       - pow(cos(mPhiAngle), 2.0));
    double denominator;
    denominator = cos(mBetaAngle) + sqrt(pow(cos(mBetaAngle), 2.0)
                                       - pow(cos(mPhiAngle), 2.0));

    return cos(mBetaAngle) * (numerator / denominator);
}

