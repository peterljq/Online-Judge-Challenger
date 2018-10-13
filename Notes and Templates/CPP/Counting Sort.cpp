#include <iostream>

using namespace std;

int main(){
    int a[8] = {1,5,5,4,6,2,3,100};
    int result[8];
    int temp[101] = {0,0,0,0,0,0,0,0};
    
    for(int i = 0; i < 8; i++){
        temp[a[i]]++;
    }
    
    for(int i = 1; i < 101; i++){
        temp[i] += temp[i-1];
    }
    
    for(int i = 0; i < 8; i++){
        temp[a[i]]--;
        result[temp[a[i]]] = a[i];
    }
    
    for(int i = 0; i < 8; i++){
        cout << result[i] << " ";
    }
}
