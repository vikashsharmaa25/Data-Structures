//Ranveer Singh
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
static int l=0;
void init(){
    head=NULL;
}
void insertion_at_particular_pos(int pos,int n){
    struct node *pre=(struct node*)malloc(sizeof(struct node));
    struct node *cur=(struct node*)malloc(sizeof(struct node));
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    int i;
    if(pos==0){
        if(head==NULL){
            temp->data=n;
            temp->next=temp;
            head=temp;
            l++;
        }
        else{
            cur=head;
            if(head->next==head){
                temp->data=n;
                temp->next=head;
                cur->next=temp;
                head=temp;
                l++;
            }
            else{
                while(cur->next!=head){
                    pre=cur;
                    cur=cur->next;
                }
                temp->data=n;
                temp->next=head;
                cur->next=temp;
                head=temp;
                l++;
            }
        }
    }
    else{
        cur=head;
        i=0;
        while(i<pos&&(cur->next)!=head){
            pre=cur;
            cur=cur->next;
            i++;
        }
        if(cur->next==head){
            temp->data=n;
            temp->next=head;
            cur->next=temp;
            l++;
        }
        else{
            temp->data=n;
            temp->next=cur;
            pre->next=temp;
            l++;
        }
    }
}
void insertion_first(int n){
    insertion_at_particular_pos(0,n);
}
void insertion_last(int n){
    insertion_at_particular_pos(l,n);
}
int delete_particular_pos(int pos){
    struct node *pre=(struct node*)malloc(sizeof(struct node));
    struct node *cur=(struct node*)malloc(sizeof(struct node));
    cur=head;
    int x,i;
    if(head==NULL){
        printf("\n\t Deletion cannot be performed in empty circular linked list ");
        return 0;
    }
    else if(pos==0){
        if(head->next==head){
            pre=head;
            x=pre->data;
            head=NULL;
            l--;
            return x;
        }
        else{
            pre=head;
            x=head->data;
            head=head->next;
            i=l;
            while(i>0){
                pre=cur;
                cur=cur->next;
                i--;
            }
            pre->next=head;
            l--;
            return x;
        }
    }
    else{
        i=0;
        while(i<pos&&(cur->next)!=head){
            pre=cur;
            cur=cur->next;
            i++;
        }
        if(cur->next==head){
            pre->next=head;
            l--;
            return cur->data;
        }
        else{
            pre->next=cur->next;
            l--;
            return cur->data;
        }
    }
}
int delete_first(){
    return delete_particular_pos(0);
}
int delete_last(){
    return delete_particular_pos(l);
}
void display_all(){
    struct node *new_node=head;
    do{
        printf("\t %d ->",new_node->data);
        new_node=new_node->next;
    }while(new_node!=head);
    printf("head");
}
int main(){
    int n;
    int z,e,p;
    init();
    while(1){
        printf("\n\n\t*-----------------------------------------------------------------------------------*");
        printf("\n\n\t 1. Insertion at Begin 2. Insertion at end 3 . Insertion at particular position ");
        printf("\n\n\t 4. Deletion at Begin 5. Deletion at End 6. Deletion at particular position ");
        printf("\n\n\t 7. Display all 8 .Display first 9. Display Last 10. Display Particular pos ");
        printf("\n\n\t*-----------------------------------------------------------------------------------*\n\t");
        scanf("%d",&n);
        if(n==1){
            printf("\n\t Enter a element : ");
            scanf("%d",&e);
            insertion_first(e);
            
        }
        else if(n==2){
            printf("\n\t Enter a element : ");
            scanf("%d",&e);
            insertion_last(e);
        }
        else if(n==3){
            printf("\n\t Enter a position : ");
            scanf("%d",&p);
            printf("\n\t Enter element : ");
            scanf("%d",&e);
            insertion_at_particular_pos(p-1,e);
        }
        else if(n==4){
            z=delete_first();
            printf("\n\t %d is deleted ",z);
        }
        else if(n==5){
            z=delete_last();
            printf("\n\t %d is deleted ",z);
        }
        else if(n==6){
            printf("\n\t Enter a position : ");
            scanf("%d",&p);
            z=delete_particular_pos(p-1);
            printf("\n\t %d is deleted ",z);
        }
       
        else if(n==7){
            display_all();
        }
        /*else if(n==8){
            display_first();
        }
        else if(n==9){
            display_last();
        }
        else if(n==10){
            printf("\n\t Enter position : ";
            scanf("%d",p);
            display_particular_pos(p);
        }*/
        else
        return 0;
    }
    return 0;
}
