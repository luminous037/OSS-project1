#include <stdio.h>

void primefactors(int n, int arr[], int* size) {
    int index = 0;

    while (n % 2 == 0) {
        arr[index++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            arr[index++] = i;
            n = n / i;
        }
    }

    if (n > 1) {
        arr[index++] = n;
    }

    *size = index;
}

int main() {
    int arr[100];
    int num, size;

    printf("Enter an integer>>");
    scanf_s("%d", &num);

    while (num != 0) {
        primefactors(num, arr, &size);

        int current = arr[0];
        int count = 1;

        for (int i = 1; i < size; i++) {
            if (arr[i] == current) {
                count++;
            }
            else {
                printf("%d^%d*", current, count);
                current = arr[i];
                count = 1;
            }
        }
        printf("%d^%d", current, count);

        printf("\n");

        printf("Enter an integer>>");
        scanf_s("%d", &num);
        if (num == 0) break;
    }

    return 0;
}
