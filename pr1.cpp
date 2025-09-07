#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int myDivide(int left, int right) {
    if (right == 0) {
        throw runtime_error("Деление на ноль!");
    }
    if (left == numeric_limits<int>::min() && right == -1) {
        throw underflow_error("Переполнение снизу (underflow)!");
    }
    return left / right;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b;
    cout << "Введите два целых числа: ";
    cin >> a >> b;
    try {
        int res = myDivide(a, b);
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
    cout << "Программа завершена." << endl;
    return 0;
}