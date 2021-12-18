#include<iostream>
using namespace std;
//template <typename T>
class node
{
    public:
        int data;
        node *next;
};

class circular_linked_list
{
private:
    node *head;
public:
    int length;
    circular_linked_list();
    ~circular_linked_list();
    void add_first(int);
    void add_last(int);
    void add_particular_pos(int,int);
    int delete_first();
    int delete_last();
    int delete_particular_pos(int);
    void display_all();
    void display_first();
    void display_last();
    void display_particular(int);
};
circular_linked_list::circular_linked_list()
{
    this->length=0;
    this->head=NULL;
}
circular_linked_list::~circular_linked_list()
{
    cout<<"\n\t Object is deleted ";
}
void circular_linked_list::add_particular_pos(int pos,int n){
    node *pre=new node();
    node *cur=new node();
    node *temp=new node();
    if(pos==0){
        if(head==NULL){
            temp->data=n;
            temp->next=temp;
            head=temp;
            this->length++;
        }
        else{
            cur=head;
            if(head->next==head){
                temp->data=n;
                temp->next=head;
                head->next=temp;
                head=temp;
                this->length++;
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
                this->length++;
            } 
        }
    }
    else{
        cur=head;
        int i=0;
        while(i<pos&&(cur->next)!=head){
            i++;
            pre=cur;
            cur=cur->next;
        }
        if(cur->next==head){
            temp->data=n;
            temp->next=head;
            cur->next=temp;
            this->length++;
        }
        else{
            temp->data=n;
            temp->next=cur;
            pre->next=temp;
            this->length++;
        }
        
    }
}
void circular_linked_list::add_first(int n){
    add_particular_pos(0,n);
}
void circular_linked_list::add_last(int n){
    add_particular_pos(this->length,n);
}
int circular_linked_list::delete_particular_pos(int pos){
    node *pre=new node();
    node *cur=new node();
    cur=head;
    int x;
    if(head==NULL)
    {
    	cout<<"\n\t Deletion cannot be performed circular link list is empty";
    	return 0;
	}
    else if(pos==0){
        if(head->next==head){
            pre=head;
            x=pre->data;
            head=NULL;
            this->length--;
            return x;
        }
        else{
            pre=head;
            head=head->next;
            x=pre->data;
            int i=length;
            while(i>0){
                pre=cur;
                cur=cur->next;
                i--;
            }
            pre->next=head;
            this->length--;
            return x;
        }
    }     
    else{
        if(pos==length){
            while(cur->next!=head){
                pre=cur;
                cur=cur->next;
            }
            pre->next=head;
            x=cur->data;
            delete cur;
            this->length--;
            return x;
        }
        else{
            int i=0;
            while(i!=pos){
                pre=cur;
                cur=cur->next;
                i++;
            }
            x=cur->data;
            pre->next=cur->next;
            this->length--;
            delete cur;
            return x;
        }
    }
}
int circular_linked_list::delete_first(){
    return delete_particular_pos(0);
}
int circular_linked_list::delete_last(){
    return delete_particular_pos(this->length);
}
void circular_linked_list::display_all(){
    node *new_node=head;
    if(head==NULL)
    cout<<"\n\t Nothing to display ";
    else{
        do{
        cout<<"\t "<<new_node->data<<"->";
        new_node=new_node->next;
        }while(new_node!=head);
        cout<<"head";
    }

}
int main(){
    circular_linked_list *l=new circular_linked_list;
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
            l->add_particular_pos(p-1,e);
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
            int z=l->delete_particular_pos(p-1);
            printf("\n\t %d is deleted ",z);
        }
       
        else if(n==7){
            l->display_all();
        }
        /*else if(n==8){
            l->display_first();
        }
        else if(n==9){
            l->display_last();
        }
        else if(n==10){
            cout<<"\n\t Enter position : ";
            cin>>p;
            l->display_particular_pos(p);
        }*/
        else
        return 0;
    }
    return 0;
}
