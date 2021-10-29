#include<iostream>
using namespace std;
int arr[1001][1001];
int parityassignment(int sum, int oddoreven)
{
    if(sum % 2 == 0)
    {
        if(oddoreven)
        {
           return 1; 
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(oddoreven)
        {
           return 0; 
        }
        else
        {
            return 1;
        }
    }
}

int paritycheck(int M,int N,int oddoreven)
{
 int sumcolumns[M]={0};
    for(int j =0; j<M; j++)
    {
        for(int i=0; i<N; i++)
        {
            sumcolumns[j] = sumcolumns[j] + arr[i][j];
        }
    }
    int sumrows[N] = {0}; 
    for(int i =0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
           sumrows[i] = sumrows[i] + arr[i][j];
        }
    }
    for(int j = 0; j<M; j++)
    {
        if(arr[N][j] != parityassignment(sumcolumns[j],oddoreven))
        {
            return 1;
        }
    }
    for(int i = 0; i<N; i++)
    {
        if(arr[i][M] != parityassignment(sumrows[i],oddoreven))
        {
            return 1;
        }
    }
    int sum=0;
    for(int i = 0; i<N; i++)
    {
        sum = sum + sumrows[i];   
    }
    if(arr[N][M] !=  parityassignment(sum,oddoreven))
    {
        return 1;
    }
    return 0;
}
int main(){
    int M,N;
    cout << "Enter length of messsage: " ;
    cin >> M;
    cout << "Enter number of messsages: " ;
    cin >> N;

    int sumrows[N]={0};
    int sumcolumns[M]={0};
    cout << "Enter data bits seperated by space"<<endl;
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
        sumrows[i] = sumrows[i] + arr[i][j];
        }
    } 

    for(int j =0; j<M; j++)
    {
        for(int i=0; i<N; i++)
        {
            sumcolumns[j] = sumcolumns[j] + arr[i][j];
        }
    }

    cout << "Enter 0 for even parity or 1 for odd parity" << endl; 
    
    int oddoreven;

    cin >> oddoreven;
    if((oddoreven != 1) && (oddoreven !=0))
    {
        cout << "Enter valid input" << endl;
        return 0;
    }
    for(int i = 0; i<N; i++)
    {
        arr[i][M] = parityassignment(sumrows[i],oddoreven);
    }
    for(int j = 0; j<M; j++)
    {
        arr[N][j] = parityassignment(sumcolumns[j],oddoreven);
    }
    int sum=0;
    for(int i = 0; i<N; i++)
    {
        sum = sum + sumrows[i];   
    }
    arr[N][M] =  parityassignment(sum,oddoreven);

    cout << "Transmitting Message: " << endl;
    for(int i = 0; i<N+1; i++)
    {
        for(int j = 0; j<M+1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int error;
    cout <<endl << "For error free transmission press 0, To create error press 1: "<<endl;
    cin >> error;
    if(error)
    {
        arr[0][0] = arr[0][0] + 1;
        arr[0][0] = arr[0][0] % 2;
    }
    cout << "Recieved Message"<<endl;
    for(int i = 0; i<N+1; i++)
    {
        for(int j = 0; j<M+1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int check;
    check = paritycheck(M,N,oddoreven);
    if(check)
    {
        cout<< endl <<"Error is present, Data should be sent again" << endl;
    }
    else
    {
        cout<< endl<<"Error is not present, Data transmission successfull" << endl;
    }
    return 0; 
    
    


}