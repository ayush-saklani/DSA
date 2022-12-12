#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * right,*left;
};

struct node * insert(struct node *head,int data){
    if(head==NULL){ 
        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;
        temp->right=temp->left=NULL;
        head=temp;
        
    }
    else if(data<head->data) {
        head->left=insert(head->left,data) ;
        printf("\n\n\nworking till here\n");
    }
    else if(data >head->data){
        head->right=insert(head->right,data);
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
    int data;
    struct node *root=NULL;
    while (choice){
        printf("\nenter data to enter\n");
        scanf("%d",&data);
        root =insert(root,data);
        printf("press 0 to exit \npress 1 for continue\n");
        scanf("%d",&choice);
    }


    printf("\n\n\n\n");
    inorder(root);
    return 0;
    
}