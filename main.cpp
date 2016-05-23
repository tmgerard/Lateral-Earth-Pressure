#include <iostream>
#include <math.h>
#include "src/LateralEarthPressure.h"
#include "src/RankineEarthPressure.h"
#include "tests/TestRankine.h"

int main()
{
    const double PI = 3.14159265358979323846;
    double soilUnitWeight = 0.12; // kips per cubic foot
    double phiAngle = 30 * (PI / 180.0); // degrees to radians
    double betaAngle = 0 * (PI / 180.0);
    double bottomDepth = 10.0; // ft

    testRankinePassive(soilUnitWeight, bottomDepth, phiAngle, betaAngle);
    testRankineAtRest(soilUnitWeight, bottomDepth, phiAngle, betaAngle);
    testRankineActive(soilUnitWeight, bottomDepth, phiAngle, betaAngle);

    return 0;
}
