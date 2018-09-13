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

void func(int a[],int left, int right, int *count){
    if(left == right){
        (*count)++;
        //cout << a[left];
    }
    else if(left > right){
        
    }
    else{
        int max = a[left], min = a[left], ind1 = left, ind2 = left, maxcont = 1, mincont = 1;
        for(int i = 0; i <right - left + 1; i++){
            
            if(max < a[i + left]){
                max = a[i + left];
                ind1 = i + left;
            }
            if(min >= a[i + left]){
                min = a[i + left];
                ind2 = i + left;
            }
            
        }
        int windowleft = ind2;
        int windowright = ind1;
        while(windowleft > left){
            if(a[windowleft] == a[windowleft - 1]){
                mincont++;
                windowleft--;
            }
            else{
                break;
            }
        }
        while(windowright < right){
            if(a[windowright] == a[windowright - 1]){
                maxcont++;
                windowright++;
            }
            else{
                break;
            }
        }
        
        if(ind1 == right || (ind1 != right && maxcont == right - ind1 + 1)){
            (*count)++;
            //cout << a[ind1];
        }
        if(ind2 == left || (ind2 != left && mincont == ind2 - left + 1)){
            (*count)++;
            //cout << a[ind2];
        }
        func(a, ind2 + 1, ind1 - 1, count);
    }
}

int main(){
    int num;
    int array[100010];
    int numofpiv = 0;
    cin >> num;
    for(int i = 0; i < num; i++){
        array[i] = read();
    }
    
    func(array,0,num-1,&numofpiv);
    
    cout << numofpiv << endl;
}

