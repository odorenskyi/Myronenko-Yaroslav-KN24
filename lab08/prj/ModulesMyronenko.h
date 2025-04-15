#ifndef MODULESMYRONENKO_H_INCLUDED
#define MODULESMYRONENKO_H_INCLUDED
#include <string>
#include <vector>

double s_calculation (double x, double y, double z); //Оголошення функції знаходження змінної S
void Dev_inf (); //Оголошення функції виведення інформації про розробника
std::string fujita_scale (double speed); // Оголошення функції для визначення категорії торнадо за шкалою Фудзіти
void average_daily_temp (); // Оголошення функції для визначення середньодобової температури
int count_bits (unsigned short N); // Оголошення функції для побітової обробки числа
void task_10_1(const std::string& inputFile, const std::string& outputFile); // Функція для перевірки наявності слова у вірші та записує результати у вихідний файл
void task_10_2(const std::string& inputFile, const std::string& outputFile); // Додає поточну дату й час запису до вихідного файлу
void task_10_3(double x, double y, double z, int b, const std::string& inputFile, const std::string& outputFile); // Викликає функцію s_calculation та переводе число b в двійкове і записує все в вихідний файл
std::wstring to_wstring(const std::string& str);


#endif // MODULESMYRONENKO_H_INCLUDED
