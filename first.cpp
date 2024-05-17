#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct {
    double x;
    int type;
} Point;

double epsilon = 1e-6;

int compare(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    if (fabs(p1->x - p2->x) <= epsilon)
        return p2->type - p1->type;
    return p1->x > p2->x ? 1 : -1 ;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n, i, cnt = 0, max = 0;
    scanf("%d", &n);
    Point* points = (Point*)malloc(2 * n * sizeof(Point));

    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &points[2 * i].x, &points[2 * i + 1].x);
        points[2 * i].type = 1;
        points[2 * i + 1].type = -1;
    }

    qsort(points, 2 * n, sizeof(Point), compare);

    for (i = 0; i < 2 * n; i++) {
        cnt += points[i].type;
        if (cnt > max)
            max = cnt;
    }

    printf("%d\n", max);
    free(points);
    return 0;
}
