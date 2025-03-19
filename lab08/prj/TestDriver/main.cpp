#include <iostream>
#include "ModulesMyronenko.h"
#include <cmath>
#include <windows.h>
#include <limits>
#include <iomanip>

using namespace std;

// Функція для валідації введення чисел
double getValidatedInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // Скидаємо помилку
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаємо рядок
            cout << "Помилка! Введіть числове значення!" << endl;
        } else {
            return value;
        }
    }
}

int main()
{
    SetConsoleOutputCP(65001); // Переведення консолі в формат UTF-8
    SetConsoleCP(65001);

    cout << "Введіть три змінні(x, y, z): " << endl; //Введення змінних
    double x = getValidatedInput("x = ");
    double y = getValidatedInput("y = ");
    double z = getValidatedInput("z = ");

    double result = s_calculation (x, y, z); //Виклик функції яка приймає три змінні x,y,z
    cout << "\nS = sqrt(1 + |cos" <<x<< "|) + 2*π + ((|" <<z<< " - " <<x<< "|) / (sin " <<x<< "))^2) = "<< result << endl; // Вивидення роботи що виконує функція та результату який вона обчислює
    return 0;
}
