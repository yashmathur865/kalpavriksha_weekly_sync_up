#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct{
    char data[1000];
    int top;
}Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack,char ch){
    if(stack->top<1000-1){
        stack->data[++stack->top] = ch;
    }
}

char pop(Stack *stack){
    return (stack->top >= 0) ? stack->data[stack->top--] : '\0';
}

char peek(Stack *stack){
    return (stack->top >= 0) ? stack->data[stack->top] : '\0';
}

bool isValidParentheses(const char *s){
    Stack stack;
    initStack(&stack);

    char matching[128] = {0};
    matching[')'] = '(';
    matching['}'] = '{';
    matching[']'] = '[';

    for(int i=0;s[i]!='\0';i++){
        char ch = s[i];

        if(ch=='(' || ch=='{' || ch=='['){
            push(&stack, ch);
        }
        else if(ch==')' || ch=='}' || ch==']'){
            if(peek(&stack) == matching[ch]){
                pop(&stack);
            }
            else{
                return false;
            }
        }
    }

    return stack.top == -1;
}

int main() {
    char input[1000];
    printf("Enter a string with brackets: ");
    fgets(input,1000,stdin);

    input[strcspn(input,"\n")] = '\0';

    if(isValidParentheses(input)){
        printf("Valid\n");
    }
    else{
        printf("Invalid\n");
    }
    return 0;
}
