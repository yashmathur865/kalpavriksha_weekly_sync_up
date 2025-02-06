#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum AvailabilityStatus{
    Offline,
    Online
}AvailabilityStatus;

typedef struct Driver{
    int id;
    AvailabilityStatus status;
    struct Driver* next;
    struct Driver* prev;
}Driver;

Driver* head=NULL;
Driver* start=NULL;

AvailabilityStatus getStatus(char* statusT){
    if(strcmp(statusT,"Offline")==0) return Offline;
    if(strcmp(statusT,"Online")==0) return Online;
    return -1;
}

Driver* createDriver(int id,AvailabilityStatus status){
    Driver* newDriver = (Driver*)malloc(sizeof(Driver));
    newDriver->id=id;
    newDriver->status=status;
    newDriver->next=NULL;
    newDriver->prev=NULL;
    return newDriver;
}

void addDriver(int id,AvailabilityStatus status){
    Driver* newDriver = createDriver(id,status);
    if(head==NULL){
        head=newDriver;
        head->next=head;
        head->prev=head;
        return;
    }
    Driver* temp = head->prev;
    temp->next=newDriver;
    newDriver->prev=temp;
    newDriver->next=head;
    head->prev=newDriver;
}

int assignRide() {
    if(head == NULL){
        printf("No drivers available\n");
        return -1;
    }
    if(start==NULL) start=head;

    Driver* temp=start;
    do{
        if(temp->status==Online){
            int assignedId=temp->id;
            start=temp->next;
            return assignedId;
        }
        temp = temp->next;
    }while(temp!=start);

    printf("No drivers available\n");
    return -1;
}

void displayDrivers() {
    if (head == NULL) {
        printf("No drivers available\n");
        return;
    }
    Driver* temp=head;
    printf("List of drivers:\n");
    do{
        printf("ID: %d, Status: %s\n",temp->id,(temp->status == Online) ? "Online" : "Offline");
        temp = temp->next;
    }while(temp!=head);
}

int main(){
    int noOfOperations;
    scanf("%d",&noOfOperations);
    while(noOfOperations--){
        printf("Enter 1 to Enter a new Driver\n");
        printf("Enter 2 to assign a Driver\n");
        printf("Enter 3 to display all drivers with there status\n");
        printf("Enter 4 to exit\n");

        int choice;
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                printf("Enter id and status of new driver\n");
                int id;
                char statusT[20];
                scanf("%d",&id);
                scanf("%s",statusT);
                AvailabilityStatus status = getStatus(statusT);
                addDriver(id,status);
                break;
            }
            case 2:{
                int id;
                id=assignRide();
                if (id != -1) {
                    printf("Ride assigned to driver with ID %d\n", id);
                }
                break;
            }
            case 3:{
                displayDrivers();
                break;
            }
            case 4:{
                printf("ThankYou for using Ride Booking\n");
                exit(1);
            }
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
                break;
        }
    }
    return 0;
}