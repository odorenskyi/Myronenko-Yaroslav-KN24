#include <iostream>
#include "ModulesMyronenko.h"
#include <windows.h>
#include <limits>

using namespace std;



// Функція отримання валідної швидкості вітру
double get_valid_speed() {
    double speed;
    while (true) {
        cout << "\nВизначення категорії торнадо\nВведіть швидкість вітру (число більше 0): ";
        cin >> speed;

        if (cin.fail() || speed <= 0) {
            cout << "Помилка: введіть коректне додатнє число!" << endl;
            cin.clear(); // Очищуємо стан потоку
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Видаляємо некоректне введення
        } else {
            return speed;
        }
    }
}

// Функція отримання валідного числа для бітової обробки
unsigned short get_valid_number() {
    unsigned short number;
    while (true) {
        cout << "\nВизначення побітових нулів і одиниць" << endl;
        cout << "Введіть ціле число (0 - 65535): ";
        cin >> number;

        if (cin.fail()) {
            cout << "Помилка: введене значення не є валідним! Введіть число від (0 до 65535)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return number;
        }
    }
}

int main()
{
    SetConsoleOutputCP(65001); // Переведення консолі в формат UTF-8
    SetConsoleCP(65001);

    Dev_inf(); //функція викликана зі статичної бібліотеки з інф. про розробника

    double speed = get_valid_speed();
    cout << "Категорія торнадо за швидкістю " << speed << " км/год = " << fujita_scale(speed) << endl;

    cout << "\nОбчислення середньої температури ";
    average_daily_temp();

    unsigned short number = get_valid_number();
    int result = count_bits(number);
    cout << "Кількість бітів, які відповідають молодшому біту: " << result << endl;

    return 0;
}


