#include <iostream>
#include "ModulesMyronenko.h"
#include <cmath>
#include <windows.h>
#include <iomanip>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    double x, y, z;

    cout << "Введіть три змінні(x, y, z): " << endl;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "z = ";
    cin >> z;

    double result = s_calculation (x, y, z);
    cout << "S = " << result << endl;
    return 0;
}
