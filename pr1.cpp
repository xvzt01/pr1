#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
using namespace std;

float myDivide(float x, float y) {
    if (y == 0.0f) {
        throw runtime_error("Деление на ноль!");
    }
    float r = x / y;
    if (r != 0.0f && fabs(r) < numeric_limits<float>::min()) {
        throw underflow_error("Переполнение снизу (underflow)!");
    }
    return r;
}

int main() {
    setlocale(LC_ALL, "Russian");
    while (true) {
        float a, b;
        cout << "\nВведите два числа (или q для выхода): ";
        if (!(cin >> a)) {
            if (cin.fail()) {
                cin.clear();
                string s;
                cin >> s;
                if (s == "q" || s == "Q") {
                    cout << "Выход из программы." << endl;
                    break;
                }
                cout << "Ошибка: нужно вводить числа!" << endl;
                continue;
            }
        }
        if (!(cin >> b)) {
            cin.clear();
            string s;
            cin >> s;
            cout << "Ошибка: нужно вводить числа!" << endl;
            continue;
        }
        try {
            float res = myDivide(a, b);
            cout << "Результат: " << res << endl;
        }
        catch (underflow_error& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
        catch (runtime_error& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
        catch (...) {
            cout << "Неизвестная ошибка!" << endl;
        }
    }
    return 0;
}
