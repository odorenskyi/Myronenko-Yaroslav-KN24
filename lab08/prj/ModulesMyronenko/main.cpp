#include <iostream>
#include <fstream>      // Для роботи з файлами
#include <ctime>        // Для отримання дати та часу
#include <cctype>       // Для перевірки isalpha()
#include <string>       // Робота з рядками
#include <sstream>      // Форматування тексту

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


static int countConsonants(const string& word) {
    string letters = "аеєиіїоуюяАЕЄИІЇОУЮЯ";
    int count = 0;
    for (char ch : word) {
        if (isalpha(ch) && letters.find(ch) == string::npos) {
            count++;
        }
    }
    return count;
}

static bool isWordInPoem(const string& word) {
    string poem =
        "Про себе не кажи недобрих слів, "
        "Бо має сказане таємну силу. "
        "Кажи: «Я сильний, впевнений, щасливий!» "
        "І буде саме так, як ти хотів!";
    return poem.find(word) != string::npos;
}

// ===== ЗАДАЧА 10.1 =====
void task_10_1(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile, std::ios::app);

    string word;
    in >> word;

    // Авторська інформація
    out << "Розробник: Мироненко Ярослав\n";
    out << "Університет: ЦНТУ \n";
    out << "Місто: Кропривницький, Країна: Україна, Рік: 2025\n";

    // Підрахунок приголосних
    int consonants = countConsonants(word);
    out << "Кількість приголосних: " << consonants << "\n";

    // Чи є слово в поезії
    if (isWordInPoem(word)) {
        out << "Слово \"" << word << "\" є у вірші Іващенка.\n";
    } else {
        out << "Слово \"" << word << "\" відсутнє у вірші Іващенка.\n";
    }
}

// ===== ЗАДАЧА 10.2 =====
void task_10_2(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile, ios::app);

    string word;
    in >> word;

    if (!word.empty()) {
        out << "Перша літера: " << word.front() << "\n";
        out << "Остання літера: " << word.back() << "\n";
    }

    // Дата і час
    time_t now = std::time(nullptr);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    out << "Дата і час запису: " << buf << "\n";
}


