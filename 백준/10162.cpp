#include <iostream>

using namespace std;

int main(){
    int t, answer = 0;
    int a = 0, b = 0, c = 0;
    
    
    cin >> t;
    
    if(t % 10 != 0){
        answer = -1;
        cout << answer << endl;
    }
    else{
         if(t >= 300){
            //  while(t / 300 != 0){
            //      t %= 300;
            //      a++;
            //  }
            a = t / 300;
            t %= 300;
         }
        if(t >= 60 && t < 300){
            // while(t / 60 != 0){
            //     t %= 60;
            //     b++;
            // }
            b = t / 60;
            t %= 60;
        }
        if(t >= 10 && t < 60){
            // while(t / 10 != 0){
            //     t /= 10;
            //     c = t;
            // }
            c = t / 10;
        }
        cout << a << " " << b << " " << c <<endl;
    }
    
    
    return 0;
}
