#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int split(int arr[], int k, int m) { //k: lowest index, m: highest index
    int v = arr[k];
    int j = k + 1;
    int i = m;

    while (j <= i) {
        while (arr[j] <= v && j <= i) j++;
        while (arr[i] >= v && j <= i) i--;
        if (j < i) swap(&arr[j], &arr[i]);
        else break;
    }

    if (i != k) {
        arr[k] = arr[i];
        arr[i] = v;
    }

}

void quick(int arr[], int k, int m) {
    if (k < m) {
        int i = split(arr, k, m);

        quick(arr, k, i - 1);
        quick(arr, i + 1, m);
    }
}

int main() {
    FILE* file = fopen("data.txt", "r");

    int integers[100];
    int index = 0;

    while (fscanf(file, "%d", &integers[index]) == 1) {
        index++;
    }

    fclose(file);

    quick(integers, 0, index - 1);

    for (int i = 0; i < index; i++) {
        printf("%d ", integers[i]);
    }

    return 0;
}
