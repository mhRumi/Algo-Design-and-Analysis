#include<bits/stdc++.h>
using namespace std;
#define v 6

bool bfs(int rgraph[v][v], int s, int t, int parent[])
{
    bool visited[v];
    memset(visited, false, sizeof(visited));
    queue < int > q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i<v; i++)
        {
            if(visited[i] == false && rgraph[u][i] > 0)
            {
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }

    return (visited[t] == true);
}

int fordFulkerson(int graph[v][v], int s, int t)
{
    int a;
    int rgraph[v][v];
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
        rgraph[i][j] = graph[i][j];
    int parent[v];
    int max_flow = 0;

    while(bfs(rgraph, s, t, parent))
    {
        int path_flow = INT_MAX;

        for(int b=t; b != s; b = parent[b])
        {
            a = parent[b];
            path_flow = min(path_flow, rgraph[a][b]);
        }

        for(int b = t; b !=s; b = parent[b])
        {
            a = parent[b];
            rgraph[a][b] -= path_flow;
            rgraph[b][a] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;

}

int main()
{
    int e;
    cin>>e;
    int graph[v][v];
    memset(graph, 0, sizeof(graph));
    for(int i=0; i<e; i++)
    {
        int a, b, weight;
        cin>>a>>b>>weight;

        graph[a][b] = weight;
    }

    cout<<fordFulkerson(graph, 0, v-1)<<endl;
}
