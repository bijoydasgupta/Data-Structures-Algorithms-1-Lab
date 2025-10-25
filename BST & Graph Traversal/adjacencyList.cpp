#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayAdjList(vector<vector<int>> &adj)
{
    for(int i=0;i<adj.size();i++)
    {
        cout<<i<<":"<<"\t";
        for(int output:adj[i])
        {
            cout<<output<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int V;
    cin>>V;
    vector<vector<int>> adj(V);

    int E;
    cin>>E;
    for(int i=0;i<E;i++)
    {
        cout<<"Enter source, destination and weight: ";
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }

    cout<<"Adjacency List Representation: "<<endl;
    displayAdjList(adj);
}
