#ifndef LATERALEARTHPRESSURE_H
#define LATERALEARTHPRESSURE_H

#include <string>

/*
*   Class enum that aids in setting the desired lateral earth pressure
*   state based on the assumed movement of the structure.
*/
enum class PressureState
{
    AtRest,
    Active,
    Passive
};

/*
*   Class to serve as the base for a set of classes to calculate lateral
*   earth pressure per AASHTO LRFD Bridge Design Specifications 7th edition
*   with 2016 interim revisions section 3.11.5 - Earth Pressure: EH.
*/
class LateralEarthPressure
{
public:
    LateralEarthPressure();
    virtual ~LateralEarthPressure();

    // getters
    double getUnitWeight() const;
    double getPhiAngle() const;
    double getBottomDepth() const;
    double getOCR() const;
    double getBetaAngle() const;
    std::string getPressureState() const;
    // setters
    void setUnitWeight(double weight);
    void setPhiAngle(double angle);  // Soil friction angle
    void setBottomDepth(double depth);  // Depth to bottom of wall
    void setOCR(double ocr);  // Overconsolidation ratio
    void setBetaAngle(double angle);  // Fill angle
    void setPressureState(PressureState state);
    // calculation lateral earth pressure per
    virtual double lateralEarthPressure() = 0;
    virtual double lateralEarthPressure(double depth) = 0;
    // calculation of lateral earth pressure coefficients
    double atRestLateralCoeficient();
    virtual double passiveLateralCoefficient() = 0;
    virtual double activeLateralCoefficient() = 0;

protected:
    double mSoilUnitWeight;
    double mPhiAngle;
    double mBottomDepth;
    double mOCR;
    double mBetaAngle;
    PressureState mState;
};

#endif // LATERALEARTHPRESSURE_H
