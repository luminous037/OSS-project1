#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[100] = { 0 };
int top = -1;

void push(char data) {
    stack[++top] = data;
}

char pop() {
    return stack[top--];
}


int convert(char ex) {
    switch (ex) {
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}

int main() {
    char exp[100];
    char input;
    char output[100];
    int k = 0;

    while (1) {
        printf("Enter an expression (or type 'quit' to exit): ");
        fgets(exp, 100, stdin);

        int len = strcspn(exp, "\n");
        exp[len] = '\0';

        if (strcmp(exp, "quit") == 0) break;

        int index = 0;

        for (int i = 0; i < strlen(exp); i++) {

            input = exp[i];

            if (input == '(') {
                push(input);
            }
            else if (input == ' ')continue;

            else if (isdigit(input)) {
                output[k++] = input;
            }
            else if (input == ')') {
                while (stack[top] != '(') {
                    output[k++] = pop();
                }
                pop(); // Pop '('
            }
            else {
                while (top >= 0 && convert(stack[top]) >= convert(input)) {
                    output[k++] = stack[top];
                    pop();
                }
                push(input);
            }
        }

        while (top >= 0) {
            output[k++] = pop();
        }
        output[k] = '\0';

        printf("%s ", output);
        printf("\n");

        k = 0;
        memset(output, 0, sizeof(output));
    }

    return 0;
}
