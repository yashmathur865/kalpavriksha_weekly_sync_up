#include<stdio.h>
#include<stdlib.h>

void processString(char *str,char *result){
    int index=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='#'){
            if(index>0){
                index--;
            }
        }
        else{
            result[index++]=str[i];
        }
    }
    result[index]='\0';
}

int areEqual(char* s,char* t){
    char processedS[201],processedT[201];
    processString(s,processedS);
    processString(t,processedT);

    int i=0;
    while(processedS[i]!='\0' && processedT[i]!='\0'){
        if(processedS[i]!=processedT[i]){
            return 0;
        }
        i++;
    }
    return processedS[i]==processedT[i];
}

int main(){
    char* s=(char*)malloc(201*sizeof(char));
    char* t=(char*)malloc(201*sizeof(char));
    scanf("%s",s);
    scanf("%s",t);

    if(areEqual(s,t)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return 0;
}