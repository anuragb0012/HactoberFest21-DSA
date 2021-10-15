// DFS code
#include<bits/stdc++.h>
using namespace std;

bool vis[200005];

vector<int>adj[200005];

//INPUT:-
// no of nodes=6
//no of edges=4
//1->3,3->5,3->6,2->4

//******EXPLANATION*****
//  1 | 3
//  2 | 4
//  3 | 1 5 6
//  4 | 2
//  5 | 3
//  6 | 3

//OUTPUT:-
//1 3 5 6 2 4


 void dfs(int v)
    {
    
        vis[v]=true;   // this visited bool array is created inorder to prevent printing of already traversed/visited element.
        cout<<v<<" ";
        for(auto x:adj[v])  //here this for loop is traversing all the adjacent nodes of the current v node and checking if its visited or not.
        {
            if(!vis[x])
            {
                dfs(x);
            }
        }
    }

  int main()
    {
        int n,e;
        cin>>n>>e; // n=no of nodes   e=no of edges

        for(int i=0;i<e;i++)
        {
            int x,y;       // input of nodes
            cin>>x>>y;
            adj[x].push_back(y);  // pushing each other adjacent values in each other adjacent vector
            adj[y].push_back(x);
        }

        for(int i=1;i<=n;i++)    //performing dfs for every node.
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }

    }



