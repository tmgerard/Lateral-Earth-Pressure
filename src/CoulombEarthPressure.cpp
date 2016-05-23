#include <math.h>
#include <assert.h>
#include "CoulombEarthPressure.h"
#include "LateralEarthPressure.h"

CoulombEarthPressure::CoulombEarthPressure()
{

}

CoulombEarthPressure::CoulombEarthPressure(double unitWeight, double bottomDepth,
                                           double phiAngle, double betaAngle,
                                           double deltaAngle, double thetaAngle)
{
    mSoilUnitWeight = unitWeight;
    mBottomDepth = bottomDepth;
    mPhiAngle = phiAngle;
    mBetaAngle = betaAngle;
    mDeltaAngle = deltaAngle;
    mThetaAngle = thetaAngle;
    mOCR = 1.0;
    mState = PressureState::AtRest;
}

CoulombEarthPressure::~CoulombEarthPressure()
{

}

// Return the friction angle between the fill and wall.
double CoulombEarthPressure::getDeltaAngle()
{
    return mDeltaAngle;
}

// Return the back face of wall angle.
double CoulombEarthPressure::getThetaAngle()
{
    return mThetaAngle;
}

// Set the friction angle between the fill and wall.
void CoulombEarthPressure::setDeltaAngle(double angle)
{
    mThetaAngle = angle;
}

// Set the back face of wall angle as shown in Figure 3.11.5.3-1 of the
// AASHTO LRFD Bridge Design Specifications, 7th Edition, with 2016
// Interim Revisions.
void CoulombEarthPressure::setThetaAngle(double angle)
{
    mThetaAngle = angle;
}

// Calculate the lateral earth pressure at the bottom of wall using
// EQ. 3.11.5.1-1 in the AASHTO LRFD Bridge Design Specifications,
// 7th Edition, with 2016 Interim Revisions. [pg. 3-104].
double CoulombEarthPressure::lateralEarthPressure()
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
double CoulombEarthPressure::lateralEarthPressure(double depth)
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
// EQ. 37.14 in the Civil Engineering Reference Manual, 9th Edition
double CoulombEarthPressure::passiveLateralCoefficient()
{
    double gamma = passiveGamma();

    double numerator;
    numerator = pow(sin(mThetaAngle - mPhiAngle), 2);

    double denominator;
    denominator = gamma * pow(sin(mThetaAngle), 2) * sin(mThetaAngle + mDeltaAngle);

    return numerator / denominator;
}

// Calculation of the active lateral earth pressure coefficient using
// EQ. 311.5.3-1 in the AASHTO LRFD Bridge Design Specifications, 7th
// Edition, with 2016 Interim Revisions. [pg. 3-106]
double CoulombEarthPressure::activeLateralCoefficient()
{
    double gamma = activeGamma();

    double numerator;
    numerator = pow(sin(mThetaAngle + mPhiAngle), 2);

    double denominator;
    denominator = gamma * pow(sin(mThetaAngle), 2) * sin(mThetaAngle - mDeltaAngle);

    return numerator / denominator;
}

// EQ. 3.11.5.3-2 in the AASHTO LRFD Bridge Design Specifications, 7th
// EQ. 311.5.3-1 in the AASHTO LRFD Bridge Design Specifications, 7th
// Edition, with 2016 Interim Revisions. [pg. 3-106]
double CoulombEarthPressure::activeGamma()
{
    double numerator;
    numerator = sin(mPhiAngle + mDeltaAngle) * sin(mPhiAngle - mBetaAngle);

    double denominator;
    denominator = sin(mThetaAngle - mDeltaAngle) * sin(mThetaAngle + mBetaAngle);

    assert(denominator != 0);
    assert(numerator / denominator >= 0);

    double inner;
    inner = 1 + sqrt(numerator / denominator);

    return pow(inner, 2);
}

// From EQ. 37.14 in the Civil Engineering Reference Manual, 9th Edition
double CoulombEarthPressure::passiveGamma()
{
    double numerator;
    numerator = sin(mPhiAngle + mDeltaAngle) * sin(mPhiAngle + mBetaAngle);

    double denominator;
    denominator = sin(mThetaAngle + mDeltaAngle) * sin(mThetaAngle + mBetaAngle);

    assert(denominator != 0);
    assert(numerator / denominator >= 0);

    double inner;
    inner = 1 - sqrt(numerator / denominator);

    return pow(inner, 2);
}
