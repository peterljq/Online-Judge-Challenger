#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}


int main(){
    int C,N;
    double average = 0,passrate = 0,passcount=0;
    int student[100000];
    C = read();
    while(C--){
        N = read();
        for(int i = 0; i < N; i++){
            student[i] = read();
            average += student[i];
        }
        average /= N;
        for(int i = 0; i < N; i++){
            if(student[i] > average){
                passcount++;
            }
        }
        passrate = 100 * passcount/N;
        printf("%.3f%%\n",passrate);
        average = 0;
        passcount = 0;
    }
}

