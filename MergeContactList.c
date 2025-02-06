#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact{
    char name[51];
    char phone[11];
    struct Contact* next;
}Contact;

Contact* createContact(char* name, char* phone){
    Contact* newContact=(Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name,name);
    strcpy(newContact->phone,phone);
    newContact->next=NULL;
    return newContact;
}

int isDuplicate(Contact* head, char* name, char* phone){
    while(head){
        if(strcmp(head->name,name)==0 && strcmp(head->phone, phone)==0){
            return 1;
        }
        head=head->next;
    }
    return 0;
}

void insertSorted(Contact** head,char* name,char* phone){
    if (isDuplicate(*head, name, phone)) return;

    Contact* newContact=createContact(name, phone);
    if(*head==NULL || strcmp((*head)->name,name)>0 ||
       (strcmp((*head)->name,name)==0 && strcmp((*head)->phone,phone)>0)){
        newContact->next=*head;
        *head = newContact;
        return;
    }
    Contact* temp=*head;
    while(temp->next && (strcmp(temp->next->name,name)<0 ||
           (strcmp(temp->next->name,name) == 0 && strcmp(temp->next->phone,phone) < 0))){
        temp = temp->next;
    }
    newContact->next = temp->next;
    temp->next = newContact;
}

void mergeLists(Contact** merged,Contact* list){
    while(list){
        insertSorted(merged,list->name,list->phone);
        list=list->next;
    }
}

void displayContacts(Contact* head){
    while(head){
        printf("(%s, %s)\n", head->name, head->phone);
        head = head->next;
    }
}

int main(){
    int k;
    printf("Enter number of contact lists: ");
    scanf("%d", &k);
    getchar();

    Contact* mergedList=NULL;
    for(int i=0;i<k;i++){
        printf("Enter number of contacts for list %d: ",i+1);
        int n;
        scanf("%d",&n);
        getchar();
        Contact* list=NULL;
        for(int j=0;j<n;j++){
            char name[51],phone[11];
            printf("Enter name and phone: ");
            scanf("%s %s",name,phone);
            insertSorted(&list,name,phone);
        }
        mergeLists(&mergedList, list);
    }

    printf("\nMerged Sorted Contact List:\n");
    displayContacts(mergedList);
    return 0;
}
