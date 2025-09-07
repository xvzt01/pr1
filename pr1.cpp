#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int myDivide(int left, int right) {
    if (right == 0) {
        throw runtime_error("������� �� ����!");
    }
    if (left == numeric_limits<int>::min() && right == -1) {
        throw underflow_error("������������ ����� (underflow)!");
    }
    return left / right;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b;
    cout << "������� ��� ����� �����: ";
    cin >> a >> b;
    try {
        int res = myDivide(a, b);
        cout << "���������: " << res << endl;
    }
    catch (underflow_error& e) {
        cout << "������: " << e.what() << endl;
    }
    catch (runtime_error& e) {
        cout << "������: " << e.what() << endl;
    }
    catch (...) {
        cout << "����������� ������!" << endl;
    }
    cout << "��������� ���������." << endl;
    return 0;
}