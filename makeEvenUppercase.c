#include <stdio.h>

void makeEvenUppercase(char str[]){

    int letterCount = 0;
    int index=0;

    for(int i=0;str[i]!='\0';i++){
        char ch = str[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
            letterCount++;

            if(letterCount%2==0 && ch>='a' && ch<='z'){
                str[index++]=ch-32;
            }
            else if(letterCount%2==0 && ch>='A' && ch<='Z'){
                str[index++] = ch;
            }
            else {
                str[index++] = ch;
            }
        }
    }

    str[index] = '\0';
}

int main() {
    char str[16];
    printf("Enter The String\n");
    scanf("%15[^\n]",str);

    makeEvenUppercase(str);
    printf("%s",str);
    return 0;
}