#include<stdio.h>
#include<stdlib.h>
struct node{
    int data , expo;
    struct node * next;
    struct node * prev;
};
void display(struct node * head){
    struct node * temp=head;
    while (temp!=NULL){
        printf("%dX^%d",temp->data ,temp->expo);
        if (temp->next!=0){
            printf(" + ");
        }
        temp=temp->next;
    }
}
struct node * create(struct node * head){
    int choice =1;
    while(choice){
    struct node * nextnode,*temp;
    nextnode=(struct node *)malloc(sizeof(struct node));
    nextnode->next=nextnode->prev=NULL;
    printf("Enter data and exponent repectively\n");
    scanf("%d",&nextnode->data);
    scanf("%d",&nextnode->expo);
    if(head==NULL){
        head=nextnode;
        temp=head;
    }
    else{
        temp->next=nextnode;
        nextnode->prev=temp;
        temp=temp->next;
    }
    printf("Press 1 to continue 0 to exit\n");
    scanf("%d",&choice);
    }
    return head;
}
struct node * insert(struct node * head){}
struct node * polsum(struct node * head1,struct node * head2,struct node * head ){
    struct node * temp1 = head1,* temp2 = head2;
   
    struct node * tempu  = head ,* tempo = head ;
    while(temp1!=NULL&&temp2!=NULL){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->next=temp->prev=NULL;
        if (temp1->expo=temp2->expo){
            temp->data=temp1->data+temp2->data;
            temp->expo=temp1->expo;
        }
        else if (temp1->expo<temp2->expo){
            temp->data=temp1->data;
            temp->expo=temp1->expo;
            temp1=temp1->next;
        }
        else if (temp1->expo>temp2->expo){
            temp->data=temp2->data;
            temp->expo=temp2->expo;
            temp2=temp2->next;
        }
        if(tempu==NULL){
        tempu=temp;
        tempo=tempu;
        }
        else{
            tempo->next=temp;
            temp->prev=tempo;
            tempo=tempo->next;
        }
    }
    return tempu;
}
int main(){
    struct node * pol1=NULL,* pol2=NULL,*pol3=NULL;
    pol1=create(pol1);
    pol2=create(pol2);
    printf("1st equation -> ");
    display(pol1);    
    printf("\n2nd equation -> ");
    display(pol2);
    pol3=polsum(pol1,pol2,pol3);
    printf("\nsum equation -> ");
    display(pol3);
    return 0;
}
        //printf("working\n");

