#include <iostream>
using namespace std;
//NOT MAINTAINING LINKEDLIST IN LP HERE

class hashEntry{
    public:
    int key;//the key is unique we use it for hash function
    int value;//associated with key

    hashEntry(int k,int v){
        key=k;
        value=v;
    }
};

class hashtable{
    static const int size=10;//to keep the table size same for all 
    hashEntry** table;//ptr to table arr

    public:
    hashtable(){
        table=new hashEntry*[size]();//initially table[0] till size to null
    }

    int hashFunc(int k){
        return k%size;
    }

    //INSERTION
    void insert(int k,int v){
        int hash=hashFunc(k);
        /*this checks that in the index found by the hash function is it occupied 
        and then checks if its occupied by a different key so that means collision has occured and thus we resolve it*/
        while(table[hash]!=NULL && table[hash]->key!=k){
            hash=(hash+1)%size;
        }

        //if keys are not unique we replace previous key entry
        if(table[hash]!=NULL){
            delete table[hash];
        } 

        //new entry inserted
        table[hash]=new hashEntry(k,v);
    }

    //SEARCH
    int search(int k){
        int hash=hashFunc(k);
        //search until key found
        while(table[hash]!=NULL && table[hash]->key!=k){
            hash=(hash+1)%size;
        }
        
        //returning key value if found
        if(table[hash]->key==k){
            return table[hash]->value;
        }
        else{
            return -1;
        }
    }

    //REMOVAL
    void remove(int k){
        int hash=hashFunc(k);

        if(table[hash]!=NULL){
            if(table[hash]->key==k){//if val to delt found
            delete table[hash];
            table[hash]=NULL;//setting null
            return;
            }
            hash=(hash+1)%size;//moving to next index until key found
        }
    }

    //PRINT
    void display(){
        for(int i=0;i<size;i++){
            if(table[i]!=NULL){
                cout<<" Index "<<i<<": key="<<table[i]->key<< ", Value=" << table[i]->value <<endl;
            }
            else{
                cout << "Index " << i << ": Empty" <<endl;
            }
        }
    }
};

int main(){
     hashtable ht; // Hash table ka object create kiya.

    // Values insert karte hain.
    ht.insert(0, 10); // Key 0 aur Value 10 insert kiya.
    ht.insert(22,3);
    ht.insert(2, 20); // Key 2 aur Value 20 insert kiya.
    ht.insert(11, 30); // Key 11 aur Value 30 insert kiya.

    cout<<"HASH TABLE AFTER INSERTION: "<<endl;
    ht.display();

    int s=ht.search(2);//key sent

    if(s!=-1){
        cout<<"Value for key 2: "<<s<<endl;
    }
    else{
        cout<<"key not found!"<<endl;
    }

    ht.remove(2);
    cout<<"\n";
    ht.display();
}