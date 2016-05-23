#ifndef TESTRANKINE_H
#define TESTRANKINE_H
#include "../src/LateralEarthPressure.h"
#include "../src/RankineEarthPressure.h"

void testRankineActive(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle);
void testRankinePassive(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle);
void testRankineAtRest(double unitWeight, double bottomDepth,
                       double phiAngle, double betaAngle);

#endif // TESTRANKINE_H
