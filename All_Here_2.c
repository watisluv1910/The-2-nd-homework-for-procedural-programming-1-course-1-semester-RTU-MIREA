#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>

void f1() {
	printf("Введите высоту, радиус нижнего основания и радиус верхнего основания усечённого конуса: \n");
	double h, R, r;
	scanf_s("%lf%lf%lf", &h, &R, &r);
	double l = sqrt(pow((R - r), 2) + pow(h, 2));
	double V = M_PI * h * (pow(R, 2) + R * r + pow(r, 2)) / 3;
	double S = M_PI * (pow(R, 2) + (R + r) * l + pow(r, 2));
	printf("Объём  заданного усеченного конуса = %lf\n", V);
	printf("Площадь заданного усеченного конуса = %lf\n", S);
}

int f2(double x, double a, double* w) {
	
	if (fabs(x) < 1 && x!=0)
	{
		*w = a * log(fabs(x));
		return 0;
	}
	else if (x == 0)
	{
		return -1;
	}
	else
	{
		if (a < pow(x, 2))
		{
			return -1;
		}
		else 
		{
			*w = sqrt(a - pow(x, 2));
			return 0;
		}
	}
}

void f3() {
	printf("Введите числа x, y, b:\n");
	double x, y, b, z;
	scanf_s("%lf%lf%lf", &x, &y, &b);
	if (b - y <= 0 || b - x <= 0)
	{
		printf("Вычисление результата невозможно, т.к. подлогарифмическое выражение должно быть > 0.\n");
	}
	else
	{
		z = log(b - y) * sqrt(b - x);
		printf("Значение функции = %lf.\n", z);
	}
}

void f4() {
	printf("Введите число N - начало последовательности:\n");
	int N;
	scanf_s("%d", &N);
	for (int i = N; i < N + 10; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
}
 
void f5() {
	double x, y;
	int x_beg = -4, x_end = 4;
	for (int i = 0; i < (abs(x_beg)+abs(x_end))+1; i++)
	{
		x = 4 + i * 0.5;
		y = (pow(x, 2) - 2 * x + 2) / (x - 1);
		printf("Значение функции y при x = %.1lf = %.3lf.\n", x, y);
	}
}

void main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	printf("Номер задачи не превышает 5.\nЧтобы закончить работу, введите 0.\n");
	printf("Введите номер задачи: \n");
	scanf_s("%d", &counter);
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			f1();
			break;
		case 2:
			printf("Введите числа х и а:\n");
			double x, a, w=0;
			scanf_s("%lf%lf", &x, &a);
			if(!f2(x, a, &w))
			printf("%.1lf\n", w);
			break;
		case 3:
			f3();
			break;
		case 4:
			f4();
			break;
		case 5:
			f5();
			break;
		default:
			printf("Номер задачи не превышает 5.\nЧтобы закончить работу, введите 0.\n");
			break;
		}
		printf("Введите номер следующей задачи: \n");
		scanf_s("%d", &counter);
	}
	return 0;
}