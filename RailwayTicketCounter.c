#include <stdio.h>
#include <string.h>

typedef enum passengerType{
    VIP,
    SENIOR_CITIZEN,
    GENERAL
}passengerType;

typedef struct passenger{
    int id;
    passengerType type;
    char name[51];
}passenger;

typedef struct Queue{
    passenger arr[100];
    int rear;
    int size;
}Queue;

void init(Queue *q){
    q->rear=-1;
    q->size=0;
}

void enqueue(Queue* q,int id,passengerType type,char* name){
    if(q->size==100){
        printf("Queue is full\n");
        return;
    }
    int i=q->rear;
    while(i>=0 && q->arr[i].type>type){
        q->arr[i+1]=q->arr[i];
        i--;
    }
    q->arr[i+1].id=id;
    q->arr[i+1].type=type;
    strcpy(q->arr[i+1].name,name);

    q->rear++;
    q->size++;
}

void dequeue(Queue*q){
    if(q->size==0){
        printf("Queue is empty!\n");
        return;
    }
    printf("Serving Passenger: ID %d, Name: %s, Type: %s\n",
           q->arr[0].id, q->arr[0].name,
           (q->arr[0].type ==VIP) ? "VIP" :
           (q->arr[0].type==SENIOR_CITIZEN) ? "SENIOR_CITIZEN" : "GENERAL");

    for (int i=0;i<q->rear;i++){
        q->arr[i]=q->arr[i + 1];
    }

    q->rear--;
    q->size--;
}

void displayQueue(Queue* q){
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Waiting Passengers:\n");
    for (int i=0;i<=q->rear;i++){
        printf("ID %d, Name: %s, Type: %s\n",
               q->arr[i].id, q->arr[i].name,
               (q->arr[i].type==VIP) ? "VIP" :
               (q->arr[i].type==SENIOR_CITIZEN) ? "SENIOR_CITIZEN" : "GENERAL");
    }
}

passengerType getPassengerType(char *typeS){
    if (strcmp(typeS, "VIP") == 0) return VIP;
    if (strcmp(typeS, "SENIOR_CITIZEN") == 0) return SENIOR_CITIZEN;
    return GENERAL;
}

int main(){
    Queue q;
    init(&q);

    int noOfOperations;
    scanf("%d",&noOfOperations);

    while(noOfOperations--){
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int id;
                char type[20];
                char name[51];
                scanf("%d",&id);
                scanf("%s",type);
                scanf("%s",name);
                passengerType typeEnum=getPassengerType(type);
                enqueue(&q,id,typeEnum,name);
                break;
            }
            case 2:{
                dequeue(&q);
                break;
            }
            case 3:{
                displayQueue(&q);
                break;
            }
            default:{
                printf("Please choose between 1 to 3");
                break;
            }
        }
    }

    return 0;
}
