#include<stdio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node * right,*left;
};
struct node *create(struct node *head){

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
int main(){
    return 0;
}


/*if(head==0){
            head=newnode;
        }
        else if(newnode->data>head->data){
            struct node *head3=head,*head2=0;
            printf("working");
            while(head3->data   <   newnode->data){
                head2=head3;
                head3=head3->next;
                //problem is that head3 is going into null after entering second element
            }
            printf("working");
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
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }*/