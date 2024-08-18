// 바닥 장식

#include <iostream>

using namespace std;

int n, m;
int currentX = 0, currentY = 0;
bool visited[51][51]; // 방문 여부를 저장할 배열
string area[51]; // 전체 방바닥

int main(){
    int answer = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> area[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]){
                continue;
            }
            visited[i][j] = true; // 새로운 거면 +1
            answer += 1;

            // - 모양이면 옆으로 방문
            if(area[i][j] == '-'){
                currentY = j + 1;
                while(currentY < m && area[i][currentY] == '-'){
                    visited[i][currentY] = true;
                    currentY += 1;
                }
            }
            // | 모양이면 아래로 방문
            else if(area[i][j] == '|'){
                currentX = i + 1;
                while(currentX < n && area[currentX][j] == '|'){
                    visited[currentX][j] = true;
                    currentX += 1;
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}