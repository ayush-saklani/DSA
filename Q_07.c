#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * right,*left;
}*root=0;
struct node * insert(struct node *head,int data){
    if(head==NULL){ 
        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;
        temp->right=temp->left=NULL;
        head=temp;
        
    }
    else if(data<head->data) {
        insert(head->left,data) ;
        printf("working till here\n");
    }
    else if(data >head->data){
        insert(head->right,data);
    }    
    else if(data==head->data){
        printf("\n\n\n\n\nerror hai bhai");
    }
    return head;
}
void inorder(struct node* head)
{
    if (head != NULL) {
        inorder(head->left);
        printf("%d ", head ->data);
        inorder(head->right);
    }
}
int main(){
    int choice =1;
    while (1){
        int data;
        printf("enter data to enter\n");
        scanf("%d",&data);
        root = insert(root,data);
        inorder(root);
    }
    return 0;
    
}