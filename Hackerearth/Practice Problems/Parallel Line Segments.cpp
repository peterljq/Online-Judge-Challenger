#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAXN 1000001

inline void write(int x);
int main(){
    long long N,M,Q;
    cin >> N >> M >> Q;
    string s = "";
    long long first;
    long long second;
    long long cut[1000000];
    long long sum = 0;
    long long accumulate[1000000];
    long long intersect[1000000];
    for(long long i = 0; i < N + 1; i++){
        accumulate[i] = 0;
        intersect[i] = 0;
    }
    for(long long i = 0; i < M; i++){
        cin >> first;
        accumulate[first] ++;
        cin >> second;
        accumulate[second + 1] --;
    }
    for(long long i = 0; i < N + 1; i++){
        sum += accumulate[i];
        intersect[i] = sum;
    }
    for(long long i = 0; i < Q; i++){
        cin >> cut[i];
    }
    for(long long i = 0; i < Q; i++){
        write(intersect[cut[i]]);
        printf("\n");
    }
    
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
