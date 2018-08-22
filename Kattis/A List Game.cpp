#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    int a;
    vector<int> collection;
    scanf("%d",&a);
    int upperlimit = a;
    if(a == 2 || a == 3){
        printf("%d\n",1);
    }
    else if(a == 1){
        printf("%d\n",0);
    }
    else{
        for(int i = 2; i*i<=upperlimit; i++){
            while(a%i == 0 && a > 1){
                a /= i;
                collection.push_back(i);
            }
        }
        if(a > 1){
            collection.push_back(upperlimit);
        }
        printf("%d\n",collection.size());
    }
}
