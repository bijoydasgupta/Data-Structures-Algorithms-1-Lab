#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); /* remove if directed*/
}

vector<int> bfs (vector<vector<int>> &adj, int source)
{
    int V= adj.size();

    vector<int> result;

    queue<int> q;

    vector<bool> visited(V, false);

    visited[source]=true;
    q.push(source);

    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        result.push_back(current);

        for(int x: adj[current])
        {
            if(!visited[x])
            {
                visited[x]=true;
                q.push(x);
            }
        }
    }

    return result;
}

int main()
{
    int V;
    cin>>V;
    vector<vector<int>> adj(V);

    int E, source;
    cin>>E;
    for(int i=0;i<E;i++)
    {
        cout<<"Enter source, destination: ";
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }

    cout<<"Enter the source: ";
    cin>>source;

    vector<int> result= bfs(adj, source);

    for(int i=0;i<V;i++)
    {
        cout<<result[i]<<" ";
    }

    return 0;
}
