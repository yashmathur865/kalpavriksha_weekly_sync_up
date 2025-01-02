
#include <stdio.h>

void sortingCodes(int arr[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            int temp = arr[mid];
            arr[mid]=arr[low];
            arr[low]=temp;
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            int temp=arr[mid];
            arr[mid]=arr[high];
            arr[high]=temp;
            high--;
        }
    }
}

int main() {

    int n;
    scanf("%d",&n);
    int codes[n];

    for(int i =0;i<n;i++){
        scanf("%d",&codes[i]);
    }

    sortingCodes(codes,n);

    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d\n",codes[i]);
    }



    return 0;
}

/*
Output:-

6
1
2
0
0
2
1

0
0
1
1
2
2

*/