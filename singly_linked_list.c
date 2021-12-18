#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
static int l=0;
struct node *head;
void init(){
    head=NULL;
}
void insertion_at_particular_pos(int pos,int n){
    int i;
    struct node *pre=(struct node*)malloc(sizeof(struct node));
    struct node *cur=(struct node*)malloc(sizeof(struct node));
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(pos==0){
        temp->data=n;
        temp->next=head;
        head=temp;
        l++;
    }
    else{
        cur=head;
        for(i=0;i<pos;i++){
            pre=cur;
            cur=cur->next;
        }
        temp->data=n;
        temp->next=cur;
        pre->next=temp;
        l++;
    }
}
void insertion_begin(int n){
    insertion_at_particular_pos(0,n);
}
void insertion_end(int n){
    insertion_at_particular_pos(l,n);
}
int delete_particular_pos(int pos){
    int x,i;
    struct node *pre=(struct node*)malloc(sizeof(struct node));
    struct node *cur=(struct node*)malloc(sizeof(struct node));
    cur=head;
    if(pos==0){
        pre=head;
        x=head->data;
        head=head->next;
        l--;
        return x;
    }
    else{
        for(i=0;i<pos;i++){
            pre=cur;
            cur=cur->next;
        }
        x=cur->data;
        pre->next=cur->next;
        l--;
        return x;
    }
}
int delete_first(){
    int x=delete_particular_pos(0);
    return x;
}
int delete_last(){
    int x=delete_particular_pos(l-1);
    return x;
}
void display_all(){
    struct node *new_node=head;
    int i=1;
    while(new_node){
        printf("\t %d",new_node->data);
        printf("->");
        new_node=new_node->next;
    }
    printf("NULL");
}
int main(){
    struct node *r;
    int n;
    int e,p,z;
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
            insertion_begin(e);
        }
        else if(n==2){
            printf("\n\t Enter a element : ");
            scanf("%d",&e);
            insertion_end(e);
        }
        else if(n==3){
            printf("\n\t Enter a position : ");
            scanf("%d",&p);
            printf("\n\t Enter element : ");
            scanf("%d",&e);
            insertion_at_particular_pos(p,e);
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
            printf("\n\t %d is deleted ",delete_particular_pos(p));
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
            scanf("%d",&p);
            display_particular_pos(p);
        }*/
        else
        return 0;
    }
    return 0;
}
