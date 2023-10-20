#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int data) {
    stack[++top] = data;
}

int pop() {
    return stack[top--];
}

int main() {
    char input[100] = { 0 };

    while (1) {
        printf("Enter a postfix expression (or '0' to exit)>> ");
        fgets(input, 100, stdin);

        int len = strcspn(input, "\n");
        input[len] = '\0';

        int size = strlen(input);

        if (strcmp(input, "0") == 0) break;

        for (int i = 0; i < size; i++) {

            if (isdigit(input[i])) {
                int value = 0; {
                    while (isdigit(input[i])) {
                        value = value * 10 + (input[i] - '0');
                        i++;
                    }
                    push(value);
                }
            }
            else if (input[i] == ' ') {
                continue;
            }
            else if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-') {
                
                int x2 = pop();
                int x1 = pop();
                int result;
                if (input[i] == '*') {
                    result = x1 * x2;
                }
                else if (input[i] == '/') {
                    result = x1 / x2;
                }
                else if (input[i] == '+') {
                    result = x1 + x2;
                }
                else if (input[i] == '-') {
                    result = x1 - x2;
                }
                push(result); 
            }
            else {
                printf("Invalid expression\n");
                top = -1; 
                break;
            }
        }

        if (top == 0) {
            printf("%d\n", stack[0]);
            top = -1;
        }

        else {
            printf("Invalid expression\n");
            top = -1; 
        }
    }
    return 0;
}
