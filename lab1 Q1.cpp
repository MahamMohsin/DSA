#include <iostream>
using namespace std;

class BankAccount{
float balance;

public:
BankAccount():balance(0){}

BankAccount(float initialbal):balance(initialbal){}

BankAccount(BankAccount &obj){
balance=obj.balance;    
}

float getbalance(){
    return balance;
}

void deduct(float amount){
    balance=balance-amount;
}
};

int main(){
    BankAccount acc1;
    BankAccount acc2(1000);
    BankAccount acc3=acc2;

    cout<<"Account 1 Balance: "<<acc1.getbalance()<<endl;
    cout<<"Account 2 Balance: "<<acc2.getbalance()<<endl;

    float amt;
    cout<<"Enter amount to deduct from account 3: ";
    cin>>amt;
    acc3.deduct(amt);
    
    cout<<"Account 3 Balance: "<<acc3.getbalance()<<endl;
    cout<<"Account 2 Balance: "<<acc2.getbalance();

return 0;
}