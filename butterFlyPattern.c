#include <stdio.h>

int main(){
    int num;
    printf("Enter no. of rows\n");
    scanf("%d",&num);

    for(int i=1;i<=num;i++){

        for(int j=1;j<=i;j++){
            printf("%d",j);
        }

        for(int j=1;j<=2*(num-i);j++){
            printf(" ");
        }

        for(int j=i;j>=1;j--){
            printf("%d", j);
        }

        printf("\n");
    }


    for (int i=num-1;i>=1;i--){

        for(int j = 1;j<= i;j++){
            printf("%d", j);
        }

        for (int j =1;j<= 2*(num - i);j++){
            printf(" ");
        }

        for (int j = i;j>=1;j--) {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}

/*  Enter no. of rows
5
1        1
12      21
123    321
1234  4321
1234554321
1234  4321
123    321
12      21
1        1   */