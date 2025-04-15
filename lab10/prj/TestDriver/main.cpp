#include "ModulesMyronenko.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <limits> // Додано для numeric_limits

using namespace std;

// Функція для запису UTF-8 тексту з консолі в файл
bool SaveWideStringToUtf8File(const wstring& wideStr, const string& filename) {
    // Конвертація з wide string в UTF-8
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, wideStr.c_str(), -1, NULL, 0, NULL, NULL);
    vector<char> utf8Str(size_needed);
    WideCharToMultiByte(CP_UTF8, 0, wideStr.c_str(), -1, utf8Str.data(), size_needed, NULL, NULL);

    // Додаємо UTF-8 BOM
    vector<unsigned char> buffer = {0xEF, 0xBB, 0xBF};

    // Додаємо текст (за винятком останнього нуль-символу)
    for (int i = 0; i < size_needed - 1; i++) {
        buffer.push_back(static_cast<unsigned char>(utf8Str[i]));
    }

    // Записуємо у файл
    HANDLE hFile = CreateFileA(
        filename.c_str(),
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        return false;
    }

    DWORD bytesWritten;
    bool success = WriteFile(
        hFile,
        buffer.data(),
        buffer.size(),
        &bytesWritten,
        NULL
    );

    CloseHandle(hFile);
    return success && (bytesWritten == buffer.size());
}

int main() {
    // Налаштування консолі для коректного відображення українських символів
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    // Файлові шляхи
    const string input_file = "input.txt";
    const string output_file = "output_results.txt";

    int choice = 0;

    while (true) {
    wcout << L"=== Тестовий драйвер лабораторної №10 ===\n";
    wcout << L"1 - Завдання 10.1 (аналіз слова)\n";
    wcout << L"2 - Завдання 10.2 (перша та остання буква, дата/час)\n";
    wcout << L"3 - Завдання 10.3 (обчислення виразу та переведення числа)\n";
    wcout << L"4 - Вихід з програми\n";
    wcout << L"Оберіть номер функції для запуску: ";
    wcin >> choice;
    // Виправлено цей рядок
    wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n')

    if (choice == 1) {
        wstring word;
        wcout << L"Введіть слово для аналізу: ";
        getline(wcin, word);

        // Записуємо введене слово у вхідний файл
        if (!SaveWideStringToUtf8File(word, input_file)) {
            wcout << L"Помилка при записі вхідного файлу!\n";
            return 1;
        }

        task_10_1(input_file, output_file);
        wcout << L"Результат записано у файл: output_file.txt\n";

    } else if (choice == 2) {
        wstring word;
        wcout << L"Введіть слово: ";
        getline(wcin, word);

        // Записуємо введене слово у вхідний файл
        if (!SaveWideStringToUtf8File(word, input_file)) {
            wcout << L"Помилка при записі вхідного файлу!\n";
            return 1;
        }

        task_10_2(input_file, output_file);
        wcout << L"Результат записано у файл: output_file.txt\n";

    } else if (choice == 3) {
        double x, y, z;
        int b;
        wcout << L"Введіть x: ";
        wcin >> x;
        wcout << L"Введіть y: ";
        wcin >> y;
        wcout << L"Введіть z: ";
        wcin >> z;
        wcout << L"Введіть ціле число b для переведення в двійкову систему: ";
        wcin >> b;

        task_10_3(x, y, z, b, input_file, output_file);
        wcout << L"Результат записано у файл: output_file.txt\n";
    }

    else if (choice == 4) {
            break; // Вихід з програми
    }else {
        wcout << L"Невірний вибір. Спробуйте ще раз.\n";
    }
}
    return 0;
}
