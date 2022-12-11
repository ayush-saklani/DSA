/*
This code works - by tempest.
Write a C program to create a double linked list by inserting nodes in such a way that the
resultant linked list remains in ascending order.(do not use any sorting technique).
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int  data;
    struct node *next;
    struct node *prev;
};
void display(struct node * head){
    struct node * temp2=head;
    printf("\n");
    while(temp2!=NULL){
        printf("%d ",temp2->data);
        temp2=temp2->next;
    }
}
int count(struct node *head){
    struct node *temp=head;
    int counter0=0 ;
    while(temp!=0){
        counter0++;
        temp=temp->next;
    }
    return counter0;
}
struct node * create(){
    int choice=1;
    struct node * head=0;
    while(choice){
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next =newnode->prev=0;
        printf("Enter data ");
        scanf("%d",&newnode->data);
        if(head==0){
            head=newnode;
        }
        else if(newnode->data<=head->data){
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        else if(newnode->data>=head->data){
            struct node *head3=head,*head2=0;
            while(head3->data   <   newnode->data){
                head2=head3;
                head3=head3->next;
                if(head3==0){
                    break;;
                }
            }
            if(head2->next!=0){
                head2->next=newnode;
                head3->prev=newnode;
                newnode->next=head3;
                newnode->prev=head2;
            }
            else{
                newnode->prev=head2;
                head2->next=newnode;
            }
        }
        printf("Enter 0 to exit \nEnter 1 to continue");
        scanf("%d",&choice);
    }
    return head ;
}
int main(){
    struct node *head;
    head=create();
    display(head);
    return 0;
}