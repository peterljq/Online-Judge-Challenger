// https://open.kattis.com/problems/alphabetspam

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    string s;
    double collection[4] = {0,0,0,0};
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '_'){
            collection[0] ++;
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){
            collection[1] ++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            collection[2] ++;
        }
        else{
            collection[3] ++;
        }
    }
    for(int i = 0; i < 4; i++){
        collection[i] /= s.size();
        printf("%.15lf\n",collection[i]);
    }
    
}
