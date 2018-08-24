#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    long num1,num2;
    while(cin >> num1){
        cin >> num2;
        cout << abs(num2 - num1) << endl;
    }
}
