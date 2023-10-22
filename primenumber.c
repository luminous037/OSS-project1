#include<stdio.h>

int main() {

	int a;

	printf("Enter an integers>> ");

	scanf("%d", &a);

	for (int i = 3; i <= a; i+=2) {

		int isprime = 1;

		for (int j = 3; j*j < i; j++) {
			
			if (i % j == 0) {
				isprime = 0;
				break;
			}

			
		}
		 if (isprime) {
			printf("%d ", i);
			}

		

	}
	return 0;

}
