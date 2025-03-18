#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>
#include "ModulesMyronenko.h"
using namespace std;

string comparison (char a, char b){ //Функція для порівняння символів за задоною формулою
    bool result = (a + 3) <= b;    //Порівнняня за допомогою типу bool
    return result ? "True" : "False"; //Якщо bool = 1 то повернути True а якщо 0 то False
}

double output_num (double x, double y, double z){ //Функція для переведення чисел з десяткової в шіснадцяткову систему числення
    cout << "Значення змінних (x,y,z) в шіснадцятковій \nта десятковій системі счислення: " << endl;
    cout << "Десяткова система: " << dec << x << ", " << y << ", " << z << endl; // Змінні x,y,z в десятковій системі числення
    cout << "Шіснадцяткова система: " << hex << (int)x << ", " << (int)y << ", " << (int)z << endl; // Змінні x,y,z в шіснадцятковій системі числення

    double S = s_calculation(x, y, z); //Використання функції з статичної бібліотеки для підрахунку S за формулою
    cout << "\nS = sqrt(1 + |cos" <<x<< "|) + 2*π + ((|" <<z<< " - " <<x<< "|) / (sin " <<x<< "))^2) = ";
    return S; //Повернення результату
}

//Валідація введення символу
char getValidChar(const string& prompt) {
    char input;  //Отримання значення char
    string line;  // Рядок для зчитування всього вводу користувача

    while (true) {  //цикл для вивидення помилки та повернення до вводу змінної
        cout << prompt; //Виведення назви змінної в консоль яку треба ввести
        getline(cin, line); // зчитуємо рядок

        if (line.length() == 1) { //Перевірка чи введено один символ
            input = line[0]; //Отримуємо перший символ від користувача
            break; //Виходимо з циклу
        } else { //Якщо введено більше одного символа виводимо помилку
            cout << "Помилка! Введіть лише один символ.\n";
        }
    }
    return input; //Повертаємо перевірений символ
}

// Валідація введення числа
double getValidDouble(const string& prompt) {
    double input;  //Отримання значення

    while (true) {    //цикл для вивидення помилки та повернення до вводу змінної
        cout << prompt; //Виведення назви змінної в консоль яку треба ввести
        if (cin >> input) { //Перевірка чи введено число
            break;
        } else { //Якщо введене не число виводимо помилку
            cout << "Помилка! Введіть число.\n";
            cin.clear(); //Очищаємо помилку
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Очищаємо весь рядок до символу нового ряднка щоб уникнути зациклення
        }
    }
    return input;
}

int main()
{
    SetConsoleOutputCP(65001); //Переводимо консоль в формат UTF-8
    SetConsoleCP(65001);

    Dev_inf(); //функція викликана зі статичної бібліотеки з інф. про розробника

    char a, b;
    double x, y, z;

    cout << "\n\nВведіть два символи \nдля порівняння (a + 3 <= b)\n";
    a = getValidChar("a --> ");
    b = getValidChar("b --> ");

    cout << "Введення (x, y, z): " << endl;
    x = getValidDouble("x --> ");
    y = getValidDouble("y --> ");
    z = getValidDouble("z --> ");

    cout << "\nРезультат порівняння (a та b): " << comparison(a, b) << endl; //Використання функції для порівняння символів
    cout << endl;
    cout << output_num(x, y, z) << endl;   //Використання функції для переведення чисел та вивидення результату роботи функції яка обчислює S

    return 0;
}
