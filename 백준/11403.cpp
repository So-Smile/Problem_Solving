// 백준 11403: 경로 찾기
#include <iostream>

using namespace std;

int main(){
    int n;

    cin >> n;

    int arr[n][n];

    // 그래프 입력 받기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int k = 0; k < n; k++){ // 중간에 거치는 노드
        for(int i = 0; i < n; i++){ // 출발 노드
            for(int j = 0; j < n; j++){ // 도착 노드
                if(arr[i][k] == 1 && arr[k][j] == 1){
                    arr[i][j] = 1;
                }
            }
        }
    }
    // 정답 출력
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}