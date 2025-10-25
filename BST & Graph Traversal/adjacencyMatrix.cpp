#include<bits/stdc++.h>
using namespace std;

#define INT_MAX 999
void addEdge(vector<vector<int>> &mat,int u,int v, int w)
{
    mat[u][v]=w;
    mat[v][u]=w;
}

void displayMatrix(vector<vector<int>> &mat)
{
    int V=mat.size();
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(mat[i][j]==INT_MAX) cout<<"INF"<<"\t";
            else cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    int V;
    cin>>V;
    vector<vector<int>> mat(V,vector<int>(V,INT_MAX));

    int E;
    cin>>E;
    for(int i=0;i<E;i++)
    {
        cout<<"Enter source, destination and weight: ";
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(mat,u,v,w);
    }

    cout<<"Adjacency Matrix Representation: "<<endl;
    displayMatrix(mat);
}
