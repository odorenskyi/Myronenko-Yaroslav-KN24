#include <iostream>
#include <cmath>

#define PI 3.141592653589793238  //Число Pi яке задається на етапі препроцесингу

double s_calculation (double x, double y, double z) { //Оголошення функції

    if (sin(x) == 0) { //Перевірка на ділення на нуль
        return NAN;
    }

    double Additions1 = sqrt(1 + fabs(cos(x))); //Перша частина виразу

    double Additions2 = pow(fabs(z - x) / sin(x), 2); //Друга частина виразу

    double result = Additions1 + Additions2 + 2*PI; //Третя фінальна дія додавання двох частин з третьою в якій число Pi зазміняється на 3.141592653589793238 на етапі препроцесингу

    return result; // Повернення результату виконаних обчислень
}
