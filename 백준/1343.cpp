// 백준 1343번 폴리오미노
#include <iostream>
#include <vector>

using namespace std;

int main(){

    /*
        처음에는 .이 나오기 전까지의 X의 개수를 처음부터 끝까지 세서 벡터에 넣은 다음 계산해서 넣어주려 했으나 좀 더 그리디답게 하고 싶었음
        .단위로 X를 세서 계산해서 answer문자열에 AAAA or BB를 넣어주면서 바로바로 answer 문장을 만들어감
        장점은 for문을 한번만 돌려도 된다는 것임
     */
    int x_cnt = 0; // X의 개수
    string inputStr; // 입력 받을 문자열
    string answer = ""; // 답으로 출력할 문자열

    cin >> inputStr; 

    for(int i = 0; i < inputStr.length(); i++){
        if(inputStr[i] == 'X'){ // .이 나오기 전까지의 X개수를 셈
            x_cnt++;
        } 
        // .을 만나거나 맨 끝의 인덱스가 되면
        if(inputStr[i] == '.' || i == (inputStr.length() - 1)){
            int temp = x_cnt; // x개수의 훼손을 막기 위해 X개수 저장
            
            if(x_cnt >= 4){ // X개수가 4개 이상이면
                int div = 0;
                div = x_cnt / 4; // 4로 나눈 몫을 저장하여 AAAA를 몫만큼 반복하여 써줌
                for(int j = 0; j < div; j++){
                    answer += "AAAA";
                }
                temp = x_cnt % 4; // 나머지를 저장, 예) X가 6개일 경우를 대비
            }
            if(temp == 2){ // 남은 X개수가 2개이면 BB를 더함
                answer += "BB";
            }
            if(x_cnt % 2 != 0){ // 2개도 아니면 X개수가 4 또는 2로 나누어 떨어지지 않는다는 뜻이므로 종료
                cout << -1 << endl;
                return 0;
            }
            if(inputStr[i] == '.') // .을 더함
                answer += ".";
            x_cnt = 0; // .단위로 X개수를 세야하므로 .을 만난 후에는 초기화
        }
    }
    cout << answer << endl;
    
  return 0;  
}