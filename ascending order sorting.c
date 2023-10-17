#include<stdio.h>

int main() {
	int n=0;
	printf("Enter the number of integers>>");
	scanf_s("%d",&n);
	int arr[100];
	printf("Enter integers>>");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++){
		for(int j=0;j<n-i-1;j++){
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("After sorting:");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
