#include<stdio.h>
#include<stdlib.h>

int split(int arr[], int r, int l) {
	int pivot = arr[r];
	int j = r + 1;
	int i = l;

	while (j <= i) {
		while (arr[j] <= pivot && j <= i)j++;
		while (arr[i] >= pivot && j <= i)i--;

		if (j < i) {
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}

		else break;
	}

	if (i != r) {
		arr[r] = arr[i];
		arr[i] = pivot;
	}
	return i;
}

void quick(int n, int arr[], int r, int l) {
	if (r < l) {
		int i = split(arr, r, l);

		printf("(%d, %d): ", r, l);
		for (int k = 0; k < n; k++) {
			printf("%d ", arr[k]);
		}
		printf("\n");

		quick(n,arr, r, i - 1);
		quick(n,arr, i + 1, l);
		
	}
	
}

int main() {
	int num;
	
	while (1) {
		printf("Enter the number of integers >> ");
		scanf("%d", &num);
		if (num == 0)break;

		printf("Enter %d integers>> ",num);

		int integers[100];

		for (int i = 0; i < num; i++) {
			scanf("%d", &integers[i]);
		}

		quick(num, integers, 0, num-1);

		printf("After Sorting: ");

		for (int j = 0; j < num; j++) {
			printf("%d ", integers[j]);
		}
		printf("\n");

	}
	return 0;


}
