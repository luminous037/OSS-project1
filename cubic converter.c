#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int find(int num) {
	int cubic=1;
	while (cubic * cubic * cubic <= num) {
		cubic++;
	}
	return cubic - 1;
}

int main() {

	int n;

	while (1) {

		printf("Enter an integer>> ");
		scanf("%d", &n);

		if (n == 0) break;

		while (n > 0) {

			int cubic=find(n);

			printf("%d", cubic * cubic * cubic);

			n -= cubic * cubic * cubic;


			if (n > 0) {
				printf(" + ");
			}
		}
		printf("\n");

	}
	return 0;
}
