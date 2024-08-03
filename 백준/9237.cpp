// 이장님의 초대

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int tree_num; // 나무 개수
    int answer = 0; 
    vector <int>v; // 나무별 심는 일 수

    cin >> tree_num;

    for(int i = 0; i < tree_num; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.rbegin(),v.rend());

    for(int i = tree_num; i > 0; i--){
        v[tree_num-i] -= i;
    }
    
    sort(v.rbegin(), v.rend());

    answer = v[0] + tree_num + 2; // 첫번째 나무 심는 날 + 마지막 나무 심는 날을 2일로 더함
    cout << answer << endl;

    return 0;
}