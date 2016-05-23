#include <iostream>
#include "TestCoulomb.h"
#include "../src/LateralEarthPressure.h"
#include "../src/CoulombEarthPressure.h"

void testCoulombActive(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle,
                       double deltaAngle, double thetaAngle)
{
    CoulombEarthPressure test(unitWeight, bottomDepth, phiAngle, betaAngle,
                              deltaAngle, thetaAngle);
    test.setPressureState(PressureState::Active);
    std::cout << "Unit Weight = " << test.getUnitWeight() << std::endl
              << "Friction Angle = " << test.getPhiAngle() << std::endl
              << "Beta Angle = " << test.getBetaAngle() << std::endl
              << "Delta Angle = " << test.getDeltaAngle() << std::endl
              << "Theta Angle = " << test.getThetaAngle() << std::endl
              << "k active = "
              << test.activeLateralCoefficient() << std::endl
              << "P at bottom = " << test.lateralEarthPressure() << std::endl
              << "P at mid = "
              << test.lateralEarthPressure(test.getBottomDepth() / 2.0)
              << std::endl << std::endl;
}

void testCoulombPassive(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle,
                       double deltaAngle, double thetaAngle)
{
    CoulombEarthPressure test(unitWeight, bottomDepth, phiAngle, betaAngle,
                              deltaAngle, thetaAngle);
    test.setPressureState(PressureState::Passive);
    std::cout << "Unit Weight = " << test.getUnitWeight() << std::endl
              << "Friction Angle = " << test.getPhiAngle() << std::endl
              << "Beta Angle = " << test.getBetaAngle() << std::endl
              << "Delta Angle = " << test.getDeltaAngle() << std::endl
              << "Theta Angle = " << test.getThetaAngle() << std::endl
              << "k passive = "
              << test.passiveLateralCoefficient() << std::endl
              << "P at bottom = " << test.lateralEarthPressure() << std::endl
              << "P at mid = "
              << test.lateralEarthPressure(test.getBottomDepth() / 2.0)
              << std::endl << std::endl;
}

void testCoulombAtRest(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle,
                       double deltaAngle, double thetaAngle)
{
    CoulombEarthPressure test(unitWeight, bottomDepth, phiAngle, betaAngle,
                              deltaAngle, thetaAngle);
    test.setPressureState(PressureState::Passive);
    std::cout << "Unit Weight = " << test.getUnitWeight() << std::endl
              << "Friction Angle = " << test.getPhiAngle() << std::endl
              << "Beta Angle = " << test.getBetaAngle() << std::endl
              << "Delta Angle = " << test.getDeltaAngle() << std::endl
              << "Theta Angle = " << test.getThetaAngle() << std::endl
              << "k passive = "
              << test.atRestLateralCoeficient() << std::endl
              << "P at bottom = " << test.lateralEarthPressure() << std::endl
              << "P at mid = "
              << test.lateralEarthPressure(test.getBottomDepth() / 2.0)
              << std::endl << std::endl;
}
