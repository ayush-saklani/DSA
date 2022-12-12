#include<stdio.h>
#include<stdlib.h>
int search=0,leaf_count=0,right_count=0;    //global counter for easy stuff
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
void inorder(struct node* head){
    if (head != NULL) {
        inorder(head->left);
        printf("%d ", head ->data);
        inorder(head->right);
    }
}
void searching(struct node* head,int data){
    if (head != NULL) {
        searching(head->left,data);
        if(head->data==data){printf("\ndata found\n");search++;}
        searching(head->right,data);
    }
}
void counting_leaf_nodes(struct node* head){
    if (head != NULL) {
        counting_leaf_nodes(head->left);
        if(head->right==NULL && head->left==NULL){leaf_count++;}
        counting_leaf_nodes(head->right);
    }
}
void counting_right_nodes(struct node* head){
    if (head != NULL) {
        counting_right_nodes(head->left);
        right_count++;
        counting_right_nodes(head->right);
    }
}
int main(){
    //creating a bst
    int choice =1,data;
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
    while (1){
        printf("\n");
        printf("Press 1 to search a node\n");
        printf("Press 2 to delete a node\n");
        printf("Press 3 to count leaf node\n");
        printf("Press 4 to finding height of BST\n");
        printf("Press 5 to counting the number of right side nodes\n");
        printf("Press 6 to exit");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            int i;
            printf("enter data\n");
            scanf("%d",&i);
            searching(root,i);
            if(search==0){printf("\ndata not found\n");}
            search=0;
            break;
        case 2:



            break;
        case 3:
            counting_leaf_nodes(root);
            printf("%d",leaf_count);
            leaf_count=0;
            break;
        case 4:



            break;
        case 5:
            counting_right_nodes(root->right);
            printf("%d",right_count);
            right_count=0;
            break;
        case 6:
            return 0;
        }
        
  
    }    
}