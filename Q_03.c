/*
This code works - by tempest.
Write a C program to create a linked list P, then write a ‘C’ function named split to
create two linked lists Q & R from P So that Q contains all elements in odd positions of
P and R contains the remaining elements. Finally print both linked lists i.e. Q and R.
*/
#include<stdio.h>
#include<stdlib.h>
int poso=0;
struct node{
    int  data;
    struct node *next;
    struct node *prev;
}*q=0,*r=0;
void display(struct node * p){
    struct node * temr=p;
    printf("\n");
    while(temr!=NULL){
        printf("%d ",temr->data);
        temr=temr->next;
    }
}
int count(struct node *p){
    struct node *temp=p;
    int counter0=0 ;
    while(temp!=0){
        counter0++;
        temp=temp->next;
    }
    return counter0;
}
struct node * create(){
    int choice=1;
    struct node * p=0;
    while(choice){
        struct node *newnode=(struct node *)malloc (sizeof(struct node));
        newnode->next =newnode->prev=0;
        printf("Enter data ");
        scanf("%d",&newnode->data);
        struct node *temp;
        if(p==0){
            p=newnode;
            temp=p;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        printf("Enter 0 to exit \nEnter 1 to continue");
        scanf("%d",&choice);
    }
    return p ;
}
struct node * insertlast(struct node *po,int item){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));  
    struct node *temp,*p=po;  
    ptr->data=item;  
    if(p == NULL){  
        ptr->next = NULL;  
        ptr->prev = NULL;  
        p = ptr;  
    }  
    else{  
        temp = p;  
        while(temp->next!=NULL)  
        {  
            temp = temp->next;  
        }  
        temp->next = ptr;  
        ptr ->prev=temp;  
        ptr->next = NULL;  
    }
    return p ;
}
void split(struct node *p){
    struct node * temp=p,*temp0=p;
    int counter1 = count(temp);
    for (int i = 0; i < counter1; i++){
        if(poso%2==0){
            printf(" entrnasdfkljlfjdsf");
            q=insertlast(q,temp0->data);
        }
        else{
            r=insertlast(r,temp0->data);
        }
        temp0=temp0->next; 
        poso++;
    } 
    display(q);
    display(r);
}
int main(){
    struct node *p;
    p=create();
    display(p);
    int temp0;
    temp0=count(p);
    split(p);
    printf("\n\n\n\n\nTotal elements ->");
    display(p);
    printf("\nOdd position ->");
    display(q);
    printf("\nEven Position ->");
    display(r);
    return 0;
}