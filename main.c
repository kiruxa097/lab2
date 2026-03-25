#include <stdio.h>
#include <math.h>
#include "sv.h"

int main() {
	int v; float u;
	float x1, x2, x3, x4;
	printf("Choose func: \n 1. sin \n 2. cos \n 3. exp \n 4. ln");
	printf("\n");
	printf("Choose: ");
	scanf_s("%d", &v);
	switch (v)
	{
	case 1:
		printf("Write x: ");
		scanf_s("%f", &u);
		x1 = mysin1(u);
		x2 = mysin2(u);
		x3 = mysin3(u);
		x4 = sinf(u);
		printf("\n");
		printf("result sum1: ");
		printf("%f", x1);
		printf("\n");
		printf("result sum2: ");
		printf("%f", x2);
		printf("\n");
		printf("result sum3: ");
		printf("%f", x1);
		printf("\n");
		printf("result sinf in math.h: ");
		printf("%f", x4);
		printf("\n");
		break;
	case 2:
		printf("Write x: ");
		printf("\n");
		scanf_s("%f", &u);
		x1 = mycos1(u);
		x2 = mycos2(u);
		x3 = mycos3(u);
		x4 = cosf(u);
		printf("\n");
		printf("result sum1: ");
		printf("%f", x1);
		printf("\n");
		printf("result sum2: ");
		printf("%f", x2);
		printf("\n");
		printf("result sum3: ");
		printf("%f", x1);
		printf("\n");
		printf("result cosf in math.h: ");
		printf("%f", x4);
		printf("\n");
		break;
	case 3:
		printf("Write x: ");
		printf("\n");
		scanf_s("%f", &u);
		x1 = myexp1(u);
		x2 = myexp2(u);
		x3 = myexp3(u);
		x4 = expf(u);
		printf("\n");
		printf("result sum1: ");
		printf("%f", x1);
		printf("\n");
		printf("result sum2: ");
		printf("%f", x2);
		printf("\n");
		printf("result sum3: ");
		printf("%f", x1);
		printf("\n");
		printf("result cosf in math.h: ");
		printf("%f", x4);
		printf("\n");
		break;
	case 4:
		printf("Write x: ");
		printf("\n");
		scanf_s("%f", &u);
		x1 = myln1(u);
		x2 = myln2(u);
		x3 = myln3(u);
		x4 = logf(u);
		printf("\n");
		printf("result sum1: ");
		printf("%f", x1);
		printf("\n");
		printf("result sum2: ");
		printf("%f", x2);
		printf("\n");
		printf("result sum3: ");
		printf("%f", x1);
		printf("\n");
		printf("result cosf in math.h: ");
		printf("%f", x4);
		printf("\n");
		break;
	}
	return 0;
}
