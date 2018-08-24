#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAXN 1000001

//Amazing large test cases. MAXN = 100000 got RE.

int main(){
    int casenum;
    cin >> casenum;
    long l,n,result1,result2;
    long position[MAXN];
    long shortanswer[101];
    long longanswer[101];
    for(int i = 0; i < casenum; i++){
        cin >> l >> n;
        for(long j = 0; j < n; j++){
            cin >> position[j];
        }
        sort(position,position + n);
        
        //find shortest time
        long batchdivide = position[0];
        for(long f = 0; f < n; f++){
            if(abs(position[f] - l/2) < abs(batchdivide - l/2)){
                batchdivide = position[f];
            }
        }
        shortanswer[i] = min(l - batchdivide,batchdivide);
        
        //find longest time
        result1 = l - position[0];
        result2 = position[n - 1];
        longanswer[i] = max(result1, result2);
    }
    for(long i = 0; i < casenum; i++){
        cout << shortanswer[i] << " " << longanswer[i] << endl;
    }
}
