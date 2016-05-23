#include <iostream>
#include "../src/LateralEarthPressure.h"
#include "../src/RankineEarthPressure.h"

void testRankineActive(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle)
{
    RankineEarthPressure test(unitWeight, bottomDepth, phiAngle, betaAngle);
    test.setPressureState(PressureState::Active);
    std::cout << "Unit Weight = " << test.getUnitWeight() << std::endl
              << "Friction Angle = " << test.getPhiAngle() << std::endl
              << "Beta Angle = " << test.getBetaAngle() << std::endl
              << "k active = "
              << test.activeLateralCoefficient() << std::endl
              << "P at bottom = " << test.lateralEarthPressure() << std::endl
              << "P at mid = "
              << test.lateralEarthPressure(test.getBottomDepth() / 2.0)
              << std::endl << std::endl;
}

void testRankinePassive(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle)
{
    RankineEarthPressure test(unitWeight, bottomDepth, phiAngle, betaAngle);
    test.setPressureState(PressureState::Passive);
    std::cout << "Unit Weight = " << test.getUnitWeight() << std::endl
              << "Friction Angle = " << test.getPhiAngle() << std::endl
              << "Beta Angle = " << test.getBetaAngle() << std::endl
              << "k passive = "
              << test.passiveLateralCoefficient() << std::endl
              << "P at bottom = " << test.lateralEarthPressure() << std::endl
              << "P at mid = "
              << test.lateralEarthPressure(test.getBottomDepth() / 2.0)
              << std::endl << std::endl;
}

void testRankineAtRest(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle)
{
    RankineEarthPressure test(unitWeight, bottomDepth, phiAngle, betaAngle);
    test.setPressureState(PressureState::AtRest);
    std::cout << "Unit Weight = " << test.getUnitWeight() << std::endl
              << "Friction Angle = " << test.getPhiAngle() << std::endl
              << "Beta Angle = " << test.getBetaAngle() << std::endl
              << "k at-rest = "
              << test.atRestLateralCoeficient() << std::endl
              << "P at bottom = " << test.lateralEarthPressure() << std::endl
              << "P at mid = "
              << test.lateralEarthPressure(test.getBottomDepth() / 2.0)
              << std::endl << std::endl;
}
