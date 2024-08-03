// 뒤집기

#include <iostream>

using namespace std;

int main(){
    string str;
    int count = 0;
    int answer = 0;

    cin >> str;
    
    for(int i = 0; i < str.length() - 1; i++){
        // 변환점 찾기
        if(str[i] != str[i+1]){
            count++;
        }
    }

    answer = (count + 1) / 2; // 변환점 개수를 2로 나눠서 전환되는 최소갯수 구함

    cout << answer << endl;

    return 0;
}