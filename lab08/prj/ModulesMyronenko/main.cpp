#include <iostream>
#include <cmath>

#define PI 3.141592653589793238

double s_calculation (double x, double y, double z) {

    if (sin(x) == 0) {
        return NAN;
    }

    double Additions1 = sqrt(1 + fabs(cos(x)));

    double Additions2 = pow(fabs(z - x) / sin(x), 2);

    double result = Additions1 + Additions2 + 2*PI;

    return result;
}
