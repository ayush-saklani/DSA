#include<stdio.h>
#include<stdlib.h>
struct node{
    int  data;
    struct node *next;
    struct node *prev;
};

struct node* create (struct node * head){
    int choice=1;
    head=0;
    while(choice){
        struct node *newnode=(struct node *)malloc (sizeof(struct node));
        struct node *temp,*tail;
        newnode->next =newnode->prev=0;
        printf("enter data ");
        scanf("%d",&newnode->data);
        if(head==0){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
            tail=temp;;
        }
        printf("enter 0 to exit and press 1 to continue");
        scanf("%d",&choice);
    }
    return head ;
}
void display(struct node * head){
    struct node * temp2=head;
    while(temp2!=NULL){
        printf("%d ",temp2->data);
        temp2=temp2->next;
    }
}
struct node * insert_at_given_position(struct node * head,int pos){
            struct node *inserttemp,*inserttempo,*inserttemp2=head,*ins=head;
            int i=2,count=0;
            inserttemp=(struct node *)malloc (sizeof(struct node));
            printf("enter data ");
            scanf("%d",&inserttemp->data);
            while(ins!=0){
                count++;
                ins=ins->next;
            }
            if(pos>count+1){
                printf("Invalid position");
                return;
            }
            else if (pos==1){
                inserttemp->next=head;
                inserttemp->prev=0;
                head=inserttemp;
                display(head);
            }
            else if (pos == count+1){
                while(i<pos)
                {
                    inserttemp2=inserttemp2->next;
                    i++;
                }
                inserttemp2->next=inserttemp;
                inserttemp->next=0;
                inserttemp->prev=inserttemp2;
                display(head);
            }
            else{
                while(i<pos){
                    inserttemp2=inserttemp2->next;
                    i++;
                }
                inserttemp->next=inserttemp2->next;
                inserttemp->prev=inserttemp2;
                inserttemp2->next=inserttemp;
                display(head);
            }
            return head;
}
struct node *  delete_from_given_position(struct node * head,int pos){
    struct node *deletetemp=head,*deletetemp2,*del=head;
            int i=2,count=0;
            while(del!=0){  //count the number of element
                count++;
                del=del->next;
            }
            if(pos>count){
                printf("Invalid position");
                return;
            }
            else if (pos==1){
                head=head->next;
                head->prev=0;
                free(deletetemp);
                display(head);
            }
            else if (pos == count){
                while(deletetemp->next!=0){
                    deletetemp2=deletetemp;
                    deletetemp=deletetemp->next;
                }
                deletetemp2->next=0;
                free(deletetemp);
                display(head);
            }
            else{
                deletetemp2=head;
                int i=1;
                while(i<pos-1){
                    deletetemp2=deletetemp2->next;
                    i++;
                }
                deletetemp=deletetemp2->next;
                deletetemp2->next=deletetemp->next;
                deletetemp->next->prev=deletetemp2;
                free (deletetemp);
                display(head);
            }
            return head;
}
int main(){
    struct node *head,*head1,*head2,*tail;
    head=create(head);
    display(head);
    int choice,choice1;
    while (1)
    {
        printf("\nPress 1 for Inserion \n");
        printf("Press 2 for Deletion \n");   
        printf("Press 3 to Display \n");
        printf("Press 5 to exit\n");      
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int pos1;
            printf("Enter position");
            scanf("%d",&pos1);
            head=insert_at_given_position(head,pos1);
            break;
        case 2:
            int pos;
            printf("Enter position");
            scanf("%d",&pos);
            head=delete_from_given_position(head,pos);
            break;
        case 3:
            display(head);
            break;
        case 5:
            return 0;
        }
        }
}
