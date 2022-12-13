/*  incompldete code right now
This code works - by tempest.
Write a C program to create a binary search tree and perform following operations: 
         1) Search a particular key.  
         2) Delete a node from the tree. 
         3) Find total number of leaf nodes  
         4) Find height of a binary search tree 
         5) Count total numbers of nodes from right hand side of root node 
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int search=0,leaf_count=0,right_count=0;    //global counter for easy stuff
struct node{
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
    //bst creation completed
    printf("\n\n\n\n");
    inorder(root);
    while (1){
       // system ("cls\n"); //to clear screen but doesnt work here
        printf("\n");
        printf("Press 1 to search a node\n");
        printf("Press 2 to delete a node\n");
        printf("Press 3 to count leaf node\n");
        printf("Press 4 to finding height of BST\n");
        printf("Press 5 to counting the number of right side nodes\n");
        printf("Press 6 to exit");
        scanf("%d",&choice);
        printf("\n");
        inorder(root);
        printf("\n");
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
/*
below code is stolen from net and above is done by tempest ;
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

// Define the Tree Node here
struct Node {
    int value;
    // Pointers to the left and right children
    Node* left, *right;
};


Node* init_tree(int data) {
    // Creates the tree and returns the
    // root node
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}

Node* create_node(int data) {
    // Creates a new node
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}

void free_tree(Node* root) {
    // Deallocates memory corresponding
    // to every node in the tree.
    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}

int tree_height(Node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int main() {
    // Program to demonstrate finding the height of a Binary Tree

    // Create the root node having a value of 10
    Node* root = init_tree(10);
    
    // Insert nodes onto the tree
    root->left = create_node(20);
    root->right = create_node(30);
    root->left->left = create_node(40);
    root->left->right = create_node(50);

    // Find the height of the tree
    int height = tree_height(root);
    printf("Height of the Binary Tree: %d\n", height);

    // Free the tree!
    free_tree(root);
    return 0;
}*/