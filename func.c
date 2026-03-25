#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sv.h"

#define y 180.f
#define h 360.f
#define M_PI 3.14159265f
#define eps 0.000001f

// Структура для функций
struct mac {
	float r;
	float s;
	int n;
	float temp;
	float *arr;
	int size;
};


float fact(int x)  // Факториал 
{
	float q = 1.f;
	for (int i = 2; i <= x; i++) { q *= i; }
	return q;
}

float sum1(struct mac* q)  // Прямая сумма 
{
	float sum = 0;
	for (int i = 0; i < q->n; i++)
	{
		sum += q->arr[i];
	}
	return sum;
}

float sum2(struct mac* q) // Обратное суммирование
{
	float sum = 0;
	for (int i = q->n-1; i >= 0; i--)
	{
		sum += q->arr[i];
	}
	return sum;
}

float sum3(struct mac* q, int l, int r) // Олимпийское суммирование
{
	if (l == r) { return q->arr[l]; }

	int mid = (l + r) / 2;

	return sum3(q, mid + 1, r) + sum3(q, l, mid);
}

float rad_in_yg(float x)  // Переводим радианы в градусы
{
	float yg = (x * y) / M_PI;
	return yg;
}

float yg_in_rad(float x) // Переводим градусы в радианы 
{
	float rad = (x * M_PI) / y;
	return rad;
}

float socr(float x)  // Сокращаем угол, чтобы был в диапазоне от 0 до 2p
{
	float r = fmod(x, h);
	return r;
}


void mac_sin(struct mac* q)  // Рекуррентная формула синуса 
{
	if (q->n == 0)
	{
		q->temp = q->r;
	}
	else
	{
		q->temp = q->temp * (-q->r * q->r) / ((2 * q->n) * (2 * q->n + 1));
	}

	if (q->n >= q->size)
	{
		q->size *= 2;
		q->arr = realloc(q->arr, q->size * sizeof(float));
	}

	q->arr[q->n] = q->temp;
	q->n++;

}

void mac_cos(struct mac *q)  // Рекуррентная функция косинуса и др.
{

	if (q->n == 0)
	{
		q->temp = 1;
	}
	else
	{
		q->temp = q->temp * (-q->r * q->r) / ((2 * q->n - 1) * (2 * q->n));
	}

	if (q->n >= q->size)
	{
		q->size *= 2;
		q->arr = realloc(q->arr, q->size * sizeof(float));
	}

	q->arr[q->n] = q->temp;
	q->n++;

}

void mac_exp(struct mac* q)  // Рекуррентная функция экспоненты и др.
{
	if (q->n == 0)
	{
		q->temp = 1;
	}
	else
	{
		q->temp = q->temp * (q->r) / (q->n);
	}

	if (q->n >= q->size)
	{
		q->size *= 2;
		q->arr = realloc(q->arr, q->size * sizeof(float));
	}

	q->arr[q->n] = q->temp;
	q->n++;

}

void mac_ln(struct mac* q)  // Рекуррентная функция натурального логарифма и др.
{
	if (q->n == 0)
	{
		q->temp = q->r;
	}
	else
	{
		q->temp = q->temp * q->r * q->r * (2*q->n-1)/(2*q->n+1);
	}

	if (q->n >= q->size)
	{
		q->size *= 2;
		q->arr = realloc(q->arr, q->size * sizeof(float));
	}

	q->arr[q->n] = q->temp;
	q->n++;

}

void mac_ret(struct mac* q, void (*ret)(struct mac*))  // Рекурсивная функция вызова рекурретных функций и др.
{
	do {
		ret(q);
	} while (fabs(q->temp) > eps);
}

// Прямая сумма синус
float mysin1(float x) {
	struct mac s1;
	s1.r = yg_in_rad(socr(rad_in_yg(x)));
	s1.s = 0.f;
	s1.n = 0;
	s1.temp = 0;
	s1.size = 10;
	s1.arr = malloc(s1.size * sizeof(float));

	mac_ret(&s1, mac_sin);
	s1.s = sum1(&s1);
	free(s1.arr);
	return s1.s;
}

// Обратная сумма синус
float mysin2(float x) {
	struct mac s1;
	s1.r = yg_in_rad(socr(rad_in_yg(x)));
	s1.s = 0.f;
	s1.n = 0;
	s1.temp = 0;
	s1.size = 10;
	s1.arr = malloc(s1.size * sizeof(float));

	mac_ret(&s1, mac_sin);
	s1.s = sum2(&s1);
	free(s1.arr);
	return s1.s;
}

// Олимп. сумма синус
float mysin3(float x) {
	struct mac s1;
	s1.r = yg_in_rad(socr(rad_in_yg(x)));
	s1.s = 0.f;
	s1.n = 0;
	s1.temp = 0;
	s1.size = 10;
	s1.arr = malloc(s1.size * sizeof(float));

	mac_ret(&s1, mac_sin);
	s1.s = sum3(&s1, 0, s1.n-1);
	free(s1.arr);
	return s1.s;
}

// Прямая сумма косинус
float mycos1(float x) {
	struct mac c1;
	c1.r = yg_in_rad(socr(rad_in_yg(x)));
	c1.s = 0.f;
	c1.n = 0;
	c1.temp = 0;
	c1.size = 10;
	c1.arr = malloc(c1.size * sizeof(float));

	mac_ret(&c1, mac_cos);
	c1.s = sum1(&c1);
	free(c1.arr);
	return c1.s;
}

// Обратная сумма косинус
float mycos2(float x) {
	struct mac c1;
	c1.r = yg_in_rad(socr(rad_in_yg(x)));
	c1.s = 0.f;
	c1.n = 0;
	c1.temp = 0;
	c1.size = 10;
	c1.arr = malloc(c1.size * sizeof(float));

	mac_ret(&c1, mac_cos);
	c1.s = sum2(&c1);
	free(c1.arr);
	return c1.s;
}


// Олимп. сумма косинус
float mycos3(float x) {
	struct mac c1;
	c1.r = yg_in_rad(socr(rad_in_yg(x)));
	c1.s = 0.f;
	c1.n = 0;
	c1.temp = 0;
	c1.size = 10;
	c1.arr = malloc(c1.size * sizeof(float));

	mac_ret(&c1, mac_cos);
	c1.s = sum3(&c1, 0, c1.n-1);
	free(c1.arr);
	return c1.s;
}


// Прямая сумма экспонента
float myexp1(float x) {
	struct mac e1;
	e1.r = x;
	e1.s = 0.f;
	e1.n = 0;
	e1.temp = 0;
	e1.size = 10;
	e1.arr = malloc(e1.size * sizeof(float));

	mac_ret(&e1, mac_exp);
	e1.s = sum1(&e1);
	free(e1.arr);
	return e1.s;
}

// Обратная сумма экспонента
float myexp2(float x) {
	struct mac e1;
	e1.r = x;
	e1.s = 0.f;
	e1.n = 0;
	e1.temp = 0;
	e1.size = 10;
	e1.arr = malloc(e1.size * sizeof(float));

	mac_ret(&e1, mac_exp);
	e1.s = sum2(&e1);
	free(e1.arr);
	return e1.s;
}

// Олимп. сумма экспонента
float myexp3(float x) {
	struct mac e1;
	e1.r = x;
	e1.s = 0.f;
	e1.n = 0;
	e1.temp = 0;
	e1.size = 10;
	e1.arr = malloc(e1.size * sizeof(float));

	mac_ret(&e1, mac_exp);
	e1.s = sum3(&e1, 0, e1.n - 1);
	free(e1.arr);
	return e1.s;
}

// Прямая сумма логарифм 
float myln1(float x) {
	struct mac l1;
	float z = (x - 1) / (x + 1);
	l1.r = z;
	l1.s = 0.f;
	l1.n = 0;
	l1.temp = 0;
	l1.size = 10;
	l1.arr = malloc(l1.size * sizeof(float));

	mac_ret(&l1, mac_ln);
	l1.s = sum1(&l1);
	free(l1.arr);
	return 2 * l1.s;
}

// Обратная сумма логарифм
float myln2(float x) {
	struct mac l1;
	float z = (x - 1) / (x + 1);
	l1.r = z;
	l1.s = 0.f;
	l1.n = 0;
	l1.temp = 0;
	l1.size = 10;
	l1.arr = malloc(l1.size * sizeof(float));

	mac_ret(&l1, mac_ln);
	l1.s = sum2(&l1);
	free(l1.arr);
	return 2 * l1.s;
}

// Олимп. сумма логарифм
float myln3(float x) {
	struct mac l1;
	float z = (x - 1) / (x + 1);
	l1.r = z;
	l1.s = 0.f;
	l1.n = 0;
	l1.temp = 0;
	l1.size = 10;
	l1.arr = malloc(l1.size * sizeof(float));

	mac_ret(&l1, mac_ln);
	l1.s = sum3(&l1, 0, l1.n - 1);
	free(l1.arr);
	return 2 * l1.s;
}
