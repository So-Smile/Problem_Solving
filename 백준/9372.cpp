// 상근이의 여행

#include<iostream>
using namespace std;

int main(){

    int t, n, m; // 테스트케이스 수, 방문할 국가 수, 비행기 종류
    int a,b; // 입력받은 비행기 왕복 
    int answer = 0;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < m ; i++){
            cin >> a >> b;//노드간 연결 정보를 엣지 수만큼 입력받기
        }
        answer = n - 1; // 연결된 그래프에서 엣지 수는 노드 수-1 일때 가장 작음
        cout << n - 1 << endl;
    }

    return 0;
}