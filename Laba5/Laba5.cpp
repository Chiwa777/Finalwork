#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int n) {
    // Объявление переменной результата факториала
    double result = 1;

    if (n == 0) return 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double computeCos(double x) {
    // Накопительная сумма ряда, начинается с первого члена (1)
    double sum = 1.0;
    // Текущий член рядаS
    double term;
    // Счетчик для итераций, начинается с 1
    int n = 1;

    do {
        term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
        sum += term;
        n++;
    } while (fabs(term) >= 0.001);  // Продолжать цикл, пока текущий член ряда не станет меньше 0.001

    return sum;
}

int main() {
    // Входное значение в радианах
    double x;
    // Результат вычисления косинуса
    double cosX;
    setlocale(LC_ALL, "");

    printf("Введите значение x (в радианах): ");
    scanf("%lf", &x);

    // Проверка на положительность введенного значения
    if (x < 0) {
        printf("Внимание: Введено отрицательное значение x. Расчет будет выполнен для абсолютного значения.\n");
        x = fabs(x);
    }

    cosX = computeCos(x);
    printf("Cos(%.2f) = %.6f\n", x, cosX);

    return 0;
}