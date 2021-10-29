#include<iostream>
using namespace std;
int arr[1001][1001];
int main(){
    int M,N;
    cout << "Enter length of messsage: " ;
    cin >> M;
    cout << "Enter number of messsages: " ;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> arr[i][j];
            if((arr[i][j] != 1) && (arr[i][j] !=0))
            {
                cout<< "Error: Enter data in binary form." << endl;
                return 0;
            }
        }
    }
    int carry = 0;
    int Checksum[M] = {0};
    for(int i=0; i <N;i++)
    {
        for(int j=M-1; j>=0; j--)
        {
            Checksum[j] = Checksum[j] + carry + arr[i][j];
            if(Checksum[j]==2)
            {
                carry = 1;
                Checksum[j] = 0;
            }
            else if(Checksum[j]==3)
            {
                carry = 1;
                Checksum[j] = 1;
            }
            else
            {
                carry = 0;
            }
        } 
    }
    if(carry == 1)
    {
        for(int j=M-1; j>=0; j--)
        {
            Checksum[j] = Checksum[j] + carry;
            if(Checksum[j]==2)
            {
                carry = 1;
                Checksum[j] = 0;
            }
            else
            {
                carry = 0;
            }
        } 
    }
    cout<< "Sum is :"<<endl;
    for(int i = 0;i<M;i++)
    {
        cout<<Checksum[i]<< " ";
        Checksum[i] = Checksum[i] + 1;
        Checksum[i] = Checksum[i] % 2;
    }
    cout<< endl;
    cout<< "CheckSum is :"<<endl;
    for(int i = 0;i<M;i++)
    {
        cout<<Checksum[i]<< " ";
    }
    cout<< endl;
    for(int j = 0; j < M; j++)
    {
        arr[N][j] = Checksum[j];
    }
    carry = 0;
    int Check[M] = {0};
    for(int i=0; i <=N;i++)
    {
        for(int j=M-1; j>=0; j--)
        {
            Check[j] = Check[j] + carry + arr[i][j];
            if(Check[j]==2)
            {
                carry = 1;
                Check[j] = 0;
            }
            else if(Check[j]==3)
            {
                carry = 1;
                Check[j] = 1;
            }
            else
            {
                carry = 0;
            }
        } 
    }
    if(carry == 1)
    {
        for(int j=M-1; j>=0; j--)
        {
            Check[j] = Check[j] + carry;
            if(Check[j]==2)
            {
                carry = 1;
                Check[j] = 0;
            }
            else
            {
                carry = 0;
            }
        } 
    }
    cout<< "Final Sum is :"<<endl;
    for(int i = 0;i<M;i++)
    {
        cout<<Check[i]<< " ";
        Check[i] = Check[i] + 1;
        Check[i] = Check[i] % 2;
    }
    cout <<endl;
    cout<< "Compliment is: "<< endl;
    for(int i = 0;i<M;i++)
    {
        cout<<Check[i]<< " ";
    }
}