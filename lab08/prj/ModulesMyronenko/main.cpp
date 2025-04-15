#include <iostream>
#include <fstream>      // Для роботи з файлами
#include <ctime>        // Для отримання дати та часу
#include <cctype>       // Для перевірки isalpha()
#include <cwctype>
#include <string>       // Робота з рядками
#include <sstream>      // Форматування тексту
#include <cmath>
#include <limits>
#include <windows.h>
#include <algorithm>
#include <codecvt>
#include <locale>
#include <vector>

#define PI 3.141592653589793238  //Число Pi яке задається на етапі препроцесингу

using namespace std;

double s_calculation (double x, double y, double z) { //Оголошення функції

    if (sin(x) == 0) { //Перевірка на ділення на нуль
        return NAN;
    }

    double Additions1 = sqrt(1 + fabs(cos(x))); //Перша частина виразу

    double Additions2 = pow(fabs(z - x) / sin(x), 2); //Друга частина виразу

    double result = Additions1 + Additions2 + 2*PI; //Третя фінальна дія додавання двох частин з третьою в якій число Pi зазміняється на 3.141592653589793238 на етапі препроцесингу

    return result; // Повернення результату виконаних обчислень
}

string fujita_scale (double speed) {

    if (speed < 65)  // Перевірка, чи є швидкість меншою за мінімальну межу
        return "Мала швидкість для виникнення торнадо";

    if (speed <= 115) // Перевірка діапазону швидкості для F0 категорії
        return "F0 (38.9% виникнення)";

    if (speed <= 180) // Перевірка діапазону швидкості для F1 категорії
        return "F1 (35.6% виникнення)";

    if (speed <= 253) // Перевірка діапазону швидкості для F2 категорії
        return "F2 (19.4% виникнення)";

    if (speed <= 332) // Перевірка діапазону швидкості для F3 категорії
        return "F3 (4.9% виникнення)";

    if (speed <= 418) // Перевірка діапазону швидкості для F4 категорії
        return "F4 (1.1% виникнення)";

    if (speed <= 512) // Перевірка діапазону швидкості для F5 категорії
        return "F5 (менше 0.1% виникнення)";

    return "Такої швидкості вітру не існує"; // Повернення повідомлення про невалідне число
}

void average_daily_temp () {
    // Обчислення середньодобової температури
    double temp[6];
    int hours[] = {0, 4, 8, 12, 16, 20}; // Часи вимірювання

    cout << "Введіть температуру в наступні години:\n";
    for (int counter = 0; counter < 6; counter++) { // Перебір значень з масиву
        cout << hours[counter] << ":00 -> "; // Додавання всіх значень температури
        cin >> temp[counter];
    }

    // Обчислення середньої температури
    double total_temp = 0;
    for (int counter = 0; counter < 6; counter++) {
        total_temp += temp[counter];
    }

    double average_celsius = total_temp / 6; // Знаходження середньодобової температури

    // Конвертація в градуси Фаренгейта
    double average_fahrenheit = (average_celsius * 9.0 / 5.0) + 32.0;

    cout << "\nСередньодобова температура:" << endl;
    cout << "В градусах Цельсія: " << average_celsius << " °C" << endl;
    cout << "В градусах Фаренгейта: " << average_fahrenheit << " °F" << endl;
}

int count_bits (unsigned short N) {
    if (N == 0) {
        cout << "Число дорівнює 0, бітів зі значенням 1 немає." << endl;
        return 0;
    }

    bool bit = N & 1; // Перевіряємо значення молодшого біта (1 або 0)
    int count = 0;

    while (N) {  // Поки число не стане нулем
        if ((N & 1) == bit) {
            count++;  // Підраховуємо біти, які відповідають молодшому біту
        }
        N >>= 1;  // Зсуваємо число праворуч на 1 біт
    }

    return count;
}

// Lab_10
// Функція для збереження UTF-8 тексту у файл з BOM (Byte Order Mark)
bool WriteUtf8File(const string& filename, const string& text) {
    // Додаємо UTF-8 BOM
    vector<unsigned char> buffer = {0xEF, 0xBB, 0xBF};

    // Додаємо текст
    for (char c : text) {
        buffer.push_back(static_cast<unsigned char>(c));
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

// Функція для читання UTF-8 тексту з файлу
string ReadUtf8File(const string& filename) {
    HANDLE hFile = CreateFileA(
        filename.c_str(),
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        return "";
    }

    DWORD fileSize = GetFileSize(hFile, NULL);
    if (fileSize == INVALID_FILE_SIZE) {
        CloseHandle(hFile);
        return "";
    }

    vector<char> buffer(fileSize);
    DWORD bytesRead;
    bool success = ReadFile(
        hFile,
        buffer.data(),
        fileSize,
        &bytesRead,
        NULL
    );

    CloseHandle(hFile);

    if (!success || bytesRead == 0) {
        return "";
    }

    // Пропускаємо BOM, якщо він є
    size_t start = 0;
    if (fileSize >= 3 &&
        static_cast<unsigned char>(buffer[0]) == 0xEF &&
        static_cast<unsigned char>(buffer[1]) == 0xBB &&
        static_cast<unsigned char>(buffer[2]) == 0xBF) {
        start = 3;
    }

    return string(buffer.begin() + start, buffer.end());
}

// Функція для конвертації UTF-8 у широкі символи
wstring Utf8ToWide(const string& utf8) {
    if (utf8.empty()) {
        return L"";
    }

    int size_needed = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, NULL, 0);
    vector<wchar_t> wideStr(size_needed);
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, wideStr.data(), size_needed);

    return wstring(wideStr.begin(), wideStr.end() - 1); // Видаляємо нульовий символ
}

// Функція для конвертації широких символів в UTF-8
string WideToUtf8(const wstring& wide) {
    if (wide.empty()) {
        return "";
    }

    int size_needed = WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), -1, NULL, 0, NULL, NULL);
    vector<char> utf8Str(size_needed);
    WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), -1, utf8Str.data(), size_needed, NULL, NULL);

    return string(utf8Str.begin(), utf8Str.end() - 1); // Видаляємо нульовий символ
}

// ===== Підрахунок приголосних =====
int countConsonants(const wstring& word) {
    const wstring ukrVowels = L"аеєиіїоуюяАЕЄИІЇОУЮЯ";
    int count = 0;

    for (wchar_t ch : word) {
        if (iswalpha(ch) && ukrVowels.find(ch) == wstring::npos) {
            count++;
        }
    }

    return count;
}

// ===== Перетворення числа на двійковий рядок =====
string toBinary(int number) {
    if (number == 0) return "0";
    string result;
    while (number > 0) {
        result = char('0' + (number % 2)) + result;
        number /= 2;
    }
    return result;
}

// ===== ЗАДАЧА 10.1 =====
void task_10_1(const string& inputFile, const string& outputFile) {
    // Читаємо вхідний файл
    string utf8Input = ReadUtf8File(inputFile);
    wstring wordWide = Utf8ToWide(utf8Input);

    // Підготовка результату
    string result = "Розробник: Мироненко Ярослав\n";
    result += "Університет: ЦНТУ \n";
    result += "Місто: Кропривницький, Країна: Україна, Рік: 2025\n";

    // Підрахунок приголосних
    int consonants = countConsonants(wordWide);
    result += "Кількість приголосних: " + to_string(consonants) + "\n";

    // Перевірка наявності у вірші
    wstring poem = L"Про себе не кажи недобрих слів, "
                   L"Бо має сказане таємну силу. "
                   L"Кажи: «Я сильний, впевнений, щасливий!» "
                   L"І буде саме так, як ти хотів!";

    string wordUtf8 = WideToUtf8(wordWide);

    if (poem.find(wordWide) != wstring::npos) {
        result += "Слово \"" + wordUtf8 + "\" є у вірші Іващенка.\n";
    } else {
        result += "Слово \"" + wordUtf8 + "\" відсутнє у вірші Іващенка.\n";
    }

    // Записуємо результат
    WriteUtf8File(outputFile, result);
}

// ===== ЗАДАЧА 10.2 =====
void task_10_2(const string& inputFile, const string& outputFile) {
    // Читаємо вхідний файл
    string utf8Input = ReadUtf8File(inputFile);
    wstring wordWide = Utf8ToWide(utf8Input);

    // Підготовка результату
    string result = "";

    if (!wordWide.empty()) {
        wchar_t first = wordWide.front();
        wchar_t last = wordWide.back();

        string firstUtf8 = WideToUtf8(wstring(1, first));
        string lastUtf8 = WideToUtf8(wstring(1, last));

        result += "Перша літера: " + firstUtf8 + "\n";
        result += "Остання літера: " + lastUtf8 + "\n";
    } else {
        result += "Помилка: файл порожній або слово відсутнє!\n";
    }

    // Дата і час
    time_t now = time(nullptr);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    result += "Дата і час запису: " + string(buf) + "\n";

    // Записуємо результат
    WriteUtf8File(outputFile, result);
}

// ===== ЗАДАЧА 10.3 =====
void task_10_3(double x, double y, double z, int b, const string& inputFile, const string& outputFile) {
    // Зберігаємо параметри у вхідний файл
    string inputContent = "x= " + to_string(x) + " y= " + to_string(y) +
                          " z= " + to_string(z) + " b= " + to_string(b);
    WriteUtf8File(inputFile, inputContent);

    // Обчислення результату
    double result = s_calculation(x, y, z);

    // Підготовка результату
    string outputContent = "";

    if (isnan(result)) {
        outputContent += "Помилка: ділення на нуль у функції s_calculation(" +
                         to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")\n";
    } else {
        outputContent += "Результат s_calculation(" + to_string(x) + ", " +
                         to_string(y) + ", " + to_string(z) + ") = " + to_string(result) + "\n";
    }

    // Переведення числа в двійкову систему
    string binary = toBinary(b);
    outputContent += "Число " + to_string(b) + " у двійковій формі: " + binary + "\n";

    // Записуємо результат
    WriteUtf8File(outputFile, outputContent);
}

// Для сумісності зі старим кодом
wstring to_wstring(const string& str) {
    return Utf8ToWide(str);
}
