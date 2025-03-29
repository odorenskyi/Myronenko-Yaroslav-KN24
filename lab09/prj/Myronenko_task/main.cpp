#include <iostream>
#include <windows.h>
#include "ModulesMyronenko.h"
#include <string>
#include <limits>

using namespace std;


double get_valid_speed() { // Функція отримання валідної швидкості вітру
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


unsigned short get_valid_number() { // Функція отримання валідного числа для бітової обробки
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


char get_valid_choice() { // Функція для отримання валідного символу
    char choice;
    while (true) {
        cout << "\nМеню програми:" << endl;
        cout << "z - Виклик s_calculation()" << endl;
        cout << "r - Виклик функції fujita_scale(double speed) задачі 9.1" << endl;
        cout << "s - Виклик функції average_daily_temp() задачі 9.2" << endl;
        cout << "t - Виклик функції count_bits(unsigned short N) задачі 9.3" << endl;
        cout << "q - Вихід" << endl;
        cout << "Введіть символ: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення залишкових символів у потоці

        // Перевірка на коректність вводу
        if (choice == 'z' || choice == 'r' || choice == 's' || choice == 't' || choice == 'q' || choice == 'Q') {
            return choice; // Якщо символ правильний, повертаємо його
        } else {
            cout << "\aНевірний символ! Спробуйте ще раз." << endl; // Звуковий сигнал
            cin.clear(); // Очищаємо потік для уникнення помилок вводу
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ігноруємо залишкові символи в потоці
        }
    }
}

int main(){

    SetConsoleOutputCP(65001); // Встановлення UTF-8 для консолі
    SetConsoleCP(65001);

    Dev_inf(); // Виклик функції з бібліотеки про розробника

    while (true) {
    char choice = get_valid_choice(); // Отримуємо валідний символ

    switch (choice) {
            case 'z': {
                cout << "Виклик функції s_calculation() задачі 9.1" << endl;
                double x, y, z;
                cout << "Введіть значення x, y, z: ";
                cin >> x >> y >> z;
                double result = s_calculation(x, y, z);
                cout << "Результат: " << result << endl;
                break;
            }
            case 'r': {
                cout << "Виклик функції fujita_scale(double speed) задачі 9.1" << endl;
                double speed = get_valid_speed();
                cout << "Категорія торнадо за швидкістю " << speed << " км/год = " << fujita_scale(speed) << endl;
                break;
            }
            case 's': {
                cout << "Виклик функції average_daily_temp() задачі 9.2" << endl;
                average_daily_temp(); // Функція з бібліотеки
                break;
            }
            case 't': {
                cout << "Виклик функції count_bits(unsigned short N) задачі 9.3" << endl;
                unsigned short number = get_valid_number();
                int result = count_bits(number);
                cout << "Кількість бітів, які відповідають молодшому біту: " << result << endl;
                break;
            }
            case 'q':
            case 'Q':
                cout << "Вихід з програми..." << endl;
                return 0;
            default:
                break;
        }
    }

    return 0;
}
