#include <stdio.h>

int split(int arr[], int r, int l) {
	int v = arr[r];
	int j = r + 1;
	int i = l;

	while (j <= i) {
		while (arr[j] <= v && j <= i)j++;
		while (arr[i] >= v && j <= i)i--;
		if (j < i) {
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		else break;
	}

	if (i != r) {
		arr[r] = arr[i];
		arr[i] = v;
	}

	return i;
}

void quick(int arr[], int r, int l) {
	if (r < l) {
		int i = split(arr, r, l);

		quick(arr, r, i - 1);
		quick(arr, i + 1, l);
	}
}



int main() {
	FILE* file = fopen("data.txt", "r");

	int integers[100];
	int index=0;

	while (fscanf(file, "%d", &integers[index]) ==1) {
		index++;
	}

	fclose(file);

	quick(integers, 0, index -1);

	for (int i = 0; i < index; i++) {
		printf("%d ",integers[i]);
	}

	return 0;
}
