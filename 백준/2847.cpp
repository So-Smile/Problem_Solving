#include <iostream>

using namespace std;

int main() {

    int n = 0; // 레벨 수
    int count = 0;

    cin >> n;

    int *score = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> score[i]; 
    }

    for(int i = (n-1); i > 0; i--) {
        if (score[i] <= score[i-1]) {
            int diff = score[i-1] - score[i] + 1;
            score[i-1] -= diff;
            count += diff;
        }
    }

    cout << count << endl;

    delete []score;

    return 0;
}