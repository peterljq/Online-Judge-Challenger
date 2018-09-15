#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

//double a = read();
inline double dbread()
{
    double X=0,Y=1.0; int w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=X*10+(ch^48),ch=getchar();
    ch=getchar();//读入小数点
    while(isdigit(ch)) X+=(Y/=10)*(ch^48),ch=getchar();
    return w?-X:X;
}

//write(myarray[4]);
//write(a);
inline void write(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

int main(){
    long long N,Q,query,A,B,C,D;
    N = read();
    Q = read();
    long long arr[100001];
    while(Q--){
        query = read();
        if(query == 1){
            A = read();
            B = read();
            C = read();
            for(long long j = 1; j <= N; j++){
                if(j % B == A){
                    arr[j] += C;
                }
            }
        }
        else{
            D = read();
            cout << arr[D] << endl;
        }
    }
    return 0;
}

