#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node* next;
};

struct Node* first;
struct Node* cur;
struct Node* pre;
struct Node* new_node;

int main() {
    first = NULL;

    int n;

    printf("Enter integers>> ");
    while (1){
        // 새 노드를 위한 메모리 할당
        new_node = (struct Node*)malloc(sizeof(struct Node));

        
        scanf("%d", &n);

        // 음수가 입력되면 루프를 종료
        if (n < 0) {
            break;
        }

        // 입력된 정수를 새 노드의 num에 할당
        new_node->num = n;

        if (first == NULL) {
            // 리스트가 비어있으면 첫 번째 노드로 설정
            first = new_node;
            new_node->next = NULL;
        }
        else {
            // 리스트가 비어있지 않으면 정렬된 순서에 따라 노드를 삽입
            cur = first;
            pre = NULL;

            while (cur != NULL && n > cur->num) {
                pre = cur;
                cur = cur->next;
            }

            if (pre == NULL) {
                // 맨 앞에 삽입
                new_node->next = first;
                first = new_node;
            }
            else {
                // 중간이나 끝에 삽입
                pre->next = new_node;
                new_node->next = cur;
            }
        }

        cur = first;
        while (cur != NULL) {
            printf("%d (%p) ", cur->num, (void*)cur);
            cur = cur->next;
        }
        printf("\n");

    }

    return 0;
}
