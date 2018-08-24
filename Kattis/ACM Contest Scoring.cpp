
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAXN 100001

int main(){
    int time;
    char question;
    string status;
    int truecount = 0;
    int result = 0;
    int accumulate[] = {0,0,0,0,0,0,0,0,0,0,0}; // A B C D E F G H I J K
    cin >> time;
    while(time != -1){
        cin >> question;
        cin >> status;
        if(question == 'A'){
            if(status == "wrong"){
                accumulate[0] += 20;
            }
            else{
                result += accumulate[0] + time;
                truecount ++;
            }
        }
        if(question == 'B'){
            if(status == "wrong"){
                accumulate[1] += 20;
            }
            else{
                result += accumulate[1] + time;
                truecount ++;
            }
        }
        if(question == 'C'){
            if(status == "wrong"){
                accumulate[2] += 20;
            }
            else{
                result += accumulate[2] + time;
                truecount ++;
            }
        }
        if(question == 'D'){
            if(status == "wrong"){
                accumulate[3] += 20;
            }
            else{
                result += accumulate[3] + time;
                truecount ++;
            }
        }
        if(question == 'E'){
            if(status == "wrong"){
                accumulate[4] += 20;
            }
            else{
                result += accumulate[4] + time;
                truecount ++;
            }
        }
        if(question == 'F'){
            if(status == "wrong"){
                accumulate[5] += 20;
            }
            else{
                result += accumulate[5] + time;
                truecount ++;
            }
        }
        if(question == 'G'){
            if(status == "wrong"){
                accumulate[6] += 20;
            }
            else{
                result += accumulate[6] + time;
                truecount ++;
            }
        }
        if(question == 'H'){
            if(status == "wrong"){
                accumulate[7] += 20;
            }
            else{
                result += accumulate[7] + time;
                truecount ++;
            }
        }
        if(question == 'I'){
            if(status == "wrong"){
                accumulate[8] += 20;
            }
            else{
                result += accumulate[8] + time;
                truecount ++;
            }
        }
        if(question == 'J'){
            if(status == "wrong"){
                accumulate[9] += 20;
            }
            else{
                result += accumulate[9] + time;
                truecount ++;
            }
        }
        if(question == 'K'){
            if(status == "wrong"){
                accumulate[10] += 20;
            }
            else{
                result += accumulate[10] + time;
                truecount ++;
            }
        }
        cin >> time;
    }
    cout << truecount << " " << result << endl;
}



