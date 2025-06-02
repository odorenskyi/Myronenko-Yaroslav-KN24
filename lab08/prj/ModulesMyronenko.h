#ifndef MODULESMYRONENKO_H_INCLUDED
#define MODULESMYRONENKO_H_INCLUDED
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

// Клас який представляє абстракцію правильної піраміди
class ClassLab12_Myronenko {
private:
    double baseArea;
    double height;
    std::string material;

    bool isValid(double value) const {
        return value > 0;
    }

public:
    ClassLab12_Myronenko(double baseArea = 1.0, double height = 1.0, std::string material = "червона цегла");

    double getBaseArea() const;
    double getHeight() const;
    std::string getMaterial() const;
    bool setBaseArea(double newBaseArea);
    bool setHeight(double newHeight);
    bool setMaterial(const std::string& newMaterial);
    bool setAttributes(double newBaseArea, double newHeight, const std::string& newMaterial);
    double calculateVolume() const;
};

// Конструктор з параметрами за замовчуванням
ClassLab12_Myronenko::ClassLab12_Myronenko(double baseArea, double height, std::string material) {
    if (!isValid(baseArea) || !isValid(height)) {
        std::cerr << "Неприпустимі значення. Встановлено значення за замовчуванням.\n";
        this->baseArea = 1.0;
        this->height = 1.0;
        this->material = "червона цегла";
    } else {
        this->baseArea = baseArea;
        this->height = height;
        this->material = material;
    }
}

// Повертає площу основи
inline double ClassLab12_Myronenko::getBaseArea() const {
    return baseArea;
}

// Повертає висоту
inline double ClassLab12_Myronenko::getHeight() const {
    return height;
}

// Повертає матеріал
inline std::string ClassLab12_Myronenko::getMaterial() const {
    return material;
}

// Встановлює площу основи
inline bool ClassLab12_Myronenko::setBaseArea(double newBaseArea) {
    if (isValid(newBaseArea)) {
        baseArea = newBaseArea;
        return true;
    }
    baseArea = 1.0;
    return false;
}

// Встановлює висоту
inline bool ClassLab12_Myronenko::setHeight(double newHeight) {
    if (isValid(newHeight)) {
        height = newHeight;
        return true;
    }
    height = 1.0;
    return false;
}

inline bool ClassLab12_Myronenko::setMaterial(const std::string& newMaterial) {
    if (!newMaterial.empty()) {
        material = newMaterial;
        return true;
    }
    material = "червона цегла";
    return false;
}

// Встановлює обидва параметри (перевантажена логіка)
inline bool ClassLab12_Myronenko::setAttributes(double newBaseArea, double newHeight, const std::string& newMaterial) {
    if (isValid(newBaseArea) && isValid(newHeight) && !newMaterial.empty()) {
        baseArea = newBaseArea;
        height = newHeight;
        material = newMaterial;
        return true;
    }
    return false;
}

// Обчислює об'єм правильної піраміди
inline double ClassLab12_Myronenko::calculateVolume() const {
    return (1.0 / 3.0) * baseArea * height;
}

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
