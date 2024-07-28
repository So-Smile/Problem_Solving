#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int fruit_num, snake_length;
    
    cin >> fruit_num >> snake_length;
    
    int *h = new int[fruit_num];
    
    for(int i = 0; i < fruit_num; i++){
        cin >> h[i];
    }
    sort(h, h+fruit_num);

    for(int i = 0; i < fruit_num; i++){
        if(snake_length >= h[i]){
            snake_length += 1;
        }
    }
    cout << snake_length << endl;
    
    delete[]h;
    
    return 0;
}
