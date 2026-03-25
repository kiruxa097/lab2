#include <stdio.h>
#include <math.h>
#include "sv.h"

int main() {
	float x = sinf(16000);
	float x1 = mysin1(16000);
	float x2 = mysin2(16000);
	float x3 = mysin3(16000);
	printf("Result lib: %f\n", x);
	printf("Result mylib1: %f\n", x1);
	printf("Result mylib2: %f\n", x2);
	printf("Result mylib3: %f\n", x3);

	return 0;
}
