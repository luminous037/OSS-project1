
#include <stdio.h>
struct Node {
    char name[20];
    char num[20];
    struct Node* next;
};
struct Node* first;
struct Node* new;
struct Node* pre, *cur;
int main(void) {
  
    first = NULL;
    FILE* file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        perror("Failed to open file.");
        return 1;
    }
    while (1) {
        new = malloc(sizeof(struct Node)); //new 동적할당
        if (fscanf(file, "%s %s", new->name, new->num) != 2) {
            break;
        } //스트링 두 개를 입력받았으니깐 반환값이 2가 아닐 때 break하는 방법
        if (first == NULL) {
            first = new;
            new->next = NULL;
        } //첫번째 노드 입력
        
        else {
            cur = first;
            pre = NULL;
            while (cur != NULL && strcmp(new->name, cur->name) > 0) {
                pre = cur;
                cur = cur->next;
            } //사전순으로 더 먼저오는 이름이 new로 왔을 때 주소 이동
            if (pre == NULL) {
                new->next = first;
                first = new;
            } 
            
            else {
                pre->next = new;
                new->next = cur;
            } //사전순으로 늦게 오는 이름이 new로 왔을 때 주소 이동
        }
    }
    fclose(file);
    cur=first;
    while (cur != NULL) {
        printf("%s %s\n", cur->name, cur->num);
        cur= cur->next;
    }
  while(1){
    
    char nameToSearch[20];
    printf("\nEnter the name to search: ");
    scanf("%s", nameToSearch);
    if(strcmp("exit" , nameToSearch) == 0) break; // 검색 종료 방법
    cur = first;
    while (cur != NULL) {
        if (strcmp(nameToSearch, cur->name) == 0) {
            printf("Phone Number: %s\n", cur->num);
            break; 
        } //해당 이름이 나올 때 까지 순서대로 탐색
        cur= cur->next;
    }
    if (cur == NULL) {
        printf("not found.\n");
    } //없는 이름 일 때
  }
  
    return 0;
}
