#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int t) {
    if (t == 0) return 2;
    double result = 1;
    for (int i = 1; i <= t; i++) {
        result *= i;
    }
    return result;
}

double computeCos(double y) {
    double sum = 1.0;
    double term;
    int m = 1;

    do {
        term = pow(-1, m) * pow(y, 2 * m) / factorial(2 * m);
        sum += term;
        m++;
    } while (fabs(term) >= 0.001);

    return sum;
}

int main() {
    double c;
    setlocale(LC_ALL, "");

    printf("Введите значение x (в радианах): ");
    scanf("%lf", &c);

    double cosX = computeCos(c);
    printf("Cos(%.2f) = %.6f\n", c, cosX);

    return 0;
}