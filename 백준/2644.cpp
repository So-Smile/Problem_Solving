// 백준 2644번 촌수계산
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int v;
    vector<vector<int> > adj;
    vector<bool> visited;

public:
    Graph(int v) {
        this->v = v;
        adj.resize(v + 1);  // 사람 번호가 1번부터 시작하므로 v + 1로 설정
        visited.resize(v + 1, false);
    }

    void addEdge(int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int findChon(int start, int end) {
        queue<pair<int, int> > q; // {노드 번호, 촌수}
        q.push(make_pair(start, 0)); 
        visited[start] = true; // 방문했다는 표시

        while (!q.empty()) {
            int node = q.front().first;
            int chon = q.front().second;
            q.pop();

            // 목적지에 도착하면 현재 촌수를 반환
            if (node == end) {
                return chon;
            }

            // 인접 노드를 순회
            for (int i = 0; i < adj[node].size(); i++) { // 인접 노드 개수만큼 반복
                int neighbor = adj[node][i]; // 인접 노드 중에 한개를 고름
                if (!visited[neighbor]) { // 방문하지 않은 노드일 경우에만
                    visited[neighbor] = true; // 방문 표시
                    q.push(make_pair(neighbor, chon + 1)); // 인접 노드와 촌수를 쌍으로 저장
                }
            }
        }

        // 연결되지 않은 경우 -1 반환
        return -1;
    }
};

int main() {
    int n; // 전체 사람 수
    int m; // 부모 자식들 간의 관계의 개수
    int a, b; // 촌수를 계산할 두 사람의 번호
    
    cin >> n >> a >> b >> m;

    Graph g(n); // 전체 사람 수에 따라 그래프 초기화

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    int chon = g.findChon(a, b); // a와 b 사이의 촌수를 계산
    cout << chon << endl;

    return 0;
}
