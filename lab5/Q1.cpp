#include <iostream>
#include <ctime>
using namespace std;

void guessingGame(int targetnumber,int player){
    int guess;
    cout<<"\nPlayer "<<player<<" enter your guess: ";
    cin>>guess;

    if(guess==targetnumber){
    cout<<"CONGRATS YOU WON!"<<endl;
    return;
}    
    else{
    if(guess>targetnumber){
        cout<<"Your guess was higher than the number to be guessed!"<<endl;
    }
    else{
        cout<<"Your guess was lower than the number to be guessed!"<<endl;
    }
}
    //passing turn
    if(player==1){
    guessingGame(targetnumber,2);
}
    else{
    guessingGame(targetnumber,1);
}
}

int main(){
    srand(time(0));
    int targetnumber=rand()%100+1;

    cout<<"WELCOME TO GUESSING GAME"<<endl;

    guessingGame(targetnumber,1);//assumming player1 goes first

return 0;
}
