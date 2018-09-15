#include<iostream>


bool FLAG  = false;

using namespace std;
bool check(int, int, int);
void knight(int pos, char arr[200][200], int x , int y, int N);
//inline int read()
//{
//    int X=0,w=0; char ch=0;
//    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
//    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
//    return w?-X:X;
//}
//
////double a = read();
//inline double dbread()
//{
//    double X=0,Y=1.0; int w=0; char ch=0;
//    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
//    while(isdigit(ch)) X=X*10+(ch^48),ch=getchar();
//    ch=getchar();//读入小数点
//    while(isdigit(ch)) X+=(Y/=10)*(ch^48),ch=getchar();
//    return w?-X:X;
//}
//
////write(myarray[4]);
////write(a);
//inline void write(int x)
//{
//    if(x<0) putchar('-'),x=-x;
//    if(x>9) write(x/10);
//    putchar(x%10+'0');
//}

int main(){
    int N;
    
    
    cin >> N;
    int num = N*N;
    int x[num + 1];
    int y[num + 1];

    char arr[200][200];
    int j = 0;
    for (int i = 0; i<N; i++){
        for(int k = 0; k < N; k++){
            cin >> arr[i][k];
            if (arr[i][k] == 'I'){
                x[j] = i;
                y[j] = k;
                j++;
                
            }
        }
        
    }
    if(j>0){
        for(int i = 0; i<j; i++){
            knight(0, arr, x[i], y[i], N);
        }
        if(FLAG == true)
            cout << "YES" <<endl;
        else
            cout << "NO"<<endl;
    }
    else
        cout << "NO" << endl;
   
    
    return 0;
}
void knight(int pos, char arr[200][200], int x , int y, int N){
    string s = "ICPCASIASG";
    char c = s[++pos];
    if(pos == 9){
        if(check(x+1, y+2, N) && arr[x+1][y+2] == c){
            FLAG = true;
            return;
        }
        if(check(x+1, y-2, N) && arr[x+1][y-2] == c){
            FLAG = true;
            return;
        }
        if(check(x-1, y+2, N) && arr[x-1][y+2] == c){
            FLAG = true;
            return;
        }
        if(check(x-1, y-2, N) && arr[x-1][y-2] == c){
           FLAG = true;
            return;
        }
        if(check(x+2, y+1, N) && arr[x+2][y+1] == c){
            FLAG = true;
            return;
        }
        if(check(x+2, y-1, N) && arr[x+2][y-1] == c){
            FLAG = true;
            return;
        }
        if(check(x-2, y+1, N) && arr[x-2][y+1] == c){
            FLAG = true;
            return;
        }
        if(check(x-2, y-1, N) && arr[x-2][y-1] == c){
            FLAG = true;
            return;
        }
        
        return;
    }
    else{
        if(check(x+1, y+2, N) && arr[x+1][y+2] == c){
            knight(pos, arr, x+1, y+2, N);
            
        }
        if(check(x+1, y-2, N) && arr[x+1][y-2] == c){
            knight(pos, arr, x+1, y-2, N);
        }
        if(check(x-1, y+2, N) && arr[x-1][y+2] == c){
            knight(pos, arr, x-1, y+2, N);
        }
        if(check(x-1, y-2, N) && arr[x-1][y-2] == c){
            knight(pos, arr, x-1, y-2, N);
        }
        if(check(x+2, y+1, N) && arr[x+2][y+1] == c){
            knight(pos, arr, x+2, y+1, N);
        }
        if(check(x+2, y-1, N) && arr[x+2][y-1] == c){
            knight(pos, arr, x+2, y-1, N);
        }
        if(check(x-2, y+1, N) && arr[x-2][y+1] == c){
            knight(pos, arr, x-2, y+1, N);
            
        }
        if(check(x-2, y-1, N) && arr[x-2][y-1] == c){
            knight(pos, arr, x-2, y-1, N);
        }
    }
}

bool check(int x, int y, int N){
    if(x<0 || x>N-1 || y < 0 || y>N-1){
        return false;
    }
    else return true;
    
}
