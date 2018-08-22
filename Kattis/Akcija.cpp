//https://open.kattis.com/problems/akcija

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    vector<int> v;
    int n,a;
    int skip = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int sum = 0;
    for(int i = n - 1; i >= 0; i--){
        if(skip != 3){
            sum += v.at(i);
            skip ++;
        }
        else{
            skip = 1;
        }
    }
    cout << sum << endl;
}
