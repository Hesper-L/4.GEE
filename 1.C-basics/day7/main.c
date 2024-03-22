#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include<stdio.h>

int main() {
	int n;
	int total = 1;
	scanf("%d", &n);
	while (n) {
		total *=n;
		n--;
	}
	printf("%d", total);
	return 0;
}