#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;


const int n = 10000000;

//функция, по которой считается интеграл
double f(double x) {
    return cos(x);
}

//метод прямоугольника
double Rectangle(double l, double r) {
    double h = (r - l) / n;//шаг
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += h * f(l + i * h);
    return sum;
}

//метод трапеции
double Trapeze(double l, double r) {
    double h = (r - l) / n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 0 || i == n)
            sum += f(l + i * h) / 2;
        else
            sum += f(l + i * h);
    }
    sum *= h;
    return sum;
}

//метод Симпсона
double Sympson(double l, double r) {
    double h = (r - l) / n;
    double sum = f(l) + f(r);
    int k;
    for (int i = 1; i <= n; i++) {
        k = 2 + 2 * (i % 2);
        sum += k * f(l + i * h);
    }
    sum *= h / 3;
    return sum;
}

int main() {
    double a = 0, b = M_PI / 4.;
    cout << "Rect: " << Rectangle(a, b) << endl;
    cout << "Trapeze: " << Trapeze(a, b) << endl;
    cout << "Sympson: " << Sympson(a, b) << endl;

    return 0;
}