//Code for Famous Stock Span Problem Added.
//Github: Gupta-Nikhil85

#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int prices[],int n, int span[]){
    
    stack<int> s; //indices of days
    s.push(0);

    span[0]=1;
    for(int i=0; i<n;i++){

        int currentPrice=prices[i];
        while(!s.empty() && prices[s.top()]<=currentPrice){
            s.pop();
        }
        if(!s.empty()){
            span[i]=i-s.top();
        }
        else{
            span[i]=i+1;
        }
        s.push(i);
    }

    for(int i=0; i<n;i++){
        cout<<span[i]<<endl;
    }
    return;
}

int main(){

    int prices[]={100,80,60,70,60,75,85};
    int n=sizeof(prices)/sizeof(int);
    int span[10000]={0};
    stockSpan(prices,n,span);
}