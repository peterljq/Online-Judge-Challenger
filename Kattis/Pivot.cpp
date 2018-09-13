#include<iostream>

using namespace std;

inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

int main(){
    int num;
    int count = 0;
    int array[100010];
    int dp_increasing[100010];
    int dp_decreasing[100010];
    cin >> num;
    for(int i = 0; i < num; i++){
        array[i] = read();
    }
    int max = array[0];
    int min = array[num-1];
    
    for(int i = 0; i < num; i++){
        if(max <= array[i]){
            max = array[i];
        }
        dp_increasing[i] = max;
    }
    
    for(int i = num - 1; i >= 0; i--){
        if(min >= array[i]){
            min = array[i];
        }
        dp_decreasing[i] = min;
    }
    for(int i = 0; i < num; i++){
        if(dp_increasing[i] == dp_decreasing[i]){
            count ++;
        }
    }
    cout << count << endl;
}

