// 백준 24444번: 알고리즘 수업 - 너비 우선 탐색1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int N, int M, int R, vector<vector<int>>& adj) {
    vector<int> visited(N + 1, 0);  // 각 노드의 방문 여부를 기록 0: 방문 X
    vector<int> order(N + 1, 0);    // 각 노드의 방문 순서를 기록
    int count = 0;  // 방문 순서 카운터

    queue<int> q;
    q.push(R);
    visited[R] = 1;  // 시작 노드 R 방문

    while (!q.empty()) {
        int u = q.front();
        q.pop(); 
        count++;
        order[u] = count;  // 현재 노드를 방문한 순서 기록

        // 인접 노드들을 오름차순으로 방문하기 위해 정렬
        sort(adj[u].begin(), adj[u].end());

        // 인접 노드들을 큐에 추가
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;  // 방문 표시
                q.push(v); // 큐에 추가
            }
        }
    }

    // 각 노드의 방문 순서를 출력
    for (int i = 1; i <= N; i++) {
        cout << order[i] << '\n';
    }
}

int main() {
    int N, M, R; // 노드 수, 간선 수, 시작 노드
    cin >> N >> M >> R;

    vector<vector<int>> adj(N + 1); // 인접 노드의 크기 설정

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v); // 서로 인접 노드에 넣음
        adj[v].push_back(u);
    }

    bfs(N, M, R, adj);

    return 0;
}

