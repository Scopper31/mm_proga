#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>



double delta = 1e-6;
double epsilon = 1e-6;

double df(double (*f)(double), double x) {
    return (f(x + delta) - f(x)) / delta;
}

double newton_method(double a, double b, int N, double (*f)(double)) {
    double x_n = a;
    double x_nm1 = a;
    double df_x_nm1;
    for (int i = 1; i <= N; i++) {
        x_nm1 = x_n;
        df_x_nm1 = df(f, x_nm1);
        if (df_x_nm1 == 0) 
            break;
        else
            x_n = x_nm1 - f(x_nm1) / df(f, x_nm1);
    }

    return x_n;
}

// Функции для тестирования метода Ньютона
double f1(double x) { return x - 2; } // Линейная функция
double df1(double x) { return 1; }

double f2(double x) { return x * x - 3; } // Парабола
double df2(double x) { return 2 * x; }

double f3(double x) { return sin(x); } // Синусоидальная функция
double df3(double x) { return cos(x); }

double f4(double x) { return x * x * x - 3 * x * x + 2; } // Кубическая функция
double df4(double x) { return 3 * x * x - 6 * x; }

int main() {
    setlocale(LC_ALL, "Rus");
    printf("Введите отрезок от a до b:\n");
    double a, b;
    scanf("%lf %lf", &a, &b);
    int N = 2;

    for (int i = 0; i < 10 ; ++i)
    {
        printf("\n-------------\n");
        printf("N = %d:\n", N);
        printf("Линейная функция:\n");
        printf("x_n = %f\n", newton_method(a, b, N, f1)); // Истинный корень: 2

        printf("\nПарабола:\n");
        printf("x_n = %f\n", newton_method(a, b, N, f2)); // Истинный корень: sqrt(3)

        printf("\nСинусоидальная функция:\n");
        printf("x_n = %f\n", newton_method(a, b, N, f3)); // Истинный корень: 0

        printf("\nКубическая функция:\n");
        printf("x_n = %f\n", newton_method(a, b, N, f4)); // Истинные корни: 1 и 2
        N *= 2;
    }
    


    return 0;
}
