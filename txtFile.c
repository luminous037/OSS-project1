#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* a, const void* b) {
	return strcmp((char*)a, (char*)b);
}



int main() {

	FILE* file;
	char word[51][100];
	int index = 0;

	file = fopen("maze.txt", "r");

	while (fscanf(file, "%s", word[index]) == 1) {
		index++;
	}

	fclose(file);

	for (int i = 0; i < index; i++) {
		printf("%s ", word[i]);
	}
	printf("\n");
	qsort(word, index, sizeof(word[0]), compare);

	const char* current = word[0];
	int count = 1;
	for (int i = 1; i < index; i++) {
		if (strcmp(word[i],current) ==0) {
			count++;
		}
		else {
			printf("%s(%d) ", current, count);
			current = word[i];
			count = 1;
			
		}
	}
	printf("%s(%d) ", current, count);
	printf("\nthe total number of words = %d", index);
	return 0;
}
