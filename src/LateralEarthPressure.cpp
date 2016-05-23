#include <math.h>
#include "LateralEarthPressure.h"

/*
*   Abstract class for lateral earth pressure of soil behind retaining walls.
*   Classes for calculating earth pressures based on Rankine's or Coulomb's
*   theory of lateral earth pressure shall inherit this class. Note that these
*   classes do not take units into account.
*/

LateralEarthPressure::LateralEarthPressure() : mSoilUnitWeight(0.0),
                                               mPhiAngle(0.0),
                                               mBetaAngle(0.0),
                                               mBottomDepth(0.0),
                                               mOCR(1.0),
                                               mState(PressureState::AtRest)
{

}

LateralEarthPressure::~LateralEarthPressure()
{

}

// Return the unit weight of the backfill soil.
double LateralEarthPressure::getUnitWeight() const
{
    return mSoilUnitWeight;
}

// Return the backfill soil's friction angle.
double LateralEarthPressure::getPhiAngle() const
{
    return mPhiAngle;
}

// Return the depth to the bottom of the retaining wall.
double LateralEarthPressure::getBottomDepth() const
{
    return mBottomDepth;
}

// Return the overconsolidation ratio. This value will default to 1.0
// and will only change if the user sets a new ratio.
double LateralEarthPressure::getOCR() const
{
    return mOCR;
}

// Return the slope angle of the backfill with respect to the top of the
// back wall.
double LateralEarthPressure::getBetaAngle() const
{
    return mBetaAngle;
}

// Return the currently active pressure state based on the predicted
// deflection of retaining wall.
std::string LateralEarthPressure::getPressureState() const
{
    if (mState == PressureState::Active)
    {
        return "Active";
    }
    else if(mState == PressureState::Passive)
    {
        return "Passive";
    }
    else
    {
        return "At-Rest";
    }
}

// Set the unit weight of the soil.
void LateralEarthPressure::setUnitWeight(double weight)
{
    mSoilUnitWeight = weight;
}

// Set the friction angle of the soil.
void LateralEarthPressure::setPhiAngle(double angle)
{
    mPhiAngle = angle;
}

// Set the bottom of wall depth.
void LateralEarthPressure::setBottomDepth(double depth)
{
    mBottomDepth = depth;
}

// Set the overconsolidation ratio.
void LateralEarthPressure::setOCR(double ocr)
{
    mOCR = ocr;
}

// Set the fill slope angle.
void LateralEarthPressure::setBetaAngle(double angle)
{
    mBetaAngle = angle;
}

// Set the pressure state based on predicted deflection of the retaining wall.
void LateralEarthPressure::setPressureState(PressureState state)
{
    mState = state;
}

// Calculate the lateral earth pressure at the bottom of wall using
// EQ. 3.11.5.1-1 in the AASHTO LRFD Bridge Design Specifications,
// 7th Edition, with 2016 Interim Revisions. [pg. 3-104].
double LateralEarthPressure::lateralEarthPressure()
{
    // Pure virtual function
}

// Calculate the lateral earth pressure at a given depth using
// EQ. 3.11.5.1-1 in the AASHTO LRFD Bridge Design Specifications,
// 7th Edition, with 2016 Interim Revisions. [pg. 3-104].
double lateralEarthPressure(double depth)
{
    // Pure virtual function
}

// Calculate the at-rest lateral earth pressure coefficient using
// EQ. 3.11.5.2-2 in the AASHTO LRFD Bridge Design Specifications,  7th
// Edition, with 2016 Interim Revisions. [pg. 3-105]
double LateralEarthPressure::atRestLateralCoeficient()
{
    return (1.0 - sin(mPhiAngle)) * pow(mOCR, sin(mPhiAngle));
}

// Calculate the passive lateral earth pressure coefficient using
// either Coulomb or Rankine theory of lateral earth pressure.
double LateralEarthPressure::passiveLateralCoefficient()
{
    // Pure virtual function
}

// Calculate the active lateral earth pressure coefficient using
// either Coulomb or Rankine theory of lateral earth pressure
double LateralEarthPressure::activeLateralCoefficient()
{
    // Pure virtual function
}
