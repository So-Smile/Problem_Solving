// 백준 14487번 욱제는 효도쟁이야
#include <iostream>
#include <vector>

using namespace std;

int main(){
    /*
        원형으로 이어져 있고 합을 구하는 것이므로 큰 거 빼고 다 더하면 됨
    */
    int n;
    int max = 0, max_idx = 0;
    int answer = 0;

    cin >> n;

    int *v = new int[n];

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(max < v[i])
            max = v[i];
            max_idx = i; // 중복된 최대값은 한번만 빼줘야하므로 최대값 인덱스를 저장하고
    }
    for(int i = 0; i < n; i++){
        if(i != max_idx) // 한번만 뺄 수 있도록 함
            answer += v[i];
    }
    cout << answer << endl;
    
    delete []v;
    return 0;
}