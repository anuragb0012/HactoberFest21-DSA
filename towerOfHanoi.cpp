#include <iostream>
#include <stdio.h>
using namespace std;

// n - number of discs
// A - From rod
// B - Auxiliary rod
// C - Destination rod 
void towerOfHanoi(int n,int A,int B,int C)
{
    if(n>0)
    {
        towerOfHanoi(n-1,A,C,B);
        printf("%d %d\n",A,C);
        towerOfHanoi(n-1,B,A,C);
    }
    
}

int main(){
    
   towerOfHanoi(3,1,2,3);
//    1 - rod A
//    2 - rod B 
//    3 - rod C 
   return 0;
}
