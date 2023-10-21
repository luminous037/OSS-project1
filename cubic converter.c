#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main() {

	int n;

	while (1) {

		printf("Enter an integer>> ");
		scanf("%d", &n);

		if (n == 0) break;

		while (n > 0) {

			int cubic=0;

			while(cubic*cubic*cubic <= n) cubic++;

			cubic -= 1;
				
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
