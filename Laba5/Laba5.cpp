#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int n) {
    if (n == 0) return 1;
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double computeCos(double x) {
    double sum = 1.0;
    double term;
    int n = 1;

    do {
        term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
        sum += term;
        n++;
    } while (fabs(term) >= 0.001);

    return sum;
}

int main() {
    int num[10];
    double x;
    setlocale(LC_ALL, "");

    printf("Введите значение x (в радианах): ");
    scanf("%lf", &x);

    double cosX = computeCos(x);
    printf("Cos(%.2f) = %.6f\n", x, cosX);

    for (int i = 0; i <= 10; i++)
    {
        printf("введите число массива %d", i);
        scanf("%d", num[i]);
    }
    printf("Четные числа:");
    for (int i = 0; i <= 10; i++)
    {
        if (num[i] % 2 == 0) {
            printf("Число номер %d само число :%d", i, num[i]);
        }//вывод на экран четных элеменотв массива

    }

    return 0;
}