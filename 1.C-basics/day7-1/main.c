#include<stdio.h>

int main() {
	int num=0;// »»·¨ÊıÄ¿
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 20; j++) {
			for (int k = 1; k < 37; k++) {
				for (int m = 1; m < 37; m++) {
					if (i * 10 + j * 5 + k * 2 + m == 100 && i + j + k + m == 40) {
						num++;
					}
				}
			}
		}
	}
	printf("%d", num);
	return 0;
}