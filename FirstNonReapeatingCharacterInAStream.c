#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char ch;
    int freq;
    struct Node* next;
}Node;

typedef struct Map{
    int capacity;
    int size;
    Node** buckets;
}Map;

int hash(char ch,int capacity){

    return ((ch-'a')%capacity);
}

Map* createMap(){
    Map* map=(Map*)malloc(sizeof(Map));
    map->size=0;
    map->capacity=26;
    map->buckets=(Node**)calloc(map->capacity,sizeof(Node*));
    return map;
}

Node* createNode(char ch){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch=ch;
    newNode->freq=1;
    newNode->next=NULL;
    return newNode;
}

void increaseFreq(Map* map,char ch){
    int index=hash(ch,map->capacity);
    Node* node=map->buckets[index];
    while(node){
        if(node->ch==ch){
            node->freq++;
            return;
        }
    }
    Node* newNode = createNode(ch);
    newNode->next=map->buckets[index];
    map->buckets[index]=newNode;
    map->size++;
}

int get(Map* map,char ch){
    int index=hash(ch,map->capacity);
    Node* node=map->buckets[index];
    while(node){
        if(node->ch==ch){
            return node->freq;
        }
    }
    return -1;
}


void findFirstNonRepeating(char* s){
    Map* map=createMap();
    char queue[26];
    int front=0,rear=0;
    for(int i=0;s[i]!='\0';i++){
        char ch=s[i];
        increaseFreq(map,ch);
        queue[rear++]=ch;

        while(front<rear && get(map,queue[front])>1){
            front++;
        }

        if(front<rear){
            printf("%c\n",queue[front]);
        }
        else{
            printf("-1\n");
        }
    }
}

int main(){
    printf("Enter a string\n");
    char str[100000];
    scanf("%s",str);
    findFirstNonRepeating(str);
    return 0;
}