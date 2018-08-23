#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ball = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            if(ball == 1){
                ball = 2;
            }
            else if(ball == 2){
                ball = 1;
            }
            else{}
        }
        else if(s[i] == 'B'){
            if(ball == 2){
                ball = 3;
            }
            else if(ball == 3){
                ball = 2;
            }
            else{}
        }
        else{
            if(ball == 1){
                ball = 3;
            }
            else if(ball == 3){
                ball = 1;
            }
            else{}
        }
    }
    cout << ball << endl;
}
