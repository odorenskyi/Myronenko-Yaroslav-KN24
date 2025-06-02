#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <sstream>
#include "ModulesMyronenko.h"

using namespace std;

struct TestCase {
    string id;
    string action;
    string expected;
};

bool compareDouble(double a, double b, double eps = 1e-6) {
    return fabs(a - b) < eps;
}

// Зчитування тест-кейсів з файлу
vector<TestCase> parseTestSuite(const string& path) {
    ifstream in(path);
    vector<TestCase> tests;
    string line;
    TestCase test;
    while (getline(in, line)) {
        if (line.find("Test Case ID:") == 0) test.id = line.substr(15);
        else if (line.find("Action:") == 0) test.action = line.substr(8);
        else if (line.find("Expected Result:") == 0) test.expected = line.substr(17);
        else if (line.find("Test Result:") == 0) {
            tests.push_back(test);
            test = TestCase(); // обнуляємо
        }
    }
    return tests;
}

// Тестування об’єкта за дією
bool runTest(const TestCase& test, ofstream& log, ClassLab12_Myronenko& obj) {
    log << "Test Case ID: " << test.id << "\n";
    log << "Action: " << test.action << "\n";
    log << "Expected Result: " << test.expected << "\n";

    try {
        string act = test.action;

        if (act == "new()") {
            obj = ClassLab12_Myronenko();
            stringstream expected(test.expected);
            string part;
            bool pass = true;

            while (getline(expected, part, ';')) {
                if (part.find("baseArea=") == 0)
                    pass &= compareDouble(obj.getBaseArea(), stod(part.substr(9)));
                else if (part.find("height=") == 0)
                    pass &= compareDouble(obj.getHeight(), stod(part.substr(7)));
                else if (part.find("material=") == 0)
                    pass &= (obj.getMaterial() == part.substr(9));
            }

            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act.find("new(") == 0) {
            size_t first = act.find("(") + 1;
            size_t last = act.find(")");
            string args = act.substr(first, last - first);
            stringstream ss(args);
            string token;
            vector<string> parts;
            while (getline(ss, token, ',')) parts.push_back(token);
            if (parts.size() != 3) throw runtime_error("Invalid arguments");

            obj = ClassLab12_Myronenko(stod(parts[0]), stod(parts[1]), parts[2]);

            stringstream expected(test.expected);
            string part;
            bool pass = true;
            while (getline(expected, part, ';')) {
                if (part.find("baseArea=") == 0)
                    pass &= compareDouble(obj.getBaseArea(), stod(part.substr(9)));
                else if (part.find("height=") == 0)
                    pass &= compareDouble(obj.getHeight(), stod(part.substr(7)));
                else if (part.find("material=") == 0)
                    pass &= (obj.getMaterial() == part.substr(9));
            }

            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act.find("setHeight(") == 0) {
            double val = stod(act.substr(10, act.size() - 11));
            bool result = obj.setHeight(val);
            if (test.expected == "false") {
                log << "Test Result: " << (!result ? "PASS" : "FAIL") << "\n\n";
                return !result;
            }
            bool pass = compareDouble(obj.getHeight(), stod(test.expected.substr(7)));
            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act.find("setBaseArea(") == 0) {
            double val = stod(act.substr(12, act.size() - 13));
            obj.setBaseArea(val);
            bool pass = compareDouble(obj.getBaseArea(), stod(test.expected.substr(9)));
            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act.find("setMaterial(") == 0) {
            string val = act.substr(12, act.size() - 13);
            obj.setMaterial(val);
            bool pass = (obj.getMaterial() == test.expected.substr(9));
            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act.find("setAttributes(") == 0) {
            size_t first = act.find("(") + 1;
            size_t last = act.find(")");
            string args = act.substr(first, last - first);
            stringstream ss(args);
            string token;
            vector<string> parts;
            while (getline(ss, token, ',')) parts.push_back(token);
            if (parts.size() != 3) throw runtime_error("Invalid arguments");

            bool result = obj.setAttributes(stod(parts[0]), stod(parts[1]), parts[2]);
            bool pass = (test.expected == "false") ? !result : result;
            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act == "getBaseArea()") {
            bool pass = compareDouble(obj.getBaseArea(), stod(test.expected.substr(9)));
            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act == "getHeight()") {
            bool pass = compareDouble(obj.getHeight(), stod(test.expected.substr(7)));
            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act == "getMaterial()") {
            bool pass = (obj.getMaterial() == test.expected.substr(9));
            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        if (act == "calculateVolume()") {
        bool pass = compareDouble(obj.calculateVolume(), stod(test.expected.substr(7)));
            log << "Test Result: " << (pass ? "PASS" : "FAIL") << "\n\n";
            return pass;
        }

        log << "Test Result: FAIL (Unknown action)\n\n";
        return false;

    } catch (exception& e) {
        log << "Test Result: FAIL (Exception: " << e.what() << ")\n\n";
        return false;
    }
}

int main() {
    for (int i = 0; i < 100; ++i) Beep(1000, 10);

    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    string exePath(path);

    string suitePath = "C:\\University\\BMTP\\Myronenko-Yaroslav-KN24\\lab12\\TestSuite\\TestSuite.txt";
    string resultPath = "C:\\University\\BMTP\\Myronenko-Yaroslav-KN24\\lab12\\TestSuite\\TestResults.txt";

    if (exePath.find("\\lab12\\prj\\Teacher\\") == string::npos &&
        exePath.find("\\Lab12\\prj\\Teacher\\") == string::npos) {
        ofstream failOut(resultPath);
        failOut << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        return 0;
    }

    vector<TestCase> tests = parseTestSuite(suitePath);

    ofstream out(resultPath);
    if (!out.is_open()) {
        cerr << "Unable to open results file" << endl;
        return 1;
    }

    ClassLab12_Myronenko obj;;

    for (const auto& test : tests) {
    ClassLab12_Myronenko obj; // створюємо новий об’єкт перед кожним тестом
    runTest(test, out, obj);
}

    out.close();

    cout << "Testing completed. Results saved in TestResults.txt" << endl;
    return 0;
}
