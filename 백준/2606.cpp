// 백준 2606번 바이러스
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int v; // 각 컴퓨터(노드)
    vector<vector<int> > adj; // 인접한 컴퓨터(노드)
    vector<bool> visited; // 카운팅한 컴퓨터(방문한 노드)

public:
    // Graph 클래스의 생성자: 초기화를 담당
    Graph(int v) {
        this->v = v; // this는 현재 객체를 가리키는 포인터로 멤버 변수 v를 지금 받은 인자 v로 초기화
        adj.resize(v + 1); // 인접한 노드 사이즈(개수) 초기화
        visited.resize(v + 1, false); // 방문한 노드를 저장할 벡터 사이즈 초기화
    }
    // 컴퓨터 쌍을 인접한 노드로 저장하는 멤버함수
    void addEdge(int u, int v) {
        // 서로를 인접한 노드에 넣음
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    // dfs로 연결되어 있는 컴퓨터를 세는 멤버함수
    int countNodes(int start) {
        int count = 0;
        dfs(start, count);
        return count - 1; // 1번 컴퓨터는 빼야함(이미 카운팅 되었기 때문)
    }
    
private:
    void dfs(int node, int &count) {
        visited[node] = true; // 새로운 노드이므로 방문했다는 표시
        count++; // 새로운 노드이므로 카운팅

        // 이웃 노드의 개수만큼 반복
        for(int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i]; // 인접한 노드 한 개씩 탐색
            if(!visited[neighbor]) { // 만약에 인접한 노드가 방문하지 않은 노드라면
                dfs(neighbor, count); // dfs 진행
            }
        }
    }
};

int main(){

    int computer_num; // 컴퓨터 수
    int pair_num; // 연결된 컴퓨터 쌍

    cin >> computer_num >> pair_num;

    Graph g(computer_num); // 컴퓨터의 개수만큼 그래프 용량 설정

    for(int i = 0; i < pair_num; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v); // 입력받은 컴퓨터 쌍을 그래프로 만듦
    }
    
    int worm_com = g.countNodes(1); // 1번 컴퓨터가 웜바이러스에 걸렸으므로 1번부터 시작
    
    cout << worm_com << endl; // 웜바이러스 걸린 컴퓨터 개수 출력

    return 0;
}