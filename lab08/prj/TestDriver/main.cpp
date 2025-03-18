#include <iostream>
#include "ModulesMyronenko.h"
#include <cmath>
#include <windows.h>
#include <iomanip>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001); // Переведення консолі в формат UTF-8
    SetConsoleCP(65001);

    double x, y, z; // Оголошення змінних

    cout << "Введіть три змінні(x, y, z): " << endl; //Введення змінних
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "z = ";
    cin >> z;

    double result = s_calculation (x, y, z); //Виклик функції яка приймає три змінні x,y,z
    cout << "\nS = sqrt(1 + |cos" <<x<< "|) + 2*π + ((|" <<z<< " - " <<x<< "|) / (sin " <<x<< "))^2) = "<< result << endl; // Вивидення роботи що виконує функція та результату який вона обчислює
    return 0;
}
