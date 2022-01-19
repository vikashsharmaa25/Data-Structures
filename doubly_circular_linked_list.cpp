/*



     ____                                
    |  _ \ __ _ _ ____   _____  ___ _ __ 
    | |_) / _` | '_ \ \ / / _ \/ _ \ '__|
    |  _ < (_| | | | \ V /  __/  __/ |   
    |_| \_\__,_|_| |_|\_/ \___|\___|_|   



*/
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node *prev;
};

class cls{
    node *head;
    public:
        int l;
        cls();
        void add_first(int);
        void add_last(int);
        void add_particular_pos(int,int);
        int delete_first();
        int delete_last();
        int delete_particular_pos(int);
        void display_all();
        ~cls(){
            cout<<"\n\t Object is deleted ";
        }
};
cls::cls(){
    this->head=NULL;
    l=0;
}
void cls::add_particular_pos(int pos,int x){
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    if(pos==0){
        if(head==NULL){
            temp->data=x;
            temp->prev=temp;
            temp->next=temp;
            head=temp;
            l++;
        }
        else{
            cur=head;
            if(l==1){
                temp->data=x;
                temp->prev=cur;
                temp->next=cur;
                cur->prev=temp;
                cur->next=temp;
                head=temp;
                l++;
            }
            else{
                temp->data=x;
                temp->next=cur;
                cur->prev=temp;
                do{
                    pre=cur;
                    cur=cur->next;
                }while(cur->next!=head);
                temp->prev=cur;
                cur->next=temp;
                head=temp;
                l++;
            }
        }   
    }
    else{
        cur=head;
        int i=0;
        while(i<pos&&cur->next!=head){
            pre=cur;
            cur=cur->next;
            i++;
        }
        if(cur->next==head){
            temp->data=x;
            temp->next=head;
            temp->prev=cur;
            cur->next=temp;
            l++;
        }
        else{
            temp->data=x;
            temp->next=cur;
            temp->prev=pre;
            pre->next=temp;
            cur->prev=temp;
            l++;
        }
    }
}
void cls ::add_first(int x){
    add_particular_pos(0,x);
}
void cls ::add_last(int x){
    add_particular_pos(l,x);
}
int cls ::delete_particular_pos(int pos){
    node *pre=new node;
    node *cur=new node;
    cur=head;
    if(head==NULL){
        cout<<"\n\t Nothing to delete ";
        return 0;
    }
    else if(pos==0){
        if(cur->next==head){
            head=NULL;
            l--;
            return cur->data;
        }
        else{
            int x=head->data;
            head=head->next;
            cout<<head->data;
            cur=head;
            while(cur->next!=head){
                pre=cur;
                cur=cur->next;
            }
            pre->next=head;
            head->prev=pre;
            l--;
            return x;
        }
    }
    else{
        int i=0;
        while(i<pos&&cur->next!=head){
            pre=cur;
            cur=cur->next;
            i++;
        }
        if(cur->next==head){
            head->prev=pre;
            pre->next=head;
            l--;
            return cur->data;
        }
        else{
            pre->next=cur->next; 
            cur->next->prev=pre;
            l--;
            return cur->data;
        }
    }
}
int cls:: delete_first(){
    return delete_particular_pos(0);
}
int cls::delete_last(){
    return delete_particular_pos(l);
}
void cls::display_all(){
    node *new_node=head;
    if(head==NULL)
    cout<<"\n\t Nothing to display ";

    else{
        cout<<"|^";
        do{
            cout<<"<-"<<new_node->data<<"->";
            new_node=new_node->next;   
        }while(new_node!=head);
        cout<<"----^|";
    }
}

int main(){
    cout<<"\n\t        ::::::: Doubly-linked List ::::::: ";
    cls *l=new cls;
    int n;
    while(1){
        cout<<"\n\n\t*-----------------------------------------------------------------------------------*";
        cout<<"\n\n\t 1. Insertion at Begin 2. Insertion at end 3 . Insertion at particular position ";
        cout<<"\n\n\t 4. Deletion at Begin 5. Deletion at End 6. Deletion at particular position ";
        cout<<"\n\n\t 7. Display all ";
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
            l->add_particular_pos(p-1,e);
        }
        else if(n==4){;
            printf("\n\t %d is deleted ",l->delete_first());
        }
        else if(n==5){
            printf("\n\t %d is deleted ",l->delete_last());
        }
        else if(n==6){
            cout<<"\n\t Enter a position : ";
            cin>>p;
            printf("\n\t %d is deleted ",l->delete_particular_pos(p-1));
        }
        else if(n==7){
            l->display_all();
        }
        else
        return 0;
    }
    return 0;
}