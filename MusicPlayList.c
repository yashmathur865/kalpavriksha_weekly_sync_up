#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Song{
    char name[100];
    struct Song* next;
    struct Song* prev;
}Song;

Song* head=NULL;
Song* current=NULL;

Song* createSong(char* name){
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

void addSong(char* name){
    Song* newSong = createSong(name);
    if(head==NULL){
        head=newSong;
        current=head;
        return;
    }
    Song* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newSong;
    newSong->prev=temp;
}

void shufflePlaylist(){
    if(head==NULL || head->next==NULL){
        printf("Not enough songs to shuffle.\n");
        return;
    }

    int count=0;
    Song* temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }

    Song* songs[count];
    temp=head;
    for(int i=0;i<count;i++){
        songs[i] = temp;
        temp = temp->next;
    }

    srand(time(NULL));
    for(int i=count-1;i>0;i--){
        int j = rand()%(i+1);
        char tempName[100];
        strcpy(tempName, songs[i]->name);
        strcpy(songs[i]->name, songs[j]->name);
        strcpy(songs[j]->name, tempName);
    }

    printf("Playlist shuffled successfully!\n");
}

void deleteSong(char* name){
    if(head==NULL){
        printf("Playlist is empty.\n");
        return;
    }

    Song* temp=head;

    while(temp!=NULL && strcmp(temp->name, name)!=0){
        temp = temp->next;
    }

    if(temp==NULL){
        printf("Song not found in playlist.\n");
        return;
    }

    if(temp->prev) temp->prev->next = temp->next;
    if(temp->next) temp->next->prev = temp->prev;
    if(temp == head) head = temp->next;
    if(temp == current) current = temp->next ? temp->next : temp->prev;

    free(temp);
    printf("Song deleted successfully!\n");
}

void nextSong(){
    if(current==NULL){
        printf("No songs in playlist.\n");
        return;
    }
    if(current->next != NULL){
        current = current->next;
        printf("Now playing: %s\n",current->name);
    }
    else{
        printf("End of playlist. No next song.\n");
    }
}

void prevSong(){
    if(current == NULL){
        printf("No songs in playlist.\n");
        return;
    }
    if(current->prev!=NULL){
        current = current->prev;
        printf("Now playing: %s\n", current->name);
    }
    else{
        printf("Start of playlist. No previous song.\n");
    }
}

void displayPlaylist(){
    if(head==NULL){
        printf("Playlist is empty.\n");
        return;
    }

    Song* temp = head;
    printf("Current Playlist:\n");
    while(temp){
        if(temp==current){
            printf("-> [%s] (Now Playing)\n", temp->name);
        }
        else{
            printf("   %s\n", temp->name);
        }
        temp=temp->next;
    }
}

int main(){
    int choice;
    char songName[100];

    while (1){
        printf("\nMusic Playlist Menu:\n");
        printf("1. Add a new song\n");
        printf("2. Shuffle the playlist\n");
        printf("3. Move to the next song\n");
        printf("4. Move to the previous song\n");
        printf("5. Delete a song\n");
        printf("6. Display playlist\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter song name: ");
                scanf(" %[^\n]", songName);
                addSong(songName);
                printf("Song added successfully!\n");
                break;
            case 2:
                shufflePlaylist();
                break;
            case 3:
                nextSong();
                break;
            case 4:
                prevSong();
                break;
            case 5:
                printf("Enter song name to delete: ");
                scanf(" %[^\n]", songName);
                deleteSong(songName);
                break;
            case 6:
                displayPlaylist();
                break;
            case 7:
                printf("Exiting music player.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
