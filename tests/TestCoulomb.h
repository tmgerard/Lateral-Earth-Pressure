#ifndef TESTCOULOMB_H
#define TESTCOULOMB_H
#include "../src/LateralEarthPressure.h"
#include "../src/CoulombEarthPressure.h"

void testCoulombActive(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle,
                       double deltaAngle, double thetaAngle);
void testCoulombPassive(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle,
                       double deltaAngle, double thetaAngle);
void testCoulombAtRest(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle,
                       double deltaAngle, double thetaAngle);

#endif // TESTCOULOMB_H
