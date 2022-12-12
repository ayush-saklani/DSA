#include<stdio.h>
#include<stdlib.h>
int n=5;
void display(int * arr){
    for (int i = 0; i < n; i++){
        printf("%d ",*(arr+i));
}   }
void shift(int * arr,int k ){
    int temp;
    temp=*(arr+k);
    for(int i=k;i<n-1;i++){
        *(arr+i)=*(arr+i+1);
    }
    *(arr+n-1)=temp;
}
int main(){
    int * arr=(int *)malloc( (n+1)*sizeof(int));
    //54564546
    printf("enter array");
    for(int i=0;i<n;i++){
        //asdjkshflads
        scanf("%d",(arr+i));
    }
    printf("\n");
    display(arr);
    int z=n;
    for(int j=0;j<z;j++){
        if(*(arr+j) > 0){
            shift(arr,j);
            z--;
            j--;
    }   }
    printf("\n");
    display(arr);
    return 0;

}
