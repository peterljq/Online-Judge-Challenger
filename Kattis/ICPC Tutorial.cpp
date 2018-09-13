#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#define d double

using namespace std;


long long fac(int k, double m){
    int a = k;
    long long array[1000000];
    array[0] = 1;
    for(long long i = 1; i <= a;i++){
        array[i] = array[i-1] * i;
        if(array[i] > m)
            return (long long) m+5;
    }
    return array[a];
}

int main(){
    int type;
    double e = 1e-7;
    double m,n;
    double totalcal = 0;
    cin >> m >> n >> type;
    switch(type){
        case 1: totalcal = fac(n, m);
            break;
        case 2: totalcal = pow(2,n);
            break;
        case 3: totalcal = n*n*n*n;
            break;
        case 4: totalcal = n*n*n;
            break;
        case 5: totalcal = n*n;
            break;
        case 6: totalcal = n*log2(n);
            break;
        case 7: totalcal = n;
            break;
    }
    
    if(totalcal < m || abs(totalcal - m) < e){
        cout << "AC" <<endl;
    }
    else{
        cout << "TLE" <<endl;
    }
}
