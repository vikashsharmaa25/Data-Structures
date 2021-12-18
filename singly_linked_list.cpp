#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class singly_linked_list{
    node *head;
    public:
        int length;
        singly_linked_list();
        ~singly_linked_list(){
            cout<<"\n\t Object deleted ";
        };
        void add_first(int);
        void add_last(int);
        void add_particular_pos(int,int);
        int delete_first();
        int delete_last();
        int delete_particular_pos(int);
        void display_all();
        void display_first();
        void display_last();
        void display_particular_pos(int);
};
singly_linked_list::singly_linked_list(){
    this->length=0;
    this->head=NULL;
}
void singly_linked_list::add_particular_pos(int pos,int n){
    node *pre=new node();
    node *cur=new node();
    node *temp=new node();
    if(pos==0){
        temp->data=n;
        temp->next=this->head;
        this->head=temp;
        this->length++;
    }
    else{
        cur=this->head;
        for(int i=0;i<pos;i++){
            pre=cur;
            cur=cur->next;
        }
        temp->data=n;
        temp->next=cur;
        pre->next=temp;
        this->length++;
    }
}
void singly_linked_list::add_first(int n){
    add_particular_pos(0,n);
}
void singly_linked_list::add_last(int n){
    add_particular_pos(this->length,n);
}
int singly_linked_list::delete_particular_pos(int pos){
    int x;
    node *pre=new node();
    node *cur=new node();
    cur=this->head;
    if(this->head==NULL){
        cout<<"\n\t singly_linked_list list is empty ";
        return x;
    }
    else if(pos==0){
        pre=this->head;
        x=head->data;
        head=head->next;
        this->length--;
        return x;
    }
    else{
        for(int i=0;i<pos;i++){
            pre=cur;
            cur=cur->next;
        }
        x=cur->data;
        pre->next=cur->next; 
        this->length--;
        return x;
    }
    
    
}
int singly_linked_list::delete_first(){
    int  z=delete_particular_pos(0);
    return z;
}
int singly_linked_list::delete_last(){
    int z=delete_particular_pos(this->length-1);
    return z;
}
void singly_linked_list::display_particular_pos(int pos){
    node *new_node=this->head;
    for(int i=0;i<pos;i++){
        new_node=new_node->next;
    }
    cout<<"\n\t "<<new_node->data;
}
void singly_linked_list::display_first(){
    display_particular_pos(0);
}
void singly_linked_list::display_last(){
    display_particular_pos(this->length-1);
}
void singly_linked_list::display_all(){
    node *new_node=this->head;
    int i=1;
    while(new_node){
        cout<<"\t "<<new_node->data<<"->";
        new_node=new_node->next;
        i++;
    }
    cout<<"NULL";
}
int main(){
    singly_linked_list *l=new singly_linked_list;
    int n;
    while(1){
        cout<<"\n\n\t*-----------------------------------------------------------------------------------*";
        cout<<"\n\n\t 1. Insertion at Begin 2. Insertion at end 3 . Insertion at particular position ";
        cout<<"\n\n\t 4. Deletion at Begin 5. Deletion at End 6. Deletion at particular position ";
        cout<<"\n\n\t 7. Display all 8 .Display first 9. Display Last 10. Display Particular pos ";
        cout<<"\n\n\t*-----------------------------------------------------------------------------------*\n\t";
        cin>>n;
        int e,p;
        if(n==1){
            cout<<"\n\t Enter a element : ";
            cin>>e;
            l->add_first(e);
        }
        else if(n==2){
            cout<<"\n\t Enter a element : ";
            cin>>e;
            l->add_last(e);
        }
        else if(n==3){
            cout<<"\n\t Enter a position : ";
            cin>>p;
            cout<<"\n\t Enter element : ";
            cin>>e;
            l->add_particular_pos(p,e);
        }
        else if(n==4){
            int z=l->delete_first();
            printf("\n\t %d is deleted ",z);
        }
        else if(n==5){
            int z=l->delete_last();
            printf("\n\t %d is deleted ",z);
        }
        else if(n==6){
            cout<<"\n\t Enter a position : ";
            cin>>p;
            printf("\n\t %d is deleted ",l->delete_particular_pos(p));
        }
       
        else if(n==7){
            l->display_all();
        }
        else if(n==8){
            l->display_first();
        }
        else if(n==9){
            l->display_last();
        }
        else if(n==10){
            cout<<"\n\t Enter position : ";
            cin>>p;
            l->display_particular_pos(p);
        }
        else
        return 0;
    }
    return 0;
}