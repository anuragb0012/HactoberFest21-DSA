#include <iostream>
#include<stack>
using namespace std;

int main()
{
    string str;
    int i=0,n,f=0;
    stack <char> s;
    cout<<"Enter any sequence of brackets( '(','{','[' )to check for balancing : ";
    cin>>str;
    while(str[i]!='\0')
    {
        if(str[i]=='('|| str[i]=='{' || str[i]=='[')
        s.push(str[i]);
        
        else if(str[i]==')')
        {
            if(s.top()=='(')
            s.pop();
        }
        else if(str[i]=='}')
        {   if(s.top()=='{')
            s.pop();
        }
        else if(str[i]==']')
        {    if(s.top()=='[')
            s.pop();
        }  
        else if(str[i]!='('|| str[i]!='{' || str[i]!='[' || str[i]!=')' || str[i]!='}' || str[i]!=']')
        {
            f=1;
            break;
        }
            
        i++;
    }
    if (f==1)
    {
        cout<<"Please give valid input using bracket symbols only ";
    }
    else if(s.empty()==1)
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Not Balanced ";
    }

    return 0;
}
