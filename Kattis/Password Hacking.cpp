#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



/* int main(){
    string s;
    int n;
    cin >> n;
    double a[n];
    double weight[n];
    double trytimes = 0;
    double accumulate = 1;
    for(int i = 0; i <n; i++){
        cin >> s;
        cin >> a[i];
    }
    weight[0] = a[0];
    for(int i = 1; i < n - 1; i++){
        accumulate *= (1 - a[i-1]);
        weight[i] = accumulate * a[i];
    }
    accumulate *= (1 - a[n - 2]);
    weight[n - 1] = accumulate;
    for(int i = 0; i < n; i++){
        trytimes += (i+1)*weight[i];
    }
    cout << trytimes << endl;
}
*/
// I disagree with answer of the provided case. Above is my old answer which I think should be correct.

int main(){
    string s;
    int n;
    cin >> n;
    double a[n];
    double trytimes = 0;
    for(int i = 0; i <n; i++){
        cin >> s;
        cin >> a[i];
    }
    sort(a,a + n);
    for(int i = 0; i <n; i++){
        trytimes += (n - i) * a[i];
    }
    printf("%.4lf\n",trytimes);
}
