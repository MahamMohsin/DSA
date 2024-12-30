#include <iostream>
using namespace std;

/*Suppose you have a doubly circular linked list that represents a playlist of songs, where each
node represents a song and contains the song's name and artist name. You want to allow the
user to remove a song at a specific position in the playlist. The user will enter the name, artist
name as well as the position from where it should be removed. Write a function in C++ that
takes the head pointer of the linked list, the name, artist name, and removes that song at the
specified position in the playlist. If the position is out of range (less than 1 or greater than the
length of the playlist), the function should return without modifying the linked list*/

class node{
    public:
    string song;
    string artist;
    node*prev;
    node*next;

    node(string s,string a){
        song=s;
        artist=a;
        this->prev=NULL;
        this->next=NULL;
    }
};

class circulardoubly{
    public:
    node* head=NULL;
    node* tail=NULL;

    //insertion from tail
    void insert(string s,string a){
        node* n=new node(s,a);

        if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
            head->prev=tail;
        }
        else{
            tail->next=n;
            n->prev=tail;
            tail=n;
            tail->next=head;
            head->prev=tail;
        }
    }

    //function to count length of linkedlist for limitation condition in question
    //else if ptr=head->next used start count from 1 as head excluded 
    int counting(){
        int count=0;
        node* ptr=head;
       do{
            count++;
            ptr=ptr->next;
        } while(ptr!=head);
        return count;
    }

    void removal(string songname,string singer,int pos){
        int count=counting();//functions return nodes in LL

        if(pos<1 || pos>count){
            cout<<"\nInvalid pos!"<<endl;
            return;
        }
        else{//doing for valid pos

            node* ptr=head;//as we gotta return to head in circular
            for(int i=1;i<pos;i++){
                ptr=ptr->next;//reaching pos
            }
        
            if(ptr->song!=songname || ptr->artist!=singer){
                cout<<"\n\nSONG TO DELETE NOT FOUND AT POSITION!"<<endl;
                return;
            }

            cout<<"\nDeleting "<<ptr->song<<" by "<<ptr->artist<<" found at "<<pos<<endl<<endl;

            //if the node to delete is the only node
            if(ptr==head && ptr==tail){
                head=tail=NULL;
            }

            else if(ptr==head){//pos==1
            head=head->next;
            tail->next=head;
            head->prev=tail;
            }

            else if(ptr==tail){//for last
                tail=tail->prev;
                tail->next=head;
                head->prev=tail;
            }

            //for general pos
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            
            delete ptr;
        }
    }

    void display(){
        node* ptr=head;
        do{
            cout<<ptr->song<<" "<<ptr->artist<<endl;
            ptr=ptr->next;
        }while(ptr!=head);
        cout<<ptr->song<<" "<<ptr->artist;//showing circular behaviour
    }
};

int main(){
    circulardoubly cdl;

    cdl.insert("Aadat","Atif Aslam");
    cdl.insert("Zaalima","Hasan Raheem");
    cdl.insert("Night Changes","One Direction");
    cdl.display();

    cdl.removal("Aadat","Hassan Raheem",1);

    cdl.removal("Aadat","Atif Aslam",1);
    cdl.display();

}