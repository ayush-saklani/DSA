#include<stdio.h>
#include<stdlib.h>
int n=5;
void display(int * arr,int n){
    for (int i = 0; i < n; i++){
        printf("%d ",*(arr+i));
}   }
void shift(int * arr,int k , int n){
    int temp;
    temp=*(arr+k);
    for(int i=k;i<n-1;i++){
        *(arr+i)=*(arr+i+1);
    }
    *(arr+n-1)=temp;
    printf("\n");
    display(arr,n);
}
int main(){
    int * arr=(int *)malloc( (n+1)*sizeof(int));
    printf("enter array");
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    for(int j=0;j<n;j++){
        if(*(arr+j) > 0){
            shift(arr,j,n);
    }   }
    printf("\n");
    display(arr,n);
    return 0;
}