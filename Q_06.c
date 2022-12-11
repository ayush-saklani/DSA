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
        else if(newnode->data>head->data){
            struct node *head3=head,*head2=0;
              printf("working");
            while(head3->data   <   newnode->data||head3->next!=0){
                head2=head3;
                head3=head3->next;
                //going into null
            }
            printf("working");
            head2->next=newnode;
            head3->prev=newnode;
            newnode->next=head3;
            newnode->prev=head2;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        printf("Enter 0 to exit \nEnter 1 to continue");
        scanf("%d",&choice);
    }
    return head ;
}
int main(){
    struct node *head;
    head=create(head);
    display(head);
    return 0;
}