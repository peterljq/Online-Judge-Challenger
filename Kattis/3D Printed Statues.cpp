#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int printer = 1;
    int day = 0;
    while(printer < n){
        printer *= 2;
        day ++;
    }
    cout << day + 1 << endl;
}

