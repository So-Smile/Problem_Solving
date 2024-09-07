// 백준 1260 DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



class Graph {
    int v;
    vector<vector<int> > adj;
    vector<bool> dfs_visited;
    vector<bool> bfs_visited;
    vector<int> orderDFS;
    vector<int> orderBFS;

public:
    Graph(int v){
        this->v = v;
        adj.resize(v + 1);
        dfs_visited.resize(v + 1, false);
        bfs_visited.resize(v + 1, false);
    }
    void sort_graph(){
        for (int i = 1; i <= v; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print_dfs(int start){
        dfs(start);
        for(int i = 0; i < orderDFS.size(); i++){
            if(i == orderDFS.size()-1){
                cout << orderDFS[i] << endl;
            }
            else{
                cout << orderDFS[i] << " ";
            }
        }
    }
    void print_bfs(int start){
        bfs(start);
        for(int i = 0; i < orderBFS.size(); i++){
            if(i == orderBFS.size()-1){
                cout << orderBFS[i] << endl;
            }
            else{
                cout << orderBFS[i] << " ";
            }
        }
    }
    void dfs(int node){
        dfs_visited[node] = true;
        orderDFS.push_back(node);
        

        for(int i = 0; i < adj[node].size(); i++){
            int neighbor = adj[node][i];
            if(!dfs_visited[neighbor]){
                dfs(neighbor);
            }
        }
    }
    void bfs(int start){
        queue<int> q;
        q.push(start);
        bfs_visited[start] = true;
        orderBFS.push_back(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int i = 0; i < adj[node].size(); i++){
                int neighbor = adj[node][i];
                if(!bfs_visited[neighbor]){
                    bfs_visited[neighbor] = true;
                    q.push(neighbor);
                    orderBFS.push_back(neighbor);
                }
            }
        }

    }  
};

int main(){
    int n, m, v; // 노드 개수, 간선 개수, 시작 노드

    cin >> n >> m >> v;

    Graph g(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.sort_graph();
    g.print_dfs(v);
    g.print_bfs(v);

    return 0;
}