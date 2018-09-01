#include <iostream>
#include <map>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

map<int,int> cakemap;
inline void write(int x);
inline int read();
bool checkallzero(map<int,int> *cakemap, int cakesize[], int mapsize, int arraysize);

int main()
{
    int T;
    cin >> T;
    while(T--){
        int N,M,pos; //N: Num of cakes types //M: Num of friends
        pos = 0;
        N = read();
        M = read();
        int friendability[M];
        int cakesize[N];
        int cakenums[N];
        int friendposition[M];
        int numofdays = 0;
        for(int i = 0; i < M; i++){
            friendability[i] = read();
        }
        for(int i = 0; i < N; i++){
            cakesize[i] = read(); // size of cake
        }
        for(int i = 0; i < N; i++){
            cakenums[i] = read(); // number of cake
        }
        for(int i = 0; i < N; i++){
            cakemap[cakesize[i]] = cakenums[i];
        }
        sort(friendability,friendability + M);
        sort(cakesize,cakesize + N);
        
        /*
        for(int i = 0; i < N; i++){
            map<int,int>::iterator iter = cakemap.find(cakesize[i]);
            cout << iter->first << " " << iter->second << endl;
        }
        */
        
        while(pos < N){
            if(friendability[M - 1] >= cakesize[pos]){
                friendposition[M - 1] = pos;
            }
            pos++;
        }
        if(friendposition[M - 1] < N-1){
            write(-1);
            cout << endl;
            cakemap.clear();
        }
        else{
            pos = 0;
            for(int i = M - 2; i >= 0; i--){
                while(pos < N){
                    if(friendability[i] >= cakesize[pos] && pos < friendposition[i + 1]){
                        friendposition[i] = pos;
                    }
                    pos++;
                }
                pos = 0;
            }//initial the eater's position
            
            while(friendposition[M - 1] >= 0){
                for(int i = M - 1; i >= 0; i--){
                    while(cakemap[cakesize[friendposition[i]]] <= 0 && friendposition[i] >= 0){
                        friendposition[i]--;
                    }
                    cakemap[cakesize[friendposition[i]]] --;
                    /* cout << "Monk friend of the index " << i << " eat the cake of size " << cakesize[friendposition[i]] << " Now left " << cakemap[cakesize[friendposition[i]]] << endl; */
                }
                numofdays++;
            }
            write(numofdays - 1);
            numofdays = 0;
            cout << endl;
        }
    }
}

inline void write(int x){
    if(x<0) {putchar('-');x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

inline int read(){
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

bool checkallzero(map<int,int> *cakemap, int cakesize[], int mapsize, int arraysize){
    for(int i = 0; i < arraysize; i++){
        map<int,int>::iterator iter = (*cakemap).find(cakesize[i]);
        if(iter->second != 0) return 0;
    }
    return 1;
}
