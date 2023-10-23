#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;  // 리스트의 첫 노드를 가리키는 포인터

// 새로운 노드를 리스트의 알맞은 위치에 삽입하는 함수
void insertSorted(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value <= head->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        struct Node* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 리스트의 현재 상태를 출력하는 함수
void printList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d(%p) ", current->data, (void*)current);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int value;

    while (1) {

        printf("Enter integers (or a negative integer to exit): ");

        while (1) {

            scanf("%d", &value);

            if (value < 0) {
                break; // 음수 입력 시 종료
            }
            
            insertSorted(value);
            printList();
        }
        
        if (head->data < 0) break;

        struct Node* current = head;
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }

    }


    // 메모리 해제
    

    return 0;
}
