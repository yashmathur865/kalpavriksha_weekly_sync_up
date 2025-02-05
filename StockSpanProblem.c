#include<stdio.h>

typedef struct Stack{
    int arr[100];
    int top;
}Stack;

void init(Stack* s){
    s->top=-1;
}

void push(Stack* s,int value){
    s->arr[++s->top]=value;
}

void pop(Stack* s){
    if(s->top!=-1){
        s->top--;
    }
}

void printSpan(int n,int arr[n],Stack* s){
    if(n>0){
        push(s,0);
        printf("1 ");
    }
    for(int i=1;i<n;i++){
        while(s->top!=-1 && arr[s->arr[s->top]]<=arr[i]){
        pop(s);
    }
    int span=(s->top==-1)?(i+1):(i - s->arr[s->top]);
    printf("%d ",span);
    push(s,i);
    }
}

int main(){
    Stack s;
    init(&s);
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printSpan(n,arr,&s);
    return 0;
}