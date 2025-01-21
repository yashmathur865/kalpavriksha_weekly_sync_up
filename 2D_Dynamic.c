#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Enter number of rows and columns\n");
    int rows,cols;
    scanf("%d %d",&rows,&cols);

    int** arr = (int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++){
        arr[i]=(int*)malloc(cols*sizeof(int));
    }

    printf("Enter the elements\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Entered elements are as follows\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<rows;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}