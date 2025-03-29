#ifndef MODULESMYRONENKO_H_INCLUDED
#define MODULESMYRONENKO_H_INCLUDED
#include <string>

double s_calculation (double x, double y, double z); //Оголошення функції знаходження змінної S
void Dev_inf (); //Оголошення функції виведення інформації про розробника
std::string fujita_scale (double speed); // Оголошення функції для визначення категорії торнадо за шкалою Фудзіти
void average_daily_temp (); // Оголошення функції для визначення середньодобової температури
int count_bits (unsigned short N); // Оголошення функції для побітової обробки числа

#endif // MODULESMYRONENKO_H_INCLUDED
