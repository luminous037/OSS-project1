#include <stdio.h>

// 배열을 분할하고 피봇 인덱스를 반환하는 함수
int split(int arr[], int r, int l) {
	int pivot = arr[r];  // 피봇 엘리먼트를 선택합니다 (이 경우, 가장 오른쪽 엘리먼트).
	int j = r + 1;       // 피봇보다 큰 엘리먼트의 인덱스를 초기화합니다.
	int i = l;          // 피봇보다 작은 엘리먼트의 인덱스를 초기화합니다.

	// 인덱스가 교차할 때까지 반복합니다.
	while (j <= i) {
		// 피봇보다 큰 엘리먼트를 찾을 때까지 인덱스를 오른쪽으로 이동합니다.
		while (arr[j] <= pivot && j <= i) j++;
		// 피봇보다 작은 엘리먼트를 찾을 때까지 인덱스를 왼쪽으로 이동합니다.
		while (arr[i] >= pivot && j <= i) i--;

		// 왼쪽 인덱스가 오른쪽 인덱스보다 작을 경우 엘리먼트를 교환합니다.
		if (j < i) {
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		// 인덱스가 교차한 경우 반복문을 종료합니다.
		else break;
	}

	// 피봇 인덱스에 있는 엘리먼트를 오른쪽 인덱스에 있는 엘리먼트와 교환합니다.
	if (i != r) {
		arr[r] = arr[i];
		arr[i] = pivot;
	}

	// 피봇 인덱스를 반환합니다.
	return i;
}

// 퀵소트 알고리즘을 구현하는 함수
void quick(int arr[], int r, int l) {
	// 왼쪽 인덱스가 오른쪽 인덱스보다 작을 때까지 반복합니다.
	if (r < l) {
		int i = split(arr, r, l);  // 배열을 분할하고 피봇 인덱스를 얻습니다.

		// 분할된 두 부분에 대해 재귀적으로 퀵소트를 수행합니다.
		quick(arr, r, i - 1);
		quick(arr, i + 1, l);
	}
}

int main() {
	FILE* file = fopen("data.txt", "r");

	int integers[100];
	int index = 0;

	// 파일이 정상적으로 열렸는지 확인합니다.
	if (file == NULL) {
		fprintf(stderr, "파일 열기 오류.\n");
		return 1;
	}

	// 파일에서 정수를 읽어들이면서 배열을 채웁니다.
	while (fscanf(file, "%d", &integers[index]) == 1) {
		index++;
	}

	fclose(file);

	// 퀵소트 알고리즘을 사용하여 배열을 정렬합니다.
	quick(integers, 0, index - 1);

	// 정렬된 배열을 출력합니다.
	for (int i = 0; i < index; i++) {
		printf("%d ", integers[i]);
	}

	return 0;
}
