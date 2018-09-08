#include <iostream>
#include <string.h>
#include <algorithm>

#define MAX 110
#define MODULUS 1001113

using namespace std;

int totalcase,casenowat,fullpermutation,numofdescent;
int dp[MAX][MAX];
int finish_lah = 0;

void process(){
    memset(dp,0,sizeof(dp));
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i = 3;i <= 100;i++)
    {
        dp[i][0] = 1;
        for(int j = 1; j < i - 1; j++)
        {
            dp[i][j] = (dp[i-1][j-1] * (i-j) + dp[i-1][j] * (j+1) );
            dp[i][j] %= MODULUS;
        }
        dp[i][i-1] = 1;
    }
}

int main(){
    process();
    scanf("%d",&totalcase);
    while(totalcase--)
    {
        cin >> casenowat >> fullpermutation >> numofdescent;
        cout << casenowat << " " << dp[fullpermutation][numofdescent] << endl;
    }
    return finish_lah;
}
