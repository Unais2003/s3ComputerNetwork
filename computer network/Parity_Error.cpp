#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// int n;
// int msg [n];


void sender(int n, int msg[]){
    cout<<"Enter the message bits: ";
    for(int i = 0; i < n; i++){
    cin>>msg[i];
    }
     int c = 0;
     for(int i = 0; i < n; i++){
        if(msg[i]==1){
            c = c + 1;
        }
     }
    if(c%2 != 0){
        msg[n] = 1;
    }
    else {
        msg[n] = 0;
    }
    cout<<"After adding parity bits: "<<endl;
     for(int i = 0; i <= n; i++){
        cout<<msg[i]<<" ";        
        }

}

void transmission(int n,int msg[]){
    srand(time(0));
    int e = rand()%n;
    cout<<"\nNumber of error bits: "<<e<<endl;
    int p; // position

    for(int i = 0; i < e; i++){
        p = rand()%n;
        cout<<"Position of error bit: "<<p<<endl;
        if (msg[p]==0){
            msg[p]=1;
        }
        else{
            msg[p]=0;
        }
    }
    cout<<"Message after error bit: ";
    for(int i = 0; i <= n; i++){
        cout<<msg[i]<<" ";
    }

}
void reciever(int n, int msg[]){
    int x=0;
    cout<<"\nChecking for error..."<<endl;
    for(int i = 0; i <= n; i++){
        if(msg[i]==1){
            x = x + 1;
        }
    }
    if (x % 2 == 0){
        cout<<"No Error Detected";
    }
    else{
        cout<<"Error Detected! Even parity expected...";
    }
}

int main(){
    int n;
    cout<<"Enter number of bits: ";
    cin>>n;
    int msg [n+1];
    sender(n,msg);
    transmission(n,msg);
    reciever(n,msg);
   
}

//4

