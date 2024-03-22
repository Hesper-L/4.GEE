#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include<stdio.h>

int main() {
	int N,num=0;
	int a[100];
	scanf("%d", &N);
	for (int i = 0; i < N;i++) {
		scanf("%d", &a[i]);
		if (a[i] == 2) {
			num++;
		}
	}
	printf("%d", num);
	return 0;
}