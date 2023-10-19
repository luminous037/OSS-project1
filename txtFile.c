#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	FILE* file;
	char word[51][100]={0};
	int index = 0;

	file = fopen("data.txt", "r");

	while (fscanf(file, "%s", word[index]) == 1) {
		index++;
	}

	fclose(file);

	char temp[100];

	for(int i=0; i<index; i++){
		for(int j=0; j< index -i-1; j++){
			if(strcmp(word[j+1],word[j])<0){
				strcpy(temp,word[j]);
				strcpy(word[j],word[j+1]);
				strcpy(word[j+1],temp);
			}
		}
	}

	int count = 1;
	for (int i = 1; i < index; i++) {
		if (strcmp(word[i],word[i+1]) ==0) {
			count++;
		}
		else {
			printf("%s(%d) ", word[i], count);
			count = 1;
			
		}
	}
	printf("\nthe total number of words = %d", index);
	return 0;
}
