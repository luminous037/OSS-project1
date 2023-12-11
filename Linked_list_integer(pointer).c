#include<stdio.h>
#include <stdlib.h> // 동적할당


struct Node {
	int num;
	struct Node* next;
};

struct Node* pre;
struct Node* first;
struct Node* new;
struct Node* cur;

int main() {

	int n;
	
	

	while (1) {
		first = NULL;
		printf("Enter integers>> ");
		
		int count = 0;

		while (1) {
			new = malloc(sizeof(struct Node));
			scanf("%d", &n);
			count++;

			if (count == 1 && n < 0)return 0;
			if (n < 0)break;
			

			new->num = n;

			if (first == NULL) {
				first = new;
				new->next = NULL;
			}

			else {
				cur = first;
				pre = NULL;

				while (cur != NULL && n > cur->num) {
					pre = cur;
					cur = cur->next;
				}

				if (pre == NULL) {
					new->next = first;
					first = new;
				}

				else {
					pre->next = new;
					new->next = cur;
				}
			}

			cur = first;
			while (cur != NULL) {
				printf("%d (%p)", cur->num, (void*)cur);
				cur = cur->next;
			}
			printf("\n");
		}
	}
	return 0;
}
