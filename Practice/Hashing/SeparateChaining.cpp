#include <iostream>
using namespace std;

//hash table entry class represents info that is to be stored in hash table
//kinda similar to creating node class
class hashEntry{
    public:
    int key; //used in hashfunction(unique for all values stored in hash table as we do lookup using it)
    int value;//value stored in hashtable associated with key(not necessarily unique) eg:(k,v)=(101,"john")
    hashEntry* next;//ptr that points to next node in LL if collision occurs

    hashEntry(int k,int v){
        key=k;
        value=v;
        this->next=NULL;
    }
};

/*static: The value is shared across all instances of the class, ensuring all hash tables start with the same size.
const: The value is fixed and cannot be modified during execution.*/
class hashTable{
    static const int initialSize=10;
    int size;//current size of table that might be alterable after resizing
    hashEntry** table;//ptr to nodes of LL basically ptr arr that stores ptr to hashtable entries
    int numOfelements;//total elements in hash table

    public:
    //constructor that initiallizes table size initially to the value we set above(in static)
    hashTable(){
        size=initialSize;
        numOfelements=0;//initially 0
        //creating array dynamically and setting values to null
        table=new hashEntry*[size]();//table[0]->NULL so on till size
    }

    int hashFunc(int k){
        //you can make you own hash function
        return k%size;
    }

    double loadfactor(){
        //used for resizing/rehashing if loadfactor increased from default or predefined value
        return 1.0*numOfelements/size;
    }

    void resizing(int newSize){
        //incase of lf>default value i.e 0.7 usually
        //basically considering hashEntry as datatype int for instance
        hashEntry** newTable=new hashEntry*[newSize]();//again initiallized with null for rehashing

         //after new table made old elements to be rehashed
         for(int i=0;i<size;i++){
            hashEntry* current=table[i];//pointing to front value of table
            while(current!=NULL){
                int newhash=current->key%newSize;//rehashing
                hashEntry* next=current->next;//storing current next as its modified later in func
                //basically now newhash value stored at the first index of new table like table[0]->newhashedValue
                current->next=newTable[newhash];//firstly we point at that index
                newTable[newhash]=current;//finally insert
                current=next;//moving ahead
            }
         }
         delete[] table;
         table=newTable;//newtable made current table
         size=newSize;
    }

    //INSERTION
    void insert(int k,int v){
        //hash index to found(hash func called)
        int hash=hashFunc(k);
        //new entrycreated like node*newNode=new node()
        hashEntry* newEntry=new hashEntry(k,v);

        if(table[hash]==NULL){//if the calculated index is empty direct insertion
        table[hash]=newEntry;
        }
        else{//collision exists so you traverse the LL for point of insertion
        hashEntry* ptr=table[hash];
        while(ptr->next!=NULL){//reaching last el of LL
            ptr=ptr->next;
        }
        ptr->next=newEntry;//finally inserting when insertion point reached
        }
         numOfelements++;

        //after handling collision/inserting checks the need for resizing
        if(loadfactor()>0.7){//considering deault lf as 0.7
        int newSize=size*2;
        resizing(newSize);
        }
    }

    //SEARCH (as value to be returned so int)
    int searching(int k){
        int hash=hashFunc(k);

        //we traverse the LL that is found at that hash index
        hashEntry* ptr=table[hash];//(rev of LL concept: node* ptr=head)
        while(ptr!=NULL){
            if(ptr->key==k){
                return ptr->value;
            }
            ptr=ptr->next;//keep traversing until val found
        }
        return -1;//if key not found 
    }

    //REMOVAL
    void remove(int k){
        int hash=hashFunc(k);//calculating index to delete

        hashEntry* ptr=table[hash];//for traversal
        hashEntry* prev=NULL;//keeps track of previous node to current for deletion cases

        //traversing until key to delete not found
        while(ptr!=NULL && ptr->key!=k){
            prev=ptr;//follows ptr
            ptr=ptr->next;
        }
        //when key found then handle delete cases
        if(ptr!=NULL){//bec nothing to delete if ptr==NULL

        if(prev==NULL){//means ptr is the only head node
        table[hash]=ptr->next;//ptr->next goes at head pos as ptr will be deleted
    }   
    else{//prev!=NULL(means mid/end)
        prev->next=ptr->next;//adjusments in mid
    }
}      
    delete ptr;
    numOfelements--;
}

//PRINTING
void display(){
    for(int i=0;i<size;i++){
        cout<<"Index "<<i<<": ";//every index of table printed
        //traversing for printing
        hashEntry* ptr=table[i];
        while(ptr!=NULL){
            cout<<" key: "<<ptr->key<<" value: "<<ptr->value<<" -> ";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;//at end of every LL at every index NULL printed
    }
}

~hashTable(){
    for(int i=0;i<size;i++){
        hashEntry* ptr=table[i];
        while(ptr!=NULL){
            hashEntry* next=ptr->next;
            delete ptr;
            ptr=next;
        }
        table[i]=NULL;
    }
    delete[] table;
}
};

int main(){
    hashTable ht;

    ht.insert(0,10);
    ht.insert(10,20);
    ht.insert(20,40);
    ht.insert(29,30);

    cout<<"HASH TABLE AFTER INSERTION: "<<endl;
    ht.display();

    int search=ht.searching(10);//key entered
    if(search!=-1){
        cout<<"Key found and its value is: "<<search<<endl;
    }
    else{
        cout<<"Key not found!";
    }

return 0;
}
