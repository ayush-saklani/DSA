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
        struct node *newnode=(struct node *)malloc (sizeof(struct node));
        newnode->next =newnode->prev=0;
        printf("Enter data ");
        scanf("%d",&newnode->data);
        struct node *temp;
        if(head==0){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        printf("Enter 0 to exit \nEnter 1 to continue");
        scanf("%d",&choice);
    }
    return head ;
}
struct node * insertlast(struct node *heado,int item){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));  
    struct node *temp,*head=heado;  
    ptr->data=item;  
    if(head == NULL){  
        ptr->next = NULL;  
        ptr->prev = NULL;  
        head = ptr;  
    }  
    else{  
        temp = head;  
        while(temp->next!=NULL)  
        {  
            temp = temp->next;  
        }  
        temp->next = ptr;  
        ptr ->prev=temp;  
        ptr->next = NULL;  
    }
    return head;
} 
struct node * seperate_positive(struct node *head,struct node *head1){
    struct node * temp=head,*temp0=head,*temp1=head1;
    int counter1 = count(temp);
    for (int i = 0; i < counter1; i++){
        if(temp0->data>0){
            temp1=insertlast(temp1,temp0->data);
        }
        temp0=temp0->next; 
    }
    return temp1; 
}
struct node * seperate_negative(struct node *head,struct node *head1){
    struct node * temp=head,*temp0=head,*temp1=head1;
    int counter1 = count(temp);
    for (int i = 0; i < counter1; i++){
        if(temp0->data<=0){
            temp1=insertlast(temp1,temp0->data);
        }
        temp0=temp0->next; 
    }
    return temp1; 
}
int main(){
    struct node *head,*head1=0,*head2=0;
    head=create(head);
    display(head);
    int temp0;
    temp0=count(head);
    head1=seperate_positive(head,head1);
    head2=seperate_negative(head,head2);
    printf("\nPositive elements ->");
    display(head1);
    printf("\nNegative elements ->");
    display(head2);
    return 0;
}