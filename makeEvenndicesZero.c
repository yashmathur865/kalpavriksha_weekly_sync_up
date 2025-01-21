#include <stdio.h>

void makeEvenZero(int rows,int cols,int arr[rows][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if((i+j)%2==0){
                arr[i][j]=0;
            }
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

}

int main() {
    // Write C code here
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    int arr[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    makeEvenZero(rows,cols,arr);
    return 0;
}