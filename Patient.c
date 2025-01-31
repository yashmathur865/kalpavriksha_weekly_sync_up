#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct patient{
    int id;
    int severityNumber;
    struct patient* next;
}patient;

int convertSeverity(char *severity){
    if (strcmp(severity, "Critical") == 0) return 1;
    if (strcmp(severity, "Serious") == 0) return 2;
    return 3;
}

patient* createPatient(int id,int sevNum){
    patient* newPatient = (patient*)malloc(sizeof(patient));
    if(!newPatient){
        printf("Memory Allocation Failed\n");
    }
    newPatient->id=id;
    newPatient->severityNumber=sevNum;
    newPatient->next=NULL;
    return newPatient;
}

void insertPatient(patient** head,int id,int sevNum){
    patient* newPatient = createPatient(id,sevNum);
    if(*head==NULL){
        *head=newPatient;
        return;
    }
    patient* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newPatient;
}

void printSev(int num){
    if(num==1){
        printf("Critical");
    }
    if(num==2){
        printf("Serious");
    }
    if(num==3){
        printf("Stable");
    }
}
void printPatient(patient** head){
    if(*head==NULL){
        return;
    }
    patient* curr=*head;
    while(curr!=NULL){
        printf("%d ",curr->id);
        printSev(curr->severityNumber);
        printf("\n");
        curr=curr->next;
    }
}

void sortPatients(patient** head){
    if(*head==NULL || (*head)->next==NULL){
        return;
    }
    patient* i;
    patient* j;
    for(i=*head;i!=NULL;i=i->next){
        for(j=*head;j->next!=NULL;j=j->next){
            if(j->severityNumber>j->next->severityNumber){
                int tempid=j->id;
                j->id=j->next->id;
                j->next->id=tempid;

                int tempSevNum=j->severityNumber;
                j->severityNumber=j->next->severityNumber;
                j->next->severityNumber=tempSevNum;
            }
            if(j->severityNumber==j->next->severityNumber){
                if(j->id>j->next->id){
                int tempid=j->id;
                j->id=j->next->id;
                j->next->id=tempid;

                int tempSevNum=j->severityNumber;
                j->severityNumber=j->next->severityNumber;
                j->next->severityNumber=tempSevNum;
                }
            }
        }
    }
}
int main(){
    patient* head=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int id;
        char severity[10];
        scanf("%d",&id);
        scanf("%s",severity);
        int sevNum;
        sevNum=convertSeverity(severity);
        insertPatient(&head,id,sevNum);
    }
    printPatient(&head);

    printf("After Sorting\n");
    sortPatients(&head);
    printPatient(&head);
    return 0;
}