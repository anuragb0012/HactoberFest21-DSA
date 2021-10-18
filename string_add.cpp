#include<bits/stdc++.h>
using namespace std;
int main()
{
  string n1,n2,res;
  cout<<"Enter n1"<<endl;
  cin>>n1;
  cout<<"Enter n2"<<endl;
  cin>>n2;
  int a=stoi(n1);
  int b=stoi(n2);
  int ans=a+b;
  res=ans.to_string();
  cout<<res;
  return 0;
}
