#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct Point {
    double x, y;
} Point;

double cross_product(Point a, Point b, Point c) {
    double y1 = a.y - b.y;
    double y2 = a.y - c.y;
    double x1 = a.x - b.x;
    double x2 = a.x - c.x;
    return y2 * x1 - y1 * x2;
}

int isConvex(Point points[], int n) {
    if (n < 4)
        return 1;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        double z = cross_product(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (z < 0) {
            if (flag == 1)
                return 0;
            flag = 2;
        }
        else if (z > 0) {
            if (flag == 2)
                return 0;
            flag = 1;
        }
    }
    return 1;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n, i;
    scanf("%d", &n);
    Point* points = (Point*)malloc(n * sizeof(Point));

    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    if (isConvex(points, n))
        printf("Многоугольник выпуклый\n");
    else
        printf("Многоугольник не выпуклый\n");
    free(points);
    return 0;
}
