else if (temp1==NULL && temp2!=NULL){
            temp->data=temp2->data;
            temp->expo=temp2->expo;
            temp2=temp2->next;
        }
        else if (temp2==NULL && temp1!=NULL){
            temp->data=temp1->data;
            temp->expo=temp1->expo;
            temp1=temp1->next;
        }