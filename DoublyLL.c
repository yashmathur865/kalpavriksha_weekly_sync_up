#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head,int data){
    struct Node* newNode = createNode(data);
    if(*head!=NULL){
        (*head)->prev=newNode;
    }
    newNode->next=*head;
    *head=newNode;
}

void insertAtEnd(struct Node** head,int data){
    struct Node* newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void deleteNode(struct Node** head,int data){
    struct Node* temp = *head;
    while(temp!=NULL && temp->data!=data){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Node not found\n");
        return;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    else{
        *head=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    free(temp);
}

void printList(struct Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void insertAtPosition(struct Node** head,int data,int position){
    if(position<1){
        printf("Invalid Position\n");
        return;
    }
    struct Node* newNode=createNode(data);
    if(position==1){
        if(*head!=NULL){
            (*head)->prev=newNode;
        }
        newNode->next=*head;
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    int count=1;
    while(temp!=NULL && count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        printf("Invalid position\n");
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
}

void insertAtMiddle(struct Node** head,int data){
    struct Node* newNode = createNode(data);
    if(*head==NULL){
        *head=newNode;
    }
    struct Node* slow = *head;
    struct Node* fast = *head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    newNode->next=slow;
    newNode->prev=slow->prev;
    if(slow->prev!=NULL){
        slow->prev->next=newNode;
    }
    else{
        *head=newNode;
    }
    slow->prev=newNode;
}

int main(){
    struct Node* head=NULL;

    while(1){
        printf("Press 1 to insert node at begin\n");
        printf("Press 2 to insert node at end\n");
        printf("Press 3 to insert node at a position\n");
        printf("Press 4 to display list\n");
        printf("Press 5 to insert at middle\n");
        printf("Press 6 to delete a node at a given position\n");
        printf("Press 7 to exit the program\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:{
            int data;
            printf("Enter data to be inserted at beginning: ");
            scanf("%d",&data);
            insertAtBeginning(&head,data);
            break;
            }
            case 2:
            {
            int data;
            printf("Enter data to be inserted at end: ");
            scanf("%d",&data);
            insertAtEnd(&head,data);
            break;
            }
            case 3:
            {
            int data;
            int pos;
            printf("Enter data to be inserted: ");
            scanf("%d",&data);
            printf("Enter position at which data is to be inserted: ");
            scanf("%d",&pos);
            insertAtPosition(&head,data,pos);
            break;
            }
            case 4:
            {
            printList(head);
            break;
            case 5:
            {
                int data;
                printf("Enter data to be inserted at middle: ");
                scanf("%d",&data);
                insertAtMiddle(&head,data);
                break;
            }
            case 6:
            {
                int data;
                printf("Enter the data of node to be deleted: ");
                scanf("%d",&data);
                deleteNode(&head,data);
            }
            case 7:
            printf("Exiting the program\n");
            exit(1);
            }
            default:{
            printf("Please Enter between 1 and 6\n");
            break;
            }
        }
    }
    return 0;
}