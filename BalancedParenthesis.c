#include<stdio.h>

typedef struct Stack{
    char arr[200];
    int top;
}Stack;

void initialize(Stack* s){
    s->top=-1;
}

void push(Stack* s,char ch){
    s->arr[++s->top]=ch;
}

int matching(char ch1,char ch2){
    if(ch1=='(' && ch2==')') return 1;
    if(ch1=='[' && ch2==']') return 1;
    if(ch1=='{' && ch2=='}') return 1;

    return 0;
}

void pop(Stack* s){
    if(s->top==-1) return;
    s->top--;
}

int main(){
    char str[200];
    scanf("%s",str);

    Stack s;
    initialize(&s);

    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            push(&s,str[i]);
        }
        else{
            if(s.top==-1){
                printf("False\n");
                return 1;
            }
            else{
                if(matching(s.arr[s.top],str[i])==0){
                    printf("False\n");
                    return 1;
                }
                else{
                    pop(&s);
                }
            }
        }
        i++;
    }

    if(s.top==-1){
        printf("True\n");
    }
    return 0;
}