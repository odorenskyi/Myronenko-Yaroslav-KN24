#ifndef STRUCT_TYPE_PROJECT_3_H_INCLUDED
#define STRUCT_TYPE_PROJECT_3_H_INCLUDED

#include <string> 
using std::string; 

struct Date { // Date стпруктура для збереженння дати
    short day{0}; //
    short month{0};
    short year{0};
};

enum EducationLevel { // Перелічення для рівня освіти
    BasicSecondary, 
    CompleteSecondary, 
    Vocational,
    IncompleteHigher, 
    BasicHigher,
    Higher
};

struct WorkExperience { // Структура для збереження досвіду роботи
    short days{0};
    short months{0};
    short years{0};
};

struct PersonRecord { // Структура для збереження даних про особу
    Date created; // Дата створення запису
    int registrationNumber{-1}; // Номер реєстрації
    int identifier{-1}; // Ідентифікатор особи
    char sex{'m'}; // Стать особи
    char workType{'f'}; // Тип роботи (фізична/інтелектуальна)
    string name; // Ім'я особи
    Date birth; // Дата народження
    string nationality; // Національність
    EducationLevel education[4]{}; // Освіта особи (перелічення)
    string educationInstitutions[4]; // Освітні заклади
    string previousWorkplace; // Попереднє місце роботи
    string previousPosition; // Попередня посада
    WorkExperience experience; // Досвід роботи
    string address; // Адреса проживання
    string passportDetails; // Паспортні дані
    string extraInfo; // Додаткова інформація
    Date terminationDate; // Дата звільнення
    string terminationReason; // Причина звільнення
};

#endif // STRUCT_TYPE_PROJECT_3_H_INCLUDED
