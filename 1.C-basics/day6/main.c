#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include<stdio.h>

int main() {
	int num;
	int a1, a2, tmp;
	scanf("%d", &num);
	a1 = num;
	a2 = 0;
	while (a1)
	{
		tmp = a1 % 10;
		a2 = a2 * 10 + tmp;
		a1 = a1 / 10;
	}
	if (num == a2) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	return 0;
}